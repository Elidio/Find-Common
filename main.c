#include <stdio.h>

typedef int err_t;


/*A função retorna o número de resultados ou -1 se este numero for maior que result
size. Neste caso, result ficará truncado em resultSize*/

err_t findCommon(int *list1, int numElem1, int *list2, int numElem2,
                 int *result, int resultSize)
{
  int i, j;
  int results = 0;
  
  for (i = 0; i < numElem1; i++){
    for (j = 0; j < numElem2; j++){

      if (list1[i] == list2[j]){
        results++;
        if (!(results > resultSize))
          result[results-1] = list1[i];
        else
        {
          return -1;
        }
      }
    }
  }

  return results;

}


int main(void) {
  int a[10] = {0,2,4,6,8,10,12,14,16,18};
  //int b[10] = {1,3,5,7,9,11,12,14,16,18};
  //int b[10] = {1,3,5,7,9,11,13,15,17,19};
  int b[10] = {0,2,4,6,8,10,12,14,16,18};
  int c[10];
  int i;
  int err;

  err = findCommon(a, 10, b, 10, c, 5);

  if (err == -1) {
    printf("Too many results\n");
    err = 5;
  }
  printf("[");
    for(i=0; i<err; i++){
      printf(" %d ", c[i]);
    }
  printf("]\n");
   

}