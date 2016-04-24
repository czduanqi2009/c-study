#include <stdio.h>
#include <stdlib.h>

/*利用函数指针别名调用函数*/

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
	typedef int (*PFUN)(int x, int y); // 定义指针函数别名
	// 类型为 int (*)(int , int);
	PFUN pFun = sub;    // 声明函数指针变量 pFun ,并初始化 
	res = (*pFun)(1,2);		  // called
	printf("result is %d\n",res);
	return 0;
}
