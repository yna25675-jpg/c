#include <stdio.h>

int main()
{
	double num1 , num2, result;
	char oper;
	
	printf("请输入表达式 (如：5 + 3)：");
	scanf("%lf %c %lf",&num1,&oper,&num2);
	
	switch(oper)
	{
		case '+':
			result =num1+num2;
			printf("%.2f + %.2f = %.2f\n",num1,num2,result);
			break;
		case '-':
			result =num1-num2;
			printf("%.2f - %.2f = %.2f\n",num1,num2,result);
			break;
		case '/':
			if(num2 !=0)
			{
				result =num1/num2;
			printf("%.2f / %.2f = %.2f\n",num1,num2,result);
			}
			else
			{
				printf("错误：除数不能为零!\n");
			}
			break;
		case '*':
			result =num1*num2;
			printf("%.2f * %.2f = %.2f\n",num1,num2,result);
			break;
		default:
			printf("错误:无效的运算符！ \n");
			break;
	}
	
	return 0;
}