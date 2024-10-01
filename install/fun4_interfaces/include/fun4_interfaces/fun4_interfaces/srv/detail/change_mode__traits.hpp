// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fun4_interfaces:srv/ChangeMode.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__TRAITS_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fun4_interfaces/srv/detail/change_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: teleop_mode
  {
    out << "teleop_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.teleop_mode, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: teleop_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "teleop_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.teleop_mode, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeMode_Request & msg, bool use_flow_style = false)
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
  const fun4_interfaces::srv::ChangeMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::ChangeMode_Request & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::ChangeMode_Request>()
{
  return "fun4_interfaces::srv::ChangeMode_Request";
}

template<>
inline const char * name<fun4_interfaces::srv::ChangeMode_Request>()
{
  return "fun4_interfaces/srv/ChangeMode_Request";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::ChangeMode_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::ChangeMode_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<fun4_interfaces::srv::ChangeMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: config_mode1
  {
    if (msg.config_mode1.size() == 0) {
      out << "config_mode1: []";
    } else {
      out << "config_mode1: [";
      size_t pending_items = msg.config_mode1.size();
      for (auto item : msg.config_mode1) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: change_mode_success
  {
    out << "change_mode_success: ";
    rosidl_generator_traits::value_to_yaml(msg.change_mode_success, out);
    out << ", ";
  }

  // member: change_teleop_mode_success
  {
    out << "change_teleop_mode_success: ";
    rosidl_generator_traits::value_to_yaml(msg.change_teleop_mode_success, out);
    out << ", ";
  }

  // member: config_check_mode1
  {
    out << "config_check_mode1: ";
    rosidl_generator_traits::value_to_yaml(msg.config_check_mode1, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: config_mode1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.config_mode1.size() == 0) {
      out << "config_mode1: []\n";
    } else {
      out << "config_mode1:\n";
      for (auto item : msg.config_mode1) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: change_mode_success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "change_mode_success: ";
    rosidl_generator_traits::value_to_yaml(msg.change_mode_success, out);
    out << "\n";
  }

  // member: change_teleop_mode_success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "change_teleop_mode_success: ";
    rosidl_generator_traits::value_to_yaml(msg.change_teleop_mode_success, out);
    out << "\n";
  }

  // member: config_check_mode1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "config_check_mode1: ";
    rosidl_generator_traits::value_to_yaml(msg.config_check_mode1, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeMode_Response & msg, bool use_flow_style = false)
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
  const fun4_interfaces::srv::ChangeMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::ChangeMode_Response & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::ChangeMode_Response>()
{
  return "fun4_interfaces::srv::ChangeMode_Response";
}

template<>
inline const char * name<fun4_interfaces::srv::ChangeMode_Response>()
{
  return "fun4_interfaces/srv/ChangeMode_Response";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::ChangeMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::ChangeMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fun4_interfaces::srv::ChangeMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fun4_interfaces::srv::ChangeMode>()
{
  return "fun4_interfaces::srv::ChangeMode";
}

template<>
inline const char * name<fun4_interfaces::srv::ChangeMode>()
{
  return "fun4_interfaces/srv/ChangeMode";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::ChangeMode>
  : std::integral_constant<
    bool,
    has_fixed_size<fun4_interfaces::srv::ChangeMode_Request>::value &&
    has_fixed_size<fun4_interfaces::srv::ChangeMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<fun4_interfaces::srv::ChangeMode>
  : std::integral_constant<
    bool,
    has_bounded_size<fun4_interfaces::srv::ChangeMode_Request>::value &&
    has_bounded_size<fun4_interfaces::srv::ChangeMode_Response>::value
  >
{
};

template<>
struct is_service<fun4_interfaces::srv::ChangeMode>
  : std::true_type
{
};

template<>
struct is_service_request<fun4_interfaces::srv::ChangeMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fun4_interfaces::srv::ChangeMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__TRAITS_HPP_
