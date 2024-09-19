#include <stdio.h>

int funcao1(int nasc, int atual, int escolha) {
    int anos = 0, dias = 0;
    for (int i = nasc; i <= atual; i++) {
        anos += i;
        if(i%4==0 && i%100!=0){
            dias++;
        }
        if(i%4==0 && i%100==0 && i%400==0){
            dias++;
        }

    }
    anos=(atual-nasc-escolha)*365+dias;
    return anos;
}

void menu() {
    int escolha, nasc, atual, futuro, dias, fut;
    char nome[30]={};
    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Digite o seu nome:\n");
        scanf(" %s", &nome);
        printf("Digite o ano de seu nascimento:\n");
        scanf(" %d", &nasc);
        printf("Digite o ano atual:\n");
        scanf(" %d", &atual);
        printf("Digite um ano futuro:\n");
        scanf(" %d", &futuro);
        printf("Escolha uma opcao:\n");
        printf("1. Ja fiz aniversario este ano\n");
        printf("2. Vou fazer aniversario este ano\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        if (escolha == 1)  {
          dias = funcao1(nasc, atual, 0);
          fut = funcao1(nasc, futuro, 0);
          printf("%s nasceu em %d, viveu %d dias até %d e vivera %d dias ate %d.\n", nome, nasc, dias, atual, fut, futuro);
        }
          if (escolha == 2)  {
            dias = funcao1(nasc, atual, 1);
            fut = funcao1(nasc, futuro, 1);
            printf("%s nasceu em %d, viveu %d dias até %d e vivera %d dias ate %d.\n", nome, nasc, dias, atual, fut, futuro);
          }
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
