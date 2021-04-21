#ifndef MY_STRING_H
#define MY_STRING_H
#define size_t unsigned int

char* my_strcpy(char* dest, char* sor);

char* my_strncpy(char* dest, char* sor, size_t count);

char* my_strcat(char* dest, char* sor);

char* my_strncat(char* dest, char* sor, int count);

size_t my_strlen(char* st);

int my_strcmp(char* str1, char* str2);

#endif
