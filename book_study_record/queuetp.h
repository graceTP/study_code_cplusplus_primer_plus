// queuetp.h -- queue template with a nested class
#pragma once
#ifndef QUEUETP_H_
#define QUEUETP_H_

#include  <iostream>

using std::string;
using std::cin;
using std::cout;

template <typename Item>
class QueueTP
{
private:
	enum {Q_SIZE = 10};
	// Node is a nested class definition
	class Node
	{
	public:
		Item item;
		Node* next;
		Node(const Item& i) : item(i), next(nullptr) {}

	};

	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP& q):qsize(0) {}
	QueueTP& operator=(const QueueTP& q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() const
	{
		return items == 0;
	}

	bool isfull() const
	{
		return items == qsize;
	}

	int queuecount() const
	{
		return items;
	}

	bool enqueue(const Item & item);  // add item to end
	bool dequeue(Item& item);         // remove item from front

	void QueueTP_test();
};

// QueueTP methods
template <typename Item>
QueueTP<Item>::QueueTP(int qs) :qsize(qs)
{
	front = nullptr;
	rear = nullptr;
	items = 0;
}

template <typename Item>
QueueTP<Item>::~QueueTP()
{
	Node* temp;
	while (front != nullptr)    // while queue is not yet empty
	{
		temp = front;          // save address of front item
		front = front->next;   // reset pointer to next item
		delete temp;           // delete former front
	}
}

// Add item to queue
template <typename Item>
bool QueueTP<Item>::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node(item);
	// on failure, new throws std::bad_alloc exception
	items++;
	if (front == nullptr)   // if queue is empty
		front = add;        // plac item at front
	else              
		rear->next = add;   // else place at rear
	rear = add;           // have rear point to new node
	return true;
}

// Place front item into item variable and remove from queue
template <typename Item>
bool QueueTP<Item>::dequeue(Item& item)
{
	if (front == nullptr)
		return false;
	item = front->item;     // set item to first item in queue
	items--;
	Node* temp = front;     // save location of first item
	front = front->next;    // reset front to next item
	delete temp;            // delete former first item
	if (items == 0)
		rear = nullptr;
	return true;
}

template <typename Item>
void QueueTP<Item>::QueueTP_test()
{
	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "Please enter your name. You will be served in the order of arrival.\n"
			"name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	
	cout << "The queue is full. Processing begins!\n";

	temp.clear();
	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";
	}

	cout << "Done\n";
}

#endif

