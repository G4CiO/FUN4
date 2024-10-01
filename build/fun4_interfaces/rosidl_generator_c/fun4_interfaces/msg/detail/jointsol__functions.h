// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fun4_interfaces:msg/Jointsol.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__FUNCTIONS_H_
#define FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fun4_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "fun4_interfaces/msg/detail/jointsol__struct.h"

/// Initialize msg/Jointsol message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fun4_interfaces__msg__Jointsol
 * )) before or use
 * fun4_interfaces__msg__Jointsol__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
bool
fun4_interfaces__msg__Jointsol__init(fun4_interfaces__msg__Jointsol * msg);

/// Finalize msg/Jointsol message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
void
fun4_interfaces__msg__Jointsol__fini(fun4_interfaces__msg__Jointsol * msg);

/// Create msg/Jointsol message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fun4_interfaces__msg__Jointsol__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
fun4_interfaces__msg__Jointsol *
fun4_interfaces__msg__Jointsol__create();

/// Destroy msg/Jointsol message.
/**
 * It calls
 * fun4_interfaces__msg__Jointsol__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
void
fun4_interfaces__msg__Jointsol__destroy(fun4_interfaces__msg__Jointsol * msg);

/// Check for msg/Jointsol message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
bool
fun4_interfaces__msg__Jointsol__are_equal(const fun4_interfaces__msg__Jointsol * lhs, const fun4_interfaces__msg__Jointsol * rhs);

/// Copy a msg/Jointsol message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
bool
fun4_interfaces__msg__Jointsol__copy(
  const fun4_interfaces__msg__Jointsol * input,
  fun4_interfaces__msg__Jointsol * output);

/// Initialize array of msg/Jointsol messages.
/**
 * It allocates the memory for the number of elements and calls
 * fun4_interfaces__msg__Jointsol__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
bool
fun4_interfaces__msg__Jointsol__Sequence__init(fun4_interfaces__msg__Jointsol__Sequence * array, size_t size);

/// Finalize array of msg/Jointsol messages.
/**
 * It calls
 * fun4_interfaces__msg__Jointsol__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
void
fun4_interfaces__msg__Jointsol__Sequence__fini(fun4_interfaces__msg__Jointsol__Sequence * array);

/// Create array of msg/Jointsol messages.
/**
 * It allocates the memory for the array and calls
 * fun4_interfaces__msg__Jointsol__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
fun4_interfaces__msg__Jointsol__Sequence *
fun4_interfaces__msg__Jointsol__Sequence__create(size_t size);

/// Destroy array of msg/Jointsol messages.
/**
 * It calls
 * fun4_interfaces__msg__Jointsol__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
void
fun4_interfaces__msg__Jointsol__Sequence__destroy(fun4_interfaces__msg__Jointsol__Sequence * array);

/// Check for msg/Jointsol message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
bool
fun4_interfaces__msg__Jointsol__Sequence__are_equal(const fun4_interfaces__msg__Jointsol__Sequence * lhs, const fun4_interfaces__msg__Jointsol__Sequence * rhs);

/// Copy an array of msg/Jointsol messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fun4_interfaces
bool
fun4_interfaces__msg__Jointsol__Sequence__copy(
  const fun4_interfaces__msg__Jointsol__Sequence * input,
  fun4_interfaces__msg__Jointsol__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FUN4_INTERFACES__MSG__DETAIL__JOINTSOL__FUNCTIONS_H_
