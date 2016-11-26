/**
 *  Collatz conjecture
 *
 * CS50 exercise
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int collatz(int n);

int main(int argc, char* argv[])
{
  // ensure proper usage
  if (argc != 2)
  {
    printf("Usage: ./collatz n[integer]\n");
    return 1;
  }

  int n;
  char *p;
  errno = 0;

  long int n_check = strtol(argv[1], &p, 10);

  // check for errors
  if (errno != 0 || *p != '\0' || n_check < 1) {
    printf("Error: collatz expects a non-negative integer as n!\n");
    printf("Usage: ./collatz n[integer]\n");
    return 1;
  } else {
    n = n_check;
  }


  printf("It took %d steps with n=%d\n", collatz(n), n);

  return 0;
}

int collatz(int n)
{
  // base case
  if (n == 1)
    return 0;
  // even numbers
  else if ((n % 2) == 0)
    return 1 + collatz(n/2);
  // odd numbers
  else
    return 1 + collatz(3*n + 1);
}
