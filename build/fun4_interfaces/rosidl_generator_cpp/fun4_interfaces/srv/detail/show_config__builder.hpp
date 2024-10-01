// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fun4_interfaces:srv/ShowConfig.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__SHOW_CONFIG__BUILDER_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__SHOW_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fun4_interfaces/srv/detail/show_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_ShowConfig_Request_pose
{
public:
  Init_ShowConfig_Request_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fun4_interfaces::srv::ShowConfig_Request pose(::fun4_interfaces::srv::ShowConfig_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::ShowConfig_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::ShowConfig_Request>()
{
  return fun4_interfaces::srv::builder::Init_ShowConfig_Request_pose();
}

}  // namespace fun4_interfaces


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_ShowConfig_Response_config
{
public:
  Init_ShowConfig_Response_config()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fun4_interfaces::srv::ShowConfig_Response config(::fun4_interfaces::srv::ShowConfig_Response::_config_type arg)
  {
    msg_.config = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::ShowConfig_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::ShowConfig_Response>()
{
  return fun4_interfaces::srv::builder::Init_ShowConfig_Response_config();
}

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__SRV__DETAIL__SHOW_CONFIG__BUILDER_HPP_
