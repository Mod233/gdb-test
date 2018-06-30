#include <cstdio>
int main(int argc,const char*argv[]){
    int i;
    while(true){
        fputs("Please input an integer:", stdout);
        scanf("%d", &i);
        printf("%d\n", i);
    }
    return 0;
}
