    #include <stdio.h>

    int intervalo(int inicio, int fim) {
        int soma = 0;
        for (int i = inicio; i <= fim; i++) {
            soma += i;
        }
        return soma;
    }

    void funcao1(){
        int num[10]={}, max=-999, min=999, pmax=0, pmin=0;
        printf("Digite 10 numeros inteiros\n");

        for (int i = 0; i<10; i++){
            printf("Digite o numero %d:", i+1); 
            scanf("%d", &num[i]);
            if (num[i]>max){
                max = num[i];
                pmax = i;
            }   
            if (num[i]<min){
                min = num[i];
                pmin = i;
            }
        }
        for (int i = 0; i < 10; i++){
            printf("%d ", num[i]);
        }
        printf("\nO valor maximo eh: %d, na posição %d.", max, pmax);
        printf("\nO valor minimo eh: %d, na posição %d.\n", min, pmin);
    }

    void menu() {
        int escolha;
        do {
            printf("\nPrograma escrito para estudar!\n");
            printf("Escolha uma acao:\n");
            printf("1. \n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    funcao1();
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
