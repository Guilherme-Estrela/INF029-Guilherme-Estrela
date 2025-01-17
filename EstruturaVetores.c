#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct Principal{
    int *aux;
    int tamanho;
    int posicaoAux;
    int temAux;
} Principal;

Principal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){

    int retorno = 0;

    // a posicao pode já existir estrutura auxiliar
    if (vetorPrincipal[posicao].temAux == 1)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;

    // se posição nao é um valor válido {entre 1 e 10}
    else if  (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    // o tamanho ser muito grande
    else if ((int *) malloc(sizeof(int) * tamanho) == NULL)
        retorno = SEM_ESPACO_DE_MEMORIA;

    // o tamanho nao pode ser menor que 1
    else if (tamanho < 1)
        retorno = TAMANHO_INVALIDO;
    
    // deu tudo certo, crie
    else{
        vetorPrincipal[posicao].aux  = (int *) malloc(sizeof(int) * tamanho);
        vetorPrincipal[posicao].posicaoAux = 0;
        vetorPrincipal[posicao].tamanho = tamanho;
        vetorPrincipal[posicao].temAux = 1;
        retorno = SUCESSO;
    }
    

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao].temAux == 1)
        {
            //ve se tem espaco
            if (vetorPrincipal[posicao].posicaoAux < vetorPrincipal[posicao].tamanho)
            {
                //insere
                vetorPrincipal[posicao].aux[vetorPrincipal[posicao].posicaoAux] = valor;
                vetorPrincipal[posicao].posicaoAux++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rcluido com sucesso
    ESTRUTURAertono (int)
    SUCESSO - ex_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if (vetorPrincipal[posicao].temAux == 0)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if (vetorPrincipal[posicao].posicaoAux < 1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
        vetorPrincipal[posicao].posicaoAux -= 1;
    return retorno;

    return retorno;

    
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'v
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar v
    NUMERO_INEXISTENTE - Número não existe v
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar v

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;

     //confere se é validop
    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao].temAux == 1)
        {
            if (vetorPrincipal[posicao].posicaoAux == 0)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else {
                
                //faz oq tiver q fazer
                int encontrou = 0;
                for (int icont = 0; icont < vetorPrincipal[posicao].tamanho; icont++){
                    if (vetorPrincipal[posicao].aux[icont] == valor)
                    {   
                        encontrou++;
                        //passa pra frente
                        for (int jcont = icont; jcont < vetorPrincipal[posicao].tamanho - 1; jcont++) {
                            vetorPrincipal[posicao].aux[jcont] = vetorPrincipal[posicao].aux[jcont + 1];
                        }
                        vetorPrincipal[posicao].posicaoAux--;
                    }
                    if (encontrou == 0)
                        retorno = NUMERO_INEXISTENTE;

                }

            }
        }
        else
        { 
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    
    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if (vetorPrincipal[posicao].temAux == 0)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if (vetorPrincipal[posicao].posicaoAux < 1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{
        for (int icont = 0; icont < vetorPrincipal[posicao].tamanho; icont++){
                vetorAux[icont] = vetorPrincipal[posicao].aux[icont];
            }
            retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if (vetorPrincipal[posicao].temAux == 0)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if (vetorPrincipal[posicao].posicaoAux < 1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{
        for (int icont = 0; icont < vetorPrincipal[posicao].tamanho; icont++){
                vetorAux[icont] = vetorPrincipal[posicao].aux[icont];
            }

        for (int icont = 0; icont < vetorPrincipal[posicao].tamanho; icont++) { 
		    int jcont = icont;
		    while (jcont > 0 && vetorAux[jcont] < vetorAux[jcont-1]) {
			    int aux = vetorAux[jcont];
			    vetorAux[jcont] = vetorAux[jcont - 1];
			    vetorAux[jcont - 1] = aux;
			    jcont -= 1;
		    }
	
	    }	
        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int contEstruturas = 0;
    int indexAux = 0;  

    for (int kcont = 0; kcont < TAM; kcont++) {
        if (vetorPrincipal[kcont].temAux == 0)
            continue; 

        if (vetorPrincipal[kcont].posicaoAux < 1)
            continue;  

        contEstruturas++;
        for (int icont = 0; icont < vetorPrincipal[kcont].tamanho; icont++) {
            vetorAux[indexAux] = vetorPrincipal[kcont].aux[icont];
            indexAux++;
        }
    }

    if (contEstruturas == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int contEstruturas = 0;
    int vet[20];
    int indexAux = 0; 

    for (int kcont = 0; kcont < TAM; kcont++){
        for (int kcont = 0; kcont < TAM; kcont++) {
        if (vetorPrincipal[kcont].temAux == 0)
            continue; 

        if (vetorPrincipal[kcont].posicaoAux < 1)
            continue;  

        contEstruturas++;
        for (int icont = 0; icont < 20; icont++)
            vet[icont] = 0;

        for (int icont = 0; icont < vetorPrincipal[kcont].tamanho; icont++)
            vet[icont] = vetorPrincipal[kcont].aux[icont];
        

            for (int icont = 0; icont < vetorPrincipal[kcont].tamanho; icont++) { 
		        int jcont = icont;
		        while (jcont > 0 && vet[jcont] < vet[jcont-1]) {
		            int aux = vet[jcont];
	                vet[jcont] = vet[jcont - 1];
	                vet[jcont - 1] = aux;
	                jcont -= 1;
	            }
            }

            for (int icont = 0; icont < vetorPrincipal[kcont].tamanho; icont++){
                vetorAux[indexAux] = vet[icont];
                indexAux++;
            }
        }

    }

    if (contEstruturas == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar v
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar v
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo x
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor v
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;

    // a posicao pode já existir estrutura auxiliar
    if (vetorPrincipal[posicao].temAux == 0)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    // se posição nao é um valor válido {entre 1 e 10}
    else if  (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    // o tamanho nao pode ser menor que 1
    else if (vetorPrincipal[posicao].tamanho + novoTamanho < 0)
        retorno = TAMANHO_INVALIDO;

    // o tamanho ser muito grande
    else if ((int *) malloc(sizeof(int) * (vetorPrincipal[posicao].tamanho + novoTamanho)) == NULL)
        retorno = SEM_ESPACO_DE_MEMORIA;
    else
     vetorPrincipal[posicao].aux = 
     (int *) realloc(vetorPrincipal[posicao].aux, sizeof(int) * (vetorPrincipal[posicao].tamanho + novoTamanho));

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar v
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia v
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;
    int icont = 0;

    if (vetorPrincipal[posicao].temAux == 0)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if  (vetorPrincipal[posicao].posicaoAux < 1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    
    else
        while (icont < vetorPrincipal[posicao].tamanho){
            if (vetorPrincipal[posicao].aux[icont] != 0)
                icont++;
            retorno = icont;
        }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for (int icont = 0; icont < TAM; icont++)
        vetorPrincipal[icont].temAux = 0;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}
