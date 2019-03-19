#include <iostream>
#include <string>
using namespace std;
/*
���ó�Ա����
����Ա����
���ñ��������õ�ʱ�������г�ʼ��,���ܶ����õĳ�Ա�����������µĳ�ʼ�����ǿ��Զ����õı����������¸�ֵ
	int a;
	int &b = a;
	b = 10;
const���εĳ�����ʼ���Ժ�������и���
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
		ma = src.ma;  //�����ý��и�ֵ
		mb = src.mb;
	}
private:
	int &ma;     //���ó�Ա����
	int mb;   
};
int main() {
	Test num1;
	cout << "===========================" << endl;
	num1.show();						//ma����data�Ķ�����������ڽ��������ma�����Чֵ
	Test num2(num1);                    //����Ĭ�ϵĿ������캯��
	cout << "===========================" << endl;
	num2.show();
	Test num3 = num1;                  //����Ĭ�ϵĿ������캯��
	cout << "===========================" << endl;
	num3.show();
	Test num4;
	cout << "===========================" << endl;
#if 0
	/*�������ó�Ա�����ͳ���Ա�����Ķ��󣬱��������Զ�������������غ���
	
	*/
	num4 = num1; //�޷����� ���� "Test::operator=(const Test &)" (����ʽ����) --������ɾ���ĺ���
#endif
	num4 = num1;
}

#if 0
//������֮�����Ϲ�ϵ
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
/*����ĵ���˳��
�������ͷ����ڴ�
�����Ա���󣨵��ó�Ա����Ĺ��캯����
�����Լ��Ĺ��캯��
�����ĵ���˳��
�����������ö���    ��������������õ�
��������˳��
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
		//_birthday(y, m, d);//��ʼ������������������ʵ�� ,��϶���ĳ�Ա�����Ѿ���ʼ����� 
	}
	Name(const Name &src) {     //����ȥ����
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
	//void operator = (const Name src)   ��Ϊ�����Ժ�Ͳ���Ҫ���ÿ������캯��
	void operator = (const Name src) {    
		cout << "operator = (const Name src)" << endl;
		delete[] _name;    //delateֻ��ȥ�ͷ��ڴ�
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
//���캯���ĳ�ʼ���б�
class Init {
public:
	/*��Ա������ʼ���б�ֻ���ƶ��˳�ʼ���ķ�ʽ��
	û��ָ����ʼ����˳�򣬳�ʼ����˳���뺯���Ķ����й�
	int ma;
	int mb;
	�ȳ�ʼ��ma,�ٳ�ʼ��mb
	Init(int data = 100):ma(mb),mb(data){}ma��һ����Чֵ
	Init(int data = 100):mb(ma),ma(data){}  ��ʼ��ma = 100��mb = 100
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