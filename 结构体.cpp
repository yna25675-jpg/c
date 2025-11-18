#include <stdio.h>
#include <string.h>
struct Person
{
	char name[50];
	int age;
	float height;
} person5,person6;

struct 
{
	char name[50];
	int age;
	float height;
} person3,person4;
int main()
{
	int a =10;
	struct Person person1,person2;
	struct Person straff[10];
	struct Person *p;
	
	//完整初始化
	struct Person person7 ={"张三",32,173};
	
	//逐个成员赋值
	struct Person person9;
	strcpy(person9.name,"王五");
	person9.age=22;
	person9.height=178.5;
	
	struct Person person10 =person9;
	
	printf("学生姓名: %s\n",person10.name);
	printf("学生姓名: %.1f\n",person10.height);
	printf("学生姓名: %d\n",person10.age);
	
	
	return 0;
}