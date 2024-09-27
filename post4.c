#include <stdio.h>

int pedeNumero(char* mensagem) {
  int temp;
  printf("%s", mensagem);
  scanf("%d", &temp);
    return temp;
}

int funcao2(int tamanho, int vetor[], char* tipo) {

  printf("\nO vetor de inteiros %s eh: |", tipo);
  for(int i=0; i<tamanho; i++){
    printf(" %d |", vetor[i]);
  }
  printf("\n");
}

void funcao3(int* vetor, int tamanho, char* tipo) {
    int posicao = pedeNumero("Digite a posição do número que deseja trocar: ");
    posicao--;
    if (posicao >= 0 && posicao < tamanho) {
        int temp = pedeNumero("Digite o novo número: ");
        vetor[posicao] = temp;
        printf("\nNúmero trocado com sucesso!\n");
    } else {
        printf("\nPosição inválida!\n");
    }
}

int funcao4(int numero){
  return (numero >=0);
}

int main() {
    int escolha, temp, qpos=0, qneg=0;
    int pos[30], neg[30];

    printf("\nPrograma escrito para estudar!\n");
    do {
      printf("\nEscolha uma opcao:\n");
      printf("1. Inserir numero nos vetores\n");
      printf("2. Imprimir os vetores\n");
      printf("3. Trocar numero no vetor\n");
      printf("0. Sair\n");
      printf("Digite sua escolha: ");
      scanf("%d", &escolha);

      switch (escolha) {
        case 1:
          temp = pedeNumero("Digite um numero inteiro:\n");
          if(funcao4(temp)){
            pos[qpos++]=temp;
          }
          else{
            neg[qneg++]=temp;
          }
          break;
        case 2: 
          funcao2(qpos, pos, "positivos");
          funcao2(qneg, neg, "negativos");
          break;
        case 3: 
          printf("\nEscolha o vetor para troca:\n");
          printf("1. Vetor de números positivos\n");
          printf("2. Vetor de números negativos\n");
          printf("Digite sua escolha: ");
          int troca;
          scanf("%d", &troca);
            if (troca == 1) {
              funcao3(pos, qpos, "positivos");
            } else if (troca == 2) {
              funcao3(neg, qneg, "negativos");
            } else {
              printf("\nOpção inválida!\n");
            }
          break;
        case 0:
          printf("Saindo...\n");
          break;
        default:
          printf("Escolha invalida. Tente novamente.\n");
          break;
      }
    } while (escolha!=0);

    return 0;
}
