//// Copyright (c) Microsoft Corporation. All rights reserved.
//// Licensed under the MIT License.
//
//#ifndef air_CarRpcLibAdaptors_hpp
//#define air_CarRpcLibAdaptors_hpp
//
//#include "common/Common.hpp"
//#include "common/CommonStructs.hpp"
//#include "api/RpcLibAdaptorsBase.hpp"
//#include "common/ImageCaptureBase.hpp"
//#include "vehicles/car/api/CarApiBase.hpp"
//
//#include "common/common_utils/WindowsApisCommonPre.hpp"
//#include "rpc/msgpack.hpp"
//#include "common/common_utils/WindowsApisCommonPost.hpp"
//
//namespace msr
//{
//namespace airlib_rpclib
//{
//
//    class CarRpcLibAdaptors : public RpcLibAdaptorsBase
//    {
//    public:
//        struct CarControls
//        {
//            float throttle = 0;
//            float steering = 0;
//            float brake = 0;
//            bool handbrake = false;
//            bool is_manual_gear = false;
//            int manual_gear = 0;
//            bool gear_immediate = true;
//
//            MSGPACK_DEFINE_MAP(throttle, steering, brake, handbrake, is_manual_gear, manual_gear, gear_immediate);
//
//            CarControls()
//            {
//            }
//
//            CarControls(const msr::airlib::CarApiBase::CarControls& s)
//            {
//                throttle = s.throttle;
//                steering = s.steering;
//                brake = s.brake;
//                handbrake = s.handbrake;
//                is_manual_gear = s.is_manual_gear;
//                manual_gear = s.manual_gear;
//                gear_immediate = s.gear_immediate;
//            }
//            msr::airlib::CarApiBase::CarControls to() const
//            {
//                return msr::airlib::CarApiBase::CarControls(throttle, steering, brake, handbrake, is_manual_gear, manual_gear, gear_immediate);
//            }
//        };
//
//        struct CarState
//        {
//            float speed;
//            int gear;
//            float rpm;
//            float maxrpm;
//            bool handbrake;
//            KinematicsState kinematics_estimated;
//            uint64_t timestamp;
//
//            MSGPACK_DEFINE_MAP(speed, gear, rpm, maxrpm, handbrake, kinematics_estimated, timestamp);
//
//            CarState()
//            {
//            }
//
//            CarState(const msr::airlib::CarApiBase::CarState& s)
//            {
//                speed = s.speed;
//                gear = s.gear;
//                rpm = s.rpm;
//                maxrpm = s.maxrpm;
//                handbrake = s.handbrake;
//                timestamp = s.timestamp;
//                kinematics_estimated = s.kinematics_estimated;
//            }
//            msr::airlib::CarApiBase::CarState to() const
//            {
//                return msr::airlib::CarApiBase::CarState(
//                    speed, gear, rpm, maxrpm, handbrake, kinematics_estimated.to(), timestamp);
//            }
//        };
//    };
//}
//} //namespace
//
//#endif


// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef air_CarRpcLibAdaptors_hpp
#define air_CarRpcLibAdaptors_hpp

#include "common/Common.hpp"
#include "common/CommonStructs.hpp"
#include "api/RpcLibAdaptorsBase.hpp"
#include "common/ImageCaptureBase.hpp"
#include "vehicles/car/api/CarApiBase.hpp"

#include "common/common_utils/WindowsApisCommonPre.hpp"
#include "rpc/msgpack.hpp"
#include "common/common_utils/WindowsApisCommonPost.hpp"

namespace msr
{
namespace airlib_rpclib
{

    class CarRpcLibAdaptors : public RpcLibAdaptorsBase
    {
    public:
        struct CarControls
        {
            float throttle = 0;
            float steering = 0;
            float brake = 0;
            bool handbrake = false;
            bool is_manual_gear = false;
            int manual_gear = 0;
            bool gear_immediate = true;

            MSGPACK_DEFINE_MAP(throttle, steering, brake, handbrake, is_manual_gear, manual_gear, gear_immediate);

            CarControls()
            {
            }

            CarControls(const msr::airlib::CarApiBase::CarControls& s)
            {
                throttle = s.throttle;
                steering = s.steering;
                brake = s.brake;
                handbrake = s.handbrake;
                is_manual_gear = s.is_manual_gear;
                manual_gear = s.manual_gear;
                gear_immediate = s.gear_immediate;
            }
            msr::airlib::CarApiBase::CarControls to() const
            {
                return msr::airlib::CarApiBase::CarControls(throttle, steering, brake, handbrake, is_manual_gear, manual_gear, gear_immediate);
            }
        };

        struct CarState
        {
            float speed;
            int gear;
            float rpm;
            float maxrpm;
            bool handbrake;
            KinematicsState kinematics_estimated;
            uint64_t timestamp;

            MSGPACK_DEFINE_MAP(speed, gear, rpm, maxrpm, handbrake, kinematics_estimated, timestamp);

            CarState()
            {
            }

            CarState(const msr::airlib::CarApiBase::CarState& s)
            {
                speed = s.speed;
                gear = s.gear;
                rpm = s.rpm;
                maxrpm = s.maxrpm;
                handbrake = s.handbrake;
                timestamp = s.timestamp;
                kinematics_estimated = s.kinematics_estimated;
            }
            msr::airlib::CarApiBase::CarState to() const
            {
                return msr::airlib::CarApiBase::CarState(
                    speed, gear, rpm, maxrpm, handbrake, kinematics_estimated.to(), timestamp);
            }
        };
    };

    //*************************************************

    class DifferentialCarRpcLibAdaptors : public RpcLibAdaptorsBase
    {
    public:
        struct DifferentialCarControls
        {
            float torque_FL = 0;
            float torque_FR = 0;
            float torque_RL = 0;
            float torque_RR = 0;
            float torque_brake = 1500;
            float brake_none = 0;
            bool handbrake = false;

            MSGPACK_DEFINE_MAP(torque_FL, torque_FR, torque_RL, torque_RR, torque_brake, brake_none, handbrake);

            DifferentialCarControls()
            {
            }

            DifferentialCarControls(const msr::airlib::CarApiBase::DifferentialCarControls& s)
            {
                torque_FL = s.torque_FL;
                torque_FR = s.torque_FR;
                torque_RL = s.torque_RL;
                torque_RR = s.torque_RR;
                torque_brake = s.torque_brake;
                handbrake = s.handbrake;
                brake_none = s.brake_none;
            }
            msr::airlib::CarApiBase::DifferentialCarControls to() const
            {
                return msr::airlib::CarApiBase::DifferentialCarControls(torque_FL, torque_FR, torque_RL, torque_RR, torque_brake, brake_none, handbrake);
            }
        };

        struct DifferentialCarState
        {
            float speed;
            float rpm_FL_0;
            float rpm_FL_1;
            float rpm_FR_0;
            float rpm_FR_1;
            float rpm_RL_0;
            float rpm_RL_1;
            float rpm_RR_0;
            float rpm_RR_1;
            float maxrpm;
            bool handbrake;
            KinematicsState kinematics_estimated;
            uint64_t timestamp;

            MSGPACK_DEFINE_MAP(speed, 
                               rpm_FL_0, rpm_FL_1,
                               rpm_FR_0, rpm_FR_1,
                               rpm_RL_0, rpm_RL_1,
                               rpm_RR_0, rpm_RR_1, maxrpm, handbrake, kinematics_estimated, timestamp);

            DifferentialCarState()
            {
            }

            DifferentialCarState(const msr::airlib::CarApiBase::DifferentialCarState& s)
            {
                speed = s.speed;
                rpm_FL_0 = s.rpm_FL_0;
                rpm_FL_1 = s.rpm_FL_1;
                rpm_FR_0 = s.rpm_FR_0;
                rpm_FR_1 = s.rpm_FR_1;
                rpm_RL_0 = s.rpm_RL_0;
                rpm_RL_1 = s.rpm_RL_1;
                rpm_RR_0 = s.rpm_RR_0;
                rpm_RR_1 = s.rpm_RR_1;
                maxrpm = s.maxrpm;
                handbrake = s.handbrake;
                timestamp = s.timestamp;
                kinematics_estimated = s.kinematics_estimated;
            }
            msr::airlib::CarApiBase::DifferentialCarState to() const
            {
                return msr::airlib::CarApiBase::DifferentialCarState(
                    speed, rpm_FL_0, rpm_FL_1, rpm_FR_0, rpm_FR_1, rpm_RL_0, rpm_RL_1, rpm_RR_0, rpm_RR_1, maxrpm, handbrake, kinematics_estimated.to(), timestamp);
            }
        };
    };
}
} //namespace

#endif
