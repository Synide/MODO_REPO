/*
 * Plug-in linear blend channel modifier.
 *
 * Copyright 0000
 */
#include <lx_plugin.hpp>
#include <lx_value.hpp>
#include <lxu_chanmod.hpp>

namespace LinearBlend
{

    static LXtTextValueHint hint_blend[] = {
        { 0, "%min" },      // float min 0.0
        { 10000, "%max" },  // float max 1.0
        { -1, nullptr },
    };

    class COperator : public CLxChannelModifier
    {
    public:
        CLxUser_Value v_1, v_2, v_blend, v_output;

        void init_chan(CLxAttributeDesc& desc) override
        {
            COperator* op = nullptr;

            desc.add("inputA", LXsTYPE_FLOAT);
            desc.chanmod_chan(LXfCHMOD_INPUT, &op->v_1);

            desc.add("inputB", LXsTYPE_FLOAT);
            desc.chanmod_chan(LXfCHMOD_INPUT, &op->v_2);

            desc.add("blend", LXsTYPE_PERCENT);
            desc.chanmod_chan(LXfCHMOD_INPUT, &op->v_blend);
            desc.hint(hint_blend);

            desc.add("output", LXsTYPE_FLOAT);
            desc.chanmod_chan(LXfCHMOD_OUTPUT, &op->v_output);
        }

        void eval() override
        {
            double v1, v2, blend, output;

            v_1.GetFlt(&v1);
            v_2.GetFlt(&v2);
            v_blend.GetFlt(&blend);

            output = v1 + LXxCLAMP(blend, 0.0, 1.0) * (v2 - v1);

            v_output.SetFlt(output);
        }
    };

    static CLxMetaRoot_ChannelModifier<COperator> meta("cmLinearBlend");

};  // namespace LinearBlend

void initialize()
{
    LinearBlend::meta.initialize();
}
