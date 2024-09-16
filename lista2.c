#include <stdio.h>

    int Maior(int a, int b) {
        if (a>b){
            return a;
        }
        else{
            return b;
        }
    }
    
    float mediaTres(float a, float b, float c) {
        float vetor[3]={a, b, c}, soma=0;
        int cont=0;
        for(int i=0; i<3; i++){
            if (vetor[i]>0){
                soma += vetor[i];
                cont++;
            }
        }
        return (soma/cont);
    }

    void ordem(int num[], int tam, int a){
        printf("\nO vetor original eh: |");
            for (int i=0; i<tam; i++){
                printf("%d |", num[i]);
            }
            for (int i = 0; i < tam-1; i++) {
                for (int j = 0; j < tam-1 - i; j++){
                if (Maior(num[j],num[j + 1]) == num[j]) {
                    int temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                }
            }
        }
        if(a){
            printf("\nO vetor na ordem crescente eh: |");
            for (int i=0; i<tam; i++){
                printf("%d |", num[i]); 
            }
            printf("\n");
        }
        else{
            printf("\nO vetor na ordem decrescente eh: |");
            for (int i=tam-1; i>=0; i--){
            printf("%d |", num[i]); 
            }
            printf("\n");
        }
    }

    void funcao1(){
        float notas[3]={0}, maior=0, media=0;
        printf("\nDigite as notas para a média\n");
        for (int i=0; i<3; i++){
            printf("Digite a nota %d: ", i+1); 
            scanf("%f", &notas[i]);
        }
        media = mediaTres(notas[0], notas[1], notas[2]);
        maior = Maior(notas[0], notas[1]);
        maior = Maior(maior, notas[2]);
                
        printf("\nA media das 3 notas eh: %.2f.", media);
        printf("\nA maior nota eh: %.2f.\n", maior);
    }

    void funcao2(){
        int num[10]={0}, maior=0;
        printf("\nDigite até 10 numeros inteiros\n");
        for (int i=0; i<10; i++){
            printf("Digite a numero %d: ", i+1); 
            scanf("%d", &num[i]);
            if (i == 0) {
            maior = num[i];
            }
            else{
                maior = Maior(maior, num[i]);
            }
        }
        printf("\nO maior numero do vetor eh: %d.\n", maior);
    }

    void funcao3(){
        int escolha=0, num[10]={0};
        printf("\nDigite até 10 numeros inteiros\n");
        for (int i=0; i<10; i++){
            printf("Digite a numero %d: ", i+1); 
            scanf("%d", &num[i]);
        }
        do{
            printf("\nEscolha o tipo de ordenamento:\n");
            printf("1. Ordem crescente\n");
            printf("2. Ordem decrescente\n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    ordem(num, 10, 1);
                    break;
                case 2:
                    ordem(num, 10, 0);
                    break;
                case 0:
                    printf("Saindo...\n");
                    return;
                default:
                    printf("Escolha invalida. Tente novamente.\n");
                    break;
            }
        } while (escolha!=0);
    }


    void menu() {
        int escolha;
        do {
            printf("\nPrograma escrito para estudar!\n");
            printf("Escolha uma acao:\n");
            printf("1. Média de tres notas e maior das tres\n");
            printf("2. Maior numero inteiro em dez\n");
            printf("3. Ordenar vetor de dez inteiros\n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    funcao1();
                    break;
                case 2:
                    funcao2();
                    break;
                case 3:
                    funcao3();
                    break;
                case 0:
                    printf("Saindo...\n");
                    return;
                default:
                    printf("Escolha invalida. Tente novamente.\n");
                    break;
            }
        } while (escolha!=0);
    }

    int main(void) {
        menu();
        return 0;
    }
