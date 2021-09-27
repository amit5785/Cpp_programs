#include<stdio.h>
#include<string.h>
typedef struct 
{
	char ch[20];
	char rn[10];
	int age;
}name;

int main()
{
	name a[2];
	int i;
	FILE *fp;
	printf("Enter the data of the student:-\n");
	for(i=0;i<2;i++)
	{
	   printf("Enter Name Roll_no and Age of the student\n");
	   fflush(stdin);
	   gets((a+i)->ch);
	   fflush(stdin);
	   gets((a+i)->rn);
	   scanf("%d",&a[i].age);
	   
	}
	fp=fopen("amit.txt","w");
	for(i=0;i<2;i++)
	fprintf(fp,"Name:- %s\nRoll no:- %s\nAge :- %d\n",(a+i)->ch,(a+i)->rn,(a+i)->age);
	fclose(fp);
	printf("%s\n%s\n%d\n",a->ch,a->rn,a->age);
	return 0;
}
