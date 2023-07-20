#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#define MAX_LIVROS 100

// Estrutura para armazenar informações sobre um livro
struct Livro {
    char nome[100];
    char autor[100];
    char dataLancamento[20];
};

// Função para salvar os dados em um arquivo TXT
void salvarDadosEmArquivo(const char *nomeArquivo, const struct Livro *livro) {
    FILE *arquivo = fopen(nomeArquivo, "a"); // Usamos "a" para adicionar ao arquivo, não sobrescrever
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    fprintf(arquivo, "Nome do livro: %s", livro->nome);
    fprintf(arquivo, "Autor: %s", livro->autor);
    fprintf(arquivo, "Data de lançamento: %s", livro->dataLancamento);
    fprintf(arquivo, "--------------------------\n"); // Separador entre livros
    fclose(arquivo);
    printf("Dados salvos com sucesso no arquivo %s.\n", nomeArquivo);
}

// Função para consultar os dados salvos no arquivo TXT
void consultarDadosNoArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    printf("Livros salvos:\n");
    printf("--------------------------\n");

    char linha[150]; // Tamanho suficiente para armazenar uma entrada de livro

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

// Função para remover livro por nome
void removerLivroPorNome(const char *nomeArquivo, const char *nomeLivro) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    // Criar um arquivo temporário para copiar os livros, exceto o que será removido
    FILE *temporario = fopen("temporario.txt", "w");
    if (temporario == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char linha[150];
    int livroRemovido = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, nomeLivro) == NULL) {
            fputs(linha, temporario);
        } else {
            livroRemovido = 1;
        }
    }

    fclose(arquivo);
    fclose(temporario);

    if (!livroRemovido) {
        printf("Livro \"%s\" não encontrado.\n", nomeLivro);
        remove("temporario.txt"); // Remover arquivo temporário
        return;
    }

    // Substituir o arquivo original pelo temporário
    remove(nomeArquivo);
    rename("temporario.txt", nomeArquivo);

    printf("Livro \"%s\" removido com sucesso.\n", nomeLivro);
}

int main() {
    char nomeArquivo[] = "livros.txt";
    struct Livro livros[MAX_LIVROS];
    int numLivros = 0;

    int opcao;

    do {
        // Limpar terminal
        system(CLEAR_COMMAND);

        // Menu de opções
        printf("Selecione uma opção:\n");
        printf("1 - Adicionar novo livro\n");
        printf("2 - Consultar livros salvos\n");
        printf("3 - Remover livro por nome\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Adicionar novo livro
                if (numLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    getchar(); // Para consumir o \n deixado pelo scanf anterior
                    fgets(livros[numLivros].nome, sizeof(livros[numLivros].nome), stdin);

                    printf("Digite o nome do autor: ");
                    fgets(livros[numLivros].autor, sizeof(livros[numLivros].autor), stdin);

                    printf("Digite a data de lançamento: ");
                    fgets(livros[numLivros].dataLancamento, sizeof(livros[numLivros].dataLancamento), stdin);

                    salvarDadosEmArquivo(nomeArquivo, &livros[numLivros]);
                    numLivros++;
                } else {
                    printf("Limite de livros atingido. Não é possível adicionar mais livros.\n");
                }
                break;

            case 2:
                // Consultar livros salvos
                consultarDadosNoArquivo(nomeArquivo);
                break;

            case 3:
                // Remover livro por nome
                printf("Digite o nome do livro a ser removido: ");
                char nomeLivro[100];
                getchar(); // Para consumir o \n deixado pelo scanf anterior
                fgets(nomeLivro, sizeof(nomeLivro), stdin);
                nomeLivro[strcspn(nomeLivro, "\n")] = '\0'; // Remover o caractere de nova linha

                removerLivroPorNome(nomeArquivo, nomeLivro);
                break;

            case 0:
                // Sair
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida. Digite uma opção válida.\n");
                break;
        }

        // Espera por uma entrada do usuário antes de mostrar o menu novamente
        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();

    } while (opcao != 0);

    return 0;
}
