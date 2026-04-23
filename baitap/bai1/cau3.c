#include <stdio.h>
int main(){
    int n;
    int a=0, b=0, c=0;
    while ((n=getchar()) != EOF){
          if(n==' '){
             a++;
          }else if(n=='\n'){
             b++;
          }else if(n=='\t'){
             c++;
          }
        }
    printf("so dau cach: %d\n",a);
    printf("so dau tab: %d\n",b);
    printf("so lan xuong dong: %d\n",c);
    return 0;
}
