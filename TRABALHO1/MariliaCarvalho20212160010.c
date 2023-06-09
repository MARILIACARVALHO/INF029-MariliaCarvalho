// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome: Marilia Brito de Carvalho
//  email: eng.mariliacarvalho@gmail.com
//  Matrícula: 202160010
//  Semestre:  3º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "MariliaCarvalho20212160010.h" // Substitua pelo seu arquivo de header renomeado
#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <string.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  printf("\n");
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  printf("\n");
  return fat;
}

int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

DataQuebrada quebraData(char data[]) {
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd e mm podem ter apenas um digito, e aaaa podem
ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */

/* MARILIA: minhas observações :
  pode usar str linha
  ->conferir tamanho
  -> conferir SE É INTEIRO

  -> QUEBRAR A STRING / jogar em uma variável string/ converter p/ inteiro:
  fazer um for procurando a barra, tudo que tiver antes joga na variável dia,
  depois continua até ter 3 variáveis. função atoi é um termo da computação que
  designa uma função da linguagem C ou C++ que converte strings em números
  inteiros no ano se tiver apenas 2 dígitos, eu somo com 2000. ex: "95" vai
  ficar "2095". Ver regra do ano BISSEXTO.
*/

int validarAno(int ano) {

  if (ano < 100)
    ano = ano + 2000;

  if ((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0)))
    return 1;
  // Ano Bissexto
  else
    return 0;
  // Ano não Bissexto
}

int validarMes(int mes) {

  if (mes > 12 || mes < 1)
    return 0;
  else
    return 1;
}

int contarDias(int mes, int ano) {
  int bissexto = validarAno(ano);
  int maxDias;

  if (mes == 2) {
    if (bissexto == 1) {
      maxDias = 29;
    } else {
      maxDias = 28;
    }
  } else {
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
      maxDias = 30;
    else
      maxDias = 31;
  }

  return maxDias;
}

int validarDia(int dia, int mes, int ano) {

  int maxDias = contarDias(mes, ano);

  if (dia > maxDias)
    return 0;
  else
    return 1;
}

int q1(char data[]) {
  int datavalida = 1;

  // scanf("%s", data);

  // quebrar a string data em strings sDia, sMes, sAno

  DataQuebrada dataQuebrada = quebraData(data);
  // if (dataQuebrada.valido == 0) return 0;

  int dia = validarDia(dataQuebrada.iDia, dataQuebrada.iMes, dataQuebrada.iAno);
  int mes = validarMes(dataQuebrada.iMes);

  if (dia == 1 && mes == 1)
    datavalida = 1;
  else
    datavalida = 0;

  // printf("%s\n", data);

  if (datavalida)
    return 1;
  else
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) {

  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  int diaI, mesI, anoI, diaF, mesF, anoF;
  DataQuebrada DataInicialQuebrada, DataFinalQuebrada;

  DataInicialQuebrada = quebraData(datainicial);
  diaI = DataInicialQuebrada.iDia;
  mesI = DataInicialQuebrada.iMes;
  anoI = DataInicialQuebrada.iAno;

  DataFinalQuebrada = quebraData(datafinal);
  diaF = DataFinalQuebrada.iDia;
  mesF = DataFinalQuebrada.iMes;
  anoF = DataFinalQuebrada.iAno;

  dma.qtdDias = 0;
  dma.qtdMeses = 0;
  dma.qtdAnos = 0;

  /*dma.qtdDias = datainicial.iDia;
  dma.qtdMeses = datainicial.iMes;
  dma.qtdAnos = datainicial.iAno;*/

  if (q1(datainicial) == 0) {
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3;
    return dma;
  } else {
    // verifique se a data final não é menor que a data inicial:
    if (anoF < anoI) {
      dma.retorno = 4;
      return dma;
    } else if ((anoF = anoI) && (mesF < mesI)) {
      dma.retorno = 4;
      return dma;
    } else if ((anoF = anoI) && (mesF = mesI) && (diaF < diaI)) {
      dma.retorno = 4;
      return dma;
    }
    // calcule a distancia entre as datas
    else {
      dma.qtdDias = diaF - diaI;
      dma.qtdMeses = mesF - mesI;
      dma.qtdAnos = anoF - anoI;

      // se tudo der certo:
      if ((dma.qtdDias >= 0) && (dma.qtdMeses >= 0) && (dma.qtdAnos >= 0)) {
        dma.retorno = 1;
        return dma;
      }
    }
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {

  int qtdOcorrencias = 0;
  char textoCop[strlen(texto)];
  int i, j;

  if (isCaseSensitive ==
      1) { // Considerar diferenças entre maiúsculas e minúsculas
    for (i = 0; i < strlen(texto); i++) {
      if (c == texto[i]) {
        qtdOcorrencias++;
      }
    }
  } else {
    for (j = 0; j < strlen(texto); j++) {
      textoCop[j] = texto[j];
    }
    textoCop[j] = '\0';

    for (i = 0; i < j; i++) {
      if (textoCop[i] >= 65 && textoCop[i] <= 90)
        textoCop[i] = texto[i] + 32;
    }
    texto[i] = '\0';

    if (c >= 65 && c <= 90)
      c = c + 32;

    for (i = 0; i < strlen(texto); i++) {
      if (c == textoCop[i])
        qtdOcorrencias++;
    }
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {

  int qtdOcorrencias = 0;

  int i, j, aux, aux2;
  int k = 0;

  int auxiliarStr[250];
  int auxiliarBsc[250];
  int m, n = 0;

  // Remover acentos do texto:
  for (m = 0; m < strlen(strTexto); m++) {
    if (strTexto[m] != -61) {
      auxiliarStr[n] = strTexto[m];
      n++;
    }
  }

  // Remover acentos da busca:
  n = 0;
  for (m = 0; m < strlen(strBusca); m++) {
    if (strBusca[m] != -61) {
      auxiliarBsc[n] = strBusca[m];
      n++;
    }
  }

  // Busca no texto e salva as posições inicial e final
  for (i = 0, j = 0; i < strlen(strTexto); i++) {
    if (auxiliarBsc[j] == auxiliarStr[i]) {
      aux = i + 1;
      while (auxiliarBsc[j] == auxiliarStr[i] && j < n) {
        i++;
        j++;
      }
      aux2 = i;
      i--;
      if (aux2 - aux + 1 == strlen(strBusca)) {
        posicoes[k] = aux;
        k++;
        posicoes[k] = aux2;
        k++;
        qtdOcorrencias++;
      }
    }
    j = 0;
  }
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

double potenciacao(double base, int expoente) { // Função para a questão 5
  double resultado = 1.0;

  if (expoente >= 0) {
    for (int i = 0; i < expoente; i++) {
      resultado *= base;
    }
  } else {
    for (int i = 0; i < -expoente; i++) {
      resultado /= base;
    }
  }

  return resultado;
}

int q5(int num) {
  int digitos = 0;
  int invertido = 0, copia = num;
  int i; // TALVEZ deva ser double

  // Conta quantos dígitos o número tem:
  while (copia != 0) {
    digitos++;
    copia = copia / 10;
  }

  // Multiplica o número pela potência equivalente à sua posição

  for (i = digitos - 1; i >= 0; i--) {
    invertido = invertido + ((num % 10) * potenciacao(10, i));
    num = num / 10;
  }

  num = invertido;
  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {

  int qtdOcorrencias = 0;

  int decompBase[10], decompBusca[10], i, j;
  int inBsc = 0, inBas = 0;

  // Vetor com o numero base decomposto
  while (numerobase > 0) {
    decompBase[inBas] = numerobase % 10;
    inBas++;
    numerobase = numerobase / 10;
  }

  // Vetor com o numero de busca decomposto
  while (numerobusca > 0) {
    decompBusca[inBsc] = numerobusca % 10;
    inBsc++;
    numerobusca = numerobusca / 10;
  }

  // Teste de quantas vezes o numero se repete, considerando o tamanho dos
  // vetores
  for (i = 0, j = 0; i < inBas; i++) {
    if (decompBase[i] == decompBusca[j]) {
      while (decompBase[i] == decompBusca[j] && j < inBsc) {
        i++;
        j++;
      }
      i--;
      if (j == inBsc) {
        qtdOcorrencias++;
      }
    }
    j = 0;
  }
  return qtdOcorrencias;
}