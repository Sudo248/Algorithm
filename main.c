#include<stdio.h>
#define MAX 10 
void nhap(int a[])
{
	int i ;
  for(i=0; i< MAX ; i++)
	{
		scanf("%d",&a[i]); 
	}
 } 
 
 void xuat (int a [])
 {
 	int i; 
 	for (i=0 ;i <MAX ; i++)
	 {
	 	if(a[i]>0) 
	 	printf ("%d",a[i]); 
	  } 
	  printf ("\n"); 
  } 
 int main ()
 {
 	int a [MAX];
	 nhap (a);
	 
	 xuat(a); 
     return 0; 
  }