#ifndef MY_STDIO_H
#define MY_STDIO_H

#include <stdio.h> // stdin stdout �� ������ ��Ŭ��� ����. �ٸ� ����� ã����

static int get_type_size(const char** format);

static int is_space_char(char c);

int my_scanf(const char* format, ...);

#endif
