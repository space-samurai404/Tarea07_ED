#pragma once
#include "Dictionary.h"
#include "Pair.h"
#include "LinkedList.h"
#include "Arraylist.h"
#include "BSTree.h"
#include <iostream>

using std::runtime_error;

template <typename K, typename V>
class BSTDictionary : public Dictionary <K, V> {
private:
	List<Pair <K, V>>* pairs;

public:
	BSTDictionary() {
		pairs = new BSTree <Pair<K, V>>();
	}

	~BSTDictionary() {
		delete pairs;
	}

private:
	bool find(K key) {
		Pair<K, V> pair(key, V);
		return pairs->contains(pair)
		return false;
	}

public:
	void insert(K key, V value) {
		if (find(key)) {
			throw runtime_error("Duplicated key");
		}
		Pair<K, V> p(key, value);
		pairs->append(p);
	}

	V remove(K key) {
		if (!find(key)) {
			throw runtime_error("Key not found");
		}
		Pair<K, V>p = pairs->remove();
		return p.Value;
	}

	V getValue(K key) {
		if (!find(key)) {
			throw runtime_error("Key not found");
		}
		Pair<K, V>p = pairs->getElement();
		return p.Value;
	}

	void setValue(K key, V value) {
		if (!find(key)) {
			throw runtime_error("Key not found");
		}
		Pair<K, V> p(key, value);
		pairs->setElement(p);
	}

	bool contains(K key) {
		return find(key);
	}

	bool isEmpty() {
		return pairs->getSize() == 0;
	}

	void clear() {
		return pairs->clear();
	}

	List<K>* getKeys() {
		List <K>* keys = new ArrayList<K>(getSize());
		while (!pairs->atEnd) {
			Pair<K, V> p = pairs->getElement();
			keys->append(p.key);
			pairs->next();
		}
		return keys;
	}

	List<V>* getValues() {
		List <V>* values = new ArrayList<K>(getSize());
		while (!pairs->atEnd()) {
			Pair<K, V> p = pairs->getElement();
			values->append(p.value);
			pairs->next();
		}
		return values;
	}


	int getSize() {
		return pairs->getSize();
	}

	void update(Dictionary<K, V>* D) {
		for (pairs->goToStart(); !pairs->atEnd(); pairs->next()) {
			Pair<K, V> p = pairs->getElement();
			if (key == p.key) {
				return true;
			}
			return false;
		}
	}

	void zip(List<K>* keys, List<K>* values) {

	}

	void print() {
		cout << "{";
		for (pairs->goToStart(); !pairs->atEnd(); pairs->next()) {
			Pair<K, V>p = pairs->getElement();
			cout << p.key << " ; " << p.value;
			if (pairs->getPos() < pairs->getSize() - 1) {
				cout << ", ";
			}
		}
		cout << "}";
	}



};

