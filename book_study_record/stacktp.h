#pragma once
#ifndef STACKTP_H_
#define STACKTP_H_

#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;

template <typename Type>
class StackTP
{
private:
	enum { MAX = 10 }; // constant specific to class
	Type items[MAX];   // holds stack items
	int top;           // index for top stack item
public:
	StackTP();
	virtual ~StackTP();
	bool isempty();
	bool isfull();
	bool push(const Type & item);  // add item to stack
	bool pop(Type& item);          // pop top into item

	void StackTP_test();
};

template <typename Type>
StackTP<Type>::StackTP()
{
	top = 0;
}

template <typename Type>
StackTP<Type>::~StackTP()
{
	cout << "\nobject destruction\n\n";
}

template <typename Type>
bool StackTP<Type>::isempty()
{
	return top == 0;
}

template <typename Type>
bool StackTP<Type>::isfull()
{
	return top == MAX;
}

template <typename Type>
bool StackTP<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <typename Type>
bool StackTP<Type>::pop(Type& item)	
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

template <typename Type>
void StackTP<Type>::StackTP_test()
{
	cout << "\n\n\n-----------StackTP_test start-------------" << "\n";
	StackTP<std::string> st;
	char ch;
	std::string po;
	cout << "Please enter A to add a perchase order, \n"
		<< "P to process a PO, or Q to quit.\n";

	/*
	while (cin >> ch && std::toupper(static_cast<unsigned char>(ch)) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
	}
	详细步骤:
    假设用户输入 "A hello\n"：
	1.外层循环条件判断：
	  cin >> ch：跳过空白，读取 'A' 到 ch
	  toupper('A') != 'Q'：'A' != 'Q' → true
	  条件成立，进入循环体
	2.内层循环执行：
	  while (cin.get() != '\n')：读取并丢弃 " hello"（直到遇到换行符）
	  遇到 '\n' 时，内层循环结束
      注意：换行符也被读取并丢弃了
    3.回到外层循环开始：
	  继续等待下一个输入
	**/

	while (cin >> ch && std::toupper(static_cast<unsigned char>(ch)) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'a':
		case 'A':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "Stack already full\n";
			else
				st.push(po);
			break;
		case 'p':
		case 'P':
			if (st.isempty())
				cout << "Stack already empty\n";
			else {
				st.pop(po);
				cout << "PO #" << po << " popped\n";
				break;
			}
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to proces a PO, or Q to quit.\n";
	}
	cout << "Bye\n";
	cout << "-----------StackTP_test end-------------" << "\n\n";
}

#endif // STACKTP_H_

