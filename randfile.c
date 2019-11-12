#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int randNum(){
    //int entropy = open("/dev/random", O_RDONLY);
    return 1;
}

int main(){
    unsigned int randNums[10];
    printf("Generating random numbers:\n");
    
    int i = 0;
    for (i = 0; i < 10; i++){
        randNums[i] = randNum();
        printf("\trandom %d: %u\n", i, randNums[1]);
    }
    
    return 0;
}