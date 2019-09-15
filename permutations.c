#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include "permutations.h"

void swap(int64_t * x, int64_t * y){
  int64_t temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
void generate_permutations(int64_t * a, int64_t * b, int64_t n);
int64_t counter, chosen;
void get_jth_permutation(int64_t * a, int64_t * b, int64_t n, int64_t j){
  chosen = j;
  counter = 0;
  generate_permutations(a, b, n);
}
void permute(int64_t * a, int64_t * b, int64_t l, int64_t r, int64_t n);
void generate_permutations(int64_t * a, int64_t * b, int64_t n){
  permute(a, b, 0, n-1, n);
}
void permute(int64_t * a, int64_t * b, int64_t l, int64_t r, int64_t n){
  int64_t g;
  if(l == r){
    if(counter++==chosen){
      for(g = 0; g < n; g++){
        b[g] = a[g];
      }
    }
  } else {
    if(counter > chosen) return;
    for(g = l; g <= r; g++){
      swap(a+l, a+g);
      permute(a, b, l+1, r, n);
      swap(a+l, a+g);
    }
  }
}
void get_jth_random_permutation(int64_t * a, int64_t * b, int64_t n, int64_t j){
  int64_t g;
  for(g = 0; g < n; g++){
    b[g] = a[g];
  }
  srand(0);
  for(g = 0; g < j; g++){
    //printf("shuffling permutation %ld times\n", j);
    int64_t x = (int64_t)((double) n * (double) rand() / (double) RAND_MAX);
    int64_t c = 0;
    int64_t y;
    while(1){
      if(c == n){
        fprintf(stderr, "Couldn't find a distinct second index~\n");
        exit(1);
      }
      y = (int64_t)((double) n * (double) rand() / (double) RAND_MAX);
      if(x != y){
        break;
      } else {
        c++;
      }
    }
    swap(b+x, b+y);
  }
  /*
  printf("permutation %ld = ", j);
  for(g = 0; g < n; g++){
    printf("%ld ", b[g]);
  }
  */
}
