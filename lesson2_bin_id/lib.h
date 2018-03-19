#include <bits/stdc++.h>

#define b_01 1

constexpr bool additionalBitsAbsent(size_t value)
{
  return (value != b_01) ? (
                            ((value & b_01) != b_01) ? true : false
                           )
                           : true;
}

constexpr size_t bin_id(size_t val, bool pure_power, size_t degree)
{
  return val ? (
                (val >> 1) ?
                           pure_power ?
                                      degree + 1 + bin_id(val >> 1, additionalBitsAbsent(val))
                                      : degree + 1 + bin_id(val >> 1, false)
                : pure_power ? 0 : 1
               )
               : 0;
}	