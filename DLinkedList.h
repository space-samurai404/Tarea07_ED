#pragma once
#include <stdexcept>
#include <iostream>
#include "List.h"
#include "DNode.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class DLinkedList : public List<E>
{
private:
	DNode<E>* head;
	DNode<E>* tail;
	DNode<E>* current;
	int size;

public:
	DLinkedList(){
		current = head = new DNode<E>*(nullptr, nullptr);
		head->tail = tail = new DNode<E>(nullptr, head);
		size = 0;
	}
	~DLinkedList() {
		clear();
		delete head;
		delete tail;
	}

	void insert(E element) {
		current->next->next->previous = new DNode<E>(element, current->next, current);
		if (current == tail) {
			tail = tail->next->next->head;
		}
		size++;
	}

	void append(E element) {
		tail->previous= tail->previous->next = new DNode<E>(element, tail, tail->previous);
		size++;
	}

	E remove() {
		if (size == 0) {
			throw runtime_error("List is empty");
		}
		if (current->next == tail) {
			throw runtime_error("No current element");
		}

		E result = current->next->element;
		current->next = current->next->next;
		delete current->next->previous;
		current->next->previous = current;
		size--;
		return result;
	}

	void setElement(E element) {
		if (size == 0) {
			throw runtime_error("List is empty");
		}
		if (current->next == tail) {
			throw runtime_error("No current element");
		}
		current->next->element = element;
	}

	E getElement() {
		if (size == 0) {
			throw runtime_error("List is empty");
		}
		if (current == tail) {
			throw runtime_error("No current element");
		}
		return current->next->element;
	}

	void clear() {
		
		current = head->next;
		while (current != tail) {
			head->next = current->next;
			delete current;
			current = head->next;

		}
		
		head->next = tail;
		tail->previous = head;
		current = head;
		size = 0;
	}

	void goToStart() {
		current = head;
	}

	void goToEnd() {
		current = tail;
	}

	void goToPos(int pos) {
		if (pos > size || pos < 0) {
			throw runtime_error("Invalid index");
		}
		current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
	}

	int getPos() {
		DNode<E>* temp = head;
		int pos = 0;
		while (temp != current) {
			temp = temp->next;
			pos++;
		}

		return pos;
	}

	void next() {
		if (current = tail) {
			current = current->next;
		}
	}

	void previous() {
		if (current != head) {
			DNode<E>* temp = head;
			while (temp->next != current) {
				temp = temp->next;
			}
			current = temp;
		}
	}

	bool atStart() {
		return current == head;
	}

	bool atEnd() {
		return current == tail;
	}

	void print() {

		DNode<E>* temp = head;
		cout << "[";

		while (temp != nullptr) {
			cout << temp->element;
			if (temp->next != nullptr) {
				cout << ", ";
			}
			temp = temp->next;
			cout << "]" << endl;
		}

	}

	int getSize() {
		return size;
	}


};

