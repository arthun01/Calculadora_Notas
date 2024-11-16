#include <stdio.h>
#include <string.h>


int maiorCredito(int credito[], int tamanho); 

int main(){
    char nome[100];
    int qtd_mat = 0;

    printf("===================\n");
    printf("CALCULADORA DE NOTAS\n");
    printf("===================\n\n");

    //Input do nome
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    //Removendo a nova linha
    nome[strcspn(nome, "\n")] = '\0';

    //Input quantidade de materias
    do{
        printf("-----------------------------------------------\n");
        printf("Quantas matérias você está tendo no semestre %s? ", nome);
        scanf("%d", &qtd_mat);
    }while(qtd_mat < 1);
    printf("-----------------------------------------------\n");

    //array que vai armazenar quantos creditos tem cada materia, [4, 2, 5, 3]
    int creditos[qtd_mat];
    float medias[qtd_mat];

    //Pegando do usuario quantos creditos tem cada materia
    for(int i = 0; i < qtd_mat; i++){
        printf("Quantos créditos tem a materia %d: ", i+1);
        scanf("%d", &creditos[i]);
    }
    printf("-----------------------------------------------\n");

    int tam = sizeof(creditos)/sizeof(creditos[0]);
    int maior_credito = maiorCredito(creditos, tam);


    float notas[maior_credito][qtd_mat];


    //preenchendo a matriz com Zeros
    for(int c = 0; c < maior_credito; c++){
        for(int v = 0; v < qtd_mat; v++){
            notas[c][v] = 0.0;
        }
    }

    // Ler os valores da matriz coluna por coluna
    printf("-- INSIRA AS NOTAS --\n");
    for (int x = 0; x < qtd_mat; x++) {
        for (int y = 0; y < maior_credito; y++) {

            if(y >= creditos[x]){
                break;
            }else{
                printf("%d° nota do crédito %d: ", y+1, x+1);
                scanf("%f", &notas[y][x]);
            }
        }
    }

    // Imprimir a matriz no formato tradicional (linha por linha)
    printf("\nNotas:\n");
    for (int n = 0; n < maior_credito; n++) {
        for (int m = 0; m < qtd_mat; m++) {
            printf("%.2f ", notas[n][m]);
        }
        printf("\n");
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