#include <stdio.h>
#include <stdlib.h>
/*
 * 每隔5秒执行一次 ls -l
 * */
int main()
{
	static int lastTime = 0;
	while(1)
	{
		if(time(NULL) - lastTime > 5)  // 5s
		{
			lastTime = time(NULL);
			system("ls -lrt");
		}	
		else
		{
			printf("111\n");
		}
		sleep(1);	
	}
	return 0;
}
