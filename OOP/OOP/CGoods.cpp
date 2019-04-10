#include "CGoods.h"              
#include <string>
#include <iostream>
using namespace std;


/*
����ʵ�ֺ���������ʵ�ֺ���������
������ʵ�ֺ����Զ��������������inline������������
������������������һЩ���⺯������������չ��ȡ�������ĵ��ý�ʡ�������ô����Ķ���ʱ�俪֧��
		  �����������ú���ʱ����ɵĹ��е�ʱ�����ķ���
�����������ɴ��κ꣨Macros����Դ�뼶ʵ�֣����Ĳ��
	�겻ִ�����͵ļ�飨ֻ�Ǽ򵥵��ı��滻������������Ҳ�����м�飬����������Ҫ���м��
	����������������ʹ���������߲�����
	ͨ�����������ȳ�������߸��������һ���ض��ĺ����Ƿ���ʽ���������չ
��������ʹ�ÿ��ܴ�����ӱ���ʱ��  
*/
#if  0     //��������ʵ��
CGoods::CGoods()
{
	cout << this << endl;
	cout << "CGoods()" << endl;
	_pname = new char(1);
	_pname = '\0';
	_amount = 0;
	_price = 0.0;
}
#endif
/*
const ���÷���  �������Ա���߱�����ĳֵ�Ǳ��ֲ����
	const int num = 10;  //const data num���ܱ��޸�
	num = 12;  (����)
const ����ָ��
const char *name   ��     char * const name ����
	const int num = 10;
	const int tmp = 10;
	const int * a = &num;
	a = &tmp;
	*a = tmp; ������
	constλ��*������ʾָ����ָ���������һ���������ܱ��޸ģ���ָ��ı�����һ������������ָ���������ڴ浥Ԫ
	int num = 10;
	int tmp = 10;
	int * const b = &num;
	b = &tmp;  (����)
	*b = 20;
	constλ��*���Ҳ��ʾָ����ָ���������һ���������Ա��޸ģ�ָ�뱾����һ�����������ܱ��޸�ָ���������ڴ浥Ԫ(����ͨ�������ý����޸�)
	cosnt int num = 10;
	int * const b = &num;      ������
	const int * const b = &num;�����ԣ�
	const �������ܸ�ֵ�� const ������ָ��
const���γ�Ա������
	(1)const���εĳ�Ա���������޸��κεĳ�Ա����(mutable���εı�������)
	(2)const��Ա�������ܵ��÷�const��Ա��������Ϊ��const��Ա�������Ի��޸ĳ�Ա����
*/
CGoods::CGoods(const char *name, int amount, double price)
{
	cout << this << endl;
	cout << "CGoods(char *name, int amount, double price)" << endl;
	/*
	strlen �� sizeof������:
	strlen:�ַ����ĳ��ȣ���"\0"Ϊ�ַ�������־
	sizeof�������������ռ�õ�ʵ���ڴ�ռ��ڵĴ�С
	
	*/
#if 0
	cout << "sizeof(name) :"<< sizeof(name) << endl;
	cout << "strlen(name) :" << strlen(name) << endl;
#endif
	_pname = new char[strlen(name) + 1];           
	//strcpy(_pname, name);                        //vs׼������strcpy   ��Ҫ�����ļ��м�#pragma warning(disable:4996)ʹ��
	memcpy(_pname, name, strlen(name) + 1);       //void *memcpy(void *dest, const void *src, size_t n);   �ڴ濽������
	_amount = amount;
	_price = price;
}

CGoods::CGoods(const CGoods &src)
{
	cout << "src�� " << &src << "->" << "this�� " << this << endl;
	cout << "CGoods(CGoods const &src)" << endl;
	_pname = new char[strlen(src._pname) + 1];
	//strcpy(_pname, src._pname);
	memcpy(_pname, src._pname, strlen(src._pname) + 1);
	_amount = src._amount;
	_price = src._price;

}

void CGoods::operator = (const CGoods &src)
{
	if (this == &src) {
		return;
	}
	cout << "src��" << &src << "->" << "this��" << this << endl;
	cout << "operator = (CGoods const &src)" << endl;
	delete[] _pname;
	_pname = NULL;
	_pname = new char[strlen(src._pname) + 1];
	//strcpy(_pname, src._pname);
	memcpy(_pname, src._pname, strlen(src._pname) + 1);
	_amount = src._amount;
	_price = src._price;
}
void CGoods::show() {
	cout << "name: " << _pname << endl;
	cout << "amount:" << _amount << endl;
	cout << "price:" << _price << endl;
}

CGoods::~CGoods()
{
	cout << "~CGoods()" << endl;
	delete[] _pname;
	_pname = NULL;
}


