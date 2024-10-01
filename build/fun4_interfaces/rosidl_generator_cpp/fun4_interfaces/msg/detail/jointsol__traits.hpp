// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__TRAITS_HPP_
#define FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fun4_interfaces/msg/detail/jointsol__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace fun4_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Jointsol & msg,
  std::ostream & out)
{
  out << "{";
  // member: q_msg
  {
    if (msg.q_msg.size() == 0) {
      out << "q_msg: []";
    } else {
      out << "q_msg: [";
      size_t pending_items = msg.q_msg.size();
      for (auto item : msg.q_msg) {
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
  const Jointsol & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: q_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.q_msg.size() == 0) {
      out << "q_msg: []\n";
    } else {
      out << "q_msg:\n";
      for (auto item : msg.q_msg) {
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

inline std::string to_yaml(const Jointsol & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace fun4_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fun4_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fun4_interfaces::msg::Jointsol & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::msg::Jointsol & msg)
{
  return fun4_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::msg::Jointsol>()
{
  return "fun4_interfaces::msg::Jointsol";
}

template<>
inline const char * name<fun4_interfaces::msg::Jointsol>()
{
  return "fun4_interfaces/msg/Jointsol";
}

template<>
struct has_fixed_size<fun4_interfaces::msg::Jointsol>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fun4_interfaces::msg::Jointsol>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fun4_interfaces::msg::Jointsol>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__TRAITS_HPP_
