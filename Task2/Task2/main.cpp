/* 2. �������� �������, ��������� ��������������� ������������� ������� � ������:
*
void RemoveDups(char* str);

// ������ �������������
char data[] = �AAA BBB AAA�;
RemoveDups(data);
printf(�% s\n�, data); // �A B A�

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
