#pragma once
#include "node.h"

template <typename T>
class list
{
private:
	node<T>* first_node;
	node<T>* end_node;
	int size;
public:
	list();

	void append(T v);
	void insert(T v, int index);

	T pop();
	T pop(int index);

	operator[](int index);
};

template <typename T>
inline list<T>::list() {
	this->size = 0;
}
template <typename T>
inline void list<T>::append(T v) {
	if (size == 0) {
		node<T> a = node<T>(v);
		this->end_node = &a;
		this->end_node - this->first_node;
		this->size = 1;
	}
	else {
		node<T> a = node<T>(v);
		this->end_node->line_next(&a);
		this->end_node = this->end_node->next();
		size++;
	}
}
template <typename T>
inline void list<T>::insert(T v, int index) 
{
	node* target = this->first_node;
	for (int i = 0; i < this->size; i++) {
		if (i == index)
			break;
		target = target->next();
	}

	node* add = *node(v);
	node* last_node = target->past();
	target->link_past(add);
	this->size++;
}

template <typename T>
inline T list<T>::pop() {
	this->end_node = this->end_node->past;
	node* a = this->end_node->next();
	T v = a->get();
	delete a;
	this->size--;
	return T();
}
template <typename T>
inline T list<T>::pop(int index) {
	node* target = this->first_node;
	for (int i = 0; i < this->size; i++) {
		if (i == index)
			break;
		target = target->next();
	}
	target = target->past();
	node* a = this->end_node->next();
	T v = a->get();
	target->line_next(target->next()->next());
	delete a;
	this->size--;
	return T();
}

template <typename T>
inline T list<T>::operator[](int index)
{
	node<T>* target = this->first_node;
	for (int i = 0; i < this->size; i++) {
		if (i == index)
			break;
		target = target->next();
	}
	return target->get();
}