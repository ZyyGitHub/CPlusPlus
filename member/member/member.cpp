#include <iostream>
using namespace std;
/*
��Ա������������
��ͨ��Ա������
1�����õ�ʱ���������һ������е���
2���ܷ���˽�кͱ����ĳ�Ա����
3�����������
��̬��Ա��������̬��Ա������Ҫ������֮��Ĺ�����Ϣ
1�������۵�������
2�����ڷ��ʾ�̬��Ա�����;�̬��Ա���������ʲ�������
��̬��Ա������
1�����õ�ʱ���������һ������е���
2���ܷ���˽�кͱ����ĳ�Ա����
3�����������
4��ֻ�ܷ��ʳ�Ա�������γ�Ա��ֻ�ܵ��ó�������
5�����������ܵ�����ͨ��Զ����
*/
//_numȥ��¼Counter�����Ĵ���
#if 0
class Counter {
public:
	Counter():_counter(0),_num(0){
		_num++;
	}
	void show() {    //this ָ�����ʽ�� Counter * const this   ����this����ָ�������ĵ�ַ
		cout << "show num:" << _num << endl;
	}
	void show() const{    //��������   thisָ�����ʽ�� const Counter * const this �Ȳ����޸�ֵҲ�����޸ĵ�ַ
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
	static void show() {    //��̬��Ա������Ϊ������������˲��ܵ��ó�Ա����
		cout << "show num:" << _num << endl;
	}
private:
	int _counter;
	static int _num;       //��̬��Ա����
};
int Counter::_num = 0;   //��̬������ʼ��������
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
��Ա�����ķ���ֵ
1��<= 4�ֽ� ͨ���Ĵ���������
2��>4 <=8 �ֽ� ͨ�������Ĵ���������
3��>8 �ֽ� ͨ��������ʱ������ʱ����ֵ̫�󣬼Ĵ����Ѿ�û���㹻���ڴ�����
����ֵ������:
1���������ͣ�char short int float double
�����������͵�ʱ�򣬲����Ķ��ǼĴ�����������
2������ָ�룺char * short* int* float* double*   
����ֵ��ָ���ʱ����Ҫ��һ��ָ��ȥ���յ�ַ
3���������ã�char& short& int& float& double&    
���÷��ص���һ����ַ������ʱ���Զ������ò�������ָ����н���
cosnt���ò�����ʱ����
4���Զ�������
struct union enum class���޹��캯����


���ú�ָ��ĵײ�ʵ����һ����
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
	//int *t2 = t.getval();   //getval���üĴ������ص�ֵ�������ڵ�ַ
	const int &t3 = t.getval();  //getval���üĴ������ص�ֵ�������ڵ�ַ,���const�����ص�ֵ������ʱ��
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