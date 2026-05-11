#pragma once
#ifndef UNBOUND_TEMPLATE_FRIEND_H_
#define UNBOUND_TEMPLATE_FRIEND_H_

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend() {}
	ManyFriend(const T& i) : item(i) {}
	template <typename C, typename D> friend void show2(C & c, D & d);

	void ManyFriend_test();
};

template <typename C, typename D> void show2(C & c, D & d)
{
	cout << c.item << ", " << d.item << endl;
}

template <typename T>
void ManyFriend<T>::ManyFriend_test()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);

	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);

	cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);

	cout << "Done" << endl;
}


#endif

