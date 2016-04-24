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


void compute1(PFUN operation,int x, int y)
{
	cout << "res is: " << operation(x, y) << endl << endl;
}

int main()
{	
	char choice = 0;
	while(1)
	{
		cout << "please select:"<< endl;
		cout << "'+' ===> add operation" << endl;
		cout << "'-' ===> sub operation" << endl;
		cout << "'q' ===> quit programe" << endl;
		cin >> choice; 
		cout << "Your choice is:" << choice << endl;
		switch(choice)
		{
			case '+':
				compute1(add,999, 1000);
				break;
			case '-':
				compute1(sub, -1, 2);
				break;
			case 'q':
				cout << "bye bye ..." << endl;
				exit(0);
			default:
				cout << "Your choice wrong" << endl;
				cout << "right choice is : + - q" << endl;
		}
		sleep(1);
	}
	return 0;
}
