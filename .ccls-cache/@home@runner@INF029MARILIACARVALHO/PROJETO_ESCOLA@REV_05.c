#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define TamAluno 3

/*STRUCTS:
 OBS: STATUS = 1 -> ATIVO  e STATUS = 0 -> INATIVO  */

typedef struct data_de_nascimento{
  int dia;
  int mes;
  int ano;
}data;

typedef struct ficha_aluno{
  int matricula;
  char nome[100];
  char sexo;
  data data;
  int cpf;
  int status;
}Aluno;

typedef struct ficha_professor{
  int matricula;
  char nome[100];
  char sexo;
  data data;
  int cpf;
  int status;
}Professor;

typedef struct ficha_disciplina{
  char nome[100]; 
  int codigo;
  int semestre;
  int status;
  
  //professor:
  //char professorDaDisciplina[100];
  //lista professor(es)??
  //lista alunos??
    
}Disciplina;


//;typedef struct ficha_aluno Aluno; //definindo APELIDO. (que pelo visto n pode ter _)

//Aluno aluno1; //declarando com o apelido criado
//o objetivo do typdef é encurtar a declaração do tipo
//struct ficha_aluno aluno1;

//PROTÓTIPOS DAS FUNÇÕES:
void menuInicial(Aluno *listaAluno, int *qtdAlunos);  
void menuAlunos(Aluno *listaAluno, int *qtdAlunos);
void cadastroAluno(Aluno *listaAluno, int *qtdAlunos);
void listarAluno(Aluno *listaAluno, int *qtdAlunos);


int main(void) {

  Aluno listaAluno[TamAluno];
  int qtdAlunos[1];
  qtdAlunos[0] = 0;
      
  menuInicial(listaAluno, qtdAlunos);  //CHAMANDO A FUNÇÃO

  return 0;
}

void menuInicial(Aluno *listaAluno, int *qtdAlunos){

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

void menuAlunos(Aluno *listaAluno, int *qtdAlunos){

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

void cadastroAluno(Aluno *listaAluno, int *qtdAlunos){
  
  if(qtdAlunos[0] == TamAluno){  
  //if(*qtdAlunos == TamAluno){
      printf("Lista de Alunos Cheia!\n");
  }else{
      printf("Digite a Matrícula do Aluno: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        listaAluno[qtdAlunos[0]].matricula = matricula;
        listaAluno[qtdAlunos[0]].status = 1;
        //*qtdAlunos++;
        qtdAlunos[0]++;

        //RECEBER O RESTO DOS DADOS DA STRUCT AQUI!
        
        printf("Cadastrado com Sucesso!\n");
                
      }
    } 
}

void listarAluno(Aluno *listaAluno, int *qtdAlunos){
  if (qtdAlunos[0] == 0) {
    printf("LISTA DE ALUNOS VAZIA\n");
  } else {
    for (int i = 0; i < qtdAlunos[0]; i++) {
      printf("Matrícula: %d\n", listaAluno[i].matricula);
    }
  }
}