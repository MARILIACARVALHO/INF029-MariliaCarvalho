#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#define TamAluno 3

//PROTÓTIPOS DAS FUNÇÕES:
void menuInicial(int *listaAluno, int *qtdAlunos);  
void menuAlunos(int *listaAluno, int *qtdAlunos);
void cadastroAluno(int *listaAluno, int *qtdAlunos);
void listarAluno(int *listaAluno, int *qtdAlunos);


int main(void) {

  int listaAluno[TamAluno];
  int qtdAlunos[1];
  qtdAlunos[0] = 1;
      
  menuInicial(listaAluno, qtdAlunos);  //CHAMANDO A FUNÇÃO

  return 0;
}

void menuInicial(int *listaAluno, int *qtdAlunos){

  int opcao;
  int sair = 0;

  while(sair==0){
  
    printf("\n\nPROJETO ESCOLA - Escolha a Opção correta para o  Cadastro: \n");
    printf("\n0 - SAIR\n");
    printf("\n1 - MENU ALUNOS\n");
    printf("\n2 - MENU PROFESSORES\n");
    printf("\n3 - MENU DISCIPLINAS\n\n");
  
    scanf("%d", &opcao);

    switch (opcao){

      case 0:{
        sair=1;
        break;
      }
      case 1:{
        printf("\nMENU ALUNOS\n");
        menuAlunos(listaAluno, qtdAlunos);
        break;
      }
      case 2:{
        printf("\nCADASTRO DE PROFESSORES\n");
        break;
      }
      case 3:{
        printf("\nCADASTRO DE DISCIPLINAS\n");
        break;
      }
      default: {
        printf("\nOPÇÃO INVÁLIDA\n");
      }

    }
  }
  
}

void menuAlunos(int *listaAluno, int *qtdAlunos){

  int opcao;
  int sair = 0;

  while(sair==0){
  
    printf("\n0 - VOLTAR\n");
    printf("\n1 - CADASTRAR ALUNO\n");
    printf("\n2 - LISTAR ALUNO\n");
    printf("\n3 - ATUALIZAR ALUNO\n");
    printf("\n4 - EXCLUIR ALUNO\n\n");
  
    scanf("%d", &opcao);

    switch (opcao){

      case 0:{
        sair=1;
        break;
      }
      case 1:{
        printf("\nCADASTRAR ALUNO: \n");
        cadastroAluno(listaAluno, qtdAlunos);
        break;
      }
      case 2:{
        printf("\nLISTAR ALUNO: \n");
        listarAluno(listaAluno, qtdAlunos);
        break;
      }
      case 3:{
        printf("\nATUALIZAR ALUNO: \n");
        break;
      }
      case 4:{
        printf("\nEXCLUIR ALUNO: \n");
        break;
      }
      default: {
        printf("\nOPÇÃO INVÁLIDA! ESCOLHA NOVAMENTE: \n");
      }

    }
  }
}

void cadastroAluno(int *listaAluno, int *qtdAlunos){

  // PROBLEMA - tá limitando a quantidade de alunos cadastrados -1 antes do valor de "TamAluno" que no caso é 3.
  
  if(qtdAlunos[0] == TamAluno+1){  //GAMBIARRA - N ENTENDI PQ PRECISA DO +1, ERA PRA BATER CERTO.
  //if(*qtdAlunos == TamAluno){
      printf("Lista de Alunos Cheia!\n");
  }else{
      printf("Digite a Matrícula do Aluno: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        listaAluno[qtdAlunos[0]] = matricula;
        //*qtdAlunos++;
        qtdAlunos[0]++;
        printf("Cadastrado com Sucesso!\n");
                
      }
    } 
}

void listarAluno(int *listaAluno, int *qtdAlunos){
  if (qtdAlunos[0] == 0) {
    printf("LISTA DE ALUNOS VAZIA\n");
  } else {
    for (int i = 0; i < qtdAlunos[0]; i++) {
      printf("Matrícula: %d\n", listaAluno[i]);
    }
  }
}