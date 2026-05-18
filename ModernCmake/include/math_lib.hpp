#ifndef MATH_LIB_H
#define MATH_LIB_H
#include <optional>
#ifndef USING_MATH_LIB
// If USING_MATH_LIB is not defined by the consumer, define it with a default
// value to avoid a hard compilation error when including this header.
#define USING_MATH_LIB 1
#endif
std::optional<int> divide(double a, double b);
#endif