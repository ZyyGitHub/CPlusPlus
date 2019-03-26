#pragma once
#include <iostream>
#include <string>
using namespace std;

//�����������ɵķ������⣬����������ģ����ȫ���Դ�����ͨ�ĳ�Ա����
template <typename T>
class CLink
{
public:
	CLink();
	~CLink();
	//��ͨ�ĳ�Ա����
	void insertHead(const T &val);    //Ӧ��const�ĺ���
	//��Ա������ģ��
	template <typename E>            
	bool query(const E &val);
	//��Ա������������ֻ��������ʵ��
	template <>
	bool query<string>(const string &val)
	{
		cout << "query<string>(const string &val)" << endl;
		Node *pcur = mphead->mnext;
		while (pcur != NULL) {
			if (strcmp(pcur->mdata, val) == 0)
			{
				return true;
			}
			pcur = pcur->mnext;
		}
		return false;
	}
	void deleteNode(const T val);
	void show();
private:
	class Node {
	public:
		Node(T data = T()):mdata(data) {
			mnext = NULL;
		}
		T mdata;
		Node *mnext;
	};
	Node *mphead;
};
#if  0
//Node�Ĺ��캯������ʵ��
template <typename T>
CLink<T>::Node::Node(int data):mdata(data),mnext(NULL){}
#endif

template <typename T>
CLink<T>::CLink()
{
	mphead = new Node();
}
template <typename T>
CLink<T>::~CLink()
{
	Node *pcur = mphead;
	while (pcur != NULL) {
		mphead = mphead->mnext;
		delete pcur;
		pcur = mphead;
	}
}
template <typename T>
void CLink<T>::insertHead(const T &val)
{
	Node *ptmp = new Node(val);
	ptmp->mnext = mphead->mnext;
	mphead->mnext = ptmp;
}
//һ��ģ�����ƶ�Ӧһ����������
template <typename T>    
template <typename E>
bool CLink<T>::query(const E &val)
{
	cout << "query(const T &val)" << endl;
	Node *pcur = mphead->mnext;
	while (pcur!=NULL) {
		if (pcur->mdata == val)
		{
			return true;
		}
		pcur = pcur->mnext;
	}
	return false;
}

template <typename T>
void CLink<T>::deleteNode(const T val)
{
	Node *ppre = mphead;
	Node *pcur = mphead->mnext;
	while (pcur != NULL) {
		if (pcur->mdata == val) {
			ppre->mnext = pcur->mnext;
			delete pcur;
			return ;
		}
		ppre = pcur;
		pcur = pcur->mnext;
	}
}
template <typename T>
void CLink<T>::show()
{
	Node *pcur = mphead->mnext;
	while (pcur != NULL) {
		cout << pcur->mdata  << " ";
		pcur = pcur->mnext;
	}
	cout << endl;
}
