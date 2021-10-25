/**
 *
 * Author     : Adrian Statescu mergesortv@gmail.com http://adrianstatescu.com
 *
 * Description: C Program to compute PI using a Monte Carlo Method.
 *
 * MIT License 
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SEED 1

int main() {

 srand( SEED );
 int i, count, n;
 double x,y,z,pi;

 scanf("%d", &n);

 count = 0;

 for(i = 0; i < n; ++i) {

     x = (double)rand() / RAND_MAX;

     y = (double)rand() / RAND_MAX;

     z = x * x + y * y;

     if( z <= 1 ) count++;
 }

 pi = (double) count / n * 4;
 
 printf("%g", pi);

 return(0);
}
