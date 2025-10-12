#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


int main()
{
	int secret,
	    guess,
	    count = 0;
	srand(time(NULL)); // 用当前时间给随机数发生器“播种”，让每次运行的随机序列不同
	secret = rand() % 100 + 1;    // %100一定是0~99
	
	printf("欢迎来到猜数字游戏！(1~100) \n");
	
	do
	{
		printf("请输入你的猜测:");
		scanf("%d",&guess);
		count++;
		
		if(guess>secret)
		{
			printf("太大了！ \n");
		}
		else if(guess<secret)
		{
			printf("太小了! \n");
		}
		else
		{
			printf("恭喜你，猜对了！一共猜了 %d次 \n",count);
		}
	}while(guess !=secret);
	
	return 0;
}