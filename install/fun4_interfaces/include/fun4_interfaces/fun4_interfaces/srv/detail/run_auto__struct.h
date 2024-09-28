// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fun4_interfaces:srv/RunAuto.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__STRUCT_H_
#define FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/RunAuto in the package fun4_interfaces.
typedef struct fun4_interfaces__srv__RunAuto_Request
{
  geometry_msgs__msg__Point target;
} fun4_interfaces__srv__RunAuto_Request;

// Struct for a sequence of fun4_interfaces__srv__RunAuto_Request.
typedef struct fun4_interfaces__srv__RunAuto_Request__Sequence
{
  fun4_interfaces__srv__RunAuto_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fun4_interfaces__srv__RunAuto_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RunAuto in the package fun4_interfaces.
typedef struct fun4_interfaces__srv__RunAuto_Response
{
  bool reach_target;
} fun4_interfaces__srv__RunAuto_Response;

// Struct for a sequence of fun4_interfaces__srv__RunAuto_Response.
typedef struct fun4_interfaces__srv__RunAuto_Response__Sequence
{
  fun4_interfaces__srv__RunAuto_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fun4_interfaces__srv__RunAuto_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FUN4_INTERFACES__SRV__DETAIL__RUN_AUTO__STRUCT_H_
