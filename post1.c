#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num[10]={}, max=-999, min=999;
  printf("Digite 10 numeros inteiros\n");

  for (int i = 0; i<10; i++){
  scanf("%d", &num[i]);
    if (num[i]>max){
      max = num[i];
    }
    if (num[i]<min){
        min = num[i];
    }
  }
  for (int i = 0; i < 10; i++){
    printf("%d ", num[i]);
  }
  printf("\nO valor maximo eh: %d ", max);
  printf("\nO valor minimo eh: %d ", min);

  return 0;
}

