#pragma once
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include<iostream>
#include<cstdlib>

using std::cout;

template <typename T, int n> // T为类型参数，n为非类型(no-type)参数或表达式(expression)参数,int指出n的类型为int
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP();
	explicit ArrayTP(const T& v);
	virtual T & operator[] (int i);
	virtual T operator[] (int i) const;
	void ArrayTP_test();
};

template<typename T, int n>
ArrayTP<T, n>::ArrayTP()
{
	for (int i = 0; i < n; i++)
		ar[i] = 0;
}

template <typename T, int n>
ArrayTP<T, n>::ArrayTP(const T & v)
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}

template <typename T, int n>
T & ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i
			<< " is out of range\n";
		std::exit(EXIT_FAILURE);
	}

	cout << "call T& function\n";
	return ar[i];
}

template<typename T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i
			<< " is out of range\n";
		std::exit(EXIT_FAILURE);
	}

	cout << "call T function";
	return ar[i];
}

template<typename T, int n>
void ArrayTP<T, n>::ArrayTP_test()
{
	// 编译器根据对象的 const 属性选择版本：
	//ArrayTP<int, 5> a;           // 非常量对象
	//const ArrayTP<int, 5> ca;    // 常量对象

	//a[0];   // 调用 T& operator[] (非const版本) 
	//ca[0];  // 调用 T operator[] (const版本)
	ArrayTP<int, 5> a;

	for (int i = 0; i < 5; ++i)
	{
		cout << "set a[i] = " << i * 2 << '\n';
		a[i] = i * 2;
	}
	cout << std::endl;

	for (int i = 0; i < 5; ++i)
		cout << "    " << a[i] << '\n';  // 这里的a[i]会调用T& operator[]而不是 T operator[]
	cout << std::endl;
}

#endif // ARRAYTP_H_

