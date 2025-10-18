#include <stdio.h>

int main()
{
	int scores[3][4] = {
	    {84,92,78,97},
	    {88,75,93,82},
	    {91,89,83,92}
	};
	
	printf("第一个学生的第一门课程为：%d\n",scores[0][0]);
	printf("第二个学生的第三门课程为：%d\n",scores[1][2]);
	
	scores[1][1] = 80;
	scores[0][3] = 96;
	printf("第二个学生的第三门课程为：%d\n",scores[1][2]);
	printf("第一个学生的第三门课程为：%d\n",scores[0][3]);
	return 0;
}