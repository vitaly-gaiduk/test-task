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
		push_back(str);
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

void List::push_front(std::string data)
{
	ListNode* newNode = new ListNode;

	newNode->prev = nullptr;
	newNode->next = head;
	newNode->data = data;

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

void List::push_back(std::string data)
{
	ListNode* newNode = new ListNode;

	newNode->next = nullptr;
	newNode->prev = tail;
	newNode->data = data;

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

void List::checkLink(ListNode* unlinked)
{
	ListNode* node;

	for (node = head; node; node = node->next) {
		if (node->rand == unlinked) {
			node->rand = seek(rand() % count); // reset random link with new count
		}
	}
}
