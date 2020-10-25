/* 2. Ќапишите функцию, удал€ющую последовательно дублирующиес€ символы в строке:
*
void RemoveDups(char* str);

// пример использовани€
char data[] = УAAA BBB AAAФ;
RemoveDups(data);
printf(У% s\nФ, data); // УA B AФ

*/

#include <cstdio>
#include <cstring>

#define DATA_LEN 256

void RemoveDups(char* str)
{
	char* pStr = str;
	char res[DATA_LEN] = { 0 };
	char* pRes = res;

	while (*pStr != '\0') {
		*pRes = *pStr;
		while (*pStr == *(pStr + 1)) {
			pStr++;
		}
		pStr++;
		pRes++;
	}

	memcpy(str, res, sizeof(char) * DATA_LEN);
}

int main()
{
	char data[DATA_LEN] = { 0 };

	printf("Input string: ");
	fgets(data, sizeof(char) * DATA_LEN, stdin);

	RemoveDups(data);

	printf("Parsed: %s\n", data);

	return 0;
}
