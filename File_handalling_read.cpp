#include<stdio.h>
int main()
{
	char ch[50];
	FILE *fp;
	fp=fopen("amit.txt","r");
	while(!feof(fp))
	{
		fgets(ch,30,fp);
		printf("%s\n",ch);
	}
	return 0;
}
