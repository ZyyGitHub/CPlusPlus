#include <iostream>
#include <string>
using namespace std;
/*
1、异常发生以后，抛出的相应catch处理，处理完以后程序可以继续运行
2、
try   把可能发生的catch块处理
throw  抛出异常对象
catch   处理异常代码块
*/
void func() {
	bool running = false;

	while (!running)
	{
		int a = 0;
		int b = 0;
		int c = 0;
		try
		{
			//变量的作用域
			cin >> a >> b >> c;
			if (a <= 0 || b <= 0 || c <= 0)
			{
				throw "input is invalid";
			}
			else {
				break;
			}
			//try throw以后的代码不执行
		}
		
		catch (const int err) {
			cout << "int error" << endl;
		}
	}
}
int main(){
	func();
	try
	{
		func();
	}
	catch (const char *errstr)
	{
		cout << errstr << endl;
	}
}