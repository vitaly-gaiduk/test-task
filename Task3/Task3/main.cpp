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
    List myList(3, "NodeSave");
    List newList(3, "NodeLoad");

    myList.display();
    newList.display();

    return 0;
}
