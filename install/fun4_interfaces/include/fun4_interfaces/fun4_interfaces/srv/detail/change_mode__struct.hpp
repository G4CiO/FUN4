// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fun4_interfaces:srv/ChangeMode.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__STRUCT_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fun4_interfaces__srv__ChangeMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__fun4_interfaces__srv__ChangeMode_Request __declspec(deprecated)
#endif

namespace fun4_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeMode_Request_
{
  using Type = ChangeMode_Request_<ContainerAllocator>;

  explicit ChangeMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0ll;
    }
  }

  explicit ChangeMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0ll;
    }
  }

  // field types and members
  using _mode_type =
    int64_t;
  _mode_type mode;
  using _pose_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__mode(
    const int64_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fun4_interfaces__srv__ChangeMode_Request
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fun4_interfaces__srv__ChangeMode_Request
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeMode_Request_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeMode_Request_

// alias to use template instance with default allocator
using ChangeMode_Request =
  fun4_interfaces::srv::ChangeMode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fun4_interfaces


#ifndef _WIN32
# define DEPRECATED__fun4_interfaces__srv__ChangeMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__fun4_interfaces__srv__ChangeMode_Response __declspec(deprecated)
#endif

namespace fun4_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeMode_Response_
{
  using Type = ChangeMode_Response_<ContainerAllocator>;

  explicit ChangeMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ChangeMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _config_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _config_type config;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__config(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->config = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fun4_interfaces__srv__ChangeMode_Response
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fun4_interfaces__srv__ChangeMode_Response
    std::shared_ptr<fun4_interfaces::srv::ChangeMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeMode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->config != other.config) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeMode_Response_

// alias to use template instance with default allocator
using ChangeMode_Response =
  fun4_interfaces::srv::ChangeMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fun4_interfaces

namespace fun4_interfaces
{

namespace srv
{

struct ChangeMode
{
  using Request = fun4_interfaces::srv::ChangeMode_Request;
  using Response = fun4_interfaces::srv::ChangeMode_Response;
};

}  // namespace srv

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__SRV__DETAIL__CHANGE_MODE__STRUCT_HPP_
