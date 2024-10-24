#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARTAS 52
#define CARTAS_JOGADOR 5

const char *naipes[] = {"Copas", "Espadas", "Ouros", "Paus"};

typedef struct {
    int valor;  
    const char *naipe;
} Carta;

void criarBaralho(Carta baralho[]) {
    int i, j, k = 0;
    for (i = 0; i < 4; i++) {  
        for (j = 1; j <= 13; j++) {  
            baralho[k].valor = j;
            baralho[k].naipe = naipes[i];
            k++;
        }
    }
}

void embaralhar(Carta baralho[]) {
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        int r = rand() % TOTAL_CARTAS;
        Carta temp = baralho[i];
        baralho[i] = baralho[r];
        baralho[r] = temp;
    }
}

void mostrarCarta(Carta c) {
    printf("%d de %s\n", c.valor, c.naipe);
}

Carta jogarCarta(Carta mao[], int tamanho, int index) {
    Carta cartaJogar = mao[index];
    for (int i = index; i < tamanho - 1; i++) {
        mao[i] = mao[i + 1];
    }
    return cartaJogar;
}

Carta jogarCartaNPC(Carta mao[], int *tamanho) {
    int escolha = rand() % (*tamanho);
    Carta cartaJogar = mao[escolha];
    for (int i = escolha; i < (*tamanho) - 1; i++) {
        mao[i] = mao[i + 1];
    }
    (*tamanho)--;
    return cartaJogar;
}

void distribuirCartas(Carta baralho[], Carta jogador1[], Carta jogador2[], int *cartasRestantes, int qtdCartas) {
    for (int i = 0; i < qtdCartas; i++) {
        jogador1[i] = baralho[i * 2];
        jogador2[i] = baralho[i * 2 + 1];
    }
    *cartasRestantes -= 2 * qtdCartas;
}

int main() {
    srand(time(NULL));

    Carta baralho[TOTAL_CARTAS];
    Carta jogador[CARTAS_JOGADOR + 10];
    Carta npc[CARTAS_JOGADOR + 10];
    int tamanhoJogador = CARTAS_JOGADOR, tamanhoNPC = CARTAS_JOGADOR;
    int cartasRestantes = TOTAL_CARTAS;

    criarBaralho(baralho);
    embaralhar(baralho);

    distribuirCartas(baralho, jogador, npc, &cartasRestantes, CARTAS_JOGADOR);

    int turno = 1;
    while (cartasRestantes > 0) {
        printf("\n--- Turno %d ---\n", turno);
        printf("Suas cartas:\n");
        for (int i = 0; i < tamanhoJogador; i++) {
            printf("%d. ", i + 1);
            mostrarCarta(jogador[i]);
        }

        int escolha;
        printf("Escolha uma carta para jogar (1-%d): ", tamanhoJogador);
        scanf("%d", &escolha);
        Carta cartaJogador = jogarCarta(jogador, tamanhoJogador, escolha - 1);
        tamanhoJogador--;

        Carta cartaNPC = jogarCartaNPC(npc, &tamanhoNPC);
        printf("NPC jogou: ");
        mostrarCarta(cartaNPC);

        if (cartaJogador.valor < cartaNPC.valor) {
            printf("Você perdeu a rodada. Pegue mais uma carta.\n");
            jogador[tamanhoJogador++] = baralho[TOTAL_CARTAS - cartasRestantes--];
        } else {
            printf("Você ganhou a rodada. NPC pega mais uma carta.\n");
            npc[tamanhoNPC++] = baralho[TOTAL_CARTAS - cartasRestantes--];
        }

        turno++;
    }

    printf("\n--- Fim do jogo ---\n");
    printf("Cartas restantes com você: %d\n", tamanhoJogador);
    printf("Cartas restantes com o NPC: %d\n", tamanhoNPC);

    if (tamanhoJogador < tamanhoNPC) {
        printf("Você venceu!\n");
    } else if (tamanhoJogador > tamanhoNPC) {
        printf("NPC venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
