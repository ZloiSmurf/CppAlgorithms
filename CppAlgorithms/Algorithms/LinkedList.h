/*
*  Implementation of a singly linked list
*/
#pragma once

template<typename Type> class LinkedList
{
	struct Node {
		Type data;
		Node* next;
		Node(Type data) : data(data), next(nullptr) {
		}
	};

	Node *head;
	int list_len;

public:
	LinkedList() {
		head = nullptr;
		list_len = 0;
	}

	//Insert first
	void add(Type data) {
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		list_len++;
	}

	//Insertion by index
	void add(Type data, int index) {
		if (index == 0) {
			add(data);
			return;
		}
		if ((index > len()) || index < 0) {
			return;
		}
		Node* newNode = new Node(data);
		Node* tmp = head;
		for (int i = 0; i < index-1; i++) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
		list_len++;
	}

	void print() {
		Node *p = head;
		while (p){
			std::cout << p->data << ", ";
			p = p->next;
		}
		std::cout << "NULL\n";
	}

	//Removing by index
	void remove(int index) {
		try {
			if (is_empty()) throw "List is empty";
			if (index == 0) {
				Node* tmp = head;
				head = tmp->next;
				delete tmp;
				list_len -= 1;
				return;
			}
			if (index < 0 || index > len() - 1) {
				throw "Index is out_of_range";
				return;
			}

			Node* prev = head;
			Node* current = head->next;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->next;
				current = current->next;
			}

			prev->next = current->next;
			list_len -= 1;
			delete current;
		}
		catch(const char* msg){
			std::cout << msg << std::endl;
		}
	}

	bool is_empty() {
		return head == nullptr;
	}

	int len() {
		return list_len;
	}
};
