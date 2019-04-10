#include <iostream>
#include <typeinfo>
#include <string.h>
using namespace std;

/*
模板：
函数模板
template<class/typename T>
模板实例化（显式实例化，隐式实例化）
模板函数通过实例化形成模板函数
模板类型参数
模板非类型参数
模板的实参推演
模板的实参推演
模板的特例化（专有化）
模板函数的重载
类模板
*/

/*类成员函数和成员方法*/
/*函数模板   函数模板特例化   非函数模板 共存*/
template <typename T>
bool compare(T a, T b) {
	cout << "compare<typename T>(T a, T b)" << endl;
	cout << typeid(T).name() << endl;
	return a > b;
}
template <>
bool compare<int>(int a, int b) {
	cout << "compare<int>(int a, int b)" << endl;
	return a < b;
}
bool compare(int a, int b) {
	cout << "compare(int a, int b)" << endl;
	return a > b;
}
int main() {
	bool result = compare<int>(10, 30);    //隐式实例化，指定模板类型
	/*模板只是省了写的代码，没有省编译器的代码量，函数模板会根据调用生成一个模板函数
	bool compare<int>(int a, int b) {
	return a > b;
	}*/
	bool res1 = compare(10, 20);      //模板的实参推演，通过实参推导出形参和模板类型
	bool res2 = compare<>(15, 10);
	cout << result << endl;
	cout << res1 << endl;
	cout << res2 << endl;
	return 0;
}