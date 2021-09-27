#include<stdio.h>
int main()
{
	int a[3][3],b[3][3],i,j,c[3][3];

	printf("Enter the data of 1st Matrix,Row wise\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		scanf("%d",*(a+i)+j);
	}
	printf("Matrix 1:-\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d ",*(*(a+i)+j));
		printf("\n");
	}
		printf("Enter the data of 2nd Matrix,Row wise\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		scanf("%d",*(b+i)+j);
	}
	printf("Matrix 1:-\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d ",*(*(b+i)+j));
		printf("\n");
	}
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		c[i][j]=a[i][j]+b[i][j];
	}
	printf("Sum of two matrix is :-\n");
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d ",*(*(c+i)+j));
		printf("\n");
	}
	   		
return 0;
}
