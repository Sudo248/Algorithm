#include <stdio.h>

int main()
{  
    int n;
    int dau=0,cuoi=0;
    scanf("%d",&n);
    if(n == 1){
        printf("1 1");
        return 0;
    }
    cuoi=n%10;
    while(n>9)
    { 
        n/=10;
        dau=n;
    }
    printf("%d %d",dau,cuoi);
}