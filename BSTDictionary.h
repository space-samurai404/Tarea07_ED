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
		Pair<K, V> p(key);
		return pairs->contains(p)
		
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
		Pair<K, V> p(key);
		return pairs->remove(p).value;
	}

	V getValue(K key) {
		if (!find(key)) {
			throw runtime_error("Key not found");
		}
		Pair<K, V> p(key);
		return p.Value;
	}

	void setValue(K key, V value) {
		if (!find(key)) {
			throw runtime_error("Key not found");
		}
		pairs->remove(Pair<K, V>(key));
		pairs->insert(Pair<K, V>(key, value));
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
		List <Pair<K, V>>* elements = pairs->getElements();
		for (elements->goToStart(); !elements->atEnd(); elements->next()) {
			keys->append(elements->getElement().key);
		}
		delete elements;
		return keys;
	}

	List<V>* getValues() {
		List <V>* values = new ArrayList<V>(getSize());
		List <Pair<K, V>>* elements = pairs->getElements();
		for (elements->goToStart(); !elements->atEnd(); elements->next()) {
			values->append(elements->getElement().value);
		}
		delete elements;
		return values;
	}


	int getSize() {
		return pairs->getSize();
	}

	void update(Dictionary<K, V>* D) {
		List<K>* keys = D->getKeys();//hace una lista de todos los elementos de D
		for (keys->goToStart(); !keys->atEnd(); keys->next()) {
			K k = keys->getElement();//los recorre  
			V v = D->getValue(k);
			if (find(k)) {
				setValue(k, v);//si existe, entonces actualiza su valor
			}
			else {
				insert(k, v);//Si no existe, la inserta como un par nuevo
			}
			return false;
		}
	}

	void zip(List<K>* keys, List<V>* values) {
		if (keys->getSize() < values->getSize()) {//Se espera que la listas sean del mismo tamaño, pero en caso de que no lo sean, simplemente se ignoran los últimos elementos de la lista que sea más larga.
			keys->goToStart();
			values->goToStart();
			while (!values->atEnd()) {
				insert(keys->getElement(), values->getElement());
				keys->next();
				values->next();
			}
		}
		else {
		keys->goToStart();
		values->goToStart();
		while (!keys->atEnd()) {
			insert(keys->getElement(), values->getElement());
			keys->next();
			values->next();
		}
	}
	}

	void print() {
		List<Pair<K, V>>* elements = pairs->getElements();
		cout << "{";
		for (elements->goToStart(); !elements->atEnd(); elements->next()) {
			Pair<K, V>p = elements->getElement();
			cout << p.key << " ; " << p.value;
			if (elements->getPos() < elements->getSize() - 1) {
				cout << ", ";
			}
		}
		cout << "}";
		delete elements;
	}



};

