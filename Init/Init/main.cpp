#include <iostream>
#include <string>
using namespace std;
/*
引用成员变量
常成员变量
引用变量在引用的时候必须进行初始化,不能对引用的成员变量进行重新的初始化但是可以对引用的变量进行重新赋值
	int a;
	int &b = a;
	b = 10;
const修饰的常量初始化以后不允许进行更改
*/
class Test {
public:
	Test(int data = 100):ma(data),mb(data){
		cout << "Test(int data = 100)" << endl;
	}
	void show() {
		cout << "ma :" << ma << " mb:" << mb << endl;
	}
	void operator = (const Test &src) {
		cout << "operator = (const Test &src)" << endl;
		ma = src.ma;  //解引用进行赋值
		mb = src.mb;
	}
private:
	int &ma;     //引用成员变量
	int mb;   
};
int main() {
	Test num1;
	cout << "===========================" << endl;
	num1.show();						//ma引用data的对象的生存周期结束，因此ma输出无效值
	Test num2(num1);                    //调用默认的拷贝构造函数
	cout << "===========================" << endl;
	num2.show();
	Test num3 = num1;                  //调用默认的拷贝构造函数
	cout << "===========================" << endl;
	num3.show();
	Test num4;
	cout << "===========================" << endl;
#if 0
	/*存在引用成员变量和常成员变量的对象，编译器不自动产生运算符重载函数
	
	*/
	num4 = num1; //无法引用 函数 "Test::operator=(const Test &)" (已隐式声明) --它是已删除的函数
#endif
	num4 = num1;
}

#if 0
//类与类之间的组合关系
class Date {
public:
	Date(int y = 0, int m = 0, int d = 0) :_year(y),_mouth(m),_day(d){}
	~Date() {
		cout << "~Date()" << endl;
	}
	void show() {
		cout << " year : " << _year << " mouth : " << _mouth << " day : " << _day << endl;
	}
private:
	int _year;
	int _mouth;
	int _day;
};
/*构造的调用顺序：
对象类型分配内存
构造成员对象（调用成员对象的构造函数）
调用自己的构造函数
析构的调用顺序：
首先析构调用对象    其次在析构被调用的
函数析构顺序：
~Name()
~Date()
*/
class Name {
public:
	Name(){
		cout << "Name()" << endl;
		_name = new char[1];
		_name = '\0';
		_age = 0;
	}
	Name(const char *n, int a, int y , int m , int d ):_age(a),_birthday(y, m, d){
		cout << "Name(const char *n, int a )" << endl;
		_name = new char[strlen(n) + 1];
		memcpy(_name, n, strlen(n) + 1);
		//_birthday(y, m, d);//初始化不能在析构函数内实现 ,组合对象的成员对象已经初始化完成 
	}
	Name(const Name &src) {     //必须去引用
		cout << "Name(const Name &src)" << endl;
		_name = new char[strlen(src._name) + 1];
		memcpy(_name, src._name, strlen(src._name) + 1);
		_age = src._age;
		_birthday = src._birthday;
	}
	~Name() {
		cout << "~Name()" << endl;
		delete[] _name;
		_name = NULL;
	}
	void show() {
		cout << "show()" << endl;
		cout << " name : " << _name << " age : " << _age << endl;
		_birthday.show();
	}
	//void operator = (const Name src)   改为引用以后就不需要调用拷贝构造函数
	void operator = (const Name src) {    
		cout << "operator = (const Name src)" << endl;
		delete[] _name;    //delate只是去释放内存
		_name = NULL;
		_name  = new char[strlen(src._name) + 1];
		memcpy(_name, src._name, strlen(src._name) + 1);
		_age = src._age;
		_birthday = src._birthday;
	}
private:
	char *_name;
	int _age;
	Date _birthday;
};
int main() {
	Name person1;
	cout << "===========================" << endl;
	Name person2("liming", 23, 2019, 1, 1);
	cout << "===========================" << endl;
	//person1.show();
	cout << "===========================" << endl;
	person2.show();
	cout << "===========================" << endl;
	person1 = person2;
	cout << "===========================" << endl;
	person1.show();
}
#endif

#if 0
//构造函数的初始化列表
class Init {
public:
	/*成员函数初始化列表只是制定了初始化的方式，
	没有指定初始化的顺序，初始化的顺序与函数的定义有关
	int ma;
	int mb;
	先初始化ma,再初始化mb
	Init(int data = 100):ma(mb),mb(data){}ma是一个无效值
	Init(int data = 100):mb(ma),ma(data){}  初始化ma = 100，mb = 100
	*/
	Init(int data = 100):ma(mb),mb(data){}
	~Init() {
		cout << "~Init() " << endl;
	}
	void show() {
		cout << "ma :" << ma << " mb:" << mb << endl;
	}
private:
	int ma;
	int mb;
};
int main() {
	Init num1;
	num1.show();
}
#endif