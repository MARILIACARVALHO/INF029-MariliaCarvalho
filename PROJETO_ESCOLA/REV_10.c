/* ARQUIVO "run.sh" pra rodar automaticamente com o botão RUN:
cd PROJETO_ESCOLA
gcc REV_10.c -o REV_10
./REV_10
*/


#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define TamAluno 3
#define TamProfessor 3
#define TamTurma 30
#define TamGradeAluno 5


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
  int codigoDisciplinasMatriculado[TamGradeAluno];
  int numDisciplinas;

}Aluno;

typedef struct ficha_professor{
  int matricula;
  char nome[100];
  char sexo;
  data data;
  int cpf;

  int status;
  //int codigoDisciplinasLecionando; //COMO RELACIONAR?? - IMPLEMENTAR FUTURAMENTE!
}Professor;

typedef struct ficha_disciplina{
  char nome[100]; 
  int codigo;
  int semestre;
  int status;

  int matriculaAlunos[TamTurma];
  int numAlunos;
  
  //int matriculaProfessores; //COMO RELACIONAR?? - IMPLEMENTAR FUTURAMENTE!
    
}Disciplina;

//PROTÓTIPOS DAS FUNÇÕES:
void menuInicial(Aluno *listaAluno, int *qtdAlunos, Disciplina *listaDisciplina, int *qtdDisciplinas, Professor *listaProfessor, int *qtdProfessores);  
//----------------FUNÇÕES ALUNO-------------------------------------------
void menuAlunos(Aluno *listaAluno, int *qtdAlunos);
void cadastroAluno(Aluno *listaAluno, int *qtdAlunos);
void listarAluno(Aluno *listaAluno, int *qtdAlunos);
void excluirAluno(Aluno *listaAluno, int *qtdAlunos);
void atualizarAluno(Aluno *listaAluno, int *qtdAlunos);
//----------------FUNÇÕES PROFESSOR---------------------------------------
void menuProfessores(Professor *listaProfessor, int *qtdProfessores);
void cadastroProfessor(Professor *listaProfessor, int *qtdProfessores);
void listarProfessor(Professor *listaProfessor, int *qtdProfessores);
void excluirProfessor(Professor *listaProfessor, int *qtdProfessores);
void atualizarProfessor(Professor *listaProfessor, int *qtdProfessores);
//----------------FUNÇÕES DISCIPLINA--------------------------------------
void menuDisciplinas(Disciplina *listaDisciplina, int *qtdDisciplinas);
void cadastroDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas);
void listarDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas);
void excluirDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas);
void atualizarDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas);
//-------------------------------------------------------------------------

//ALTERAR PARA main:
int main1(void) {

  Aluno listaAluno[TamAluno];
  int qtdAlunos[1];
  qtdAlunos[0] = 0;

  Disciplina listaDisciplina[TamTurma];
  int qtdDisciplinas[1];
  qtdDisciplinas[0] = 0;

  Professor listaProfessor[TamProfessor];
  int qtdProfessores[1];
  qtdProfessores[0] = 0;
      
  menuInicial(listaAluno, qtdAlunos, listaDisciplina, qtdDisciplinas, listaProfessor, qtdProfessores);  //CHAMANDO A FUNÇÃO

  return 0;
}

void menuInicial(Aluno *listaAluno, int *qtdAlunos, Disciplina *listaDisciplina, int *qtdDisciplinas, Professor *listaProfessor, int *qtdProfessores){

  int opcao;
  int sair = 0;

  while(sair==0){
  
    printf("\n\nPROJETO ESCOLA - Escolha a Opção desejada: \n");
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
        printf("\n\tMENU ALUNOS\n");
        menuAlunos(listaAluno, qtdAlunos);
        break;
      }
      case 2:{
        printf("\n\tMENU PROFESSORES\n");
        menuProfessores(listaProfessor, qtdProfessores);
        break;
      }
      case 3:{
        printf("\n\tMENU DISCIPLINAS\n");
        menuDisciplinas(listaDisciplina, qtdDisciplinas);
        break;
      }
      default: {
        printf("\n\tOPÇÃO INVÁLIDA\n");
      }

    }
  }
  
}

//------------------  FUNÇÕES ALUNOS: -----------------------------------------------

void menuAlunos(Aluno *listaAluno, int *qtdAlunos){

  int opcao;
  int sair = 0;

  while(sair==0){
  
    printf("\n0 - VOLTAR\n");
    printf("\n1 - CADASTRAR ALUNO\n");
    printf("\n2 - LISTAR ALUNOS\n");
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
        printf("\nLISTAR ALUNOS: \n");
        listarAluno(listaAluno, qtdAlunos);
        break;
      }
      case 3:{
        printf("\nATUALIZAR ALUNOS: \n");
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
          //EM QUANTAS E QUAIS DISCIPLINAS O ALUNO ESTÁ MATRICULADO?
        printf("Em quantas disciplinas o aluno está matriculado? MIN = 1 e MAX = %d\n", TamGradeAluno);
        int numDisciplinas;
        scanf("%d", &numDisciplinas);
        a.numDisciplinas = numDisciplinas;
        printf("Digite o codigo das disciplinas as quais o aluno esta matriculado:\n");
        for(int i = 0; i<a.numDisciplinas; i++){
          int codigo;
          scanf("%d", &codigo);
          a.codigoDisciplinasMatriculado[i] = codigo;
        }
        
        listaAluno[qtdAlunos[0]] = a;
        
        qtdAlunos[0]++;

        printf("Cadastrado com Sucesso!\n");
        
        //teste pra saber se tá incrementando a quantidade de alunos: (remover depois)
        //printf("%d", qtdAlunos[0]);          
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
        printf("O aluno esta matriculado em %d disciplinas:", listaAluno[i].numDisciplinas);
        printf("\n\tCodigos disciplinas:");
        for(int j = 0; j<listaAluno[i].numDisciplinas; j++){
          printf("\n\t\t\t\t\t%d", listaAluno[i].codigoDisciplinasMatriculado[j]);
        }
        printf("\n");
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
          if(matricula == listaAluno[i].matricula){
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
            //Dados armazenados:
            printf("\n\tDados Armazenados do aluno: ");
            printf("\nMatrícula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            printf("CPF: %d\n", listaAluno[i].cpf);
                //Disciplinas:
            printf("O aluno esta matriculado em %d disciplinas:", listaAluno[i].numDisciplinas);
            printf("\n\tCodigos disciplinas:");
            for(int j = 0; j<listaAluno[i].numDisciplinas; j++){
              printf("\n\t\t\t\t\t%d", listaAluno[i].codigoDisciplinasMatriculado[j]);
            }
            printf("\n");
            
            //Recebendo Atualização dos dados:
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
                 //disciplinas:
            printf("Em quantas disciplinas o aluno está matriculado? MIN = 1 e MAX = %d\n", TamGradeAluno);
            int numDisciplinas;
            scanf("%d", &numDisciplinas);
            listaAluno[i].numDisciplinas = numDisciplinas;
            printf("Digite o codigo das disciplinas as quais o aluno esta matriculado:\n");
            for(int j = 0; j<listaAluno[i].numDisciplinas; j++){
              int codigo;
              scanf("%d", &codigo);
              listaAluno[i].codigoDisciplinasMatriculado[j] = codigo;
            }
            
            //Exibindo os dados atualizados:   
            printf("\nDados ATUALIZADOS do aluno: ");
            printf("\nMatrícula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            printf("CPF: %d\n", listaAluno[i].cpf);
                  //disciplinas:
            printf("O aluno esta matriculado em %d disciplinas:", listaAluno[i].numDisciplinas);
            printf("\n\tCodigos disciplinas:");
            for(int j = 0; j<listaAluno[i].numDisciplinas; j++){
              printf("\n\t\t\t\t\t%d", listaAluno[i].codigoDisciplinasMatriculado[j]);
            }
            printf("\n");
                     
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
            (terminar aulas do prof, ver aulas da playlist que descobri sobre struct, curso udemy)
        ->> COPIAR TUDO DESDE O MENU ALUNO E REPLICAR COM AS DEVIDAS ALTERAÇÕES PARA PROFESSORES E DISCIPLINAS.
*/

//------------------  FUNÇÕES DISCIPLINAS: -----------------------------------------------

void menuDisciplinas(Disciplina *listaDisciplina, int *qtdDisciplinas){

  int opcao;
  int sair = 0;

  while(sair==0){
  
    printf("\n0 - VOLTAR\n");
    printf("\n1 - CADASTRAR DISCIPLINA\n");
    printf("\n2 - LISTAR DISCIPLINAS\n");
    printf("\n3 - ATUALIZAR DISCIPLINA\n");
    printf("\n4 - EXCLUIR DISCIPLINA\n\n");
  
    scanf("%d", &opcao);

    switch (opcao){

      case 0:{
        sair=1;
        break;
      }
      case 1:{
        printf("\nCADASTRAR DISCIPLINA: \n");
        cadastroDisciplina(listaDisciplina, qtdDisciplinas);
        break;
      }
      case 2:{
        printf("\nLISTAR DISCIPLINAS: \n");
        listarDisciplina(listaDisciplina, qtdDisciplinas);
        break;
      }
      case 3:{
        printf("\nATUALIZAR DISCIPLINAS: \n");
        atualizarDisciplina(listaDisciplina, qtdDisciplinas);
        break;
      }
      case 4:{
        printf("\nEXCLUIR DISCIPLINA: \n");
        excluirDisciplina(listaDisciplina, qtdDisciplinas);
        break;
      }
      default: {
        printf("\nOPÇÃO INVÁLIDA! ESCOLHA NOVAMENTE: \n");
      }

    }
  }
}

void cadastroDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas){
  
  if(qtdDisciplinas[0] == TamGradeAluno){  
  
      printf("Lista de Disciplinas Cheia!\n");
  }else{
      printf("\nDigite o codigo do Disciplina: ");
      int codigo;
      scanf("%d", &codigo);
      if (codigo<0){
        printf("Codigo Invalido!\n");
      }else{
        Disciplina a;
        a.codigo = codigo;
        printf("\nDigite o nome: ");
        scanf("\n");
        fgets(a.nome, 100, stdin);
              
        printf("Digite o semestre da disciplina: ");
        scanf("%d", &a.semestre);
        a.status = 1;
          //QUANTOS ALUNOS E QUAIS ALUNOS ESTÃO MATRICULADOS NA DISCIPLINA?
        printf("Quantos alunos estao matriculados na disciplina? MIN = 1 e MAX = %d\n", TamTurma);
        int numAlunos;
        scanf("%d", &numAlunos);
        a.numAlunos = numAlunos;
        printf("Digite a matricula dos alunos que estão matriculados:\n");
        for(int i = 0; i<a.numAlunos; i++){
          int matricula;
          scanf("%d", &matricula);
          a.matriculaAlunos[i] = matricula;
        }
        
        listaDisciplina[qtdDisciplinas[0]] = a;
        
        qtdDisciplinas[0]++;

        printf("Cadastrado com Sucesso!\n");
         
      }
    } 
}

void listarDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas){
  if (qtdDisciplinas[0] == 0) {
    printf("LISTA DE DISCIPLINAS VAZIA\n");
  } else {
    for (int i = 0; i < qtdDisciplinas[0]; i++) {
      if(listaDisciplina[i].status==1){
        printf("\n\tDisciplina %d.:\n", i+1);
        printf("\nMatrícula: %d\n", listaDisciplina[i].codigo);
        printf("Nome: %s", listaDisciplina[i].nome);
        printf("Semestre da Disciplina: %d\n", listaDisciplina[i].semestre);
        printf("A Disciplina possui %d alunos matriculados", listaDisciplina[i].numAlunos);
        printf("\n\tMatricula dos Alunos:");
        for(int j = 0; j<listaDisciplina[i].numAlunos; j++){
          printf("\n\t\t\t\t\t%d", listaDisciplina[i].matriculaAlunos[j]);
        }
        printf("\n");
      }
    }
  }
}

void excluirDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas){

  printf("\nDigite o Codigo do Disciplina: ");
      int codigo;
      scanf("%d", &codigo);
      if (codigo<0){
        printf("Codigo Inválida!\n");
      }else{
        int achou = 0;
        for (int i = 0; i < qtdDisciplinas[0]; i++) {
          if(codigo == listaDisciplina[i].codigo){
            //apenas exclusão lógica:
            listaDisciplina[i].status = 0;
            for (int j = i; j < qtdDisciplinas[0]-1; j++){
              //shift = mover todos os Disciplinas da frente p/ a casa anterior:
              listaDisciplina[j] = listaDisciplina[j+1];
            }
            qtdDisciplinas[0]--;
            achou = 1;
            break;
          }
        }
        if(achou==1)
          printf("DISCIPLINA EXCLUIDO!\n");
        else
          printf("Codigo/Disciplina não existe!\n");
      }
}

void atualizarDisciplina(Disciplina *listaDisciplina, int *qtdDisciplinas){

  printf("\nDigite a Codigo da Disciplina: ");
      int codigo;
      scanf("%d", &codigo);
      if (codigo<0){
        printf("Codigo Inválido!\n");
      }else{
        int achou = 0;
        for (int i = 0; i < qtdDisciplinas[0]; i++) {
          if(codigo == listaDisciplina[i].codigo && listaDisciplina[i].status==1){
            //Dados armazenados:
            printf("\n\tDados Armazenados do Disciplina: ");
            printf("\nCodigo: %d\n", listaDisciplina[i].codigo);
            printf("Nome: %s", listaDisciplina[i].nome);
            printf("Semestre: %d\n", listaDisciplina[i].semestre);
                //Alunos:
            printf("Quantidade de Alunos nessa disciplina: %d", listaDisciplina[i].numAlunos);
            printf("\n\tMatriculas Alunos:");
            for(int j = 0; j<listaDisciplina[i].numAlunos; j++){
              printf("\n\t\t\t\t\t%d", listaDisciplina[i].matriculaAlunos[j]);
            }
            printf("\n");
            
            //Recebendo Atualização dos dados:
            printf("\nINSIRA OS DADOS ATUALIZADOS DO DISCIPLINA REGISTRADO NA MATRÍCULA %d: ", codigo);
            listaDisciplina[i].codigo = codigo;
            printf("\nDigite o nome: ");
            scanf("\n");
            fgets(listaDisciplina[i].nome, 100, stdin);
            printf("Digite o semestre: ");
            scanf("%d", &listaDisciplina[i].semestre);
            listaDisciplina[i].status = 1;
                 //Alunos:
            printf("Quantos Alunos estão matriculados na disciplina? MIN = 1 e MAX = %d\n", TamTurma);
            int numAlunos;
            scanf("%d", &numAlunos);
            listaDisciplina[i].numAlunos = numAlunos;
            printf("Digite o codigo das disciplinas as quais o Disciplina esta codigodo:\n");
            for(int j = 0; j<listaDisciplina[i].numAlunos; j++){
              int codigo;
              scanf("%d", &codigo);
              listaDisciplina[i].matriculaAlunos[j] = codigo;
            }
            
            //Exibindo os dados atualizados:   
            printf("\nDados ATUALIZADOS do Disciplina: ");
            printf("\nMatrícula: %d\n", listaDisciplina[i].codigo);
            printf("Nome: %s", listaDisciplina[i].nome);
            printf("Semestre: %d\n", listaDisciplina[i].semestre);
                  //Alunos:
            printf("Quantidade de Alunos nessa disciplina: %d", listaDisciplina[i].numAlunos);
            printf("\n\tMatriculas Alunos:");
            for(int j = 0; j<listaDisciplina[i].numAlunos; j++){
              printf("\n\t\t\t\t\t%d", listaDisciplina[i].matriculaAlunos[j]);
            }
            printf("\n");
                       
            achou = 1;
            break;
          }
        }
        if(achou==1)
          printf("DISCIPLINA ATUALIZADA!\n");
        else
          printf("Codigo/Disciplina não existe!\n");
      }
}

//------------------  FUNÇÕES PROFESSORES: -----------------------------------------------

void menuProfessores(Professor *listaProfessor, int *qtdProfessores){

  int opcao;
  int sair = 0;

  while(sair==0){
  
    printf("\n0 - VOLTAR\n");
    printf("\n1 - CADASTRAR PROFESSOR\n");
    printf("\n2 - LISTAR PROFESSORES\n");
    printf("\n3 - ATUALIZAR PROFESSOR\n");
    printf("\n4 - EXCLUIR PROFESSOR\n\n");
  
    scanf("%d", &opcao);

    switch (opcao){

      case 0:{
        sair=1;
        break;
      }
      case 1:{
        printf("\nCADASTRAR PROFESSOR: \n");
        cadastroProfessor(listaProfessor, qtdProfessores);
        break;
      }
      case 2:{
        printf("\nLISTAR PROFESSORES: \n");
        listarProfessor(listaProfessor, qtdProfessores);
        break;
      }
      case 3:{
        printf("\nATUALIZAR PROFESSORES: \n");
        atualizarProfessor(listaProfessor, qtdProfessores);
        break;
      }
      case 4:{
        printf("\nEXCLUIR PROFESSOR: \n");
        excluirProfessor(listaProfessor, qtdProfessores);
        break;
      }
      default: {
        printf("\nOPÇÃO INVÁLIDA! ESCOLHA NOVAMENTE: \n");
      }

    }
  }
}

void cadastroProfessor(Professor *listaProfessor, int *qtdProfessores){
  
  if(qtdProfessores[0] == TamProfessor){  
      printf("Lista de Professores Cheia!\n");
  }else{
      printf("\nDigite a Matrícula do Professor: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        Professor a;
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
          //EM QUANTAS disciplinas O PROFESSOR leciona? futuro!!!
       
        listaProfessor[qtdProfessores[0]] = a;
        
        qtdProfessores[0]++;

        printf("Cadastrado com Sucesso!\n");
        
        //teste pra saber se tá incrementando a quantidade de Professores: (remover depois)
        //printf("%d", qtdProfessores[0]);          
      }
    } 
}

void listarProfessor(Professor *listaProfessor, int *qtdProfessores){
  if (qtdProfessores[0] == 0) {
    printf("LISTA DE PROFESSORES VAZIA\n");
  } else {
    for (int i = 0; i < qtdProfessores[0]; i++) {
      if(listaProfessor[i].status==1){
        printf("\n\tProfessor %d.:\n", i+1);
        printf("\nMatrícula: %d\n", listaProfessor[i].matricula);
        printf("Nome: %s", listaProfessor[i].nome);
        printf("Sexo: %c\n", listaProfessor[i].sexo);
        printf("Data de Nascimento: %d/%d/%d\n", listaProfessor[i].data.dia, listaProfessor[i].data.mes, listaProfessor[i].data.ano);
        printf("CPF: %d\n", listaProfessor[i].cpf);
      }
    }
  }
}

void excluirProfessor(Professor *listaProfessor, int *qtdProfessores){

  printf("\nDigite a Matrícula do Professor: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        int achou = 0;
        for (int i = 0; i < qtdProfessores[0]; i++) {
          if(matricula == listaProfessor[i].matricula){
            //apenas exclusão lógica:
            listaProfessor[i].status = 0;
            for (int j = i; j < qtdProfessores[0]-1; j++){
              //shift = mover todos os Professores da frente p/ a casa anterior:
              listaProfessor[j] = listaProfessor[j+1];
            }
            qtdProfessores[0]--;
            achou = 1;
            break;
          }
        }
        if(achou==1)
          printf("PROFESSOR EXCLUIDO!\n");
        else
          printf("Matricula/Professor não existe!\n");
      }
}

void atualizarProfessor(Professor *listaProfessor, int *qtdProfessores){

  printf("\nDigite a Matrícula do Professor: ");
      int matricula;
      scanf("%d", &matricula);
      if (matricula<0){
        printf("Matrícula Inválida!\n");
      }else{
        int achou = 0;
        for (int i = 0; i < qtdProfessores[0]; i++) {
          if(matricula == listaProfessor[i].matricula && listaProfessor[i].status==1){
            //Dados armazenados:
            printf("\n\tDados Armazenados do Professor: ");
            printf("\nMatrícula: %d\n", listaProfessor[i].matricula);
            printf("Nome: %s", listaProfessor[i].nome);
            printf("Sexo: %c\n", listaProfessor[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaProfessor[i].data.dia, listaProfessor[i].data.mes, listaProfessor[i].data.ano);
            printf("CPF: %d\n", listaProfessor[i].cpf);
                
            //Recebendo Atualização dos dados:
            printf("\nINSIRA OS DADOS ATUALIZADOS DO PROFESSOR REGISTRADO NA MATRÍCULA %d: ", matricula);
            listaProfessor[i].matricula = matricula;
            printf("\nDigite o nome: ");
            scanf("\n");
            fgets(listaProfessor[i].nome, 100, stdin);
            printf("Digite F ou M para o sexo: ");
            scanf("%c", &listaProfessor[i].sexo);
            printf("Digite a data de nascimento no formato dd mm aaaa: ");
            scanf("%d%d%d", &listaProfessor[i].data.dia, &listaProfessor[i].data.mes, &listaProfessor[i].data.ano);
            printf("Digite o CPF: ");
            scanf("%d", &listaProfessor[i].cpf);
            listaProfessor[i].status = 1;
            
            //Exibindo os dados atualizados:   
            printf("\nDados ATUALIZADOS do Professor: ");
            printf("\nMatrícula: %d\n", listaProfessor[i].matricula);
            printf("Nome: %s", listaProfessor[i].nome);
            printf("Sexo: %c\n", listaProfessor[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaProfessor[i].data.dia, listaProfessor[i].data.mes, listaProfessor[i].data.ano);
            printf("CPF: %d\n", listaProfessor[i].cpf);
                     
            achou = 1;
            break;
          }
        }
        if(achou==1)
          printf("PROFESSOR ATUALIZADO!\n");
        else
          printf("Matricula/Professor não existe!\n");
      }
}