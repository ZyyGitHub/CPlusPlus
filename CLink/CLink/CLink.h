#pragma once
#include <iostream>
#include <string>
using namespace std;

//除编译器生成的方法以外，其他方法的模板完全可以代替普通的成员方法
template <typename T>
class CLink
{
public:
	CLink();
	~CLink();
	//普通的成员方法
	void insertHead(const T &val);    //应用const的含义
	//成员方法的模板
	template <typename E>            
	bool query(const E &val);
	//成员方法的特例化只能在类内实现
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
//Node的构造函数类外实现
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
//一个模板名称对应一个参数名称
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
