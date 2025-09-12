// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__ADD_TWO_INTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/add_two_ints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_AddTwoInts_b
{
public:
  explicit Init_AddTwoInts_b(::custom_interfaces::msg::AddTwoInts & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::AddTwoInts b(::custom_interfaces::msg::AddTwoInts::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::AddTwoInts msg_;
};

class Init_AddTwoInts_a
{
public:
  Init_AddTwoInts_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddTwoInts_b a(::custom_interfaces::msg::AddTwoInts::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddTwoInts_b(msg_);
  }

private:
  ::custom_interfaces::msg::AddTwoInts msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::AddTwoInts>()
{
  return custom_interfaces::msg::builder::Init_AddTwoInts_a();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
