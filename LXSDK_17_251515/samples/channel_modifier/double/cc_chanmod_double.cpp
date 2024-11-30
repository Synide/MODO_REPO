/*
 * MODO SDK SAMPLE
 *
 * ChannelModifier server
 * ======================
 *
 *	Copyright 0000
 *
 * This implements a ChannelModifier server with one input and one output.
 *
 * CLASSES USED:
 *
 *		CLxChannelModifier
 *		CLxMetaRoot_ChannelModifier
 *
 * TESTING:
 *
 * Modifier can be added in schematic and wired up to an input. The output
 * will be twice the input.
 */
#include <lxu_chanmod.hpp>

#define SRVNAME_CHANMOD "csam.chanmod.double"

namespace ChanModDouble
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
        CLxUser_Value v_input, v_result;

        /*
         * init_chan() is called once to initialize the channels of the
         * modifier.
         *
         * We add the channels with required name and type. Channel modifier
         * inputs and outputs are associated with Value wrappers in the
         * class itself. The INPUT and OUTPU flags tell the schematic which
         * side to put the dot.
         */
        void init_chan(CLxAttributeDesc& desc) override
        {
            COperator* op = 0;

            desc.add("input", LXsTYPE_FLOAT);
            desc.chanmod_chan(LXfCHMOD_INPUT, &op->v_input);

            desc.add("output", LXsTYPE_FLOAT);
            desc.chanmod_chan(LXfCHMOD_OUTPUT, &op->v_result);
        }

        /*
         * eval() is called to perform operation. Inputs and outputs are
         * bound and can be read and written.
         *
         * Read out input float and output twice its value to the result.
         */
        void eval() override
        {
            double val;

            lx_err::check(v_input.GetFlt(&val));
            lx_err::check(v_result.SetFlt(val * 2.0));
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

};  // namespace ChanModDouble
