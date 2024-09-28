// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fun4_interfaces:srv/RunAuto.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__BUILDER_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fun4_interfaces/srv/detail/run_auto__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_RunAuto_Request_target
{
public:
  Init_RunAuto_Request_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fun4_interfaces::srv::RunAuto_Request target(::fun4_interfaces::srv::RunAuto_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::RunAuto_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::RunAuto_Request>()
{
  return fun4_interfaces::srv::builder::Init_RunAuto_Request_target();
}

}  // namespace fun4_interfaces


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_RunAuto_Response_reach_target
{
public:
  Init_RunAuto_Response_reach_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fun4_interfaces::srv::RunAuto_Response reach_target(::fun4_interfaces::srv::RunAuto_Response::_reach_target_type arg)
  {
    msg_.reach_target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::RunAuto_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::RunAuto_Response>()
{
  return fun4_interfaces::srv::builder::Init_RunAuto_Response_reach_target();
}

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__BUILDER_HPP_
