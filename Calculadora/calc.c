/*
- Autor: Arthur Ramos Vieira
- Algoritmo de Média Ponderada e Nota Final
    1° pergunta o nome
    2° pergunta quantas matérias tem no semestra
    3° pergunta quantos créditos tem cada uma
    4° pergunta as notas de cada crédito e guarda em uma matriz
    5° tira a média de cada crédito
    6° mostra as médias
    7° ve se passou ou não
    8° se não, calcula quanto precisa na final e mostra
*/


//Bibliotecas utilizadas
#include <stdio.h>
#include <string.h>
#include "./libs/cores.h"

void calc(int qtd_cred);


int main(){
    char nome[100];
    int qtd_cred, qtd_mats;

    printf("====================\n");
    printf("CALCULADORA DE NOTAS\n");
    printf("====================\n\n");

    //Input do nome
    printf("- Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    //Removendo a nova linha
    nome[strcspn(nome, "\n")] = '\0';

    printf("- Digite a quantidade de matérias: ");
    scanf("%d", &qtd_mats);

    for(int i = 0; i < qtd_mats; i++){
        printf("- Digite quantos créditos tem a matéria %d: ", i+1);
        scanf("%d", &qtd_cred);
        calc(qtd_cred);
    }

}

void calc(int qtd_cred){
    float notas[qtd_cred];
    float media = 0;

    for(int i = 0; i < qtd_cred; i++){
        printf("-- Nota %d: ", i+1);
        scanf("%f", &notas[i]);
        media += notas[i];
    }
    printf("\n");

    media /= qtd_cred;

    float final = ((5 - (media * 0.6)) / 0.4);

    if(media > 6.99){
        printf( GREEN "Média %.2f - " RESET, media);
        printf("Parabéns, você passou na matéria!!\n");
    }else{
        printf( RED "Média %.2f - " RESET, media);
        printf("Vi que você perder na matéria e precisa de %.2f na final!!\n", final);
    }    
}