#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define blocksize 1024

void wait_for_input(const char*prefix, int is_interactive){
    char c;
    if(is_interactive){
        printf("%s hit return to continue\n", prefix);
        fflush(stdout);       // refresh the FILE* buffer.
        c = getchar();
    }
    else{
        sleep(1);
    }
}


int main(int argc, const char*argv[]) {
    const char *usage = "usage: testmalloc i[interactive]|n n iter\n";
    int n, i, j, iterations, is_interactive = 0;
    int **myarray;
    if(argc!=4){
        fprintf(stderr, usage);
        return 1;
    }
    if(argv[1][0]=='i')
        is_interactive = 1;

    n = atoi(argv[2]);              // size of malloc buffer.
    iterations = atoi(argv[3]);     // iterations
    if(n<=0 || iterations <0){
        fprintf(stderr, usage);
        return 2;
    }
    for(i=0;i<iterations;i++){
        wait_for_input("before malloc: ", is_interactive);
#ifdef USE_NEW
        myarray = new int*[n];
#else
        myarray = (int **)malloc(n*(sizeof(int*)));
#endif
        for(j=0;j<n;j++){
#ifdef USE_NEW
            myarray[j] = new int[blocksize];
#else
            myarray[j] = (int*) malloc(blocksize * sizeof(int));
#endif
        }
        wait_for_input("after malloc: ", is_interactive);
        for(j=0;j<n;j++){
#ifdef USE_NEW
            delete [] myarray[j];
#else
            free(myarray[j]);
#endif
        }
#ifdef USE_NEW
        delete [] myarray;
#else
        free(myarray);
#endif
    }
    return 0;
}
