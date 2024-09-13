
    #include <stdio.h>

    void desenhaLinha(int iguais) {
        for (int i = 0; i < iguais; i++) {
            printf("=");
        }
        printf("\n");
    }

    int intervalo(int inicio, int fim) {
        int soma = 0;
        for (int i = inicio; i <= fim; i++) {
            soma += i;
        }
        return soma;
    }

    void printEconomia(float media) {
        if (media > 12) {
            printf("O veiculo eh supereconomico!\n");
        } else if (media >= 8) {
            printf("O veiculo eh economico!\n");
        } else {
            printf("Venda o veiculo!\n");
        }
    }

    float calculaConsumo(float km, float gas) {
        return km / gas;
    }

    float calculaAreaRetangulo(float altura, float largura) {
        return altura * largura;
    }

    float calculaAreaTriangulo(float altura, float largura) {
        return (altura * largura) / 2;
    }

    float calculaAreaCirculo(float raio) {
        return 3.14 * raio * raio;
    }

    float pedeMedida(const char* mensagem) {
        float medida;
        printf("%s", mensagem);
        scanf("%f", &medida);
        return medida;
    }

    void calculaArea() {
        int escolha;
        float altura, largura, raio, area;
        do {
            printf("\nEscolha uma figura para calcular a area:\n");
            printf("1. Retangulo\n");
            printf("2. Triangulo\n");
            printf("3. Circulo\n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    altura = pedeMedida("Informe a altura do retangulo: ");
                    largura = pedeMedida("Informe a largura do retangulo: ");
                    area = calculaAreaRetangulo(altura, largura);
                    printf("A area do retangulo eh: %.2f\n", area);
                    break;
                case 2:
                    altura = pedeMedida("Informe a altura do triangulo: ");
                    largura = pedeMedida("Informe a largura do triangulo: ");
                    area = calculaAreaTriangulo(altura, largura);
                    printf("A area do triangulo eh: %.2f\n", area);
                    break;
                case 3:
                    raio = pedeMedida("Informe o raio do circulo: ");
                    area = calculaAreaCirculo(raio);
                    printf("A area do circulo eh: %.2f\n", area);
                    break;
                case 0:
                    return;
                default:
                    printf("Escolha invalida. Tente novamente.\n");
                    break;
            }
        } while (escolha!=0);
    }

    void somaIntervalo() {
        int num, inicio, fim, conf;
        do {
            printf("Digite quantos sinais de '=' formam o separador: ");
            scanf("%d", &num);

            printf("Digite o inicio do intervalo: ");
            scanf("%d", &inicio);

            printf("Digite o fim do intervalo: ");
            scanf("%d", &fim);

            int resultado = intervalo(inicio, fim);
            printf("A soma dos elementos do intervalo eh: %d\n", resultado);

            desenhaLinha(num);

            printf("Digite 0 para sair ou outro numero para continuar: ");
            scanf("%d", &conf);
        } while (conf!=0);
    }

    void verificaEconomia() {
        float km, gas;
        printf("Digite a distancia percorrida em km: ");
        scanf("%f", &km);
        printf("Digite a quantidade de gasolina gasta em litros: ");
        scanf("%f", &gas);

        float media = calculaConsumo(km, gas);
        printEconomia(media);
    }

    void verificaNum(){
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
            printf("1. Somar os valores de um intervalo\n");
            printf("2. Verificar economia do automovel\n");
            printf("3. Calcular area da figura\n");
            printf("4. Verificar maior e menor entre 10 numeros\n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    somaIntervalo();
                    break;
                case 2:
                    verificaEconomia();
                    break;
                case 3:
                    calculaArea();
                    break;
                case 4:
                    verificaNum();
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
