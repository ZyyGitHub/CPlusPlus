#include <iostream>
#include "arrList.h"

using namespace std;

int main()
{
	arrList<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.apendArr(rand()%100 +1);
	}
	array1.showArr();

	arrList<int> array2(10);
	for (int i = 0; i < 10; i++)
	{
		array2.apendArr(i);
	}
	array2.showArr();
	array2.deleteArr(3);
	array2.deleteArr(5);
	array2.showArr();
	array2.insertArr(3,12);
	array2.setValueArr(0, 100);
	array2.showArr();
	int p;
	array2.getPosArr(p,1);
	cout << "getPosArr postion : " << p << endl;
	int tp;
	array2.getValueArr(0, tp);
	cout << "getValueArr : " << tp << endl;
	array2.clearArr();
	array2.apendArr(111);
	array2.showArr();
	cout << "array2.lengthArr : " << array2.lengthArr() << endl << "array2.fullArr : " << array2.fullArr() << endl;

	double tmp = 0.0;
	arrList<double> array3(10);
	for (int i = 0; i < 10; i++)
	{
		tmp = tmp + 1 / 3.0;
		array3.apendArr(tmp);
	}
	array3.showArr();

}