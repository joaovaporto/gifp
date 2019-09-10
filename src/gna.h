#ifndef __gna_h__
#define __gna_h__

#include "../src/util.h"
#include "time.h"
#include "math.h"

ul_int seed = 0;

double gna();
double sgna(int nseed);
ul_int gnai(int length);

double gna() {
  ul_int multiplier, module;

  if (seed == 0) seed = time(NULL);

  multiplier = 46341;
  module = 2147483647;
  seed = seed * multiplier % module;
  
  return (double) seed / (double) module;
}

double sgna(int nseed) {
  seed = nseed;
  return gna();
}

ul_int gnai(int length) {
  ul_int n, c;
  u_int r, q, i, j;

  n = 0; c = 0;
  r = length%6;
  q = length/6;

  // printf("r = %d, q = %d\n", r, q);

  for (i = 0; i < q; i++) {
    double a = gna();
    u_int p = (u_int) (a * 1e6);
    while (p == 0) p = (u_int) (gna() * 1e6);
    n += (ul_int) (p * pow(10, 6*i));
    printf("n in 1for = %ld, p = %d, a = %lf\n", n, p, a);
  }

  for (int j = 0; j < r; j++) {
    double a = gna();
    u_int p = (u_int) (a * 1e1);
    while (p == 0) p = (u_int) (gna() * 1e1);

    // printf("p in 2for = %d, part desired = %f\n", p, ();
    c += (ul_int) (p * pow(10, j));
    printf("n in 2for = %ld, p = %d, a = %lf, c = %ld", n, p, a, c);
  }

  n += (ul_int) (c * pow(10, 6*i));
  printf("n == %ld ", n);
  return n;
}

#endif