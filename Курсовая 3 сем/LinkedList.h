#pragma once
#include <string>

using namespace std;

class LinkedList
{
private:

	void add_first(string newElem); 
	void reset_list(); 

	class Node
	{
	public:
		Node(string data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		~Node() {}

		string data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	LinkedList();
	~LinkedList();

	void push_back(string newElem); 
	string pop_back(); 
	string getTop();
	size_t get_size();
	void clear(); 
	bool isEmpty(); 
};