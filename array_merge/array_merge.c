#include <climits>
#include <stdio.h>
#include "array_merge.h"
#include "mergesort.c"

int* array_merge(int num_arrays, int* sizes, int** values) { 
  int maxSize = 0;
  //sort each value array and get total number of values
  for(int i=0; i<num_arrays; i++){
    mergesort(sizes[i], values[i]);
    maxSize = maxSize + sizes[i];
  }
  //make the array where we will store our result
  int* final = (int*) calloc(maxSize+1, sizeof(int));
  //make an array to keep track of indices in each newly sorted values array
  int* indexarr = (int*) calloc(num_arrays, sizeof(int));
  //set them to 0 by default.
  for(int i=0; i<num_arrays; i++){
    indexarr[i] = 0;
  }
  //this will count the number of values in final
  final[0] = 0;
  //loop through each value, merging the sorted arrays but ignoring repeated values
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
    if(lowest != final[nextInd - 1] || nextInd == 1){
      final[nextInd] = lowest;
      nextInd = nextInd + 1;
      final[0] = final[0] + 1;      
    }
    indexarr[lowestArr] = indexarr[lowestArr] + 1;

  } 
  //And now we're done!
  free(indexarr);
  return final;
  //Thanks nic
}


