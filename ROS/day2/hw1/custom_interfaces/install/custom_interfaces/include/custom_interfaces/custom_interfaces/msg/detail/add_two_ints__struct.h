// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ADD_TWO_INTS__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__ADD_TWO_INTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'b'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/AddTwoInts in the package custom_interfaces.
typedef struct custom_interfaces__msg__AddTwoInts
{
  int64_t a;
  rosidl_runtime_c__int64__Sequence b;
} custom_interfaces__msg__AddTwoInts;

// Struct for a sequence of custom_interfaces__msg__AddTwoInts.
typedef struct custom_interfaces__msg__AddTwoInts__Sequence
{
  custom_interfaces__msg__AddTwoInts * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__AddTwoInts__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ADD_TWO_INTS__STRUCT_H_
