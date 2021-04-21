#ifndef MY_STDIO_H
#define MY_STDIO_H

#include <stdio.h> // stdin stdout 을 쓰려고 인클루드 했음. 다른 방안을 찾도록

static int get_type_size(const char** format);

static int is_space_char(char c);

int my_scanf(const char* format, ...);

#endif
