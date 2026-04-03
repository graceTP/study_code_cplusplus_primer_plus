#include <iostream>
using std::cout;
#include "StringBad.h"

void callme1(StringBad &); // pass by reference
void callme2(StringBad); // pass by value

int main()
{
	StringBad headline1("Celery Stalks at Midnight");
	StringBad headline2("Lettuce Prey");
	StringBad sports("Spinach Leaves Bowl for Dollars");
	cout << "------------------------" << "\n";

	cout << "headline1: " << headline1 << "\n";
	cout << "headline2: " << headline2 << "\n";
	cout << "sports: " << sports << "\n";
	cout << "------------------------" << "\n";

	callme1(headline1);
	cout << "headline1: " << headline1 << "\n";
	cout << "------------------------" << "\n";

	callme2(headline2); // 值传递会导致释放headline2.str指针所指向的内存，导致后续访问headline2.str指针时出现未定义行为
	cout << "headline2: " << headline2 << "\n";
	cout << "------------------------" << "\n";

	cout << "Initialize one object to another:\n";
	StringBad sailor = sports;
	cout << "sailor: " << sailor << "\n";
	cout << "Assign one object to another:\n";
	StringBad knot;
	knot = headline1;
	cout << "knot: " << knot << "\n";
	cout << "Exiting the block.\n";

	cout << "End of main()\n";
	return 0;
}

void callme1(StringBad &rsb)
{
	cout << "String passed by reference:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	// 采用值传递的方式传入类对象，会先调用类复制构造函数产生一个临时对象，临时对象的成员变量会与实参对象的成员变量相同（浅复制），并将该临时对象传入函数内部使用
	// 然后在函数返回后调用类析构函数将该临时对象内存释放
	// 在当前例子中，sb为调用复制构造函数产生的临时对应，sb的str指针会与headline2的str指针相同（浅复制），当sb在函数返回后被销毁时，会调用析构函数释放sb.str指针所指向的内存，此时headline2.str指针也被释放了，导致后续访问headline2.str指针时出现未定义行为
	// 当前例子中，类内没有定义复制构造函数和赋值运算符重载函数，因此编译器会自动生成默认的复制构造函数和赋值运算符重载函数，这些默认的函数会进行浅复制，即仅复制指针的值，而不会复制指针所指向的内存内容，这就导致了上述的问题
	cout << "String passed by value:\n";
	cout << "    \"" << sb << "\"\n";
}