/* 1.	Реализуйте функции сериализации и десериализации двусвязного списка в бинарном формате в файл. 
        Алгоритмическая сложность решения должна быть меньше квадратичной.

// структуру ListNode модифицровать нельзя
struct ListNode {
     ListNode *      prev;
     ListNode *      next;
     ListNode *      rand; // указатель на произвольный элемент данного списка, либо NULL
     std::string     data;
};

class List {
public:
     void Serialize   (FILE * file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
     void Deserialize (FILE * file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))

private:
     ListNode *      head;
     ListNode *      tail;
     int       count;
};

Примечание: сериализация подразумевает сохранение и восстановление полной структуры списка, 
            включая взаимное соотношение его элементов между собой.
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
