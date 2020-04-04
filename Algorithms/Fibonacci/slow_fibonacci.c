#include <stdio.h>
#include <stdlib.h>

long slow_fibonacci (long n)
{
    long ret;
    if (n == 0) {
        ret = 0l;
    } else if (n == 1) {
        ret = 1l;
    } else {
        ret = slow_fibonacci (n-1) + slow_fibonacci (n-2);
    }
    return ret;
}

int main (int argc, char **argv)
{
  long n = strtol (argv[1], NULL, 0);
  printf ("%ld\n", n);
  printf ("%ld\n", slow_fibonacci (n));
  return 0;
}
