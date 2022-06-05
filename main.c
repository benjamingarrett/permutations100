#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "permutations.h"

int main(int argc, char ** argv){
  int64_t n = 5;
  int64_t * a = calloc(n, sizeof(int64_t));
  int64_t * b = calloc(n, sizeof(int64_t));
  int64_t g;
  for(g = 0; g < n; g++){
    a[g] = g;
  }
  get_jth_random_permutation(a, b, n, 0);
  for(g = 0; g < n; g++){
    printf("%ld ", b[g]);
  }
  printf("\n"); 
  get_jth_random_permutation(a, b, n, 3);
  for(g = 0; g < n; g++){
    printf("%ld ", b[g]);
  }
  printf("\n");
  get_jth_random_permutation(a, b, n, 7);
  for(g = 0; g < n; g++){
    printf("%ld ", b[g]);
  }
  printf("\n");
}
