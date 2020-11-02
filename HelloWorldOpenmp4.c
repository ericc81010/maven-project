#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  clock_t start, stop;
  unsigned int iter=2000000000; 
  int i,j;
  double x, y;
  double dUnderCurve=0.0;
  double pi=0.0;
  start=clock();     
  srand(  0);
  for (i=0;i<iter;i++) {
     x=(double)rand()/(double)RAND_MAX;          //X Coordinate
     y=(double)rand()/(double)RAND_MAX;          //Y Coordinate
     if (x*x + y*y <= 1.0) {	//is distance from Origin under Curve 
         dUnderCurve++;
     }
  } 
  pi = dUnderCurve / (double) iter * 4 ;
  stop=clock();
  printf ("pi = %10.9f\n", pi);
  printf ("Seconds = %10.9f\n",(double)(stop-start)/ CLOCKS_PER_SEC);
    return 0;
}
