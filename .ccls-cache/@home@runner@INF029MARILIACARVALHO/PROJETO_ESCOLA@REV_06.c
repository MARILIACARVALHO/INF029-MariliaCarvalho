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
  int codigoDisciplinasMatriculado; //COMO RELACIONAR?? puxar os códigos da Struct de Disciplinas

}Aluno;

typedef struct ficha_professor{
  int matricula;
  char nome[100];
  char sexo;
  data data;
  int cpf;

  int status;
  int codigoDisciplinasLecionando; //COMO RELACIONAR??
}Professor;

typedef struct ficha_disciplina{
  char nome[100]; 
  int codigo;
  int semestre;
  int status;

  int matriculaAlunos; //COMO RELACIONAR??
  int matriculaProfessores;  //COMO RELACIONAR??
    
}Disciplina;

//PROTÓTIPOS DAS FUNÇÕES:
void menuInicial(Aluno *listaAluno, int *qtdAlunos);  
//----------------FUNÇÕES ALUNO------------------
void menuAlunos(Aluno *listaAluno, int *qtdAlunos);
void cadastroAluno(Aluno *listaAluno, int *qtdAlunos);
void listarAluno(Aluno *listaAluno, int *qtdAlunos);
void excluirAluno(Aluno *listaAluno, int *qtdAlunos);
void atualizarAluno(Aluno *listaAluno, int *qtdAlunos);
//----------------FUNÇÕES PROFESSOR------------------

//----------------FUNÇÕES DISCIPLINA------------------


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
        atualizarAluno(listaAluno, qtdAlunos);
        break;
      }
      case 4:{
        printf("\nEXCLUIR ALUNO: \n");
        excluirAluno(listaAluno, qtdAlunos);
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
      printf("\nDigite a Matrícula do Aluno: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        Aluno a;
        a.matricula = matricula;
        printf("\nDigite o nome: ");
        scanf("\n");
        fgets(a.nome, 100, stdin);
        printf("Digite F ou M para o sexo: ");
        scanf("%c", &a.sexo);
        //CABE UMA VERIFICAÇÃO AQUI (while...)
        printf("Digite a data de nascimento no formato dd mm aaaa: ");
        scanf("%d%d%d", &a.data.dia, &a.data.mes, &a.data.ano);
        printf("Digite o CPF: ");
        scanf("%d", &a.cpf);
        a.status = 1;
        listaAluno[qtdAlunos[0]] = a;
        
        qtdAlunos[0]++;

        printf("Cadastrado com Sucesso!\n");
        
        //teste pra saber se tá incrementando a quantidade de alunos: (remover depois)
        printf("%d", qtdAlunos[0]);

        //return a;
                
      }
    } 
}

void listarAluno(Aluno *listaAluno, int *qtdAlunos){
  if (qtdAlunos[0] == 0) {
    printf("LISTA DE ALUNOS VAZIA\n");
  } else {
    for (int i = 0; i < qtdAlunos[0]; i++) {
      if(listaAluno[i].status==1){
      printf("\n\tAluno %d.:\n", i+1);
      printf("\nMatrícula: %d\n", listaAluno[i].matricula);
      printf("Nome: %s", listaAluno[i].nome);
      printf("Sexo: %c\n", listaAluno[i].sexo);
      printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
      printf("CPF: %d\n", listaAluno[i].cpf);
      }
      
    }
  }
}

void excluirAluno(Aluno *listaAluno, int *qtdAlunos){

  printf("\nDigite a Matrícula do Aluno: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        int achou = 0;
        for (int i = 0; i < qtdAlunos[0]; i++) {
          if(matricula== listaAluno[i].matricula){
            //apenas exclusão lógica:
            listaAluno[i].status = 0;
            for (int j = i; j < qtdAlunos[0]-1; j++){
              //shift = mover todos os alunos da frente p/ a casa anterior:
              listaAluno[j] = listaAluno[j+1];
            }
            qtdAlunos[0]--;
            achou = 1;
            break;
          }
        }
        if(achou==1)
          printf("ALUNO EXCLUIDO!\n");
        else
          printf("Matricula/Aluno não existe!\n");
      }
}

void atualizarAluno(Aluno *listaAluno, int *qtdAlunos){

  printf("\nDigite a Matrícula do Aluno: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        int achou = 0;
        for (int i = 0; i < qtdAlunos[0]; i++) {
          if(matricula == listaAluno[i].matricula && listaAluno[i].status==1){
            
            printf("\n\tDados Armazenados do aluno: ");
            printf("\nMatrícula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            printf("CPF: %d\n", listaAluno[i].cpf);
            //Atualização:
            printf("\nINSIRA OS DADOS ATUALIZADOS DO ALUNO REGISTRADO NA MATRÍCULA %d: ", matricula);
            listaAluno[i].matricula = matricula;
            printf("\nDigite o nome: ");
            scanf("\n");
            fgets(listaAluno[i].nome, 100, stdin);
            printf("Digite F ou M para o sexo: ");
            scanf("%c", &listaAluno[i].sexo);
            printf("Digite a data de nascimento no formato dd mm aaaa: ");
            scanf("%d%d%d", &listaAluno[i].data.dia, &listaAluno[i].data.mes, &listaAluno[i].data.ano);
            printf("Digite o CPF: ");
            scanf("%d", &listaAluno[i].cpf);
            listaAluno[i].status = 1;
               
            printf("\nDados ATUALIZADOS do aluno: ");
            printf("\nMatrícula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            printf("CPF: %d\n", listaAluno[i].cpf);
                     
            achou = 1;
            break;
          }
        }
        if(achou==1)
          printf("ALUNO ATUALIZADO!\n");
        else
          printf("Matricula/Aluno não existe!\n");
      }
}

/* CONCEITO DE CRUD:
                CREATE
                  READ
                    UPDATE
                      DELETE
                              */

/*    PRÓXIMOS PASSOS:
        1 - UTILIZAR UM GERADOR AUTOMÁTICO DE MATRÍCULA - FALTA!
        2- MODULARIZAÇÃO - FEITO!
        3 - NOVOS ATRIBUTOS NA STRUCT ALUNO E FAZER A LEITURA DESSES ATRIBUTOS - FEITO! 
        4 - VALIDAÇÕES - +-

        ->> DESCOBRIR COMO CORRELACIONAR ALUNOS, PROFESSORES E DISCIPLINAS
        ->> COPIAR TUDO DESDE O MENU ALUNO E REPLICAR COM AS DEVIDAS ALTERAÇÕES PARA PROFESSORES E DISCIPLINAS.
*/