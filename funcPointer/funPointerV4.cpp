#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

typedef int (*PFUN)(int , int);

/* 利用通用接口调用相关函数*/

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}


PFUN select()
{
	char choice = 0;
	cout << "please select:"<< endl;
	cout << "'+' ===> add operation" << endl;
	cout << "'-' ===> sub operation" << endl;
	cout << "'q' ===> quit programe" << endl;
	//cin.clear();
	//cin.sync();
	cin >> choice; 
	cout << "Your choice is:" << choice << endl;
	switch(choice)
	{
		case '+':
			return add;
		case '-':
			return sub;
		case 'q':
			cout << "bye bye ..." << endl;
			exit(0);
		default:
			cout << "Your choice wrong" << endl;
			cout << "right choice is : + - q" << endl;
			return NULL;
	}
}

void getdata(int *first, int *second)
{
	cout << "input two data:" << endl;
	cout << "first is : "<< endl;
	cin >> *first;
	cout << "second is : "<< endl;
	cin >> *second;

}

int main()
{
	int first = 0, second = 0;
	while(1)
	{	
		PFUN pFun = select();
		
		if(pFun != NULL)
		{
			getdata(&first, &second);
			cout <<"res is :" << (*pFun)(first ,second) << endl << endl;
		}
		sleep(1);
	}
	return 0;
}
