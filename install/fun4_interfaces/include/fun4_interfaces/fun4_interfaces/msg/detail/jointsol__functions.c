// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice
#include "fun4_interfaces/msg/detail/jointsol__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `q_msg`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
fun4_interfaces__msg__Jointsol__init(fun4_interfaces__msg__Jointsol * msg)
{
  if (!msg) {
    return false;
  }
  // q_msg
  if (!rosidl_runtime_c__double__Sequence__init(&msg->q_msg, 0)) {
    fun4_interfaces__msg__Jointsol__fini(msg);
    return false;
  }
  return true;
}

void
fun4_interfaces__msg__Jointsol__fini(fun4_interfaces__msg__Jointsol * msg)
{
  if (!msg) {
    return;
  }
  // q_msg
  rosidl_runtime_c__double__Sequence__fini(&msg->q_msg);
}

bool
fun4_interfaces__msg__Jointsol__are_equal(const fun4_interfaces__msg__Jointsol * lhs, const fun4_interfaces__msg__Jointsol * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // q_msg
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->q_msg), &(rhs->q_msg)))
  {
    return false;
  }
  return true;
}

bool
fun4_interfaces__msg__Jointsol__copy(
  const fun4_interfaces__msg__Jointsol * input,
  fun4_interfaces__msg__Jointsol * output)
{
  if (!input || !output) {
    return false;
  }
  // q_msg
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->q_msg), &(output->q_msg)))
  {
    return false;
  }
  return true;
}

fun4_interfaces__msg__Jointsol *
fun4_interfaces__msg__Jointsol__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__msg__Jointsol * msg = (fun4_interfaces__msg__Jointsol *)allocator.allocate(sizeof(fun4_interfaces__msg__Jointsol), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fun4_interfaces__msg__Jointsol));
  bool success = fun4_interfaces__msg__Jointsol__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fun4_interfaces__msg__Jointsol__destroy(fun4_interfaces__msg__Jointsol * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fun4_interfaces__msg__Jointsol__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fun4_interfaces__msg__Jointsol__Sequence__init(fun4_interfaces__msg__Jointsol__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__msg__Jointsol * data = NULL;

  if (size) {
    data = (fun4_interfaces__msg__Jointsol *)allocator.zero_allocate(size, sizeof(fun4_interfaces__msg__Jointsol), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fun4_interfaces__msg__Jointsol__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fun4_interfaces__msg__Jointsol__fini(&data[i - 1]);
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
fun4_interfaces__msg__Jointsol__Sequence__fini(fun4_interfaces__msg__Jointsol__Sequence * array)
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
      fun4_interfaces__msg__Jointsol__fini(&array->data[i]);
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

fun4_interfaces__msg__Jointsol__Sequence *
fun4_interfaces__msg__Jointsol__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fun4_interfaces__msg__Jointsol__Sequence * array = (fun4_interfaces__msg__Jointsol__Sequence *)allocator.allocate(sizeof(fun4_interfaces__msg__Jointsol__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fun4_interfaces__msg__Jointsol__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fun4_interfaces__msg__Jointsol__Sequence__destroy(fun4_interfaces__msg__Jointsol__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fun4_interfaces__msg__Jointsol__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fun4_interfaces__msg__Jointsol__Sequence__are_equal(const fun4_interfaces__msg__Jointsol__Sequence * lhs, const fun4_interfaces__msg__Jointsol__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fun4_interfaces__msg__Jointsol__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fun4_interfaces__msg__Jointsol__Sequence__copy(
  const fun4_interfaces__msg__Jointsol__Sequence * input,
  fun4_interfaces__msg__Jointsol__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fun4_interfaces__msg__Jointsol);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fun4_interfaces__msg__Jointsol * data =
      (fun4_interfaces__msg__Jointsol *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fun4_interfaces__msg__Jointsol__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fun4_interfaces__msg__Jointsol__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fun4_interfaces__msg__Jointsol__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
