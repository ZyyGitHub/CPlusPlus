#include <iostream>
#include <typeinfo>
#include <string.h>
using namespace std;

/*
ģ�壺
����ģ��
template<class/typename T>
ģ��ʵ��������ʽʵ��������ʽʵ������
ģ�庯��ͨ��ʵ�����γ�ģ�庯��
ģ�����Ͳ���
ģ������Ͳ���
ģ���ʵ������
ģ���ʵ������
ģ�����������ר�л���
ģ�庯��������
��ģ��
*/

/*���Ա�����ͳ�Ա����*/
/*����ģ��   ����ģ��������   �Ǻ���ģ�� ����*/
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
	bool result = compare<int>(10, 30);    //��ʽʵ������ָ��ģ������
	/*ģ��ֻ��ʡ��д�Ĵ��룬û��ʡ�������Ĵ�����������ģ�����ݵ�������һ��ģ�庯��
	bool compare<int>(int a, int b) {
	return a > b;
	}*/
	bool res1 = compare(10, 20);      //ģ���ʵ�����ݣ�ͨ��ʵ���Ƶ����βκ�ģ������
	bool res2 = compare<>(15, 10);
	cout << result << endl;
	cout << res1 << endl;
	cout << res2 << endl;
	return 0;
}