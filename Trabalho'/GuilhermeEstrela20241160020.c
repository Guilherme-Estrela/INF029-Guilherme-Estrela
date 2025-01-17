// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "GuilhermeEstrela20241160020.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

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
int somar(int x, int y)
{
    int soma;
    soma = x + y;
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
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;
  DataQuebrada dq;

  int diasDoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  //quebrar a string data em strings sDia, sMes, sAno
  dq = quebraData (data);

if (dq.iAno < 100)
  dq.iAno += 2000;

//verifica se bisexto
if ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) || (dq.iAno % 400 == 0)) {
  diasDoMes[1] = 29;
 }
  
else {
  diasDoMes[1] = 28;
}

if (dq.iAno < 0)
  datavalida = 0;

if (dq.iMes < 1 || dq.iMes > 12)
  datavalida = 0;

if (dq.iDia < 1 || dq.iDia > diasDoMes[dq.iMes - 1])
 datavalida = 0;


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
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      DataQuebrada dqInicial, dqFinal;

      dqInicial = quebraData(datainicial);
      dqFinal = quebraData(datafinal);

      if (dqFinal.iAno < dqInicial.iAno){
        dma.retorno = 4;
        return dma;
      } else if (dqFinal.iAno == dqInicial.iAno && dqFinal.iMes < dqInicial.iMes){
        dma.retorno = 4;
        return dma;
      }  else if (dqFinal.iAno == dqInicial.iAno && dqFinal.iMes == dqInicial.iMes && dqFinal.iDia < dqInicial.iDia){
        dma.retorno = 4;
        return dma;
      }

      //calcule a distancia entre as datas
      int diasDoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

      if ((dqFinal.iAno % 4 == 0 && dqFinal.iAno % 100 != 0) || (dqFinal.iAno % 400 == 0)) {
        diasDoMes[1] = 29;
      }
  
      else {
        diasDoMes[1] = 28;
      }

      dma.qtdAnos = dqFinal.iAno - dqInicial.iAno;
      dma.qtdMeses = dqFinal.iMes - dqInicial.iMes;
      dma.qtdDias = dqFinal.iDia - dqInicial.iDia;

      if (dma.qtdMeses < 0){
        dma.qtdAnos -= 1;
        dma.qtdMeses = dma.qtdMeses + 12;
      }
      if (dma.qtdDias < 0){
        dma.qtdMeses -=  1;
        dma.qtdDias = dma.qtdDias + diasDoMes[dqFinal.iMes - 2];
        // - 2 pra oder pegar a qtd de dias do mes anterior do inforado no dqfinal.mes
      }

      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    char copia[250];

    for (int icont = 0; icont < strlen(texto); icont++)
      copia[icont] = texto[icont];

    if (isCaseSensitive == 1){
      for (int icont = 0; icont < strlen(copia); icont++)
        if (copia[icont] == c)
          qtdOcorrencias++;

    } else {
      if (c >= 'A' && c <= 'Z')
        c += 'a' - 'A';

      for (int icont = 0; icont < strlen(copia); icont++)
        if (copia[icont] >= 'A' && copia[icont] <= 'Z')
          copia[icont] += 'a' - 'A';

      for (int icont = 0; icont < strlen(copia); icont++)
        if (copia[icont] == c)
          qtdOcorrencias++;
      
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto 
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    char copia [250];
    int qtdOcorrencias = 0;
    int posicao = 0, inicio;


    for (int icont = 0; icont < strlen(strTexto); icont++)
      if (strTexto[icont] != -65)
        copia[icont] = strTexto[icont];

    for (int icont = 0; icont < strlen(copia); icont++){
      int jcont = 0;

      if (copia[icont] == strBusca[0]){
        inicio = icont+1;

        while (copia[icont] == strBusca[jcont] && jcont < strlen(strBusca)){
          icont++;
          jcont++;
        }
        
        if (jcont == strlen(strBusca))
        {
          posicoes[posicao] = inicio;
          posicao++;
          posicoes[posicao] = icont;
          posicao++;
          qtdOcorrencias++;
          icont--;
        }
        
      }
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

int q5(int num)
{
    int inverso = 0;

    while (num > 0){
      inverso += num%10;
      num /= 10;
      inverso *= 10;
    }

    num = inverso/10;

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

int q6(int numerobase, int numerobusca)
{ 
    int qtdOcorrencias = 0;
    char stringbase[250];
    char stringbusca[250];

    snprintf(stringbase, sizeof(stringbase), "%d", numerobase);
    snprintf(stringbusca, sizeof(stringbusca), "%d", numerobusca);

    int lenBase = strlen(stringbase);
    int lenBusca = strlen(stringbusca);

    for (int icont = 0; icont <= lenBase - lenBusca; icont++) {
        // Verificando se a substring a partir de 'i' corresponde a 'stringbusca'
        int iguais = 1;
        for (int jcont = 0; jcont < lenBusca; jcont++) {
            if (stringbase[icont + jcont] != stringbusca[jcont]) {
                iguais = 0;
                break;
            }
        }

        // Se encontrar uma correspondência, incrementa a contagem
        if (iguais) {
            qtdOcorrencias++;
            icont += lenBusca - 1;  // Avançar o índice para depois da correspondência
        }
    }

    return qtdOcorrencias;
}




DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

