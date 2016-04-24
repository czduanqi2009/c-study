#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

typedef int (*PFUN)(int , int);

PFUN pFunArray[2] = {NULL};

/* 利用函数数组指针，数组里保存的是指针，指针类型为: int (*)(int ,int);*/

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

void getdata(int *first, int *second)
{
	cout << "input two data:" << endl;
	cout << "first is : "<< endl;
	cin.clear();cin.sync();
	cin >> *first;
	//cout << "second is : "<< endl;
	//cin >> *second;

}

void initFunPointerArray()
{
	pFunArray['+'] = add;	
	pFunArray['-'] = sub;	
}	

int compute(char opCode,int x, int y)
{
	PFUN pFun = pFunArray[opCode];
	return (*pFun)(x, y);
}

int main()
{
	initFunPointerArray();
	int first = 0, second = 0;
	while(1)
	{	
		getdata(&first, &second);
		cout <<"add result is :" << compute('+',first ,second) << endl << endl;
		cout <<"sub result is :" << compute('-',first ,second) << endl << endl;
	}
	return 0;
}
