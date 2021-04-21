#include "my_stdio.h"

#include <stdarg.h>
#include <assert.h>

#define BUFFER_SIZE (1024)
#define WORD_SIZE (512)



int my_scanf(const char* format, ...)
{
	va_list va;

	va_start(va, format);

	char tmp_word[WORD_SIZE];
	char* tmp_p = tmp_word;


	int type_size;
	while ((type_size = get_type_size(&format)) != -1) {

		if (type_size == 0) { // ���ڿ��� ���
			// ���鹮�ڸ� ���� �� ���� getc
			//getc�� *va_arg�� ����
			char tmp_c;
			char* str = va_arg(va, char*);
			tmp_c = getc(stdin);

			while (is_space_char(tmp_c) != 0) { // ������ �ƴ� ���� ���� �̵�
				tmp_c = getc(stdin);
			}

			while (is_space_char(tmp_c) == 0) { // ������ �ƴ� �������� ����

				*str++ = tmp_c;

				tmp_c = getc(stdin);
			}
			*str = '\0';
		}
		else if (type_size == 4) { // ���ڿ��� �ƴ� ��� (���⼱ ��������)
			// ���鹮�ڸ� ���� �� ���� getc
			// ����� �������� ��ȯ
			char tmp_c;
			char word[WORD_SIZE];
			char* str = word;
			tmp_c = getc(stdin);

			while (is_space_char(tmp_c) != 0) { // ������ �ƴ� ���� ���� �̵�
				tmp_c = getc(stdin);
			}

			while (is_space_char(tmp_c) == 0) { // ������ �ƴ� �������� ����

				*str++ = tmp_c;

				tmp_c = getc(stdin);
			}

			int result = 0;
			int digit = 1;
			char* front = word;
			char* back = str - 1;
			while (front <= back) {

				result += digit * (*back - 48); // char to int >> -48

				back -= 1;
				digit *= 10;
			}

			*va_arg(va, int*) = result;
		}
	}

	va_end(va);

	return 0; // ��ȯ�� ���� �˾Ƴ�
}

int my_printf(const char* format, ...)
{

	return 0; // ��ȯ�� ���� �˾Ƴ�
}






/////////////////////////////////// �μ� �Լ�

static int get_type_size(const char** format) // ���ڿ��� ��� 0�� ��ȯ, �ι��� ������� -1 ��ȯ
{
	do {
		if (**format == '\0') {
			return -1;
		}
	} while (*(*format)++ != '%');

	switch (**format) {
	case 'd':
		return 4;

	case 's':
		return 0;

	default:
		assert(0);
		break;
	}
}

static int is_space_char(char c)
{
	if (c == ' ' || c == '\n') {
		return 1;
	}
	return 0;
}

#undef BUFFER_SIZE
#undef WORD_SIZE
