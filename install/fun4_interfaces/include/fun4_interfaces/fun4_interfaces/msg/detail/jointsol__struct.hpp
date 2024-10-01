// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__STRUCT_HPP_
#define FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__fun4_interfaces__msg__Jointsol __attribute__((deprecated))
#else
# define DEPRECATED__fun4_interfaces__msg__Jointsol __declspec(deprecated)
#endif

namespace fun4_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Jointsol_
{
  using Type = Jointsol_<ContainerAllocator>;

  explicit Jointsol_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Jointsol_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _q_msg_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _q_msg_type q_msg;

  // setters for named parameter idiom
  Type & set__q_msg(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->q_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fun4_interfaces::msg::Jointsol_<ContainerAllocator> *;
  using ConstRawPtr =
    const fun4_interfaces::msg::Jointsol_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::msg::Jointsol_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::msg::Jointsol_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fun4_interfaces__msg__Jointsol
    std::shared_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fun4_interfaces__msg__Jointsol
    std::shared_ptr<fun4_interfaces::msg::Jointsol_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Jointsol_ & other) const
  {
    if (this->q_msg != other.q_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const Jointsol_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Jointsol_

// alias to use template instance with default allocator
using Jointsol =
  fun4_interfaces::msg::Jointsol_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__STRUCT_HPP_
