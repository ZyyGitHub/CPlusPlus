#include "CLink.h"
#include <ctime>
#include <cstdlib>

int main()
{
	CLink<int> intLink;
	for (int i = 0; i < 10; i++)
	{
		intLink.insertHead(i);
	}
	intLink.show();
	cout << "find 7" << endl;
	if (intLink.query(7)) {
		cout << "in link" << endl;
	}
	else {
		cout << "no in link" << endl;
	}
	cout << "delete 7 " << endl;
	intLink.deleteNode(7);
	intLink.show();
	cout << "=========================" << endl;
	CLink<const char*> strlink;
	strlink.insertHead("hello");
	strlink.insertHead("world");
	strlink.insertHead("china");
	strlink.insertHead("C++");

	strlink.show();
	
	CLink<string> stringLink;
	stringLink.insertHead("hello");
	stringLink.insertHead("world");
	stringLink.insertHead("china");
	stringLink.insertHead("string");

	stringLink.show();


	cout << "find china" << endl;
	if (stringLink.query<string>("china")) {    //其实是在比较地址
		cout << "in link" << endl;
	}
	else {
		cout << "no in link" << endl;
	}
}