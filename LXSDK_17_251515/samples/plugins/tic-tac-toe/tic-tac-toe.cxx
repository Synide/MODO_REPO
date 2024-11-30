// Tic Tac Toe
// This plugin demonstrates a "simple" virtual model plugin that draws an nteractive game of tic
// tac toe in all 3D viewports.

#include <lx_draw.hpp>
#include <lx_file.hpp>
#include <lx_handles.hpp>
#include <lx_image.hpp>
#include <lx_stddialog.hpp>
#include <lx_toolui.hpp>
#include <lx_vector.hpp>
#include <lx_vmodel.hpp>
#include <lx_vp.hpp>

#include <lxu_command.hpp>
#include <lxu_math.hpp>

#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>

#define SERVER_BASE      "tictactoe"
#define SERVER_VMODEL    SERVER_BASE ".vmodel"
#define SERVER_CMD_PLAY  SERVER_BASE ".play"
#define SERVER_CMD_MOVE  SERVER_BASE ".move"
#define SERVER_CMD_RESET SERVER_BASE ".reset"

// Magic Numbers!
#define EMPTYSPACE_SCORE     0.01
#define PLAYER1PIECE_SCORE   1.0
#define PLAYER2PIECE_SCORE   5.0
#define COMPUTER1PIECE_MULT  0.0
#define COMPUTER2PIECE_SCORE 20.0

static CLxUser_VirtualModel* gVModel = nullptr;

enum TicTacToe_State
{
    TicTacToe_State_Empty,
    TicTacToe_State_X,
    TicTacToe_State_O
};

// Game State
struct MoveOption
{
    uint32_t x;
    uint32_t y;
    double   score;
};

bool SortMoveOptions(const MoveOption& a, const MoveOption& b)
{
    return a.score > b.score;
}

typedef std::vector<MoveOption> MoveList;

class TicTacToe
{
public:
    TicTacToe()
    {
        Restart();
        mPlayerPiece  = TicTacToe_State_X;
        mPlayerWins   = 0;
        mComputerWins = 0;
    }

    void Restart()
    {
        for (uint32_t i = 0; i < 3; ++i)
        {
            for (uint32_t j = 0; j < 3; ++j)
            {
                mCells[i][j] = TicTacToe_State_Empty;
            }
        }

        mChangeCount = 0;
        mWinner      = TicTacToe_State_Empty;
    }

    bool IsGameComplete()
    {
        return (mChangeCount == 9 || mWinner != TicTacToe_State_Empty);
    }

    bool IsPlayerWinner()
    {
        return (mWinner == PlayerPiece());
    }

    bool IsComputerWinner()
    {
        return (mWinner == ComputerPiece());
    }

    uint32_t PlayerWinCount()
    {
        return mPlayerWins;
    }

    uint32_t ComputerWinCount()
    {
        return mComputerWins;
    }

    void SetPlayerPiece(TicTacToe_State piece)
    {
        if (piece != TicTacToe_State_Empty)
        {
            mPlayerPiece = piece;
            Restart();
        }
    }

    TicTacToe_State PlayerPiece()
    {
        return mPlayerPiece;
    }

    TicTacToe_State ComputerPiece()
    {
        return (mPlayerPiece == TicTacToe_State_O) ? TicTacToe_State_X : TicTacToe_State_O;
    }

    bool MovePlayerPiece(uint32_t x, uint32_t y)
    {
        uint32_t computerX, computerY;

        if (SetCellState(x, y, mPlayerPiece))
        {
            mWinner = GetWinner();
            if (!IsGameComplete())
            {
                if (CalculateComputerMove(&computerX, &computerY))
                {
                    SetCellState(computerX, computerY, ComputerPiece());
                    mWinner = GetWinner();
                }
            }

            if (IsGameComplete())
            {
                if (IsPlayerWinner())
                    mPlayerWins++;
                else if (IsComputerWinner())
                    mComputerWins++;
            }

            return true;
        }

        return false;
    }

    TicTacToe_State CellState(uint32_t x, uint32_t y)
    {
        return mCells[x][y];
    }

private:
    TicTacToe_State GetWinner()
    {
        if (TestWin(TicTacToe_State_O))
            return TicTacToe_State_O;
        else if (TestWin(TicTacToe_State_X))
            return TicTacToe_State_X;

        return TicTacToe_State_Empty;
    }

    bool TestWin(TicTacToe_State piece)
    {
        if (mCells[0][0] == piece)
        {
            if (mCells[0][1] == piece && mCells[0][2] == piece)
                return true;
            if (mCells[1][0] == piece && mCells[2][0] == piece)
                return true;
            if (mCells[1][1] == piece && mCells[2][2] == piece)
                return true;
        }

        if (mCells[1][0] == piece && mCells[1][1] == piece && mCells[1][2] == piece)
        {
            return true;
        }

        if (mCells[2][0] == piece && mCells[2][1] == piece && mCells[2][2] == piece)
        {
            return true;
        }

        if (mCells[0][1] == piece && mCells[1][1] == piece && mCells[2][1] == piece)
        {
            return true;
        }

        if (mCells[0][2] == piece)
        {
            if (mCells[1][2] == piece && mCells[2][2] == piece)
                return true;
            else if (mCells[1][1] == piece && mCells[2][0] == piece)
                return true;
        }

        return false;
    }

    bool SetCellState(uint32_t x, uint32_t y, TicTacToe_State state)
    {
        if (x < 3 && y < 3)
        {
            if (mCells[x][y] != state)
            {
                mCells[x][y] = state;

                if (state == TicTacToe_State_Empty)
                    mChangeCount--;
                else
                    mChangeCount++;

                return true;
            }
        }

        return false;
    }

    double ScoreRow(uint32_t x, uint32_t y)
    {
        TicTacToe_State playerState   = PlayerPiece();
        TicTacToe_State computerState = ComputerPiece();
        TicTacToe_State tempState = TicTacToe_State_Empty, previousState = TicTacToe_State_Empty;
        uint32_t        lookupIndex[3][2] = { { 1, 2 }, { 0, 2 }, { 0, 1 } };
        double          score = 0.0, multiplier = 1.0;

        tempState = CellState(lookupIndex[x][0], y);
        if (tempState == playerState)
            score += PLAYER1PIECE_SCORE;
        else if (tempState == computerState)
            multiplier = COMPUTER1PIECE_MULT;
        else
            score += EMPTYSPACE_SCORE;

        previousState = tempState;
        tempState     = CellState(lookupIndex[x][1], y);
        if (tempState == playerState && previousState == playerState)
            score += PLAYER2PIECE_SCORE;
        else if (tempState == playerState)
            score += PLAYER1PIECE_SCORE;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) != 0)
            multiplier = COMPUTER1PIECE_MULT;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) == 0)
        {
            score      = COMPUTER2PIECE_SCORE;
            multiplier = 1.0;
        }
        else
            score += EMPTYSPACE_SCORE;

        return (score * multiplier);
    }

    double ScoreColumn(uint32_t x, uint32_t y)
    {
        TicTacToe_State playerState   = PlayerPiece();
        TicTacToe_State computerState = ComputerPiece();
        TicTacToe_State tempState = TicTacToe_State_Empty, previousState = TicTacToe_State_Empty;
        uint32_t        lookupIndex[3][2] = { { 1, 2 }, { 0, 2 }, { 0, 1 } };
        double          score = 0.0, multiplier = 1.0;

        tempState = CellState(x, lookupIndex[y][0]);
        if (tempState == playerState)
            score += PLAYER1PIECE_SCORE;
        else if (tempState == computerState)
            multiplier = COMPUTER1PIECE_MULT;
        else
            score += EMPTYSPACE_SCORE;

        previousState = tempState;
        tempState     = CellState(x, lookupIndex[y][1]);
        if (tempState == playerState && previousState == playerState)
            score += PLAYER2PIECE_SCORE;
        else if (tempState == playerState)
            score += PLAYER1PIECE_SCORE;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) != 0)
            multiplier = COMPUTER1PIECE_MULT;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) == 0)
        {
            score      = COMPUTER2PIECE_SCORE;
            multiplier = 1.0;
        }
        else
            score += EMPTYSPACE_SCORE;

        return (score * multiplier);
    }

    double ScoreDiagonal(uint32_t x, uint32_t y)
    {
        TicTacToe_State playerState   = PlayerPiece();
        TicTacToe_State computerState = ComputerPiece();
        TicTacToe_State tempState = TicTacToe_State_Empty, previousState = TicTacToe_State_Empty;
        uint32_t        lookupOne[2], lookupTwo[2];
        double          score = 0.0, multiplier = 1.0;

        switch (x)
        {
            case 0:
                if (y == 0)
                {
                    lookupOne[0] = 1;
                    lookupOne[1] = 1;
                    lookupTwo[0] = 2;
                    lookupTwo[1] = 2;
                }
                else
                {
                    lookupOne[0] = 1;
                    lookupOne[1] = 1;
                    lookupTwo[0] = 0;
                    lookupTwo[1] = 2;
                }

                break;

            case 2:
                if (y == 0)
                {
                    lookupOne[0] = 1;
                    lookupOne[1] = 1;
                    lookupTwo[0] = 0;
                    lookupTwo[1] = 2;
                }
                else
                {
                    lookupOne[0] = 1;
                    lookupOne[1] = 1;
                    lookupTwo[0] = 0;
                    lookupTwo[1] = 0;
                }

                break;
        }

        tempState = CellState(lookupOne[0], lookupOne[1]);
        if (tempState == playerState)
            score += PLAYER1PIECE_SCORE;
        else if (tempState == computerState)
            multiplier = COMPUTER1PIECE_MULT;
        else
            score += EMPTYSPACE_SCORE;

        previousState = tempState;
        tempState     = CellState(lookupTwo[0], lookupTwo[1]);
        if (tempState == playerState && previousState == playerState)
            score += PLAYER2PIECE_SCORE;
        else if (tempState == playerState)
            score += PLAYER1PIECE_SCORE;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) != 0)
            multiplier = COMPUTER1PIECE_MULT;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) == 0)
        {
            score      = COMPUTER2PIECE_SCORE;
            multiplier = 1.0;
        }
        else
            score += EMPTYSPACE_SCORE;

        return (score * multiplier);
    }

    double ScoreCenterDiagonal()
    {
        TicTacToe_State playerState   = PlayerPiece();
        TicTacToe_State computerState = ComputerPiece();
        TicTacToe_State tempState = TicTacToe_State_Empty, previousState = TicTacToe_State_Empty;
        double          tempScore = 0.0, score = 0.0, multiplier = 1.0;

        tempState = CellState(0, 0);
        if (tempState == playerState)
            tempScore += PLAYER1PIECE_SCORE;
        else if (tempState == computerState)
            multiplier = COMPUTER1PIECE_MULT;
        else
            tempScore += EMPTYSPACE_SCORE;

        previousState = tempState;
        tempState     = CellState(2, 2);
        if (tempState == playerState && previousState == playerState)
            tempScore += PLAYER2PIECE_SCORE;
        else if (tempState == playerState)
            tempScore += PLAYER1PIECE_SCORE;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) != 0)
            multiplier = COMPUTER1PIECE_MULT;
        else if (tempState == computerState && lx::Compare(multiplier, 0.0) == 0)
        {
            score      = COMPUTER2PIECE_SCORE;
            multiplier = 1.0;
        }
        else
            tempScore += EMPTYSPACE_SCORE;

        score += (tempScore * multiplier);

        tempScore  = 0.0;
        multiplier = 1.0;

        tempState = CellState(0, 2);
        if (tempState == playerState)
            tempScore += PLAYER1PIECE_SCORE;
        else if (tempState == computerState)
            multiplier = COMPUTER1PIECE_MULT;
        else
            tempScore += EMPTYSPACE_SCORE;

        previousState = tempState;
        tempState     = CellState(2, 0);
        if (tempState == playerState && previousState == playerState)
            tempScore += PLAYER2PIECE_SCORE;
        else if (tempState == playerState)
            tempScore += PLAYER1PIECE_SCORE;
        else if (tempState == computerState && multiplier != 0)
            multiplier = COMPUTER1PIECE_MULT;
        else if (tempState == computerState && multiplier == 0)
        {
            score      = COMPUTER2PIECE_SCORE;
            multiplier = 1.0;
        }
        else
            tempScore += EMPTYSPACE_SCORE;

        score += (tempScore * multiplier);

        return score;
    }

    bool CalculateComputerMove(uint32_t* x, uint32_t* y)
    {
        *x = 0;
        *y = 0;

        if (IsGameComplete())
            return false;

        MoveList moves;
        double   score = 0.0;
        uint32_t count = 0;

        // Calculate the scores for each potential position.
        for (uint32_t i = 0; i < 3; ++i)
        {
            for (uint32_t j = 0; j < 3; ++j)
            {
                if (CellState(i, j) != TicTacToe_State_Empty)
                    continue;

                count = 2;
                score = (ScoreRow(i, j) + ScoreColumn(i, j));

                // Test the diagonals.
                if (i == 1 && j == 1)
                {
                    score += ScoreCenterDiagonal();
                    count++;
                }
                else if (i == j)
                {
                    score += ScoreDiagonal(i, j);
                    count++;
                }
                else if ((i == 0 && j == 2) || (j == 0 && i == 2))
                {
                    score += ScoreDiagonal(i, j);
                    count++;
                }

                // If the score is greater than 0, add it to the list.
                if (score > 0.0)
                {
                    MoveOption moveOption;

                    moveOption.x     = i;
                    moveOption.y     = j;
                    moveOption.score = score;

                    moves.push_back(moveOption);
                }
            }
        }

        if (!moves.empty())
        {
            // Sort the move list and pick the highest score. If more than one choice has the
            // same score, randomly choose one.
            MoveList choices;
            double   highScore = 0.0;

            std::sort(moves.begin(), moves.end(), SortMoveOptions);

            for (uint32_t i = 0; moves.size(); ++i)
            {
                MoveOption option = moves[i];

                if (option.score >= highScore)
                {
                    highScore = option.score;
                    choices.push_back(option);
                }
                else
                {
                    break;
                }
            }

            if (choices.size() > 1)
            {
                srand(time(nullptr));

                MoveOption option = choices[rand() % choices.size()];

                *x = option.x;
                *y = option.y;

                return true;
            }
            else if (choices.size() == 1)
            {
                MoveOption option = choices[0];

                *x = option.x;
                *y = option.y;

                return true;
            }
        }

        // Something has gone wrong, just try and pick any empty cell.
        for (uint32_t i = 0; i < 3; ++i)
        {
            for (uint32_t j = 0; j < 3; ++j)
            {
                if (CellState(i, j) == TicTacToe_State_Empty)
                {
                    *x = i;
                    *y = j;

                    return true;
                }
            }
        }

        return false;
    }

    TicTacToe_State mCells[3][3];
    TicTacToe_State mPlayerPiece;
    TicTacToe_State mWinner;
    uint32_t        mChangeCount;
    uint32_t        mPlayerWins, mComputerWins;
};

// Virtual Model
enum VModel_Part
{
    VModel_Part_TitleBar = 100,
    VModel_Part_CloseButton,
    VModel_Part_ResetButton,
    VModel_Part_Cell_00,
    VModel_Part_Cell_10,
    VModel_Part_Cell_20,
    VModel_Part_Cell_01,
    VModel_Part_Cell_11,
    VModel_Part_Cell_21,
    VModel_Part_Cell_02,
    VModel_Part_Cell_12,
    VModel_Part_Cell_22
};

class VModel : public CLxImpl_VirtualModel, public TicTacToe
{
public:
    static void initialize()
    {
        CLxGenericPolymorph* srv = new CLxPolymorph<VModel>;
        srv->AddInterface(new CLxIfc_VirtualModel<VModel>);
        lx::AddSpawner(SERVER_VMODEL, srv);
    }

    VModel() : mInitialized(false), mPart(-1)
    {
        CLxUser_PacketService pktSvc;
        mPktOffset_input = pktSvc.GetOffset(LXsCATEGORY_TOOL, LXsP_TOOL_INPUT_EVENT);
    }

    static VModel* Spawn(void** ppvObj)
    {
        static CLxSpawner<VModel> spawner(SERVER_VMODEL);
        return spawner.Alloc(ppvObj);
    }

    static VModel* Cast(ILxUnknownID unknown)
    {
        static CLxSpawner<VModel> spawner(SERVER_VMODEL);
        return spawner.Cast(unknown);
    }

    LXxO_VirtualModel_Flags
    {
        return LXfTMOD_DRAW_PIXEL | LXfTMOD_I0_INPUT;
    }

    LXxO_VirtualModel_Draw
    {
        CLxUser_StrokeDraw draw(stroke);

        InitializeState();
        DrawGrid(draw, false);
    }

    LXxO_VirtualModel_Test
    {
        CLxUser_StrokeDraw draw(stroke);

        InitializeState();
        DrawGrid(draw, true);
    }

    LXxO_VirtualModel_Track
    {
        mPart = part;
    }

    LXxO_VirtualModel_Down
    {
        // TODO...
    }

    LXxO_VirtualModel_Move
    {
        // TODO...
    }

    LXxO_VirtualModel_Up
    {
        CLxUser_VectorStack vector(vts);

        if (vector.test())
        {
            LXpToolInputEvent* pktInput = (LXpToolInputEvent*) vector.Read(mPktOffset_input);
            uint32_t           x = 0, y = 0;

            if (CellFromPart((VModel_Part) pktInput->part, &x, &y) && TicTacToe::CellState(x, y) == TicTacToe_State_Empty)
            {
                CLxUser_CommandService cmdSvc;
                std::string            command;
                std::stringstream      ss;

                ss << SERVER_CMD_MOVE << " " << x << " " << y;
                command = ss.str();

                cmdSvc.ExecuteArgString(LXfCMD_EXEC_DEFAULT, LXiCTAG_NULL, command.c_str());
            }
        }
    }

private:
    int32_t CellToPart(uint32_t x, uint32_t y)
    {
        switch (x)
        {
            case 0:
                if (y == 0)
                    return VModel_Part_Cell_00;
                else if (y == 1)
                    return VModel_Part_Cell_01;
                else if (y == 2)
                    return VModel_Part_Cell_02;

            case 1:
                if (y == 0)
                    return VModel_Part_Cell_10;
                else if (y == 1)
                    return VModel_Part_Cell_11;
                else if (y == 2)
                    return VModel_Part_Cell_12;

            case 2:
                if (y == 0)
                    return VModel_Part_Cell_20;
                else if (y == 1)
                    return VModel_Part_Cell_21;
                else if (y == 2)
                    return VModel_Part_Cell_22;
        }

        return -1;
    }

    bool CellFromPart(VModel_Part part, uint32_t* x, uint32_t* y)
    {
        if (part < VModel_Part_Cell_00 || part > VModel_Part_Cell_22)
            return false;

        switch (part)
        {
            case VModel_Part_Cell_00:
                *x = 0;
                *y = 0;
                return true;

            case VModel_Part_Cell_01:
                *x = 0;
                *y = 1;
                return true;

            case VModel_Part_Cell_02:
                *x = 0;
                *y = 2;
                return true;

            case VModel_Part_Cell_10:
                *x = 1;
                *y = 0;
                return true;

            case VModel_Part_Cell_11:
                *x = 1;
                *y = 1;
                return true;

            case VModel_Part_Cell_12:
                *x = 1;
                *y = 2;
                return true;

            case VModel_Part_Cell_20:
                *x = 2;
                *y = 0;
                return true;

            case VModel_Part_Cell_21:
                *x = 2;
                *y = 1;
                return true;

            case VModel_Part_Cell_22:
                *x = 2;
                *y = 2;
                return true;
        }

        return false;
    }

    void DrawGrid(CLxUser_StrokeDraw& stroke, bool hit)
    {
        CLxUser_View view(stroke);
        int32_t      dimensions[2];
        double       width = 1.0, height = 1.0;
        double       drawSize = 0.0;
        double       cellWidth, cellHeight, cellX, cellY, baseCellX, baseCellY;

        view.Dimensions(&(dimensions[0]), &(dimensions[1]));

        width  = (double) dimensions[0];
        height = (double) dimensions[1];

        drawSize   = std::min(width, height) * 0.80;
        baseCellX  = (width - drawSize) * 0.5;
        baseCellY  = (height - drawSize) * 0.5;
        cellWidth  = drawSize / 3;
        cellHeight = cellWidth;

        if (!hit)
        {
            LXtVector color;
            LXx_VSET(color, 0.0);

            stroke.BeginW(LXiSTROKE_LINES, color, 0.25, 3.0);
            stroke.Vert(baseCellX, baseCellY + cellHeight, LXiSTROKE_ABSOLUTE);
            stroke.Vert(baseCellX + drawSize, baseCellY + cellHeight, LXiSTROKE_ABSOLUTE);

            stroke.BeginW(LXiSTROKE_LINES, color, 0.25, 3.0);
            stroke.Vert(baseCellX, baseCellY + (cellHeight * 2.0), LXiSTROKE_ABSOLUTE);
            stroke.Vert(baseCellX + drawSize, baseCellY + (cellHeight * 2.0), LXiSTROKE_ABSOLUTE);

            stroke.BeginW(LXiSTROKE_LINES, color, 0.25, 3.0);
            stroke.Vert(baseCellX + cellHeight, baseCellY, LXiSTROKE_ABSOLUTE);
            stroke.Vert(baseCellX + cellHeight, baseCellY + drawSize, LXiSTROKE_ABSOLUTE);

            stroke.BeginW(LXiSTROKE_LINES, color, 0.25, 3.0);
            stroke.Vert(baseCellX + (cellHeight * 2.0), baseCellY, LXiSTROKE_ABSOLUTE);
            stroke.Vert(baseCellX + (cellHeight * 2.0), baseCellY + drawSize, LXiSTROKE_ABSOLUTE);
        }

        cellX = baseCellX;
        cellY = baseCellY;

        for (uint32_t i = 0; i < 3; ++i)
        {
            cellY = baseCellY;

            for (uint32_t j = 0; j < 3; ++j)
            {
                DrawGridCell(stroke, TicTacToe::CellState(i, j), cellX, cellY, cellWidth, cellHeight, CellToPart(i, j), hit);

                cellY += cellHeight;
            }

            cellX += cellWidth;
        }
    }

    void DrawGridCell(CLxUser_StrokeDraw& stroke, TicTacToe_State state, double x, double y, double w, double h, int32_t part, bool hit)
    {
        if (hit && (state != TicTacToe_State_Empty || part < 0))
            return;

        if (!hit)
        {
            if (mPart == part)
            {
                if (state == TicTacToe_State_Empty && !mImages[TicTacToe::PlayerPiece()].test())
                    return;
            }
            else if (!mImages[state].test())
            {
                return;
            }
        }

        LXtVector color;
        LXx_VSET(color, 1.0);

        if (hit)
        {
            stroke.Begin(LXiSTROKE_QUADS, color, 1.0);
            stroke.SetPart(part);

            stroke.Vert(x, y, LXiSTROKE_ABSOLUTE);
            stroke.Vert(x + w, y, LXiSTROKE_ABSOLUTE);
            stroke.Vert(x + w, y + h, LXiSTROKE_ABSOLUTE);
            stroke.Vert(x, y + h, LXiSTROKE_ABSOLUTE);
        }
        else
        {
            if (mPart == part && state == TicTacToe_State_Empty)
                stroke.BeginI(mImages[TicTacToe::PlayerPiece()], LXiSTROKE_QUADS, color, 1.0);
            else
                stroke.BeginI(mImages[state], LXiSTROKE_QUADS, color, 1.0);

            stroke.TextureUV(0.0, 0.0);
            stroke.Vert(x, y, LXiSTROKE_ABSOLUTE);

            stroke.TextureUV(1.0, 0.0);
            stroke.Vert(x + w, y, LXiSTROKE_ABSOLUTE);

            stroke.TextureUV(1.0, 1.0);
            stroke.Vert(x + w, y + h, LXiSTROKE_ABSOLUTE);

            stroke.TextureUV(0.0, 1.0);
            stroke.Vert(x, y + h, LXiSTROKE_ABSOLUTE);
        }
    }

    void InitializeState()
    {
        if (mInitialized)
            return;

        CLxUser_ImageService      imgSvc;
        CLxUser_View3DportService v3dSvc;
        CLxUser_FileService       fileSvc;
        std::string               path = "";

        if (LXx_OK(fileSvc.ToLocalAlias("resource:tic-tac-toe-X.tga", path)))
        {
            CLxUser_Image xImage;
            if (imgSvc.Load(xImage, path))
                v3dSvc.ImageToGLImage(xImage, mImages[TicTacToe_State_X]);
        }

        if (LXx_OK(fileSvc.ToLocalAlias("resource:tic-tac-toe-O.tga", path)))
        {
            CLxUser_Image yImage;
            if (imgSvc.Load(yImage, path))
                v3dSvc.ImageToGLImage(yImage, mImages[TicTacToe_State_O]);
        }

        mInitialized = true;
    }

    CLxUser_GLImage mImages[3];
    bool            mInitialized;
    uint32_t        mPktOffset_input;
    int32_t         mPart;
};

// Commands
namespace PlayCommand
{
    class Command : public CLxCommand
    {
    public:
        class Argument : public CLxCustomArgumentUI
        {
        public:
            void query(CLxCommand& cmd) LXx_OVERRIDE
            {
                cmd.cmd_add_query((gVModel && gVModel->test()));
            }
        };

        Command() : mPlayArg(false)
        {
        }

        void setup_args(CLxAttributeDesc& desc) LXx_OVERRIDE
        {
            Command* command = nullptr;

            desc.add("play", LXsTYPE_BOOLEAN);
            desc.struct_offset(&command->mPlayArg);
            desc.bool_type(CLxAttributeDesc::BOOL_CHECKMARK);
            desc.arg_flag(LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY);
            desc.arg_set_custom(new Argument);
        }

        void execute() LXx_OVERRIDE
        {
            CLxUser_View3DportService v3dSvc;

            cmd_read_args(this);

            if (mPlayArg)
            {
                if (gVModel && gVModel->test())
                    throw LXe_FAILED;

                LXtObjectID obj = nullptr;

                if (!gVModel)
                    gVModel = new CLxUser_VirtualModel;

                if (VModel::Spawn((void**) &obj))
                {
                    gVModel->set(obj);
                    lx::UnkRelease((ILxUnknownID) obj);
                }

                if (!gVModel || !gVModel->test() || LXx_FAIL(v3dSvc.AddVirtualModel(*gVModel)))
                    throw LXe_FAILED;
            }
            else
            {
                if (gVModel)
                {
                    if (gVModel->test())
                        v3dSvc.RemoveVirtualModel(*gVModel);
                    delete gVModel;
                    gVModel = nullptr;
                }
            }
        }

        bool mPlayArg;
    };

}  // namespace PlayCommand

namespace MoveCommand
{
    class Command : public CLxCommand
    {
    public:
        Command() : mXArg(-1), mYArg(-1)
        {
        }

        void setup_args(CLxAttributeDesc& desc) LXx_OVERRIDE
        {
            Command* command = nullptr;

            desc.add("x", LXsTYPE_INTEGER);
            desc.struct_offset(&command->mXArg);

            desc.add("y", LXsTYPE_INTEGER);
            desc.struct_offset(&command->mYArg);
        }

        void execute() LXx_OVERRIDE
        {
            cmd_read_args(this);

            if (mXArg < 3 && mXArg >= 0 && mYArg < 3 && mYArg >= 0 && gVModel && gVModel->test())
            {
                VModel* vmodel = VModel::Cast(*gVModel);
                if (vmodel)
                {
                    if (vmodel->MovePlayerPiece((uint32_t) mXArg, (uint32_t) mYArg))
                    {
                        CLxUser_View3DportService v3dSvc;
                        v3dSvc.UpdateVirtualModel(*gVModel);

                        if (vmodel->IsGameComplete())
                        {
                            CLxUser_StdDialogService dlgSvc;
                            CLxUser_Message          message;
                            LxResult                 dialogResult = LXeMSGDIALOG_NO;

                            if (dlgSvc.MessageAllocate(message))
                            {
                                message.SetCode(LXeMSGDIALOG_AS_YESNO);

                                if (vmodel->IsPlayerWinner())
                                    message.SetMsg("tictactoe", "gameOverPlayerWon");
                                else if (vmodel->IsComputerWinner())
                                    message.SetMsg("tictactoe", "gameOverComputerWon");
                                else
                                    message.SetMsg("tictactoe", "gameOverDraw");

                                dialogResult = dlgSvc.MessageOpen(message, "@tictactoe@gameOver@", nullptr, nullptr);
                            }

                            CLxUser_CommandService cmdSvc;
                            if (dialogResult == LXeMSGDIALOG_YES)
                                cmdSvc.ExecuteArgString(LXfCMD_EXEC_DEFAULT, LXiCTAG_NULL, SERVER_BASE ".reset");
                            else
                                cmdSvc.ExecuteArgString(LXfCMD_EXEC_DEFAULT, LXiCTAG_NULL, SERVER_BASE ".play false");
                        }

                        return;
                    }
                }
            }

            throw LXe_FAILED;
        }

        int32_t mXArg, mYArg;
    };
}  // namespace MoveCommand

namespace ResetCommand
{
    class Command : public CLxCommand
    {
    public:
        void execute() LXx_OVERRIDE
        {
            if (gVModel && gVModel->test())
            {
                VModel* vmodel = VModel::Cast(*gVModel);
                if (vmodel)
                {
                    vmodel->Restart();

                    CLxUser_View3DportService v3dSvc;
                    v3dSvc.UpdateVirtualModel(*gVModel);

                    return;
                }
            }

            throw LXe_FAILED;
        }
    };

}  // namespace ResetCommand

static CLxMeta_Command<PlayCommand::Command>  playCommand_meta(SERVER_CMD_PLAY);
static CLxMeta_Command<MoveCommand::Command>  moveCommand_meta(SERVER_CMD_MOVE);
static CLxMeta_Command<ResetCommand::Command> resetCommand_meta(SERVER_CMD_RESET);

static class Root : public CLxMetaRoot
{
    bool pre_init() LXx_OVERRIDE
    {
        playCommand_meta.set_type_UI();
        playCommand_meta.set_type_flags(LXfCMD_INTERNAL);
        add(&playCommand_meta);

        moveCommand_meta.set_type_UI();
        moveCommand_meta.set_type_flags(LXfCMD_INTERNAL);
        add(&moveCommand_meta);

        resetCommand_meta.set_type_UI();
        resetCommand_meta.set_type_flags(LXfCMD_INTERNAL);
        add(&resetCommand_meta);

        return false;
    }

} root_meta;

// Startup and Shutdown Servers
void initialize()
{
    VModel::initialize();
}

void cleanup()
{
    if (gVModel)
    {
        delete gVModel;
        gVModel = nullptr;
    }
}
