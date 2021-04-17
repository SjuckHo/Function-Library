#ifndef MY_STRING_H
#define MY_STRING_H

char* strcpy(char* dest, char* sor);

char* strncpy(char* dest, char* sor, size_t count);

char* strcat(char* dest, char* sor);

char* strncat(char* dest, char* sor, int count)

size_t strlen(char* st);

int strcmp(char* str1, char* str2);


#endif