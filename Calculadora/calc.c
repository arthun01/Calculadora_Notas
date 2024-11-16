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

// Códigos de reset
#define RESET          "\033[0m"

// Códigos de cores de texto
#define BLACK          "\033[30m"
#define RED            "\033[31m"
#define GREEN          "\033[32m"
#define WHITE          "\033[37m"

// Códigos de cores de fundo
#define BG_WHITE       "\033[47m"
#define BG_RED         "\033[41m"
#define BG_GREEN       "\033[42m"


int maiorCredito(int credito[], int tamanho); 

int main(){
    char nome[100];
    int qtd_mat = 0;

    printf("====================\n");
    printf("CALCULADORA DE NOTAS\n");
    printf("====================\n\n");

    //Input do nome
    printf("- Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    //Removendo a nova linha
    nome[strcspn(nome, "\n")] = '\0';

    //Input quantidade de materias
    do{
        printf("-----------------------------------------------\n");
        printf("- Quantidade de matérias no semestre:  ");
        scanf("%d", &qtd_mat);
    }while(qtd_mat < 1);
    printf("-----------------------------------------------\n");

    //array que vai armazenar quantos creditos tem cada materia, [4, 2, 5, 3]
    int creditos[qtd_mat];
    float medias[qtd_mat];

    //Pegando do usuario quantos creditos tem cada materia
    for(int i = 0; i < qtd_mat; i++){
        printf("- Quantos créditos tem a materia %d: ", i+1);
        scanf("%d", &creditos[i]);
    }
    printf("-----------------------------------------------\n");

    int tam = sizeof(creditos)/sizeof(creditos[0]);
    int maior_credito = maiorCredito(creditos, tam);


    float notas[maior_credito][qtd_mat];
    float notas_materia[qtd_mat];


    //preenchendo a matriz com Zeros para evitar lixo de memória
    for(int c = 0; c < maior_credito; c++){
        for(int v = 0; v < qtd_mat; v++){
            notas[c][v] = 0.0;
        }
        //preeenchendo as notas com zero para evitar lixo de memória
        notas_materia[c] = 0.0;
    }

    // Ler os valores da matriz coluna por coluna
    printf("-- INSIRA AS NOTAS --\n");
    for (int x = 0; x < qtd_mat; x++) {
        for (int y = 0; y < maior_credito; y++) {

            //Somando as notas
            if(y < creditos[x]){
                printf("%d° nota do crédito %d: ", y+1, x+1);
                scanf("%f", &notas[y][x]);
                notas_materia[x] += notas[y][x];
            }else{
                break;
            }
        }
    }

    float materias_perdidas[qtd_mat];

    //Mostrando o resultado
    printf("-----------------------------------------------\n");

    for(int d = 0; d < qtd_mat; d++){
        float media = notas_materia[d] / creditos[d];

        if(media >= 7.0){
            printf("Materia %d <-> " BG_WHITE GREEN "Média %.1f" RESET"\n", d+1, media);
            materias_perdidas[d] = 7.1;
        }else{
            printf("Materia %d <-> " BG_WHITE RED "Média %.1f" RESET "\n", d+1, media);
            materias_perdidas[d] = media;
        }
    }

    //--------------------------------------------------------------------//

    float final = 0.0;

    //erro aqui!!
    printf("-----------------------------------------------\n");
    printf("-- Boletim %s --\n", nome);
    printf("-----------------------------------------------\n");
    for(int count = 0; count < qtd_mat; count++){
        if(materias_perdidas[count] < 7.0){
            final = (5 - (materias_perdidas[count] * 0.6)) / 0.4;
            printf(BG_RED " " RESET " Vi que você perdeu na Matéria %d | Você precisa tirar " BG_WHITE BLACK "%.1f" RESET " na final para passar!!\n", count+1, final);
        }else{
            printf(BG_GREEN " " RESET " Vi que você passou na Matéria %d, meus parabêns!!\n", count+1);
        }
    }

    return 0;
}

//Função que retorna qual o maior credito para criar a matriz de notas
int maiorCredito(int credito[], int tamanho) {
    int maior = credito[0];

    for (int i = 1; i < tamanho; i++) {
        if (credito[i] > maior) {
            maior = credito[i];
        }
    }

    return maior;
}