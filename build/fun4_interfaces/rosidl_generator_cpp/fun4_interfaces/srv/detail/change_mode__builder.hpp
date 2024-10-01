// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fun4_interfaces:srv/ChangeMode.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__BUILDER_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fun4_interfaces/srv/detail/change_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_ChangeMode_Request_pose
{
public:
  explicit Init_ChangeMode_Request_pose(::fun4_interfaces::srv::ChangeMode_Request & msg)
  : msg_(msg)
  {}
  ::fun4_interfaces::srv::ChangeMode_Request pose(::fun4_interfaces::srv::ChangeMode_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::ChangeMode_Request msg_;
};

class Init_ChangeMode_Request_teleop_mode
{
public:
  explicit Init_ChangeMode_Request_teleop_mode(::fun4_interfaces::srv::ChangeMode_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeMode_Request_pose teleop_mode(::fun4_interfaces::srv::ChangeMode_Request::_teleop_mode_type arg)
  {
    msg_.teleop_mode = std::move(arg);
    return Init_ChangeMode_Request_pose(msg_);
  }

private:
  ::fun4_interfaces::srv::ChangeMode_Request msg_;
};

class Init_ChangeMode_Request_mode
{
public:
  Init_ChangeMode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeMode_Request_teleop_mode mode(::fun4_interfaces::srv::ChangeMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_ChangeMode_Request_teleop_mode(msg_);
  }

private:
  ::fun4_interfaces::srv::ChangeMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::ChangeMode_Request>()
{
  return fun4_interfaces::srv::builder::Init_ChangeMode_Request_mode();
}

}  // namespace fun4_interfaces


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_ChangeMode_Response_success
{
public:
  explicit Init_ChangeMode_Response_success(::fun4_interfaces::srv::ChangeMode_Response & msg)
  : msg_(msg)
  {}
  ::fun4_interfaces::srv::ChangeMode_Response success(::fun4_interfaces::srv::ChangeMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::ChangeMode_Response msg_;
};

class Init_ChangeMode_Response_config
{
public:
  Init_ChangeMode_Response_config()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeMode_Response_success config(::fun4_interfaces::srv::ChangeMode_Response::_config_type arg)
  {
    msg_.config = std::move(arg);
    return Init_ChangeMode_Response_success(msg_);
  }

private:
  ::fun4_interfaces::srv::ChangeMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::ChangeMode_Response>()
{
  return fun4_interfaces::srv::builder::Init_ChangeMode_Response_config();
}

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__BUILDER_HPP_
