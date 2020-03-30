#include <stdio.h>
#include <stdlib.h>

long* matrix_mult (long* a, long* b)
{
  long ret[4];
  ret[0] = (a[0] * b[0]) + (a[1] * b[2]);
  ret[1] = (a[0] * b[1]) + (a[1] * b[3]);
  ret[2] = (a[2] * b[0]) + (a[3] * b[2]);
  ret[3] = (a[2] * b[1]) + (a[3] * b[3]);
  return ret;
}

long* matrix_pow (long* arr, long n)
{
  long res[4] = {1, 0, 0, 1};
  while (n)
  {
    if (n % 2 != 0) {
      long tmp[4];
      tmp = matrix_mult (res, arr);
      res[0] = tmp[0];
      res[1] = tmp[1];
      res[2] = tmp[2];
      res[3] = tmp[3];
    }
    n /= 2;
    arr = matrix_mult (arr, arr);
  }
  return res;
}

long matrixexp_fibonacci (long n)
{
  long matrix[4] = {1, 1, 1, 0};
  return matrix_pow (matrix, n)[1];
}

int main (int argc, char **argv)
{
  long n = strtol (argv[1], NULL, 0);
  printf ("%ld\n", n);
  printf ("%ld\n", matrixexp_fibonacci (n));
  return 0;
}
