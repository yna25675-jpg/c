#include <stdio.h>
#include <string.h>
int main()
{
	char buffer[15]="hello";
	char addition[]="beautiful world";
	
	printf("连接前: %s\n",buffer);
	
	size_t available = sizeof(buffer)-strlen(buffer)-1;
	strncat(buffer,addition,available);
	printf("连接后: %s\n",buffer);
	return 0;
}