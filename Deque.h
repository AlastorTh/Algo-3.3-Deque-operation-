#ifndef _DEQUE_H
#define _DEQUE_H

#include <iostream>

template <class Type> // для работы с любым типом
class Deque 
{  // класс дека

	class Node  // элемент дека
	{
		friend class Deque;
		Type data;
		Node* next, * prev;

		

	public:
		Node(Type data = Type(), Node* next = nullptr, Node* prev = nullptr)
			: data(data), next(next), prev(prev) {};  // конструктор узла

		~Node() { delete next; }

		
	};
public:
	template <class Ptr, class T>
	class Iterator 
	{
		Ptr ptr;

	public:
		Iterator(Ptr ptr = nullptr) : ptr(ptr) {}; //конструктор

		T& operator*() { return ptr->data; }
		T& operator->() { return ptr->data; }
		void operator++() { ptr = ptr->next; } // префиксный ++
		Iterator operator++(int) //постфиксный ++ 
		{
			Iterator iter(*this);
			++(*this);
			return iter;
		}
		bool operator==(const Iterator& i) { return ptr == i.ptr; }
		bool operator!=(const Iterator& i) { return !(*this == i); }
	};

	
	using const_iterator = Iterator<const Node*, const Type>;
private:
	Node* head, * tail;

public:
	Deque() : head(nullptr), tail(nullptr) {}; // конструктор дека 

	void push_front(const Type& value) // добавление в начало 
	{
		Node* insert = new Node(value, head);
		if (head)
			head = head->prev = insert;
		else
			head = tail = insert;
	}
	void push_back(const Type& value)
	{
		Node* insert = new Node(value, nullptr, tail);
		if (tail)
			tail = tail->next = insert;
		else
			head = tail = insert;
	}

	void pop_front() {
		if (head) {
			Node* remove = head;
			head = head->next;
			remove->next = nullptr;
			if (head) head->prev = nullptr;
			delete remove;
		}
	}
	void pop_back() {
		if (tail) {
			auto remove = tail;
			tail = tail->prev;
			if (tail) tail->next = nullptr;
			delete remove;
		}
	}

	void clear() 
	{
		delete head;
		head = tail = nullptr;
	}
	
	bool empty() 
	{
		if (head == nullptr) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	

	const_iterator begin() const { return const_iterator(head); }
	const_iterator end() const { return const_iterator(nullptr); }

	friend std::ostream& operator<<(std::ostream& os, const Deque& d) 
	{
		os << "Elements:" << std::endl;
		for (auto& it : d) // 
		{
			os << it << std::endl;
		}
		return os; 
	}

	~Deque() { delete head; }
};

#endif
