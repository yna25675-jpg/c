#include <stdio.h>
#include <ctype.h>

void toggle_case(char *str)
{
	for(int i=0; str[i] !='\0'; i++)
	{
		if(isupper(str[i]))
			str[i] =tolower(str[i]);
		else if(islower(str[i]))
			str[i] =toupper(str[i]);
		
	}
}



int main()
{
	char text[] ="Hello World 123!";
	printf("原始文本 ：%s\n",text);
	toggle_case(text);
	printf("切换后的文本 ：%s\n",text);
	return 0;
}