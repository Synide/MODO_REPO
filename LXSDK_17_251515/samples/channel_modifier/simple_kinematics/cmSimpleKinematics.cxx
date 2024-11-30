/*
 * Plug-in Simple Kinematics channel modifier.
 *
 * This channel modifier applies the equation of motion derived from a constant
 * acceleration to the given channel. The inputs are the initial position and
 * speed, and the acceleration. In addition, the user can specify a starting
 * time before which the modifier simply returns the initial position.
 *
 * None of the inputs are exposed as inputs because they can't be animated.
 * Correctly animating acceleration requires simulation, which is a whole
 * different type of modifier.
 *
 * Copyright 0000
 */
#include <lx_plugin.hpp>
#include <lx_value.hpp>
#include <lxu_chanmod.hpp>

namespace SimpleKinematics
{

    class COperator : public CLxChannelModifier
    {
    public:
        CLxUser_Value v_x0, v_t0, v_speed, v_acc, v_time, v_output;

        void init_chan(CLxAttributeDesc& desc) override
        {
            COperator* op = nullptr;

            desc.add("startValue", LXsTYPE_DISTANCE);
            desc.chanmod_chan(0, &op->v_x0);

            desc.add("startTime", LXsTYPE_TIME);
            desc.chanmod_chan(0, &op->v_t0);

            desc.add("startSpeed", LXsTYPE_SPEED);
            desc.chanmod_chan(0, &op->v_speed);

            desc.add("acceleration", LXsTYPE_ACCELERATION);
            desc.chanmod_chan(0, &op->v_acc);

            desc.chanmod_time(&op->v_time);

            desc.add("output", LXsTYPE_DISTANCE);
            desc.chanmod_chan(LXfCHMOD_OUTPUT, &op->v_output);
        }

        void eval() override
        {
            double t0, v0, x0, a, t;

            v_t0.GetFlt(&t0);
            v_x0.GetFlt(&x0);
            v_acc.GetFlt(&a);
            v_time.GetFlt(&t);
            v_speed.GetFlt(&v0);

            if (t >= t0)
            {
                t -= t0;
                x0 += v0 * t + 0.5 * a * t * t;
            }

            v_output.SetFlt(x0);
        }
    };

    static CLxMetaRoot_ChannelModifier<COperator> meta("cmSimpleKinematics");

};  // namespace SimpleKinematics

void initialize()
{
    SimpleKinematics::meta.initialize();
}
