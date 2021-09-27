#include<stdio.h>
void swap(int*,int*);
int main()
{
	int a,b;
	printf("Enter two number:- \n");
	scanf("%d%d",&a,&b);
	printf("Number Entered as:- %d & %d\n",a,b);
	swap(&a,&b);
	printf("Number After Swapping as:- %d & %d\n",a,b);
	return 0;
}


void swap(int *a,int *b)
{
    *a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;		
}
