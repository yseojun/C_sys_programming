#include <malloc.h>
#include <stdio.h>

int main() {
  void *a;

  a=malloc(1024);
  a=malloc(32);
  free(malloc(1));
  free(a);
  return (0);
}