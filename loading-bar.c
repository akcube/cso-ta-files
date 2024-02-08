#include <stdio.h>
#include <unistd.h>

int main(void){
    char *pw = "Open the pod bay doors, HAL.";
    printf("%d\n", sizeof(pw));
}