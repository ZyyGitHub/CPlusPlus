#include <iostream>
using namespace std;
/*
成员方法（函数）
普通成员方法：
1、调用的时候必须依赖一个类进行调用
2、能访问私有和保护的成员变量
3、类的作用域
静态成员方法：静态成员方法主要处理类之间的共有信息
1、属于累的作用域
2、用于访问静态成员函数和静态成员变量，访问不依赖类
常态成员方法：
1、调用的时候必须依赖一个类进行调用
2、能访问私有和保护的成员变量
3、类的作用域
4、只能访问成员不能修饰成员（只能调用常方法）
5、常量对象不能调用普通长远函数
*/
//_num去记录Counter创建的次数
#if 0
class Counter {
public:
	Counter():_counter(0),_num(0){
		_num++;
	}
	void show() {    //this 指针的形式： Counter * const this   表明this不能指向其他的地址
		cout << "show num:" << _num << endl;
	}
	void show() const{    //常量方法   this指针的形式： const Counter * const this 既不能修改值也不能修改地址
		cout << "show num:" << _num << endl;
	}
private:
	int _counter;
	int _num;   
};
#if 0
class Counter {
public:
	Counter() :_counter(0) {
		_num++;
	}
	static void show() {    //静态成员方法因为不依赖对象，因此不能调用成员方法
		cout << "show num:" << _num << endl;
	}
private:
	int _counter;
	static int _num;       //静态成员函数
};
int Counter::_num = 0;   //静态常量初始化在类外
#endif
int main() {
	Counter c1;
	Counter c2;
	Counter c3;
	const Counter c4;
	c4.show();
	return 0;
}
#endif

/*
成员方法的返回值
1、<= 4字节 通过寄存器带出来
2、>4 <=8 字节 通过两个寄存器带出来
3、>8 字节 通过产生临时量，此时返回值太大，寄存器已经没有足够的内存存放它
返回值得类型:
1、内置类型：char short int float double
返回内置类型的时候，产生的都是寄存器的立即数
2、返回指针：char * short* int* float* double*   
返回值是指针的时候需要用一个指针去接收地址
3、返回引用：char& short& int& float& double&    
引用返回的是一个地址，接收时候自动解引用不能利用指针进行接收
cosnt引用产生临时变量
4、自定义类型
struct union enum class（无构造函数）


引用和指针的底层实现是一样的
*/
 typedef struct node {
	int data;
} node;
class test {
public:
	test(int v = 0,double d = 0.0, int n = 0):_value(v),_data(d){
		_node.data = n;
	}
	int getval() {
		return _value;
/*00FB1F5D  mov         eax,dword ptr [this]  
00FB1F60  mov         eax,dword ptr [eax] */
	}
	double* getdata() {
		return &_data;
	}
	int& getnode()
	{
		return _node.data;
	}
	double& doubledata()
	{
		return _data;
	}
private:
	int _value;
	double _data;
	node _node;
};
int main()
{
	test t(10,3.3,9);
	int t1 = t.getval();
	//int *t2 = t.getval();   //getval利用寄存器返回的值不能用于地址
	const int &t3 = t.getval();  //getval利用寄存器返回的值不能用于地址,添加const将返回的值产生临时量
	double *d1 = t.getdata();
	double * const &d2 = t.getdata();
	int n1 = t.getnode();
	int *n2 = &t.getnode();
	int &n3 = t.getnode();
	double b1 = t.doubledata();
	double &b2 = t.doubledata();
	double *b3 = &t.doubledata();
	cout << t1 << t3 << d1 << d2 << n1 << n2 << endl;
}