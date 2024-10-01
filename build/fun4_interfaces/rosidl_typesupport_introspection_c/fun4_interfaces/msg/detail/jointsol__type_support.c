// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fun4_interfaces/msg/detail/jointsol__rosidl_typesupport_introspection_c.h"
#include "fun4_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fun4_interfaces/msg/detail/jointsol__functions.h"
#include "fun4_interfaces/msg/detail/jointsol__struct.h"


// Include directives for member types
// Member `q_msg`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fun4_interfaces__msg__Jointsol__init(message_memory);
}

void fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_fini_function(void * message_memory)
{
  fun4_interfaces__msg__Jointsol__fini(message_memory);
}

size_t fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__size_function__Jointsol__q_msg(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__get_const_function__Jointsol__q_msg(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__get_function__Jointsol__q_msg(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__fetch_function__Jointsol__q_msg(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__get_const_function__Jointsol__q_msg(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__assign_function__Jointsol__q_msg(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__get_function__Jointsol__q_msg(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__resize_function__Jointsol__q_msg(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_member_array[1] = {
  {
    "q_msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fun4_interfaces__msg__Jointsol, q_msg),  // bytes offset in struct
    NULL,  // default value
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__size_function__Jointsol__q_msg,  // size() function pointer
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__get_const_function__Jointsol__q_msg,  // get_const(index) function pointer
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__get_function__Jointsol__q_msg,  // get(index) function pointer
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__fetch_function__Jointsol__q_msg,  // fetch(index, &value) function pointer
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__assign_function__Jointsol__q_msg,  // assign(index, value) function pointer
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__resize_function__Jointsol__q_msg  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_members = {
  "fun4_interfaces__msg",  // message namespace
  "Jointsol",  // message name
  1,  // number of fields
  sizeof(fun4_interfaces__msg__Jointsol),
  fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_member_array,  // message members
  fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_init_function,  // function to initialize message memory (memory has to be allocated)
  fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_type_support_handle = {
  0,
  &fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fun4_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, msg, Jointsol)() {
  if (!fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_type_support_handle.typesupport_identifier) {
    fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fun4_interfaces__msg__Jointsol__rosidl_typesupport_introspection_c__Jointsol_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
