## Bin Id
Implement function that defines nearest power of 2.

### **Requerements**
1. Function should be implemented using `C++11`(not C++14!) standart.
2. Function should be `constexpr`.
3. Function should `pass compile-time tests` such as:

```cpp
static_assert(bin_id(7) == 3, "bin_id doesn't work");
static_assert(bin_id(8) == 3, "bin_id doesn't work");
static_assert(bin_id(9) == 4, "bin_id doesn't work");
static_assert(bin_id(1023) == 10, "bin_id doesn't work");
static_assert(bin_id(1024) == 10, "bin_id doesn't work");
static_assert(bin_id(1025) == 11, "bin_id doesn't work");
```
