
int DEBUG = 0;

#include <stdio.h>
#include <stdint.h>
#include "common.h"

#define N 40000
uint32_t a[N];

void binit() {
  for(uint32_t i = 0; i < N; i++) a[i] = N-i; /* обратный порядок */
}

/* Сортировка 'пузырьком' */
void bsort() {
  for(uint32_t k2 = 0; k2 < N; k2++)
  for(uint32_t k1 = 0; k1 < k2; k1++)
    if (a[k1] > a[k2]) {
      uint32_t v = a[k2]; a[k2] = a[k1]; a[k1] = v;
    } /* swap */
}

void print() {
  for(uint32_t i = 0; i < N; i++) printf(" %I32d",a[i]);
  printf("\n");
}

int main() {
  int64_t t1,t2;
  binit();
  if (DEBUG) print();
  t1 = GetTS();
  bsort();
  t2 = GetTS();
  if (DEBUG) print();
  printf("milliseconds(ms): %I64d\n",(t2-t1)/10000);
  return 0;
}
/*
   40k elements: 2560 ms, i3/3GHz
  100k elements: 15978 ms
*/
