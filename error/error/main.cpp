#include <iostream>
#include <string>
using namespace std;
/*
1���쳣�����Ժ��׳�����Ӧcatch�����������Ժ������Լ�������
2��
try   �ѿ��ܷ�����catch�鴦��
throw  �׳��쳣����
catch   �����쳣�����
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
			//������������
			cin >> a >> b >> c;
			if (a <= 0 || b <= 0 || c <= 0)
			{
				throw "input is invalid";
			}
			else {
				break;
			}
			//try throw�Ժ�Ĵ��벻ִ��
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