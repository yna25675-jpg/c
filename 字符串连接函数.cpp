#include <stdio.h>
#include <string.h>
int main()
{
	char greeting[50] ="hello,";
	char name[] ="xiaoming";
	strcat(greeting,name);
	printf("连接后:'%s'\n",greeting);
	printf("源字符串: '%s'\n",name);
	return 0;
}