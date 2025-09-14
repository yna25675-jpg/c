#include <stdio.h>

int main()
{
	int year,month,day;
	
	int count;
	
	count = scanf("%d %d %d",&year,&month,&day);
	printf("成功接受了%d个数据\n",count);
	
	printf("今天是: %d-%d-%d\n",year,month,day);
	
	return 0;
}