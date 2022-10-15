// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef air_CarApiBase_hpp
#define air_CarApiBase_hpp

#include "common/VectorMath.hpp"
#include "common/CommonStructs.hpp"
#include "api/VehicleApiBase.hpp"
#include "physics/Kinematics.hpp"
#include "sensors/SensorBase.hpp"
#include "sensors/SensorCollection.hpp"
#include "sensors/SensorFactory.hpp"

namespace msr
{
namespace airlib
{

    class CarApiBase : public VehicleApiBase
    {
    public:
        struct CarControls
        {
            float throttle = 0; /* 1 to -1 */
            float steering = 0; /* 1 to -1 */
            float brake = 0; /* 1 to -1 */
            bool handbrake = false;
            bool is_manual_gear = false;
            int manual_gear = 0;
            bool gear_immediate = true;

            CarControls()
            {
            }
            CarControls(float throttle_val, float steering_val, float brake_val, bool handbrake_val,
                        bool is_manual_gear_val, int manual_gear_val, bool gear_immediate_val)
                : throttle(throttle_val), steering(steering_val), brake(brake_val), handbrake(handbrake_val), is_manual_gear(is_manual_gear_val), manual_gear(manual_gear_val), gear_immediate(gear_immediate_val)
            {
            }
            void set_throttle(float throttle_val, bool forward)
            {
                if (forward) {
                    is_manual_gear = false;
                    manual_gear = 0;
                    throttle = std::abs(throttle_val);
                }
                else {
                    is_manual_gear = false;
                    manual_gear = -1;
                    throttle = -std::abs(throttle_val);
                }
            }
        };
        //**********************************differentail speed vehicle********************************************
        //分别对四个轮子进行力矩控制
        struct DifferentialCarControls
        {
            float torque_FL = 0; //Nm
            float torque_FR = 0; //Nm
            float torque_RL = 0; //Nm
            float torque_RR = 0; //Nm
            float torque_brake = 1500; //Nm
            float brake_none = 0; //Nm(无刹车情况下刹车扭矩)
            bool handbrake = false;

            DifferentialCarControls()
            {
            }

            DifferentialCarControls(float torque_FL_val, float torque_FR_val, float torque_RL_val, float torque_RR_val, float torque_brake_val, float brake_val, bool handbrake_val)
                : torque_FL(torque_FL_val), torque_FR(torque_FR_val), torque_RL(torque_RL_val), torque_RR(torque_RR_val), torque_brake(torque_brake_val), brake_none(brake_val), handbrake(handbrake_val)
            {
            }

            ////set left_torque and right_torque(另一种定义方式，暂时空缺)
            //void set_torque(float left_torque_val, float right_torque_val)
            //{

            //}
        };

        struct DifferentialCarState
        {
            float speed;
            float rpm_FL_0;
            float rpm_FR_0;
            float rpm_RL_0;
            float rpm_RR_0;
            float rpm_FL_1;
            float rpm_FR_1;
            float rpm_RL_1;
            float rpm_RR_1;
            float maxrpm;
            bool handbrake;

            Kinematics::State kinematics_estimated;
            uint64_t timestamp;

            DifferentialCarState()
            {
            }
            DifferentialCarState(float speed_val,
                float rpm_FL_0_val,float rpm_FL_1_val,
                float rpm_FR_0_val,float rpm_FR_1_val,
                float rpm_RL_0_val,float rpm_RL_1_val,
                float rpm_RR_0_val,float rpm_RR_1_val,
                float maxrpm_val, bool handbrake_val,
                                 const Kinematics::State& kinematics_estimated_val, uint64_t timestamp_val)
                : speed(speed_val), 
                rpm_FL_0(rpm_FL_0_val), rpm_FL_1(rpm_FL_1_val), 
                rpm_FR_0(rpm_FR_0_val), rpm_FR_1(rpm_FR_1_val), 
                rpm_RL_0(rpm_RL_0_val), rpm_RL_1(rpm_RL_1_val), 
                rpm_RR_0(rpm_RR_0_val), rpm_RR_1(rpm_RR_1_val),
                maxrpm(maxrpm_val), handbrake(handbrake_val), kinematics_estimated(kinematics_estimated_val), timestamp(timestamp_val)
            {
            }

            //shortcuts
            const Vector3r& getPosition() const
            {
                return kinematics_estimated.pose.position;
            }
            const Quaternionr& getOrientation() const
            {
                return kinematics_estimated.pose.orientation;
            }
        };

        //**********************************differentail speed vehicle********************************************

        struct CarState
        {
            float speed;
            int gear;
            float rpm;
            float maxrpm;
            bool handbrake;
            Kinematics::State kinematics_estimated;
            uint64_t timestamp;

            CarState()
            {
            }

            CarState(float speed_val, int gear_val, float rpm_val, float maxrpm_val, bool handbrake_val,
                     const Kinematics::State& kinematics_estimated_val, uint64_t timestamp_val)
                : speed(speed_val), gear(gear_val), rpm(rpm_val), maxrpm(maxrpm_val), handbrake(handbrake_val), kinematics_estimated(kinematics_estimated_val), timestamp(timestamp_val)
            {
            }

            //shortcuts
            const Vector3r& getPosition() const
            {
                return kinematics_estimated.pose.position;
            }
            const Quaternionr& getOrientation() const
            {
                return kinematics_estimated.pose.orientation;
            }
        };

    public:
        // TODO: Temporary constructor for the Unity implementation which does not use the new Sensor Configuration Settings implementation.
        //CarApiBase() {}

        CarApiBase(const AirSimSettings::VehicleSetting* vehicle_setting,
                   std::shared_ptr<SensorFactory> sensor_factory,
                   const Kinematics::State& state, const Environment& environment)
        {
            initialize(vehicle_setting, sensor_factory, state, environment);
        }

        virtual void update() override
        {
            VehicleApiBase::update();

            getSensors().update();
        }

        void reportState(StateReporter& reporter) override
        {
            getSensors().reportState(reporter);
        }

        // sensor helpers
        virtual const SensorCollection& getSensors() const override
        {
            return sensors_;
        }

        SensorCollection& getSensors()
        {
            return sensors_;
        }

        void initialize(const AirSimSettings::VehicleSetting* vehicle_setting,
                        std::shared_ptr<SensorFactory> sensor_factory,
                        const Kinematics::State& state, const Environment& environment)
        {
            sensor_factory_ = sensor_factory;

            sensor_storage_.clear();
            sensors_.clear();

            addSensorsFromSettings(vehicle_setting);

            getSensors().initialize(&state, &environment);
        }

        void addSensorsFromSettings(const AirSimSettings::VehicleSetting* vehicle_setting)
        {
            const auto& sensor_settings = vehicle_setting->sensors;

            sensor_factory_->createSensorsFromSettings(sensor_settings, sensors_, sensor_storage_);
        }
        //普通车辆
        virtual void setCarControls(const CarControls& controls) = 0;
        virtual void updateCarState(const CarState& state) = 0;
        virtual const CarState& getCarState() const = 0;
        virtual const CarControls& getCarControls() const = 0;
        //差速车辆
        virtual void setDifferentialCarControls(const DifferentialCarControls& controls) = 0;
        virtual void updateDifferentialCarState(const DifferentialCarState& state) = 0;
        virtual const DifferentialCarState& getDifferentialCarState() const = 0;
        virtual const DifferentialCarControls& getDifferentialCarControls() const = 0;

        virtual ~CarApiBase() = default;

        std::shared_ptr<const SensorFactory> sensor_factory_;
        SensorCollection sensors_; //maintains sensor type indexed collection of sensors
        vector<shared_ptr<SensorBase>> sensor_storage_; //RAII for created sensors

    protected:
        virtual void resetImplementation() override
        {
            //reset sensors last after their ground truth has been reset
            getSensors().reset();
        }
    };
}
} //namespace
#endif
