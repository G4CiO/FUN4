// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fun4_interfaces:srv/RunAuto.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__TRAITS_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fun4_interfaces/srv/detail/run_auto__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RunAuto_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: reach_target
  {
    out << "reach_target: ";
    rosidl_generator_traits::value_to_yaml(msg.reach_target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RunAuto_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: reach_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reach_target: ";
    rosidl_generator_traits::value_to_yaml(msg.reach_target, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RunAuto_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace fun4_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fun4_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fun4_interfaces::srv::RunAuto_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::RunAuto_Request & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::RunAuto_Request>()
{
  return "fun4_interfaces::srv::RunAuto_Request";
}

template<>
inline const char * name<fun4_interfaces::srv::RunAuto_Request>()
{
  return "fun4_interfaces/srv/RunAuto_Request";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::RunAuto_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::RunAuto_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fun4_interfaces::srv::RunAuto_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RunAuto_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: target
  {
    out << "target: ";
    to_flow_style_yaml(msg.target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RunAuto_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target:\n";
    to_block_style_yaml(msg.target, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RunAuto_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace fun4_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fun4_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fun4_interfaces::srv::RunAuto_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::RunAuto_Response & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::RunAuto_Response>()
{
  return "fun4_interfaces::srv::RunAuto_Response";
}

template<>
inline const char * name<fun4_interfaces::srv::RunAuto_Response>()
{
  return "fun4_interfaces/srv/RunAuto_Response";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::RunAuto_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::RunAuto_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<fun4_interfaces::srv::RunAuto_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fun4_interfaces::srv::RunAuto>()
{
  return "fun4_interfaces::srv::RunAuto";
}

template<>
inline const char * name<fun4_interfaces::srv::RunAuto>()
{
  return "fun4_interfaces/srv/RunAuto";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::RunAuto>
  : std::integral_constant<
    bool,
    has_fixed_size<fun4_interfaces::srv::RunAuto_Request>::value &&
    has_fixed_size<fun4_interfaces::srv::RunAuto_Response>::value
  >
{
};

template<>
struct has_bounded_size<fun4_interfaces::srv::RunAuto>
  : std::integral_constant<
    bool,
    has_bounded_size<fun4_interfaces::srv::RunAuto_Request>::value &&
    has_bounded_size<fun4_interfaces::srv::RunAuto_Response>::value
  >
{
};

template<>
struct is_service<fun4_interfaces::srv::RunAuto>
  : std::true_type
{
};

template<>
struct is_service_request<fun4_interfaces::srv::RunAuto_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fun4_interfaces::srv::RunAuto_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__TRAITS_HPP_
