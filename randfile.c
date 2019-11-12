#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int randNum(){
    int entropy = open("/dev/random", O_RDONLY);
    unsigned int final;
    
    read(entropy, &final, sizeof(int));
    close(entropy);

    return final;
}

int main(){
    unsigned int randNums[10];
    printf("Generating random numbers:\n");
    
    int i = 0;
    for (i = 0; i < 10; i++){
        randNums[i] = randNum();
        printf("\trandom %d: %u\n", i, randNums[i]);
    }

    printf("\nWriting numbers to file...\n");

    int writeFile = open("test", O_WRONLY | O_CREAT, 0666);
    write(writeFile, randNums, sizeof(randNums));
    close(writeFile);

    unsigned int finalNums[10];
    printf("\nReading numbers to file...\n");

    int readFile = open("test", O_RDONLY);
    read(readFile, finalNums, sizeof(finalNums));
    close(readFile);

    printf("\nVerification that written values were the same:\n");
    
    for (i = 0; i < 10; i++){
        printf("\trandom %d: %u\n", i, finalNums[i]);
    }

    return 0;
}