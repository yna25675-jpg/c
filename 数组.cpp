#include <stdio.h>

int main()
{
	int numbers[8] = {13,4515,5134,13,13,521,412,32};
	int length = 8;
	
	printf("数组中的所有元素: \n");
	for(int i =0;i< length;i++)
	{
		printf("numbers[%d] = %d\n",i,numbers[i]);
		
	}
	printf("计数元素总和：");
	int sum = 0;
	for(int i = 0;i <length;i++)
	{
		sum+=numbers[i];
	}
	printf("数组元素的总和: %d\n",sum);
	
	printf("查找数组中的最大值: \n");
	int max = numbers[0];
	for(int i = 0;i<length;i++)
	{
		if(numbers[i] >max)
		    max = numbers[i];
	}
	printf("数组中的最大值为：%d\n",max);
	return 0;
}