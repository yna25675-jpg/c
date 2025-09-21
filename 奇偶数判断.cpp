#include <stdio.h>

int main()
{
	int num;
	printf("请输入一个整数:");
	scanf("%d",&num);
	
	if(num>0)
	{
	   printf("%d是正数",num);
	   if(num%2==0)
	   {
	   	printf("且是偶数\n");
	   }
	   else
	   {
	   	printf("且是奇数\n");
	   }
	   	
	}
	else if(num<0)
	{
		printf("%d是负数\n",num);
		
	}
	else
	{
		printf("输入的是零\n");
	}
	return 0;
}