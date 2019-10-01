#include <cstdlib>
#include "mergesort.h"

void mergeRanges(int* values, int start, int middle, int end){
  //takes two an array with two sorted subarrays (start- middle-1 and middle-end)
  int range = end - start;
  int* destination = (int*) calloc(range, sizeof(int));
  int i = start;
  int j = middle;
  int copy = 0;
  //looking at the lowest of each sub array, take the lower one and put it first
  while(i < middle && j < end){
    if(values[i] < values[j]){
      destination[copy] = values[i];
      i = i + 1;
    } else {
      destination[copy] = values[j];
      j = j + 1;
    }
    copy = copy + 1;
  }
  while (i < middle){
    destination[copy] = values[i];
    i = i + 1;
    copy = copy + 1;
  }
  while (j < end){
    destination[copy] = values[j];
    copy = copy + 1;
    j = j + 1;
  }
  for(i = 0; i<range; i++){
    values[start + i] = destination[i];
  }
 
  free(destination);
  return;
}

void mergesortRange(int* values, int start, int end){
  //split the array into two sub arrays and sort them.
  int size = end - start;
  if(size >= 2){
    int middle = (start + end) / 2;
    mergesortRange(values, start, middle);
    mergesortRange(values, middle, end);
    mergeRanges(values, start, middle, end);
  }
  return;
}

void mergesort(int size, int* values) {
  mergesortRange(values, 0, size);
  return;
}

