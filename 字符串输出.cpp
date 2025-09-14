#include <stdio.h>

int main(){
    char name[] = "张三";
    char greeting[]="你好";
    
    printf("姓名： %s\n",name);
    printf("问候语:%s\n",greeting);
    printf("完整的文化:%s,%s!\n",greeting,name);
    printf("直接输出: %s\n","Hello World");
    
	
	return 0;
}