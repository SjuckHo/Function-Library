#include "my_string.h"

char* my_strcpy(char* dest, char* sor)
{
	char* temp = dest;
	while ((*dest++ = *sor++) != '\0') {
	}

	return temp;
}

char* my_strncpy(char* dest, char* sor, size_t count)
{
	size_t i = 0;
	char* temp = dest;

	while (i++ < count && (*dest++ = *sor++) != '\0')) {
	}

	return temp;
}

char* my_strcat(char* dest, char* sor)
{
	char* temp = dest;

	while (*dest != '\0') {
		dest += 1;
	}

	while (*sor != '\0') {
		*dest++ = *sor++;
	}
	*dest = '\0';

	return temp;
}

char* my_strncat(char* dest, char* sor, int count)
{
	int i = 0;
	char* temp = dest;

	while (*dest != '\0') {
		dest += 1;
	}

	while (i++ < count && (*dest++ = *sor++) != '\0') {
	}

	return temp;
}

size_t my_strlen(char* st)
{
	size_t len = (size_t)0;

	while (*st++ != '\0') {
		len += (size_t)1;
	}

	return len;
}

int my_strcmp(char* str1, char* str2)
{
	while (*str1 != '\0' && *str1 == str2) {
		str1 += 1;
		str2 += 1;
	}

	if (*str1 == *str2) {
		return 0;
	}

	return *str1 > *str2 ? 1 : -1;
}

