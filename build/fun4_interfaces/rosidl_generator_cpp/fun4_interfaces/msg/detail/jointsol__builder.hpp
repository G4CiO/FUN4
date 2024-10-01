// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__BUILDER_HPP_
#define FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fun4_interfaces/msg/detail/jointsol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fun4_interfaces
{

namespace msg
{

namespace builder
{

class Init_Jointsol_q_msg
{
public:
  Init_Jointsol_q_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fun4_interfaces::msg::Jointsol q_msg(::fun4_interfaces::msg::Jointsol::_q_msg_type arg)
  {
    msg_.q_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::msg::Jointsol msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::msg::Jointsol>()
{
  return fun4_interfaces::msg::builder::Init_Jointsol_q_msg();
}

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__BUILDER_HPP_
