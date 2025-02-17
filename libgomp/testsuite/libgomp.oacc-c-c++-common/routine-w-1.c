/* { dg-do run } */
/* { dg-additional-options "-O2" } */

#include <stdio.h>

#define N (32*32*32+17)

#pragma acc routine worker
void __attribute__ ((noinline)) worker (int ary[N])
{
#pragma acc loop worker
  for (unsigned ix = 0; ix < N; ix++)
    {
      if (__builtin_acc_on_device (5))
	{
	  int g = 0, w = 0, v = 0;

	  __asm__ volatile ("mov.u32 %0,%%ctaid.x;" : "=r" (g));
	  __asm__ volatile ("mov.u32 %0,%%tid.y;" : "=r" (w));
	  __asm__ volatile ("mov.u32 %0,%%tid.x;" : "=r" (v));
	  ary[ix] = (g << 16) | (w << 8) | v;
	}
      else
	ary[ix] = ix;
    }
}

int main ()
{
  int ary[N];
  int ix;
  int exit = 0;
  int ondev = 0;

  for (ix = 0; ix < N;ix++)
    ary[ix] = -1;
  
#pragma acc parallel num_workers(32) vector_length(32) copy(ary) copy(ondev)
  {
    ondev = __builtin_acc_on_device (5);
    worker (ary);
  }

  for (ix = 0; ix < N; ix++)
    {
      int expected = ix;
      if(ondev)
	{
	  int g = 0;
	  int w = ix % 32;
	  int v = 0;

	  expected = (g << 16) | (w << 8) | v;
	}
      
      if (ary[ix] != expected)
	{
	  exit = 1;
	  printf ("ary[%d]=%x expected %x\n", ix, ary[ix], expected);
	}
    }
  
  return exit;
}
