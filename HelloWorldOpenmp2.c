#include <stdio.h>
#include <omp.h>
int main() {
int i;
    #pragma omp parallel for
         for(i=0;i<8;i++)
            printf("Iter:%d\n",i);
    printf("GoodBye World\n");
}
