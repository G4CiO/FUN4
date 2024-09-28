// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fun4_interfaces:srv/ChangeMode.idl
// generated code does not contain a copyright notice
#include "fun4_interfaces/srv/detail/change_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
fun4_interfaces__srv__ChangeMode_Request__init(fun4_interfaces__srv__ChangeMode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // teleop_mode
  // pose
  if (!geometry_msgs__msg__Point__init(&msg->pose)) {
    fun4_interfaces__srv__ChangeMode_Request__fini(msg);
    return false;
  }
  return true;
}

void
fun4_interfaces__srv__ChangeMode_Request__fini(fun4_interfaces__srv__ChangeMode_Request * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // teleop_mode
  // pose
  geometry_msgs__msg__Point__fini(&msg->pose);
}

bool
fun4_interfaces__srv__ChangeMode_Request__are_equal(const fun4_interfaces__srv__ChangeMode_Request * lhs, const fun4_interfaces__srv__ChangeMode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // teleop_mode
  if (lhs->teleop_mode != rhs->teleop_mode) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
fun4_interfaces__srv__ChangeMode_Request__copy(
  const fun4_interfaces__srv__ChangeMode_Request * input,
  fun4_interfaces__srv__ChangeMode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // teleop_mode
  output->teleop_mode = input->teleop_mode;
  // pose
  if (!geometry_msgs__msg__Point__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

fun4_interfaces__srv__ChangeMode_Request *
fun4_interfaces__srv__ChangeMode_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__srv__ChangeMode_Request * msg = (fun4_interfaces__srv__ChangeMode_Request *)allocator.allocate(sizeof(fun4_interfaces__srv__ChangeMode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fun4_interfaces__srv__ChangeMode_Request));
  bool success = fun4_interfaces__srv__ChangeMode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fun4_interfaces__srv__ChangeMode_Request__destroy(fun4_interfaces__srv__ChangeMode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fun4_interfaces__srv__ChangeMode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fun4_interfaces__srv__ChangeMode_Request__Sequence__init(fun4_interfaces__srv__ChangeMode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__srv__ChangeMode_Request * data = NULL;

  if (size) {
    data = (fun4_interfaces__srv__ChangeMode_Request *)allocator.zero_allocate(size, sizeof(fun4_interfaces__srv__ChangeMode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fun4_interfaces__srv__ChangeMode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fun4_interfaces__srv__ChangeMode_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fun4_interfaces__srv__ChangeMode_Request__Sequence__fini(fun4_interfaces__srv__ChangeMode_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fun4_interfaces__srv__ChangeMode_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fun4_interfaces__srv__ChangeMode_Request__Sequence *
fun4_interfaces__srv__ChangeMode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__srv__ChangeMode_Request__Sequence * array = (fun4_interfaces__srv__ChangeMode_Request__Sequence *)allocator.allocate(sizeof(fun4_interfaces__srv__ChangeMode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fun4_interfaces__srv__ChangeMode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fun4_interfaces__srv__ChangeMode_Request__Sequence__destroy(fun4_interfaces__srv__ChangeMode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fun4_interfaces__srv__ChangeMode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fun4_interfaces__srv__ChangeMode_Request__Sequence__are_equal(const fun4_interfaces__srv__ChangeMode_Request__Sequence * lhs, const fun4_interfaces__srv__ChangeMode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fun4_interfaces__srv__ChangeMode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fun4_interfaces__srv__ChangeMode_Request__Sequence__copy(
  const fun4_interfaces__srv__ChangeMode_Request__Sequence * input,
  fun4_interfaces__srv__ChangeMode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fun4_interfaces__srv__ChangeMode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fun4_interfaces__srv__ChangeMode_Request * data =
      (fun4_interfaces__srv__ChangeMode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fun4_interfaces__srv__ChangeMode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fun4_interfaces__srv__ChangeMode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fun4_interfaces__srv__ChangeMode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `config`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
fun4_interfaces__srv__ChangeMode_Response__init(fun4_interfaces__srv__ChangeMode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // config
  if (!rosidl_runtime_c__double__Sequence__init(&msg->config, 0)) {
    fun4_interfaces__srv__ChangeMode_Response__fini(msg);
    return false;
  }
  return true;
}

void
fun4_interfaces__srv__ChangeMode_Response__fini(fun4_interfaces__srv__ChangeMode_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // config
  rosidl_runtime_c__double__Sequence__fini(&msg->config);
}

bool
fun4_interfaces__srv__ChangeMode_Response__are_equal(const fun4_interfaces__srv__ChangeMode_Response * lhs, const fun4_interfaces__srv__ChangeMode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // config
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->config), &(rhs->config)))
  {
    return false;
  }
  return true;
}

bool
fun4_interfaces__srv__ChangeMode_Response__copy(
  const fun4_interfaces__srv__ChangeMode_Response * input,
  fun4_interfaces__srv__ChangeMode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // config
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->config), &(output->config)))
  {
    return false;
  }
  return true;
}

fun4_interfaces__srv__ChangeMode_Response *
fun4_interfaces__srv__ChangeMode_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__srv__ChangeMode_Response * msg = (fun4_interfaces__srv__ChangeMode_Response *)allocator.allocate(sizeof(fun4_interfaces__srv__ChangeMode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fun4_interfaces__srv__ChangeMode_Response));
  bool success = fun4_interfaces__srv__ChangeMode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fun4_interfaces__srv__ChangeMode_Response__destroy(fun4_interfaces__srv__ChangeMode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fun4_interfaces__srv__ChangeMode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fun4_interfaces__srv__ChangeMode_Response__Sequence__init(fun4_interfaces__srv__ChangeMode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__srv__ChangeMode_Response * data = NULL;

  if (size) {
    data = (fun4_interfaces__srv__ChangeMode_Response *)allocator.zero_allocate(size, sizeof(fun4_interfaces__srv__ChangeMode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fun4_interfaces__srv__ChangeMode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fun4_interfaces__srv__ChangeMode_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fun4_interfaces__srv__ChangeMode_Response__Sequence__fini(fun4_interfaces__srv__ChangeMode_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fun4_interfaces__srv__ChangeMode_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fun4_interfaces__srv__ChangeMode_Response__Sequence *
fun4_interfaces__srv__ChangeMode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__srv__ChangeMode_Response__Sequence * array = (fun4_interfaces__srv__ChangeMode_Response__Sequence *)allocator.allocate(sizeof(fun4_interfaces__srv__ChangeMode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fun4_interfaces__srv__ChangeMode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fun4_interfaces__srv__ChangeMode_Response__Sequence__destroy(fun4_interfaces__srv__ChangeMode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fun4_interfaces__srv__ChangeMode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fun4_interfaces__srv__ChangeMode_Response__Sequence__are_equal(const fun4_interfaces__srv__ChangeMode_Response__Sequence * lhs, const fun4_interfaces__srv__ChangeMode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fun4_interfaces__srv__ChangeMode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fun4_interfaces__srv__ChangeMode_Response__Sequence__copy(
  const fun4_interfaces__srv__ChangeMode_Response__Sequence * input,
  fun4_interfaces__srv__ChangeMode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fun4_interfaces__srv__ChangeMode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fun4_interfaces__srv__ChangeMode_Response * data =
      (fun4_interfaces__srv__ChangeMode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fun4_interfaces__srv__ChangeMode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fun4_interfaces__srv__ChangeMode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fun4_interfaces__srv__ChangeMode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
