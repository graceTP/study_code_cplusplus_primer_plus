#pragma once
#ifndef NON_TEMPLATE_FRIEND_H_
#define NON_TEMPPLATE_REIEND_H_  // 非模板友元：友元函数不是模板，只对特定实例化生效



#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend() {}
	HasFriend(const T& i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void reports(HasFriend<T> &);  // template parameter

	void HasFriend_test();
};

// each specialization has its own static data member ct
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void counts()
{
	cout << "int count: " << HasFriend<int>::ct << "; ";
	cout << "double count: " << HasFriend<double>::ct << endl;
}

//
void reports(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

void reports(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}

template <typename T>
void HasFriend<T>::HasFriend_test()
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared: ";
	counts();

	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared: ";
	counts();

	HasFriend<double> hfib(10.5);
	cout << "After hfib declared: ";
	counts();

	reports(hfi1);
	reports(hfi2);
	reports(hfib);

	cout << "Done" << endl;
}

#endif NON_TEMPLATE_FRIEND_H_

