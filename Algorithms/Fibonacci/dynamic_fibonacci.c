#include <stdlib.h>
#include <stdio.h>

long dynamic_fibonacci (long n)
{
  long fib_arr[n+2];
  long i;

  fib_arr[0] = 0;
  fib_arr[1] = 1;

  for (i = 2; i <= n; i++)
    fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
  return fib_arr[n];
}

int main (int argc, char **argv)
{
  long n = strtol (argv[1], NULL, 0);
  printf ("%ld\n", n);
  printf ("%ld\n", dynamic_fibonacci (n));
  return 0;
}
