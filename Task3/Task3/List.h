#pragma once

#include <cstdio>
#include <string>

class List {
private:
	struct ListNode {
		ListNode* prev;
		ListNode* next;
		ListNode* rand; // указатель на произвольный элемент данного списка, либо NULL
		std::string     data;
	};

	ListNode* head;
	ListNode* tail;
	int       count;
public:
	List();
	List(int cnt, const char* str);
	~List();

	void push_front(std::string data);
	void push_back(std::string data);

	void pop_front();
	void pop_back();

	void Serialize(FILE* file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
	void Deserialize(FILE* file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))

	void display();
protected:
	ListNode* seek(int pos);
	void checkLink(ListNode* unlinked);
};
