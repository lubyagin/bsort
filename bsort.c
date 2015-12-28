
#include <stdio.h>
#include <stdint.h>

#define N 1200
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
  binit();
  print();

  bsort();
  print();
  return 0;
}
/*
  SET NAME=bsort
  D:\PROGS\CodeBlocks\MinGW\bin\gcc.exe -std=c99 -o %NAME%.exe %NAME%.c
  D:\PROGS\CodeBlocks\MinGW\bin\strip.exe %NAME%.exe
  D:\UTILS\upx.exe %NAME%.exe
*/
