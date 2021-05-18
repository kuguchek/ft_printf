# ft_printf

## Description
```c
int   ft_printf(char const *str, ...)
```
Recoding C-library's printf function. ft_printf can print different contents depending on conversions and flags. You can print using the following syntax: 

```
%[flag][min-width].[precision][length modifier][conversion specifier]
```

- managed following conversions: s p d D i o O u U x X c f F and %%
- managed flags: #0-+ and space
- managed minimum field-width and precision
- managed lenght modifiers: hh, h, l, ll, j, z, L

## Usage

``make`` will compile a ``libftprintf.a`` library. Use it like you would use the real printf function

```c
#include "src/ft_printf.h"

ft_printf("**%d**% d% d **\n", 42, 42, -42);
//output: **42** 42-42 **
```


