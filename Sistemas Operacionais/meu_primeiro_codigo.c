#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    FILE *arquivo;
    int vetor[10];
    int i;

    arquivo = fopen("relatorio_so.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo\n");
        return 1;
    }

    fprintf(arquivo, "Aluno: Valdemar Espindula Neto\n");
    fprintf(arquivo, "Data: 2026\n");
    fprintf(arquivo, "PID do processo: %d\n", getpid());
    fprintf(arquivo, "Teste prático de interação com o kernel\n");

    fclose(arquivo);


    pid_t pid = fork();

    if (pid == 0) {
        printf("Processo filho em execução\n");
    } 
    else if (pid > 0) {
        wait(NULL);
        printf("Processo pai em execução\n");
    } 
    else {
        printf("Erro ao criar processo\n");
    }

    printf("Conteúdo do vetor:\n");

    for (i = 0; i < 10; i++) {
        vetor[i] = i;
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}
