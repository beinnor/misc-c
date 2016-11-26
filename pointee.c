#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int* a;
  int* b;

  a = malloc(sizeof(int));
  b = malloc(sizeof(int));

  *a = 5;
  *b = 3;

  

  printf("a: %d, b: %d\n", *a, *b);

  return 0;
}
