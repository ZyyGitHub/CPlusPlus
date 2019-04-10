#include "CGoods.h"              
#include <string>
#include <iostream>
using namespace std;


/*
类外实现函数和类体实现函数的区别：
类体内实现函数自动被编译器处理成inline（内联）函数
内联函数：编译器对一些特殊函数进行内联扩展（取代函数的调用节省函数调用带来的额外时间开支）
		  用于消除调用函数时所造成的固有的时间消耗方法
内联函数（由带参宏（Macros）在源码级实现）与宏的差别：
	宏不执行类型的检查（只是简单的文本替换），正常参数也不进行检查，而内联函数要进行检查
	内联函数可以随意使其内联或者不内联
	通常，编译器比程序设计者更清楚对于一个特定的函数是否合适进行内联扩展
内联函数使用可能大大增加编译时间  
*/
#if  0     //在类体内实现
CGoods::CGoods()
{
	cout << this << endl;
	cout << "CGoods()" << endl;
	_pname = new char(1);
	_pname = '\0';
	_amount = 0;
	_price = 0.0;
}
#endif
/*
const 的用法：  允许程序员告诉编译器某值是保持不变的
	const int num = 10;  //const data num不能被修改
	num = 12;  (错误)
const 修饰指针
const char *name   与     char * const name 区别：
	const int num = 10;
	const int tmp = 10;
	const int * a = &num;
	a = &tmp;
	*a = tmp; （错误）
	const位于*的左侧表示指针所指针的数据是一个常量不能被修改，而指针的本身是一个变量，可以指向其他的内存单元
	int num = 10;
	int tmp = 10;
	int * const b = &num;
	b = &tmp;  (错误)
	*b = 20;
	const位于*的右侧表示指针所指针的数据是一个变量可以被修改，指针本身是一个常量，不能被修改指向其他的内存单元(可以通过解引用进行修改)
	cosnt int num = 10;
	int * const b = &num;      （错误）
	const int * const b = &num;（可以）
	const 常量不能赋值给 const 保护的指针
const修饰成员函数：
	(1)const修饰的成员函数不能修改任何的成员变量(mutable修饰的变量除外)
	(2)const成员函数不能调用非const成员函数，因为非const成员函数可以会修改成员变量
*/
CGoods::CGoods(const char *name, int amount, double price)
{
	cout << this << endl;
	cout << "CGoods(char *name, int amount, double price)" << endl;
	/*
	strlen 和 sizeof的区别:
	strlen:字符串的长度，以"\0"为字符结束标志
	sizeof：分配的数组所占用的实际内存空间内的大小
	
	*/
#if 0
	cout << "sizeof(name) :"<< sizeof(name) << endl;
	cout << "strlen(name) :" << strlen(name) << endl;
#endif
	_pname = new char[strlen(name) + 1];           
	//strcpy(_pname, name);                        //vs准备弃用strcpy   需要在有文件中加#pragma warning(disable:4996)使用
	memcpy(_pname, name, strlen(name) + 1);       //void *memcpy(void *dest, const void *src, size_t n);   内存拷贝函数
	_amount = amount;
	_price = price;
}

CGoods::CGoods(const CGoods &src)
{
	cout << "src： " << &src << "->" << "this： " << this << endl;
	cout << "CGoods(CGoods const &src)" << endl;
	_pname = new char[strlen(src._pname) + 1];
	//strcpy(_pname, src._pname);
	memcpy(_pname, src._pname, strlen(src._pname) + 1);
	_amount = src._amount;
	_price = src._price;

}

void CGoods::operator = (const CGoods &src)
{
	if (this == &src) {
		return;
	}
	cout << "src：" << &src << "->" << "this：" << this << endl;
	cout << "operator = (CGoods const &src)" << endl;
	delete[] _pname;
	_pname = NULL;
	_pname = new char[strlen(src._pname) + 1];
	//strcpy(_pname, src._pname);
	memcpy(_pname, src._pname, strlen(src._pname) + 1);
	_amount = src._amount;
	_price = src._price;
}
void CGoods::show() {
	cout << "name: " << _pname << endl;
	cout << "amount:" << _amount << endl;
	cout << "price:" << _price << endl;
}

CGoods::~CGoods()
{
	cout << "~CGoods()" << endl;
	delete[] _pname;
	_pname = NULL;
}


