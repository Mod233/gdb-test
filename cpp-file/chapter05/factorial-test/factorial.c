#include <cstdio>
#include <cstdlib>
int factorial(int n){
    int result = 1;
    if(n==0) return 1;
    result=factorial(n-1)*n;
    return result;
}
int main(int argc,const char*argv[]){
    int n, result;
    if(argc!=2){
        fprintf(stderr, "Usage: factorial n, n>=0\n");
        return 1;
    }
    n = atoi(argv[1]);
    result = factorial(n);
    printf("factorial %d  = %d\n", n, result);
    return 0;
}
