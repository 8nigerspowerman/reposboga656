#pragma once

template <typename T>
class node
{
private:
	node* next_node;
	T value;
	node* past_node;
public:
	node(T a);
	node(node<T>* a);
	node(node<T>* a, T v);

	node(const node<T>& a);

	T get();

	node<T>* next();
	node<T>* past();

	void line_next(node<T>* a);
	void line_past(node<T>* a);
};

template<typename T>
inline node<T>::node(T a)
{
	this->value = a;
	this->next_node = nullptr;
	this->past_node = nullptr;
}

template<typename T>
inline node<T>::node(node* a)
{
	this->value = 0;
	this->next_node = a;
	a->past_node = this;
}

template<typename T>
inline node<T>::node(node* a, T v)
{
	this->value = v;
	this->next_node = a;
	a->past_node = this;
}

template<typename T>
inline node<T>::node(const node& a)
{
	this->value = a.value;
	this->next_node = nullptr;
	this->past_node = nullptr;
}

template<typename T>
inline T node<T>::get()
{
	return this->value;
}

template<typename T>
inline node<T>* node<T>::next()
{
	return this->next_node;
}

template<typename T>
inline node<T>* node<T>::past()
{
	return this->past_node;
}

template<typename T>
inline void node<T>::line_next(node* a)
{
	this->next_node = a;
	a->past_node = this;
}

template<typename T>
inline void node<T>::line_past(node* a)
{
	this->past_node = a;
	a->next_node = this;
}