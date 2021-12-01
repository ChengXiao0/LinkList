#include "utils.h"
void cpyByNum(char* dest, char* src, int begin, int end) {
	
	int i = begin;
	for (; begin <= end; begin++)
	{
		dest[begin - i] = src[begin];
	}
	dest[end - i + 1] = '\0';
}

void strcpy(char* dest, char* src)
{
	while (*dest++ = *src++);
}

int hashFunction(char* dest)
{
	int count = 0;
	do
	{
		if (('a' <= *dest&&*dest < 'z') || ('A' <= *dest && *dest < 'Z'))
		{
			if (('a' <= *dest && *dest <= 'z'))
			{
				count = count + *dest - 97;
				*dest = (char)(*dest - 32);
			}
			else
			{
				count = count + *dest - 65;
			}
		}
		dest++;
	} while (*dest != '\0');
	return count;
}

int checkLength(char* str)
{
	int i = 0;
	while (str[i++] != '\0')
	{

	}
	return i-1;
}
