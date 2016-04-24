#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * revertStr(char *str)
{	// hello
	char *tmp = str + strlen(str) - 1;
	int len = strlen(str), i = 0;
	char *arr = (char *)malloc(sizeof(char) *strlen(str) + 1); // +1 ==>'\0'
	memset(arr, 0, strlen(str) + 1);
	while( i < len ) // i = 5
	{
		//printf("tmp is %c\n",*tmp);
		*(arr + i) = *tmp--;	
		//printf("arr is %c\n",*(arr + i));
		i++;
		//tmp = tmp -1;
	}
	// i = 5
	*(arr + i) = '\0';
	return arr;
}

int main()
{
	char *str = "hello world!";
	printf("before revert is :%s\n",str);
	char *resStr = revertStr(str);
	//sleep(2);
	printf("after revert is  :%s\n",resStr);
	free(resStr);
}
