#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  
  int opcao;
  
  printf("PROJETO ESCOLA - Escolha a Opção correta para o Cadastro: \n");
  printf("0 - SAIR\n");
  printf("1 - CADASTRO DE ALUNOS\n");
  printf("2 - CADASTRO DE PROFESSORES\n");
  printf("3 - CADASTRO DE DISCIPLINAS\n");

  scanf("%d", &opcao);
  
  printf("%d", opcao);
  

  
  return 0;
}