	#include<stdio.h>
	#include<math.h>
	#include<stdlib.h>
	int reverse(int);
	int digit(int);
	int Last_digit(int);
	int ones_digit(int);
	int sum(int);
	int* digits(int);
	int main()
	{
	  int n,i=0,*p;
	  printf("Enter a nummber\n");
	  scanf("%d",&n);
	  printf("Entered number is :- %d\n",n);
	  printf("Reverse of number is :- %d\n",reverse(n));
	  printf("Number of digit %d\n",digit(n));
	  printf("1st digit is %d\n",ones_digit(n));
	  printf("Last digit is %d\n",Last_digit(n));
	  printf("sum of digits of number:-%d is %d:-\n",n,sum(n));
	  printf("digits in number are:-\n");
	  p=digits(n);
	  for(i=digit(n)-1;i>=0;i--)
	  printf("%d\n",*(p+i));
	   return 0;
	}
	
int reverse(int n)
{
	int q=n,rev=0,r;
	while(q!=0)
	{
	  r=q%10;
	  rev=r+rev*10;
	  q=q/10;	
	}
	return rev;
}

int digit(int n)
{
	int i=0,q=n;
	while(q!=0)
	{
		q=q/10;
		i++;
	}
	return i;
	}	


int ones_digit(int n)
{
	return(n/(pow(10,digit(n)-1)));
}


int Last_digit(int n)
{
	return(n%10);
}

int sum(int n)
{
	int sum=0,q=n,r;
	while(q!=0)
	{
		r=q%10;
		sum=sum+r;
		q=q/10;
	
	}
	return sum;
}


int* digits(int n)
{
	int *p,i=0,q=n,r;
	p=(int*)calloc(digit(n),sizeof(int));
	while(q!=0)
	{
		r=q%10;
		*(p+i)=r;
		q=q/10;
		i++;
	}
	return p;
}

