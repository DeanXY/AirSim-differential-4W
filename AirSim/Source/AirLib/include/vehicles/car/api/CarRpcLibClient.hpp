//// Copyright (c) Microsoft Corporation. All rights reserved.
//// Licensed under the MIT License.
//
//#ifndef air_CarRpcLibClient_hpp
//#define air_CarRpcLibClient_hpp
//
//#include "common/Common.hpp"
//#include <functional>
//#include "common/CommonStructs.hpp"
//#include "vehicles/car/api/CarApiBase.hpp"
//#include "api/RpcLibClientBase.hpp"
//#include "common/ImageCaptureBase.hpp"
//
//namespace msr
//{
//namespace airlib
//{
//
//    class CarRpcLibClient : public RpcLibClientBase
//    {
//    public:
//        CarRpcLibClient(const string& ip_address = "localhost", uint16_t port = RpcLibPort, float timeout_sec = 60);
//
//        void setCarControls(const CarApiBase::CarControls& controls, const std::string& vehicle_name = "");
//        CarApiBase::CarState getCarState(const std::string& vehicle_name = "");
//        CarApiBase::CarControls getCarControls(const std::string& vehicle_name = "");
//        virtual ~CarRpcLibClient(); //required for pimpl
//    };
//}
//} //namespace
//#endif


// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef air_CarRpcLibClient_hpp
#define air_CarRpcLibClient_hpp

#include "common/Common.hpp"
#include <functional>
#include "common/CommonStructs.hpp"
#include "vehicles/car/api/CarApiBase.hpp"
#include "api/RpcLibClientBase.hpp"
#include "common/ImageCaptureBase.hpp"

namespace msr
{
namespace airlib
{

    class CarRpcLibClient : public RpcLibClientBase
    {
    public:
        CarRpcLibClient(const string& ip_address = "localhost", uint16_t port = RpcLibPort, float timeout_sec = 60);

        void setCarControls(const CarApiBase::CarControls& controls, const std::string& vehicle_name = "");
        CarApiBase::CarState getCarState(const std::string& vehicle_name = "");
        CarApiBase::CarControls getCarControls(const std::string& vehicle_name = "");
        virtual ~CarRpcLibClient(); //required for pimpl
    };

    class DifferentialCarRpcLibClient : public RpcLibClientBase
    {
    public:
        DifferentialCarRpcLibClient(const string& ip_address = "localhost", uint16_t port = RpcLibPort, float timeout_sec = 60);

        void setDifferentialCarControls(const CarApiBase::DifferentialCarControls& controls, const std::string& vehicle_name = "");
        CarApiBase::DifferentialCarState getDifferentialCarState(const std::string& vehicle_name = "");
        CarApiBase::DifferentialCarControls getDifferentialCarControls(const std::string& vehicle_name = "");
        virtual ~DifferentialCarRpcLibClient(); //required for pimpl
    };

}

} //namespace
#endif
