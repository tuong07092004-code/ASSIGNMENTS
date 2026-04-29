#include <stdio.h>
int factorial(int n){
    int i = 1, a = 1;
    while(i <= n){
       a *= i;
       i++;
    }
    return a;
}
int main(){
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int a = factorial(n);
    printf("%d\n",a);
    return 0;
}
