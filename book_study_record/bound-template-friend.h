#pragma once
#ifndef BOUND_TEMPLATE_FRIEND_H_
#define BOUND_TEMPLATE_FRIEND_H_ // 约束模板友元,一对一约束友元：友元函数的模板参数与类的模板参数一一对应约束

#include <iostream>
using std::cout;
using std::endl;

// template prototypes
template <typename T> void counts();
template <typename T> void report(T &);

template <typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT() {}
	HasFriendT(const TT& i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>&);

	void HasFriendT_test();
};

template <typename TT>
int HasFriendT<TT>::ct = 0;

// template friend functions definitions
template <typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
	cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T& hf)
{
	cout << hf.item << endl;
}

template <typename TT>
void HasFriendT<TT>::HasFriendT_test()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);

	report(hfi1);  // generate report(HasFriendT<int> &)
	report(hfi2);  // generate report(HasFriendT<int> &)
	report(hfdb);  // generate report(HasFriendT<double> &)

	cout << "counts<int>() output:\n";
	counts<int>();
	cout << "counts<double>() output:\n";
	counts<double>();

	cout << "Done" << endl;
}

#endif // !BOUND_TEMPLATE_FRIEND_H_


