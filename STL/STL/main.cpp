#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <iterator>
#include <algorithm>
#include <memory>
#include <ctime>

using namespace std;

/*
容器
数据的增删改查

顺序容器：
vector：添加元素push_back   insert        底层提供了[]的重载函数     内存成倍增长的数组
deque :     添加元素push_back   insert    底层提供了[]的重载函数     动态开辟的二维数组
list   :添加元素push_back push_front   insert     双向链表
关联容器：
底层实现红黑树
set：单重集合不允许关键字重复   insert   erase    begin   end    find   iterator    
mutiset：多重集合   
map：映射表   
mutimap
容器适配器：
stack : 底层实现deque实现
queue ：底层实现deque实现
priority_queue

迭代器：
正向迭代器:iterator、const_iterator
反向迭代器：reserve_iterator、const_reserve_iterator
插入迭代器:back_insert_iterator 、 front_insert_interator 、insert_iterator
流迭代器
输入输出流迭代器：ostream_iterator   istream_iterator
copy(con.begin(),con.end(),osteram_iterator<int>(cout, " "))
泛型算法
copy()
sort()
find()
*/


int main()
{
	typedef map<string, vector<int>> _MyT;
	map<string, vector<int>> map1;
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;
	map1["name1"] = vec1;
	//map1["name2"] = vec2;
	//map1["name3"] = vec3;

	typedef map<string, vector<int>>::value_type _VT;
	map1.insert(_VT("name3", vec3));

	typedef pair<string, vector<int>> _PAIR;
	map1.insert(_PAIR("name2", vec2));

	_MyT::iterator iter= map1.find("name2");
	if (iter == map1.end())
	{
		cout << "not found" << endl;
		return -1;
	}
	for (int i = 0; i < 20; i++)
	{
		iter->second.push_back(rand() % 100 + 1);
	}
	copy(iter->second.begin(), iter->second.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << map1.count("name3") << endl;
	_MyT::iterator iter1 = map1.find("name3");
	map1.erase(iter1);
	cout << map1.count("name3") << endl;
}



#if 0
int main() {
	set<int> myset;
	set<int, greater<int>> myset2;
	multiset<int,greater<int>> myset1;
	myset1.insert(10);
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		myset1.insert(rand() % 100 + 1);
	}
	copy(myset1.begin(), myset1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	myset1.insert(20);
	cout << myset1.count(20) << endl;
	myset1.insert(20);
	cout << myset1.count(20) << endl;

	multiset<int, greater<int>>::iterator iter = myset1.find(20);
	if (iter == myset1.end()) {
		cout << "not find" << endl;
		return -1;
	}
	cout << *iter << endl;
	myset1.erase(iter);
	copy(myset1.begin(), myset1.end(), ostream_iterator<int>(cout, " "));

}
#endif

#if 0
template <typename Container>
void showBase(Container &con)
{
	if (con.empty()) {
		cout << "Container is empty" << endl;
	}
	cout << con.size() << endl;
	cout << con.max_size() << endl;
}
#if 0
template <typename Container>
void showContainer(Container &con) {
	typename Container::iterator it = con.begin();
	for (; it != con.end(); it++)
	{
		cout << *it << endl;
	}
}
#endif
template <typename Container>
void showContainer(const Container &con) {
	//const typename Container::iterator it = con.begin();
	//typename Container::const_iterator it = con.begin();
	//for(; it != con.end(); it++)
	//{
	//	cout << *it << " " ;
	//}
	copy(con.begin(), con.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//typename Container::const_reverse_iterator rit = con.rbegin();
	//for (; rit != con.rend(); it++)
	//{
	//	cout << *rit << " ";
	//}
	//cout << endl;
}
int main()
{
	vector<int> vec1;
	vector<int> vec2(10);
	vector<int> vec3(10, 40);
	vector<int> vec4(vec3);

	int array[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100 + 1;
	}

	srand(time(0));

	vector<int> vec5(array, array + 10);
	vector<int> vec6(vec5.begin(), vec5.end());
	for (int i = 0; i < 10; i++)
	{
		vec6.push_back(rand() % 100);
	}
	vec6.insert(vec6.begin(), 66);
	vec6.insert(vec6.end(), 11);

	showBase(vec1);
	showBase(vec2);
	showContainer(vec2);
	showContainer(vec3);
	cout << "=====================" << endl;
	showContainer(vec4); 
	cout << "=====================" << endl;
	showContainer(vec5);
	showContainer(vec6);
	//从大到小排序
	sort(vec6.begin(), vec6.end(),greater<int>());
	showContainer(vec6);
	//bind1st 绑定器
	//greater_equal
	//less_equal
	vector<int>::iterator iter = find_if(vec6.begin(), vec6.end(), bind1st(greater_equal<int>(),73));
	if (*iter != 73) {
		vec6.insert(iter, 73);
	}
	showContainer(vec6);
	//删除   clear   erase(iter)  erase(iterf,iterl)
	//vector  pop_back
	//deque    list     pop_back     pop_front

	vector<int>::iterator iter1 = find(vec6.begin(), vec6.end(), 70);
	if (iter1 == vec6.end()) {
		cout << "not found" << endl;
		return -1;
	}
	vec6.erase(iter1);
	vec6.pop_back();
	showContainer(vec6);
	//迭代器的区间 半开半闭，包含起始不包含末尾
	//find 和 find_if
	vector<int>::iterator iter3 = find_if(vec6.begin(), vec6.end(), bind1st(greater<int>(), 20));
	vector<int>::iterator iter2 = find_if(vec6.begin(), vec6.end(), bind1st(greater_equal<int>(), 60));
	if (iter2 == vec6.end()) {
		cout << "not found" << endl;
		return -1;
	}
	vec6.erase(iter2, iter3);
	showContainer(vec6);


	//vec6.clear();
	//showContainer(vec6);

	vector<int> vec7;
	//back_insert_iterator<vector<int>> backit(vec7);
	//*backit = 20;
	copy(vec6.begin(), vec6.end(), back_inserter(vec7));
	copy(vec6.begin(), vec6.end(), inserter(vec7,vec7.end()));
	showContainer(vec7);
	return 0;
}
#endif