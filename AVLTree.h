#pragma once
#include "BSTNode.h"
#include "List.h"
#include "DLinkedList.h"
using std::exception;
using std::runtime_error;

template <typename E>
class AVLTree
{
private:
	BSTNode<E>* root;
	int size;
	BSTNode<E>* insertAux(BSTNode<E>* current, E element) {
		if (current == nullptr) {
			return new BSTNode<E>(element);
		}
		if (element == current->element) {
			throw runtime_error("Duplicated element");
		}
		if (element < current->element) {
			current->left = insertAux(current->left, element);
		}
		else {
			current->right = insertAux(current->right, element);
		}
		return rebalance(current);
	}

	E findAux(BSTNode<E>* current, E element) {
		if (current == nullptr) {
			throw runtime_error("Element not found");
		}
		if (current->element == element) {
			return current->element;
		}
		if (element < current->element) {
			return findAux(current->right, element);
		}
	}



	BSTNode<E>* removeAux(BSTNode<E>* current, E element, E* result) {
		if (current == nullptr) {
			throw runtime_error("Element not found");
		}
		if (element < current->element) {
			current->left = removeAux(current->left, element, result);
			return rebalance(current);
		}
		if (element > current->element) {
			current->right = remove(current->right, element, result);
			return rebalance(current);
		}
		*result = current->element;
		if (current->childrenCount() == 0) {
			delete current;
			return nullptr;
		}
		if (current->childrenCount() == 1) {
			BSTNode<E>* child = current->onlyChild();
			delete current;
			return child;
		}
		BSTNode<E> successor = getSuccessor(current);
		swap(successor, current);
		current->rignt = removeAux(current->right, element, result);
		return rabalance(current);

	}

	BSTNode<E>* rotateRight(BSTNode<E>* current) {
		if (current->left == nullptr) {
			throw runtime_error("");
		}
		BSTNode<E>* temp = current->left;
		current->left = temp->right;
		temp->right = current;
		return temp;
	}

	BSTNode<E>* rotateLeft(BSTNode<E>* current) {
		if (current->left == nullptr) {
			throw runtime_error("");
		}
		BSTNode<E>* temp = current->right;
		current->right = temp->left;
		temp->left = current;
		return temp;
	}

	BSTNode<E>* rebalance(BSTNode<E>* current)
	{
		int lh = height(current->left);
		int rh = height(current->right);

		if (lh > rh + 1){
			int llh = height(current->left->left);
			int lrh = height(current->left->right);

			if (lrh > llh){
				current->left = rotateLeft(current->left);
			}
			return rotateRight(current);
		}
		if (rh > lh + 1){
			int rlh = height(current->right->left);
			int rrh = height(current->right->right);
			if (rlh > rrh){
				current->right = rotateRight(current->right);
			}
			rotateLeft(current);
		}
		return current;
	}
	

	int height(BSTNode<E>* current) {
		if (current == nullptr) {
			return 0;
		}
		int lh = height(current->left);
		int rh = height(current->right);
		return (lh > rh ? lh : rh);
	}

	BSTNode<E>* getSuccessor(BSTNode<E>* current) {
		BSTNode<E>* successor = current->right;
		while (successor->left != nullptr) {
			successor = successor->left;
		}
		return successor;
	}

	void swap(BSTNode<E>* n1, BSTNode<E>* n2) {
		E temp = n1->element;
		n1->element = n2->element;
		n2->element = temp;
	}

	void clearAux(BSTNode<E>* current) {
		if (current == nullptr) {
			return;
		}
		clearAux(current->left);
		clearAux(current->right);
		delete current;
	}


	void getElementsAux(BSTNode<E>* current, List<E>* elements) {
		if (current == nullptr) {
			return;
		}
		getElementsAux(current->left, elements);
		elements->append();
	}

	void printAux(BSTNode<E>* current) {
		if (current == nullptr) {
			return;
		}
		cout << "(";
		printAux(current->left);
		cout << current->element;
		printAux(current->right);
		cout << ")";
	}

public:
	AVLTree() {
		root = nullptr;
	}

	~AVLTree() {
		clear();
	}

	void insert(E element) {
		root = insertAux(root, element);
	}

	E find(E element) {
		BSTNode<E>* current = root;
		return findAux(root, element);
		while (current != nullptr) {
			if (element == current->element) {
				return current->element;
			}
			if (element < current->element) {
				current = current->left;
			}
		}
	}

	E remove(E element) {
		E result;
		root = removeAux(root, element, &result);
		return result;
	}

	bool contains(E element) {
		BSTNode<E>* current = root;
		while (current != nullptr) {
			if (element == current->element) {
				return true;
			}
			if (element < current->element) {
				current = current->left;

			}
			else {
				current = current->right;
			}

		}
		return false;

	}

	void clear() {
		clearAux(root);
		root = nullptr;

	}

	List<E> getElements() {
		List<E>* elements = new DLinkedList<E>();
		getElements(root, elements);
		return elements;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void print() {
		printAux(root);
	}



};


