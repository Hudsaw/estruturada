#include <stdio.h>
#include <string.h>

typedef struct {
    int hora;
    int minuto;
    int segundo;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char descricao[100];
} Compromisso;

typedef struct {
    char nome[50];
    int idade;
    char endereco[100];
} Pessoa;

typedef struct {
    char nome[50];
    int matricula;
    char curso[50];
} Aluno;

typedef struct {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} AlunoCurso;

typedef struct {
    int matricula;
    char nome[50];
    int codigoDisc;
    float nota1;
    float nota2;
} AlunoDisc;

void funcao1() {
    Compromisso compromisso = {{11, 10, 2024}, {20, 30, 0}, "Reuniao de projeto"};
    printf("Compromisso: %02d/%02d/%d %02d:%02d:%02d - %s\n", 
           compromisso.data.dia, compromisso.data.mes, compromisso.data.ano, 
           compromisso.horario.hora, compromisso.horario.minuto, compromisso.horario.segundo, 
           compromisso.descricao);

    printf("Para qual data (DD MM AA) gostaria de alterar?\n");
    scanf("%d %d %d", &compromisso.data.dia, &compromisso.data.mes, &compromisso.data.ano);

    printf("Para qual horario (HH MM SS) gostaria de alterar?\n");
    scanf("%d %d %d", &compromisso.horario.hora, &compromisso.horario.minuto, &compromisso.horario.segundo);

    strcpy(compromisso.descricao, "Reuniao de projeto - Alterado");

    printf("Compromisso modificado: %02d/%02d/%d %02d:%02d:%02d - %s\n", 
           compromisso.data.dia, compromisso.data.mes, compromisso.data.ano, 
           compromisso.horario.hora, compromisso.horario.minuto, compromisso.horario.segundo, 
           compromisso.descricao);
}

void imprimirPessoa(Pessoa p) {
    printf("Nome: %s\nIdade: %d\nEndereco: %s\n", p.nome, p.idade, p.endereco);
}

void funcao2() {
    Pessoa pessoa;
    printf("Digite o nome (separe com _): ");
    scanf(" %s", pessoa.nome);
    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);
    printf("Digite o endereco (separe com _): ");
    scanf(" %s", pessoa.endereco);

    imprimirPessoa(pessoa);
}

void imprimirAlunos(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Matricula: %d, Curso: %s\n", 
               alunos[i].nome, alunos[i].matricula, alunos[i].curso);
    }
}

void funcao3() {
    Aluno alunos[5];
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %s", alunos[i].nome);
        printf("Digite a matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Digite o curso: ");
        scanf(" %s", alunos[i].curso);
    }
    imprimirAlunos(alunos, 5);
}

void Maior(AlunoCurso alunos[], int num){
    int maior=0;
    for (int i = 0; i < num; i++) {
        if (alunos[i].nota1 > maior) {
            maior = i;
        }
    }
    printf("Aluno com maior nota na primeira prova: %s\n", alunos[maior].nome);
}

void MaiorM(AlunoCurso alunos[], int num){
    int maiorM=0, media=0;
    for (int i = 0; i < num; i++) {
        media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if (media > (alunos[maiorM].nota1 + alunos[maiorM].nota2 + alunos[maiorM].nota3) / 3) {
            maiorM = i;
        }
    printf("Aluno com maior media geral: %s\n", alunos[maiorM].nome);
    }
}

void MenorM(AlunoCurso alunos[], int num){
    int menorM=0, media=0;
    for (int i = 0; i < num; i++) {
        media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if (media > (alunos[menorM].nota1 + alunos[menorM].nota2 + alunos[menorM].nota3) / 3) {
            menorM = i;
        }
    printf("Aluno com menor media geral: %s\n", alunos[menorM].nome);
    }
}

void Media (AlunoCurso alunos[], int num){
    for (int i = 0; i < num; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        printf("Aluno %s - Media: %.2f - %s\n", alunos[i].nome, media, media >= 6.0 ? "Aprovado" : "Reprovado");
    }
}

void funcao4() {
    AlunoCurso alunos[50];
    int i, num=5;

    printf("Digite quantos alunos tem no curso:");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %s", alunos[i].nome);
        printf("Digite a nota da primeira prova: ");
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota da segunda prova: ");
        scanf("%f", &alunos[i].nota2);
        printf("Digite a nota da terceira prova: ");
        scanf("%f", &alunos[i].nota3);
    }

    Maior(alunos, num);
    MaiorM(alunos, num);
    MenorM(alunos, num);
    Media(alunos, num);
}

void funcao5() {
    AlunoDisc alunos[50];
    float media, soma;
    int i, num=10;

    printf("Digite quantos alunos tem na disciplina 101 - Estruturada:");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        alunos[i].codigoDisc = 101;
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %s", alunos[i].nome);
        printf("Digite a nota da primeira prova: ");
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota da segunda prova: ");
        scanf("%f", &alunos[i].nota2);
    }

    for (i = 0; i < num; i++) {

        float media = ((alunos[i].nota1 + alunos[i].nota2 *2) / 3);

        printf("Aluno %s da disciplina de %d teve media: %.2f - %s\n", alunos[i].nome, alunos[i].codigoDisc, media, media >= 6.0 ? "Aprovado" : "Reprovado");
    }
}

void menu() {
    int escolha;
    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Novos tipos de dados\n");
        printf("2. Leitura de dados de uma pessoa\n");
        printf("3. Cadastro de alunos\n");
        printf("4. Notas dos alunos\n");
        printf("5. Media ponderada dos alunos\n");

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
            case 4:
                funcao4();
                break;
            case 5:
                funcao5();
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != 0);
}

int main(void) {
    menu();
    return 0;
}
