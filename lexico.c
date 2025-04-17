#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura para representar tokens
typedef struct {
    char lexema[100];
    char token[100];
    int linha;
    int status;
} Token;

// Array de tokens (simulação de vetor dinâmico)
Token tokens[1000];
int tokenIndex = 0;

// Função para adicionar um token ao array
void adicionarToken(const char *lexema, const char *token, int linha, int status) {
    strcpy(tokens[tokenIndex].lexema, lexema);
    strcpy(tokens[tokenIndex].token, token);
    tokens[tokenIndex].linha = linha;
    tokens[tokenIndex].status = status;
    tokenIndex++;
}

// Função para validar identificadores
void automatoIdentificador(const char *palavra, int num_linha) {
    int s = 0; // Estado
    int i = 0;
    int flag = 1; // Controla o loop
    char c;

    while (flag) {
        c = palavra[i];
        switch (s) {
            // Estado 0
            case 0:
                if (isalpha(c)) {
                    s = 1;
                } else {
                    s = 3;
                }
                break;

            // Estado 1
            case 1:
                if (isalnum(c)) {
                    s = 1;
                    if (i == strlen(palavra) - 1) {
                        adicionarToken(palavra, "ident", num_linha, 1);
                        flag = 0;
                    }
                } else if (i == strlen(palavra)) {
                    adicionarToken(palavra, "ident", num_linha, 1);
                    flag = 0;
                } else {
                    s = 2;
                }
                break;

            // Estado 2
            case 2:
                adicionarToken(palavra, "Identificador com caracter inválido", num_linha, 0);
                flag = 0;
                break;

            // Estado 3
            case 3:
                adicionarToken(palavra, "Identificador não inicia com letra", num_linha, 0);
                flag = 0;
                break;
        }
        i++;
    }
}

// Função para imprimir os tokens
void imprimirTokens() {
    for (int i = 0; i < tokenIndex; i++) {
        printf("Lexema: %s, Token: %s, Linha: %d, Status: %s\n",
               tokens[i].lexema,
               tokens[i].token,
               tokens[i].linha,
               tokens[i].status ? "Válido" : "Inválido");
    }
}

// Teste do automatoIdentificador
int main() {
    automatoIdentificador("var1", 1);
    automatoIdentificador("123abc", 2);
    automatoIdentificador("var_2", 3);
    automatoIdentificador("Abc123", 4);

    imprimirTokens();
    return 0;
}
