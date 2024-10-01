// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__STRUCT_H_
#define FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'q_msg'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Jointsol in the package fun4_interfaces.
typedef struct fun4_interfaces__msg__Jointsol
{
  rosidl_runtime_c__double__Sequence q_msg;
} fun4_interfaces__msg__Jointsol;

// Struct for a sequence of fun4_interfaces__msg__Jointsol.
typedef struct fun4_interfaces__msg__Jointsol__Sequence
{
  fun4_interfaces__msg__Jointsol * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fun4_interfaces__msg__Jointsol__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__STRUCT_H_
