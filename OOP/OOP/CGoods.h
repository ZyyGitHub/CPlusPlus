#pragma once
#include <iostream>
using namespace std;
/*   
class��struct������:
��C++��class��struct
class Node{
	Ĭ����˽�еģ�private��
}��
class Node{
	Ĭ���ǹ��еģ�public��
}��
struct ��C��C++�е�����
��C++��struct�����Ժ� struct Node{}��   ֱ�ӿ���Node node
��C��struct�����Ժ� struct Node{}��   ����struct Node node  ��struct ����ӣ�
*/
class CGoods                                
{
public:
	CGoods()												//Ĭ�Ϲ��캯��
	{														//����ʵ��  -����������
		cout << this << endl;
		cout << "CGoods()" << endl;
		_pname = new char(1);
		_pname = '\0';
		_amount = 0;
		_price = 0.0;
	}
	CGoods(const char *name, int amount, double price);		//����Ĭ�Ϲ��캯��
	CGoods(CGoods const &src);								//���ؿ������캯��
	void operator = (CGoods const &src);					//���ظ�ֵ���������          
	void show();
	~CGoods();												//Ĭ����������   �������������������Բ��ܽ�������
private:
	char *_pname;
	int _amount;
	double _price;
};

