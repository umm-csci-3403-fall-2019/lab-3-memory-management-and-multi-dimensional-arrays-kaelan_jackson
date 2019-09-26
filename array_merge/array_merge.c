#include <climits>
#include "array_merge.h"
#include "mergesort.c"

int* array_merge(int num_arrays, int* sizes, int** values) {
  int maxSize = 0;
  for(int i=0; i<num_arrays; i++){
    mergesort(sizes[i], values[i]);
    maxSize = maxSize + sizes[i];
  }
  int* final = (int*) calloc(maxSize+1, sizeof(int));
  int* indexarr = (int*) calloc(num_arrays, sizeof(int));
  for(int i=0; i<num_arrays; i++){
    indexarr[i] = 0;
  }
  final[0] = 0;
  int nextInd = 1; 
  for(int i=0; i<maxSize; i++){
    int lowest = INT_MAX;
    int lowestArr = -1;
    for(int j=0; j<num_arrays; j++){
      if(indexarr[j] < sizes[j]){
        if(values[j][indexarr[j]] < lowest){
          lowest = values[j][indexarr[j]];
	  lowestArr=j;
	}	
      }
    }
    if(lowest == final[nextInd - 1] || nextInd == 1){
      final[nextInd] = lowest;
      nextInd = nextInd + 1;      
    }
    indexarr[lowestArr] = indexarr[lowestArr] + 1;

  }

  return final;
}

