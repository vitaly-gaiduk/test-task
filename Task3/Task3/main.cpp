/* 1.	���������� ������� ������������ � �������������� ����������� ������ � �������� ������� � ����. 
        ��������������� ��������� ������� ������ ���� ������ ������������.

// ��������� ListNode ������������� ������
struct ListNode {
     ListNode *      prev;
     ListNode *      next;
     ListNode *      rand; // ��������� �� ������������ ������� ������� ������, ���� NULL
     std::string     data;
};

class List {
public:
     void Serialize   (FILE * file);  // ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
     void Deserialize (FILE * file);  // �������� �� ����� (���� ������ � ������� fopen(path, "rb"))

private:
     ListNode *      head;
     ListNode *      tail;
     int       count;
};

����������: ������������ ������������� ���������� � �������������� ������ ��������� ������, 
            ������� �������� ����������� ��� ��������� ����� �����.
*/

#include <iostream>

#include "List.h"

int main() 
{
    const char* filename = "List.bin";
    FILE* pFile = fopen(filename, "wb");
    List myList(3, "NodeSave");
    List newList;

    myList.Serialize(pFile);
    myList.display();
    fclose(pFile);

    newList.display();

    pFile = fopen(filename, "rb");
    newList.Deserialize(pFile);
    newList.display();
    fclose(pFile);

    return 0;
}
