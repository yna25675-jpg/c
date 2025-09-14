#include <stdio.h>

int main()
{
	int age;
	float height;
	char grade;
	
    printf("请输入你的年龄: ");
	scanf("%d",&age);
	
	printf("请输入你的身高:");
	scanf("%f",&height);
	
	printf("请输入你的成绩:");
	scanf(" %c",&grade);
	
	printf("\n你的信息: \n");
	printf("你的年龄是:%d岁\n",age);
	printf("身高: %.1f厘米\n",height);
	printf("等级: %c\n",grade);
	return 0;
}
	