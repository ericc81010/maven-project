#include <stdio.h>
#include <omp.h>
int main() {
 #pragma omp parallel
{
		int i;
		printf("Hello World\n");
		for(i=0;i<3;i++)
			printf("Printing Hello :%d\n",i);
}
		printf("GoodBye World\n");
}
