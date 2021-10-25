/* The Computer Language Benchmarks Game
 * http://benchmarksgame.alioth.debian.org/
 *
 * Contributed by Sebastien Loisel
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double eval_A(int i, int j) { return 1.0/((i+j)*(i+j+1)/2+i+1); }

void eval_A_times_u(int N, const double u[], double Au[])
{
  int i,j;
  for(i=0;i<N;i++)
    {
      Au[i]=0;
      for(j=0;j<N;j++) Au[i]+=eval_A(i,j)*u[j];
    }
}

void eval_At_times_u(int N, const double u[], double Au[])
{
  int i,j;
  for(i=0;i<N;i++)
    {
      Au[i]=0;
      for(j=0;j<N;j++) Au[i]+=eval_A(j,i)*u[j];
    }
}

void eval_AtA_times_u(int N, const double u[], double AtAu[])
{ double v[N]; eval_A_times_u(N,u,v); eval_At_times_u(N,v,AtAu); }

int main(int argc, char *argv[])
{
  int i;
  //const int N = ((argc == 2) ? atoi(argv[1]) : 2000);
  const int N;
  fscanf(stdin, "%d", &N);
  double u[N],v[N],vBv,vv;
  for(i=0;i<N;i++) u[i]=1;
  //vac_activate(VAC_APPROX_MEM_BITFLIP);
  //vac_newSection();

  for(i=0;i<10;i++)
    {
      eval_AtA_times_u(N,u,v);
      eval_AtA_times_u(N,v,u);
    }
  vBv=vv=0;
  for(i=0;i<N;i++) { vBv+=u[i]*v[i]; vv+=v[i]*v[i]; }

  //vac_deactivate(VAC_APPROX_MEM_BITFLIP);
  //vac_newSection();
  printf("%0.9f\n",sqrt(vBv/vv));
  return 0;
}

