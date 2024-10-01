// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "fun4_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "fun4_interfaces/msg/detail/jointsol__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace fun4_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fun4_interfaces
cdr_serialize(
  const fun4_interfaces::msg::Jointsol & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fun4_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fun4_interfaces::msg::Jointsol & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fun4_interfaces
get_serialized_size(
  const fun4_interfaces::msg::Jointsol & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fun4_interfaces
max_serialized_size_Jointsol(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace fun4_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fun4_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fun4_interfaces, msg, Jointsol)();

#ifdef __cplusplus
}
#endif

#endif  // FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
