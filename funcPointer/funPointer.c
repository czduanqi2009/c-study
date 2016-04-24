#include <stdio.h>
#include <stdlib.h>

/*普通的函数指针*/

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int main()
{	
	int res = 0;
	int (*pFun)(int x,int y); // declare a function pointer pFun
	pFun = add;  		  // init fun pointer
	res = (*pFun)(1,2);		  // called
	printf("result is %d\n",res);
	return 0;
}
