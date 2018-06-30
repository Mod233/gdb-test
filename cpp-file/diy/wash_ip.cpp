#include <cstdio>
#include <cstring>
int main(int argc, const char *argv[]){
    int a=232;
    char *c;
    memcpy(&c,&a,4);
    printf("c is %s\n", c);
    return 0;
}





