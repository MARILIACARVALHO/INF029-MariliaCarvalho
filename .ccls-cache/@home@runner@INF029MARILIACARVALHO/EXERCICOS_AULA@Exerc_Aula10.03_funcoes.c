#include <stdio.h>

int soma(int x, int y);//protótipo da função

int main(void) {
  
  int a, b, res;
  
  printf("Digite o primeiro inteiro: \n");
  scanf("%d", &a);
  printf("Digite o segundo inteiro: \n");
  scanf("%d", &b);

  res = soma(a, b);

  printf("O resultado da soma é: %d",res);
  
  return 0;
}

int soma(int x, int y){
  int res = x+y;
  return res;
}