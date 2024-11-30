/*
 * MODO SDK SAMPLE
 *
 * ChannelModifier server
 * ======================
 *
 *	Copyright 0000
 *
 * This implements a ChannelModifier server with one input which
 * accomodates multiple input links and one output.
 *
 * CLASSES USED:
 *
 *		CLxChannelModifier
 *		CLxMetaRoot_ChannelModifier
 *
 * TESTING:
 *
 * Modifier can be added in schematic and wired up to an input. The output
 * will be the sum of all the linked input channels.
 */
#include <lxu_chanmod.hpp>

#define SRVNAME_CHANMOD "csam.chanmod.sum"

namespace ChanModSum
{

    /*
     * ----------------------------------------------------------------
     * The operator is the core of the channel modifier. It both sets up the
     * channels for the modifier and serves as the object to hold onto value
     * interfaces.
     */
    class COperator : public CLxChannelModifier
    {
    public:
        CLxUser_Value      v_result;
        CLxUser_ValueArray v_inputs;

        /*
         * init_chan() is called once to initialize the channels of the
         * modifier.
         *
         * We add the channels with required name and type. Channel modifier
         * inputs and outputs are associated with Value wrappers in the
         * class itself. The INPUT and OUTPUT flags tell the schematic which
         * side to put the dot, and the MULTILINK flag allows multiple inputs.
         */
        void init_chan(CLxAttributeDesc& desc) override
        {
            COperator* op = 0;

            desc.add("input", LXsTYPE_FLOAT);
            desc.chanmod_chan(LXfCHMOD_INPUT | LXfCHMOD_MULTILINK, &op->v_inputs);

            desc.add("output", LXsTYPE_FLOAT);
            desc.chanmod_chan(LXfCHMOD_OUTPUT, &op->v_result);
        }

        /*
         * eval() is called to perform operation. Inputs and outputs are
         * bound and can be read and written.
         *
         * Read the input value array values and set the output to their sum.
         */
        void eval() override
        {
            double inVal, output = 0.0;
            int    i, n;

            n = v_inputs.Count();
            for (i = 0; i < n; i++)
            {
                lx_err::check(v_inputs.GetFloat(i, &inVal));
                output += inVal;
            }
            lx_err::check(v_result.SetFlt(output));
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * Since no more customization is necessary. this special metaclass installs
     * the server directly without needing an explicit root.
     */
    static CLxMetaRoot_ChannelModifier<COperator> cm_meta(SRVNAME_CHANMOD);

};  // namespace ChanModSum
