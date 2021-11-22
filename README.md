# Integer

```cpp
#include <Integer.h>
Integer myInteger = Integer("1234556709159591230592856");
myInteger *= 2; //2469113418319182461185712
myInteger /= 2; //1234556709159591230592856
myInteger += 1; //1234556709159591230592857
myInteger--; //1234556709159591230592856
```

This repository contains the Integer class.

This class is a utility for doing arithmetic on large integers without strict precision limits.
It implements the C++ std::vector class so any limits on precision are those that apply to this class.

From [cplusplus.com](http://www.cplusplus.com/reference/vector/vector/max_size/) reference:

>**Returns the maximum number of elements that the vector can hold.**

>**This is the maximum potential size the container can reach due to known system or library implementation limitations,**
>**but the container is by no means guaranteed to be able to reach that size:**
>**it can still fail to allocate storage at any point before that size is reached.**
