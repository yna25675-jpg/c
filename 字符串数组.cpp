#include <stdio.h>

int main()
{
	char s[1000];
	int i=1,count=0;
	gets(s);
	if(s[0] !=' '&& s[0]!='\0')//不是空格也不是单词 
		count=1;
	for(i=1;s[i]!='\0';i++)//第二个开始数 
	{
		if(s[i] !=' '&&s[i-1]==' ')
			count++;
	}
	printf("%d\n",count);
	return 0;
}

