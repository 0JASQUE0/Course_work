#include <stdexcept>
#include "iostream"
#include "LinkedList.h"

using namespace std;

void LinkedList::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList()
{
	reset_list();
	size = 0;
}

LinkedList::~LinkedList()
{
}

void LinkedList::add_first(string newElem)
{
	head = new Node(newElem);
	tail = head;
}

void LinkedList::push_back(string newElem)
{
	string temp;
	temp = newElem;
	if (size == 0) {
		add_first(temp);
	}
	else {
		tail->next = new Node(temp, nullptr, tail);
		tail = tail->next;
	}
	size++;
}

string LinkedList::pop_back()
{
	string temp;

	if (size == 0) return " ";

	if (size == 1) {
		temp = head->data;
		delete head;
		reset_list();
	}
	else {
		temp = tail->data;
		Node* current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
	return temp;
}

string LinkedList::getTop()
{
	if (size == 0) return " ";
	return tail->data;
}

size_t LinkedList::get_size()
{
	return size;
}

void LinkedList::clear()
{
	Node* current = head->next;
	while (current->next != nullptr) {
		delete head;
		head = current;
		current = head->next;
	}
	delete head;
	delete tail;
	size = 0;
}

bool LinkedList::isEmpty() // if empty - true, else false
{
	return !size;
}