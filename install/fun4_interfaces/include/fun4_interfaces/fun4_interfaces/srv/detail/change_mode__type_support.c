// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fun4_interfaces:srv/ChangeMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fun4_interfaces/srv/detail/change_mode__rosidl_typesupport_introspection_c.h"
#include "fun4_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fun4_interfaces/srv/detail/change_mode__functions.h"
#include "fun4_interfaces/srv/detail/change_mode__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/point.h"
// Member `pose`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fun4_interfaces__srv__ChangeMode_Request__init(message_memory);
}

void fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_fini_function(void * message_memory)
{
  fun4_interfaces__srv__ChangeMode_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_member_array[2] = {
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fun4_interfaces__srv__ChangeMode_Request, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fun4_interfaces__srv__ChangeMode_Request, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_members = {
  "fun4_interfaces__srv",  // message namespace
  "ChangeMode_Request",  // message name
  2,  // number of fields
  sizeof(fun4_interfaces__srv__ChangeMode_Request),
  fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_member_array,  // message members
  fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_type_support_handle = {
  0,
  &fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fun4_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, srv, ChangeMode_Request)() {
  fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_type_support_handle.typesupport_identifier) {
    fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fun4_interfaces__srv__ChangeMode_Request__rosidl_typesupport_introspection_c__ChangeMode_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fun4_interfaces/srv/detail/change_mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fun4_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fun4_interfaces/srv/detail/change_mode__functions.h"
// already included above
// #include "fun4_interfaces/srv/detail/change_mode__struct.h"


// Include directives for member types
// Member `config`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fun4_interfaces__srv__ChangeMode_Response__init(message_memory);
}

void fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_fini_function(void * message_memory)
{
  fun4_interfaces__srv__ChangeMode_Response__fini(message_memory);
}

size_t fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__size_function__ChangeMode_Response__config(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__get_const_function__ChangeMode_Response__config(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__get_function__ChangeMode_Response__config(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__fetch_function__ChangeMode_Response__config(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__get_const_function__ChangeMode_Response__config(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__assign_function__ChangeMode_Response__config(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__get_function__ChangeMode_Response__config(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__resize_function__ChangeMode_Response__config(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fun4_interfaces__srv__ChangeMode_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "config",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fun4_interfaces__srv__ChangeMode_Response, config),  // bytes offset in struct
    NULL,  // default value
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__size_function__ChangeMode_Response__config,  // size() function pointer
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__get_const_function__ChangeMode_Response__config,  // get_const(index) function pointer
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__get_function__ChangeMode_Response__config,  // get(index) function pointer
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__fetch_function__ChangeMode_Response__config,  // fetch(index, &value) function pointer
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__assign_function__ChangeMode_Response__config,  // assign(index, value) function pointer
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__resize_function__ChangeMode_Response__config  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_members = {
  "fun4_interfaces__srv",  // message namespace
  "ChangeMode_Response",  // message name
  2,  // number of fields
  sizeof(fun4_interfaces__srv__ChangeMode_Response),
  fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_member_array,  // message members
  fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_type_support_handle = {
  0,
  &fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fun4_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, srv, ChangeMode_Response)() {
  if (!fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_type_support_handle.typesupport_identifier) {
    fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fun4_interfaces__srv__ChangeMode_Response__rosidl_typesupport_introspection_c__ChangeMode_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fun4_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fun4_interfaces/srv/detail/change_mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_service_members = {
  "fun4_interfaces__srv",  // service namespace
  "ChangeMode",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_Request_message_type_support_handle,
  NULL  // response message
  // fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_Response_message_type_support_handle
};

static rosidl_service_type_support_t fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_service_type_support_handle = {
  0,
  &fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, srv, ChangeMode_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, srv, ChangeMode_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fun4_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, srv, ChangeMode)() {
  if (!fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_service_type_support_handle.typesupport_identifier) {
    fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, srv, ChangeMode_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fun4_interfaces, srv, ChangeMode_Response)()->data;
  }

  return &fun4_interfaces__srv__detail__change_mode__rosidl_typesupport_introspection_c__ChangeMode_service_type_support_handle;
}
