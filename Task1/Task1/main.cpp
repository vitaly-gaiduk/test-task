// Task 1
// 1. Напишите функцию, которая принимает на вход знаковое целое число и 
//    печатает его двоичное представление, не используя библиотечных классов или функций.

#include <iostream>

#define STR_SIZE (sizeof(int)*8 + 1) // for radix=2 (also add 1 byte for '\0')

char* compl_code(char* str, int size)
{
	char* p = str;
	short carry = 1;

	// To create complement code:
	// 1. Invert bits
	// 2. Add 1 to number

	while (*p != '\0') { // invert bits
		if (*p == '0')
			*p = '1';
		else
			*p = '0';

		p++;
	}

	// move to end
	p = str + size - 1;

	while (carry) { // add 1 to number
		if (*p == '0') {
			*p = '1';
			carry = 0;
		}
		else {
			*p = '0';
		}
		p--;
	}

	return str;
}

char* itob(int val, char* str, int size)
{
	short sign = 0;
	char* p = str;

	// move to end
	p += size - 1;

	if (val < 0) {
		sign = 1;
		val = -val;
	}

	do
	{
		*p = val % 2 + '0';
		p--;
		val /= 2;
	} while (val);

	if (sign)
		compl_code(str, size);

	return str;
}

int main()
{
	int n;
	char str[STR_SIZE] = { 0 };

	memset(str, '0', (STR_SIZE - 1) * sizeof(char));

	std::cout << "Input number: ";
	std::cin >> n;

	itob(n, str, STR_SIZE - 1);

	std::cout << "Binary format: " << str << std::endl;

	return 0;
}
