#include <stdio.h>

int main()
{
	int age;
	
	printf("请输入你的年龄:");
	scanf("%d",&age);
	
	if(age>=18)
	{
		printf("你是成年人\n");
		
	}
	else
	{
		printf("你是未成年人\n");
	}
	return 0;
}