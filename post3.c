#include <stdio.h>

int funcao1(int a, int b) {
  int num=a;
  if(b==0) {
    return 1;
  }
  else{
    for (int i = 1; i < b; i++) {
    num *= a;
    }
    return num;
  }
}

void menu() {
    int escolha, base, expo;
    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Digite um numero base:\n");
        scanf(" %d", &base);
        printf("Digite um expoente:\n");
        scanf(" %d", &expo);
        escolha = funcao1(base, expo);
        printf("O numero base %d elevado ao expoente %d eh: %d", base, expo, escolha);
        printf("\nEscolha uma opcao:\n");
        printf("1. Reiniciar\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
      scanf("%d", &escolha);

        switch (escolha) {
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Reiniciando o programa.\n");
                break;
        }
    } while (escolha!=0);
}

int main(void) {
    menu();
    return 0;
}
