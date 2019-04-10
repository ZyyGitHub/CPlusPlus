#include "CGoods.h"


//不应该返回局部对象的引用
//指针和引用的对象周期
CGoods GetGood()    //返回临时对象调用拷贝构造函数    
{
	CGoods tmpgood("apple", 20, 1.2);   //构造函数
	return tmpgood;  //产生临时对象，拷贝构造对象
}
void test(CGoods *g) {
	cout << "===========test(CGoods *g)" << endl;
	g->show();
}
int main() {
	test(&CGoods("shangpin g", 10, 12.5));
	cout << "===========================" << endl;

	/*
	成员函数可以被看作类作用域外的全局函数，不在对象分配的空间里
	只有虚函数才会在类对象里有一个指针，存放虚函数的相关地址信息
	*/
	cout << "sizeof(CGoods):" << sizeof(CGoods) << endl;
	CGoods good1;  
	cout << "sizeof(good1):" << sizeof(good1) << endl;
	//调用不带参数的构造函数
	cout << "===================================good1" << endl;

	CGoods good2("shangpin2", 10, 12.5);                    //调用带参数的构造函数
	cout << "sizeof(good2):" << sizeof(good2) << endl;
	cout << "===================================good2" << endl;

	/*拷贝构造函数
	**当对象产生除内存以外的内存分配时，可能发生浅拷贝，因此需要自定义拷贝构造函数进行深拷贝
	*/
	CGoods good3(good2); 
	cout << "===================================good3" << endl;

	/*
	对象进行赋值时，发生发生浅拷贝，产生内存泄漏问题
	防止对象的自赋值；
	释放当前资源
	重新开辟空间
	拷贝成员变量
	*/
	good1 = good2;
	cout << "===================================good1 = good2" << endl;

	good2 = good2;
	cout << "===================================good2 = good2" << endl;

	//用临时对象构建同类型的新对象，此时临时对象不生成，用构造临时对象的方式直接构造对象
	CGoods good4 = CGoods("shangpin4", 12, 12.6);
	cout << "===================================good4 = CGoods(shagnpin4, 12, 22.2);" << endl;

	//临时对象赋值产生临时对象，当语句结束时释放临时对象的资源（临时对象的生存周期-》临时对象所在语句），调用析构函数
	CGoods good5;
	good5 = CGoods("shangpin5", 12, 12.6);
	cout << "===================================CGoods(shangpin5, 12, 12.6);" << endl;

	CGoods good6;
	good6 = GetGood();   //调用赋值运算符重载函数
	cout << "===================================good6 = GetGood();" << endl;

	CGoods *good7 = new CGoods("shangpin7", 12, 12.6);
	CGoods &good8 = *new CGoods("shangpin8", 12, 12.6);
#if 0
	//临时对象的生存周期
	CGoods *good7 = CGoods("shangpin7", 12, 12.6);
	CGoods &good7 = CGoods("shangpin7", 12, 12.6);
#endif
	cout << "===========================" << endl;
	good1.show();
	good2.show();
	good3.show();
	good4.show();
	good5.show();
	good6.show();
	good7->show();
	good8.show();
	cout << "===================================show()" << endl;
	good1.~CGoods();                   //析构函数可以自己进行调用，构造函数不能自己调用系统自动进行调用
	cout << "===================================good1.~CGoods()" << endl;
	const int num = 10;
	return 0;
}