// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fun4_interfaces:srv/RunAuto.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__STRUCT_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__fun4_interfaces__srv__RunAuto_Request __attribute__((deprecated))
#else
# define DEPRECATED__fun4_interfaces__srv__RunAuto_Request __declspec(deprecated)
#endif

namespace fun4_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RunAuto_Request_
{
  using Type = RunAuto_Request_<ContainerAllocator>;

  explicit RunAuto_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reach_target = false;
    }
  }

  explicit RunAuto_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reach_target = false;
    }
  }

  // field types and members
  using _reach_target_type =
    bool;
  _reach_target_type reach_target;

  // setters for named parameter idiom
  Type & set__reach_target(
    const bool & _arg)
  {
    this->reach_target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fun4_interfaces__srv__RunAuto_Request
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fun4_interfaces__srv__RunAuto_Request
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RunAuto_Request_ & other) const
  {
    if (this->reach_target != other.reach_target) {
      return false;
    }
    return true;
  }
  bool operator!=(const RunAuto_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RunAuto_Request_

// alias to use template instance with default allocator
using RunAuto_Request =
  fun4_interfaces::srv::RunAuto_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fun4_interfaces


// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fun4_interfaces__srv__RunAuto_Response __attribute__((deprecated))
#else
# define DEPRECATED__fun4_interfaces__srv__RunAuto_Response __declspec(deprecated)
#endif

namespace fun4_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RunAuto_Response_
{
  using Type = RunAuto_Response_<ContainerAllocator>;

  explicit RunAuto_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_init)
  {
    (void)_init;
  }

  explicit RunAuto_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _target_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _target_type target;

  // setters for named parameter idiom
  Type & set__target(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fun4_interfaces__srv__RunAuto_Response
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fun4_interfaces__srv__RunAuto_Response
    std::shared_ptr<fun4_interfaces::srv::RunAuto_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RunAuto_Response_ & other) const
  {
    if (this->target != other.target) {
      return false;
    }
    return true;
  }
  bool operator!=(const RunAuto_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RunAuto_Response_

// alias to use template instance with default allocator
using RunAuto_Response =
  fun4_interfaces::srv::RunAuto_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fun4_interfaces

namespace fun4_interfaces
{

namespace srv
{

struct RunAuto
{
  using Request = fun4_interfaces::srv::RunAuto_Request;
  using Response = fun4_interfaces::srv::RunAuto_Response;
};

}  // namespace srv

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__STRUCT_HPP_
