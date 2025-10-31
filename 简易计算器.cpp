#include <stdio.h>

int add(int x, int y)
{
	return x+y;
}
int sub(int x, int y)
{
	return x-y;
}
int mul(int x, int y)
{
	return x*y;
}
int div(int x, int y)
{
	return x/y;
}





int calc(int(*op)(int, int))
{
	int x ,y;
	printf("请输入两个操作数：");
	scanf("%d%d", &x,&y);
	
	int ret = op(x, y);
	printf("结果: %d\n", ret);
}

void menu()
{
	printf("\n****** 计算器菜单******\n");
	printf("1. 加法\t2. 减法\n");
	printf("3. 乘法\t4. 除法\n");
	printf("*************************\n");
	printf("请选择：");
}
int main()
{
	int result = add(1,2);
	printf("result = %d\n",result);
	
	printf("add函数的地址: \t%p\n",add);  //申明了一个指向返回int，接受两个int参数的函数指针
	
	int (*p)(int, int) ;
	p =add;
	
	result =p(3,1);
	printf("result = %d\n",result);
	
	//calc(add);
	int input = 0;
	do
	{	menu();
		scanf("%d",&input);
		
		switch(input)
		{
			case 1:
				calc(add);
				break;
			case 2:
				calc(sub);
				break;
			case 3:
				calc(mul);
				break;
			case 4:
				calc(div);
				break;
			case 0:
				printf("已退出\n");
				break;
			default:
				printf("无效选择! \n");
				break;
		}
	}while(input !=0);  //输入0时退出循环
	
	
	return 0;
}