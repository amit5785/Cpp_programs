#include<stdio.h>
int length(char *);
char* upper(char *);
char * lower(char *);
int main()
{
	char name[30];
   printf("Enter your name:-\n");
   gets(name);
   puts(name);
   printf("Length of your name is: %d\n",length(name));
   printf("Nmae in upper case:- %s\n",upper(name));
   printf("name in lower case :- %s\n",lower(name));
   printf("\n%s",name);
   return 0;
}

int length(char *name)
{
	int i=0;
	while(*(name+i)!='\0')
	i++;
	return i;
}


char* upper(char * name)
{
	int i=0;
	while(*(name+i)!='\0')
	{
		if((int)(*(name+i))-97>=0 && *(name+i)!=' ' )
		*(name+i)=(char)((int)(*(name+i))-32);
		i++;
	}
	return name;
}


char* lower(char * name)
{
	int i=0;
	while(*(name+i)!='\0')
	{
		if((int)(*(name+i))-97<0 && *(name+i)!=' ' )
		*(name+i)=(char)((int)(*(name+i))+32);
		i++;
	}
	return name;
}


