#pragma once
#include <iostream>
using namespace std;
/*   
class与struct的区别:
在C++中class和struct
class Node{
	默认是私有的（private）
}；
class Node{
	默认是公有的（public）
}；
struct 在C和C++中的区别：
在C++中struct定义以后 struct Node{}；   直接可以Node node
在C中struct定义以后 struct Node{}；   必须struct Node node  （struct 必须加）
*/
class CGoods                                
{
public:
	CGoods()												//默认构造函数
	{														//体内实现  -》内联函数
		cout << this << endl;
		cout << "CGoods()" << endl;
		_pname = new char(1);
		_pname = '\0';
		_amount = 0;
		_price = 0.0;
	}
	CGoods(const char *name, int amount, double price);		//重载默认构造函数
	CGoods(CGoods const &src);								//重载拷贝构造函数
	void operator = (CGoods const &src);					//重载赋值运算符函数          
	void show();
	~CGoods();												//默认析构函数   析构函数不带参数所以不能进行重载
private:
	char *_pname;
	int _amount;
	double _price;
};

