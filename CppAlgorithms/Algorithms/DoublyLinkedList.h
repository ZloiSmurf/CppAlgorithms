#pragma once
template<typename Type> class DoublyLinkedList {

	struct Node {
		Type data;
		Node* next;
		Node* prev;
		Node(Type data) : data(data), next(nullptr), prev(nullptr) {
		}
	};

	Node* head;
	int list_len;

public:
	DoublyLinkedList() {
		head = nullptr;
		list_len = 0;
	}

	void add(Type data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		if (!is_empty()) {
			newNode->next->prev = newNode;
		}
		newNode->prev = NULL;
		head = newNode;
		list_len++;
	}

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
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		newNode->prev = tmp;
		newNode->next->next->prev = newNode;
		tmp->next = newNode;
		list_len++;
	}

	void print() {
		Node* p = head;
		while (p) {
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << "NULL\n";
	}

	void remove(int index) {
		if (is_empty()) return;
		if (index == 0) {
			Node* tmp = head;
			head = tmp->next;
			delete tmp;
			list_len -= 1;
			return;
		}
		if (index < 0 || index > len()) {
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

	bool is_empty() {
		return head == nullptr;
	}

	int len() {
		return list_len;
	}
};
