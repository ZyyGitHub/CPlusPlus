#include "arrList.h"


/*
	int _curLen;
	int _maxLen;
	T *_aList;
	int _position;
*/

/*
模板的调用要看到模板的定义
模板的实例化实在编译阶段进行的，编译阶段每一个cpp文件都是单独进行编译
*/
#if 0
template <typename T>
arrList<T>::arrList(const int size):_curLen(0),_maxLen(size),_position(0)
{
	cout << "arrList(const int size)" << endl;
	_aList = new T[_maxLen];
}

template <typename T>
arrList<T>::~arrList()
{
	cout << "~arrList()" << endl;
	delete[] _aList;
	_aList = NULL;
}

template <typename T>
void arrList<T>::clearArr()    //将顺序表中的内容清零，成为空表
{
	cout << "clearArr()" << endl;
	delete[] _aList;
	_aList = new T[_maxLen];
	_curLen = _position = 0;
}

template <typename T>
int arrList<T>::lengthArr()   //放回当前的实际长度
{
	cout << "lengthArr()" << endl;
	return _curLen;
}

template <typename T>
bool arrList<T>::fullArr() 
{
	cout << "fullArr()" << endl;
	return _curLen == _maxLen;
}

template <typename T>
bool arrList<T>::apendArr(const T value)   //在表尾添加元素V
{
	cout << "apendArr(const T value)" << endl;
	if (_curLen >= _maxLen) {
		cout << "This list is overflow" << endl;
		return false;
	}
	_aList[++_curLen] == value;
}
template <typename T>
bool arrList<T>::insertArr(const int p, const T value)   //插入元素
{
	cout << "insertArr(const int p, const T value)" << endl;
	if (_curLen >= _maxLen) {
		cout << "This list is overflow" << endl;
		return false;
	}
	if (p < 0 || p >= _curLen) {
		cout << "insert postion is illegal" << endl;
		return false;
	}
	for (_position = _curLen; _position > p; _position--)
	{
		_aList[_position] = _aList[_position - 1];
	}
	_aList[p] = value;
	_curLen++;
	return true;
}

template <typename T> 
bool arrList<T>::deleteArr(const int p)     //删除位置p上的元素
{
	cout << "deleteArr(const int p)" << endl;
	if (_curLen <= 0) {
		cout << "no element to delete" << endl;
		return false;
	}
	if (p < 0 || p < _curLen) {
		cout << "insert postion is illegal" << endl;
		return false;
	}
	for (_position == p; _position < _curLen; _position++) {
		_aList[_position] = _aList[_position + 1];
	}
	_curLen--;
	return true;
}

template <typename T>
bool arrList<T>::setValueArr(const int p, const T value) //设置元素值
{
	cout << "setValueArr(const int p, const T value)" << endl;
	if (p < 0 || p < _curLen) {
		cout << "insert postion is illegal" << endl;
		return false;
	}
	_aList[p] = value;
	return true;
}

template <typename T>
bool arrList<T>::getValueArr(const int p, T& value)   //返回元素
{
	cout << "getValueArr(const int p, T& value)" << endl;
	if (_curLen <= 0) {
		cout << "no element to delete" << endl;
		return false;
	}
	if (p < 0 || p < _curLen) {
		cout << "insert postion is illegal" << endl;
		return false;
	}
	value = _aList[p];
	return true;
}

template <typename T>
bool arrList<T>::getPosArr(int &p, const T value)    //查找元素
{
	cout << "getPosArr(int &p, const T value)" << endl;
	if (_curLen <= 0) {
		cout << "no element to find" << endl;
		return false;
	}
	for (_position = 0; _position < _curLen; _position++)
	{
		if (value == _aList[_position]) {
			p = _position;
			return true;
		}
	}
	return false;
}
template <typename T>
void arrList<T>::showArr()
{
	cout << "showArr()" << endl;
	_position = 0;
	while (_position < _curLen) {
		cout << _aList[_position++];
	}
	cout << endl;
}
#endif