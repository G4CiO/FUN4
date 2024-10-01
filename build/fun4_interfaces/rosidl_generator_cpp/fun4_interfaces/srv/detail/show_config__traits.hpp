// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fun4_interfaces:srv/ShowConfig.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__SHOW_CONFIG__TRAITS_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__SHOW_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fun4_interfaces/srv/detail/show_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ShowConfig_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShowConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShowConfig_Request & msg, bool use_flow_style = false)
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
  const fun4_interfaces::srv::ShowConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::ShowConfig_Request & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::ShowConfig_Request>()
{
  return "fun4_interfaces::srv::ShowConfig_Request";
}

template<>
inline const char * name<fun4_interfaces::srv::ShowConfig_Request>()
{
  return "fun4_interfaces/srv/ShowConfig_Request";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::ShowConfig_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::ShowConfig_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<fun4_interfaces::srv::ShowConfig_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ShowConfig_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: config
  {
    if (msg.config.size() == 0) {
      out << "config: []";
    } else {
      out << "config: [";
      size_t pending_items = msg.config.size();
      for (auto item : msg.config) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShowConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: config
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.config.size() == 0) {
      out << "config: []\n";
    } else {
      out << "config:\n";
      for (auto item : msg.config) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShowConfig_Response & msg, bool use_flow_style = false)
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
  const fun4_interfaces::srv::ShowConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::ShowConfig_Response & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::ShowConfig_Response>()
{
  return "fun4_interfaces::srv::ShowConfig_Response";
}

template<>
inline const char * name<fun4_interfaces::srv::ShowConfig_Response>()
{
  return "fun4_interfaces/srv/ShowConfig_Response";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::ShowConfig_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::ShowConfig_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fun4_interfaces::srv::ShowConfig_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fun4_interfaces::srv::ShowConfig>()
{
  return "fun4_interfaces::srv::ShowConfig";
}

template<>
inline const char * name<fun4_interfaces::srv::ShowConfig>()
{
  return "fun4_interfaces/srv/ShowConfig";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::ShowConfig>
  : std::integral_constant<
    bool,
    has_fixed_size<fun4_interfaces::srv::ShowConfig_Request>::value &&
    has_fixed_size<fun4_interfaces::srv::ShowConfig_Response>::value
  >
{
};

template<>
struct has_bounded_size<fun4_interfaces::srv::ShowConfig>
  : std::integral_constant<
    bool,
    has_bounded_size<fun4_interfaces::srv::ShowConfig_Request>::value &&
    has_bounded_size<fun4_interfaces::srv::ShowConfig_Response>::value
  >
{
};

template<>
struct is_service<fun4_interfaces::srv::ShowConfig>
  : std::true_type
{
};

template<>
struct is_service_request<fun4_interfaces::srv::ShowConfig_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fun4_interfaces::srv::ShowConfig_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FUN4_INTERFACES__SRV__DETAIL__SHOW_CONFIG__TRAITS_HPP_
