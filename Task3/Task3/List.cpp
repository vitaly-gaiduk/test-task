#include <ctime>
#include <iostream>

#include "List.h"

List::List() : count(0), head(nullptr), tail(nullptr)
{
	srand(time(NULL));
}

List::List(int cnt, const char* str) : count(0), head(nullptr), tail(nullptr)
{
	srand(time(NULL));

	for (int i = 0; i < cnt; ++i) {
		std::string str(str);
		str += '0' + i;
		push_back(str, -1);
	}
}

List::~List()
{
	ListNode* node, *nextNode;

	for (node = head; node;) {
		nextNode = node->next;
		delete node;
		node = nextNode;
	}
}

void List::push_front(std::string data, int rand_pos)
{
	ListNode* newNode = new ListNode;

	newNode->prev = nullptr;
	newNode->next = head;
	newNode->data = data;

	if (rand_pos != -1)
		newNode->rand = seek(rand_pos);
	else
		if (count)
			newNode->rand = seek(rand() % count);
		else
			newNode->rand = nullptr;

	if (head)
		head->prev = newNode;

	if (!count)
		head = tail = newNode;
	else
		head = newNode;

	count++;
}

void List::push_back(std::string data, int rand_pos)
{
	ListNode* newNode = new ListNode;

	newNode->next = nullptr;
	newNode->prev = tail;
	newNode->data = data;

	if (rand_pos != -1)
		newNode->rand = seek(rand_pos);
	else
		if (count)
			newNode->rand = seek(rand() % count);
		else
			newNode->rand = nullptr;

	if (tail)
		tail->next = newNode;

	if (!count)
		head = tail = newNode;
	else
		tail = newNode;

	count++;
}

void List::pop_front()
{
	ListNode* pop = head;

	head = pop->next;
	head->prev = nullptr;

	count--;

	checkLink(pop);
	delete pop;
}

void List::pop_back()
{
	ListNode* pop = tail;

	tail = pop->prev;
	tail->next = nullptr;

	count--;

	checkLink(pop);
	delete pop;
}

void List::Serialize(FILE* file)  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
{
	ListNode* node;

	int pos;
	fwrite(&count, sizeof(int), 1, file);

	for (node = head, pos = 0; node; node = node->next, ++pos) {
		int rand_pos = toNode(node->rand);

		fwrite(&pos, sizeof(int), 1, file);
		fwrite(&rand_pos, sizeof(int), 1, file);

		int dataSize = node->data.size();
		fwrite(&dataSize, sizeof(int), 1, file);
		fwrite(&node->data[0], dataSize, 1, file);
	}
}

void List::Deserialize(FILE* file)  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
{
	int size;

	fread(&size, sizeof(int), 1, file);

	for (int i = 0; i < size; ++i) {
		int pos, rand_pos;
		fread(&pos, sizeof(int), 1, file);
		fread(&rand_pos, sizeof(int), 1, file);

		int dataSize;
		std::string data;
		fread(&dataSize, sizeof(int), 1, file);
		data.resize(dataSize);
		fread(&data[0], dataSize, 1, file);

		push_back(data, rand_pos);
	}
}

void List::display()
{
	ListNode* node;

	std::cout << "List " << this << std::endl;
	std::cout << "|" << std::endl;

	if (!head)
		std::cout << "*EMPTY*" << std::endl;

	for (node = head; node; node = node->next) {
		if (node == head)
			std::cout << "*HEAD*" << std::endl;

		std::cout << node->data;

		if (node->prev) {
			std::cout << "--";
			std::cout << "*PREV: " << node->prev->data;
		}

		if (node->next) {
			std::cout << std::endl << "|" << std::endl;
			std::cout << "*NEXT: " << node->next->data;
		}

		std::cout << std::endl << std::endl;
	}

	std::cout << std::endl;
}

List::ListNode* List::seek(int pos)
{
	ListNode* node;
	
	if (!head || pos > count)
		return nullptr;
	
	node = head;
	
	for (int i = 0; i < pos; ++i, node = node->next); // seek to pos

	return node;
}

int List::toNode(ListNode* to)
{
	ListNode* node;
	int pos;

	if (!to)
		return -1;

	for (node = head, pos = 0; node; node = node->next, ++pos) {
		if (to == node)
			return pos;
	}

	return -1;
}

void List::checkLink(ListNode* unlinked)
{
	ListNode* node;

	for (node = head; node; node = node->next) {
		if (node->rand == unlinked) {
			node->rand = seek(rand() % count); // reset random link with new count
		}
	}
}
