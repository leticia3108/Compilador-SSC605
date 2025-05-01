#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DEN 20

typedef struct {
    char simbolo[3];
    char denominador[MAX_DEN];
}SSimb;

int relacional(FILE* textFile){

SSimb relacionais[] = {
    {"<>", "simbolo_diferente"},
    {"<=", "simbolo_menor_igual"},
    {">=", "simbolo_maior_igual"},
    {"=", "simbolo_igual"},
    {">", "simbolo_maior"},
    {"<", "simbolo_menor"}
};

char lido[3], c;
lido[2] = '\0';
int nLidos = 0;

do {
    c = getc(textFile);
    if (c == EOF) return 0;
} while (isspace(c));

ungetc(c, textFile);

nLidos = fread (lido, sizeof(char), 2, textFile);

for (int i = 0; i < sizeof(relacionais) / sizeof(relacionais[0]); i++){
   // printf ("Comparando (%s) com (%s).\n", relacionais[i].simbolo, lido);
    if (strncmp(relacionais[i].simbolo, lido, strlen(relacionais[i].simbolo)) == 0){
        fseek (textFile, strlen(relacionais[i].simbolo)-(nLidos), SEEK_CUR);
      //  printf("nLidos = %d strlen(relacionais[i].simbolo)) = %d \n", nLidos, strlen(relacionais[i].simbolo));
        printf("%s, %s\n", relacionais[i].simbolo, relacionais[i].denominador);
        return 1;
    }
}

//printf("nLidos = %d\n", nLidos);
fseek (textFile, -(nLidos), SEEK_CUR);
return 0;

}

int operadorUnario(FILE* textFile){

SSimb relacionais[] = {
    {"+", "simbolo_mais"},
    {"-", "simbolo_menos"}
};

char lido[3], c;
lido[2] = '\0';
int nLidos = 0;

do {
    c = getc(textFile);
    if (c == EOF) return 0;
} while (isspace(c));

ungetc(c, textFile);

nLidos = fread (lido, sizeof(char), 1, textFile);

for (int i = 0; i < sizeof(relacionais) / sizeof(relacionais[0]); i++){
   // printf ("Comparando (%s) com (%s).\n", relacionais[i].simbolo, lido);
    if (strncmp(relacionais[i].simbolo, lido, strlen(relacionais[i].simbolo)) == 0){
        fseek (textFile, strlen(relacionais[i].simbolo)-(nLidos), SEEK_CUR);
      //  printf("nLidos = %d strlen(relacionais[i].simbolo)) = %d \n", nLidos, strlen(relacionais[i].simbolo));
        printf("%s, %s\n", relacionais[i].simbolo, relacionais[i].denominador);
        return 1;
    }
}

//printf("nLidos = %d\n", nLidos);
fseek (textFile, -(nLidos), SEEK_CUR);
return 1;

}

int operadorMaisMenos(FILE* textFile){

SSimb relacionais[] = {
    {"+", "simbolo_mais"},
    {"-", "simbolo_menos"}
};

char lido[3], c;
lido[2] = '\0';
int nLidos = 0;

do {
    c = getc(textFile);
    if (c == EOF) return 0;
} while (isspace(c));

ungetc(c, textFile);

nLidos = fread (lido, sizeof(char), 1, textFile);

for (int i = 0; i < sizeof(relacionais) / sizeof(relacionais[0]); i++){

    if (strncmp(relacionais[i].simbolo, lido, strlen(relacionais[i].simbolo)) == 0){
        fseek (textFile, strlen(relacionais[i].simbolo)-(nLidos), SEEK_CUR);
        printf("%s, %s\n", relacionais[i].simbolo, relacionais[i].denominador);
        return 1;
    }
}


fseek (textFile, -(nLidos), SEEK_CUR);
return 0;

}

int operadorDivMult(FILE* textFile){

SSimb relacionais[] = {
    {"/", "simbolo_divisao"},
    {"*", "simbolo_multiplicacao"}
};

char lido[3], c;
lido[2] = '\0';
int nLidos = 0;

do {
    c = getc(textFile);
    if (c == EOF) return 0;
} while (isspace(c));

ungetc(c, textFile);

nLidos = fread (lido, sizeof(char), 1, textFile);

for (int i = 0; i < sizeof(relacionais) / sizeof(relacionais[0]); i++){;
    if (strncmp(relacionais[i].simbolo, lido, strlen(relacionais[i].simbolo)) == 0){
        fseek (textFile, strlen(relacionais[i].simbolo)-(nLidos), SEEK_CUR);
        printf("%s, %s\n", relacionais[i].simbolo, relacionais[i].denominador);
        return 1;
    }
}

//printf("nLidos = %d\n", nLidos);
fseek (textFile, -(nLidos), SEEK_CUR);
return 0;

}

int ParentesesDireito(FILE* textFile){

SSimb relacionais[] = {
    {"(", "parenteses_direito"},
};

char lido[3], c;
lido[2] = '\0';
int nLidos = 0;

do {
    c = getc(textFile);
    if (c == EOF) return 0;
} while (isspace(c));

ungetc(c, textFile);

nLidos = fread (lido, sizeof(char), 1, textFile);

    if (strncmp(relacionais[0].simbolo, lido, strlen(relacionais[0].simbolo)) == 0){
        fseek (textFile, strlen(relacionais[0].simbolo)-(nLidos), SEEK_CUR);
        printf("%s, %s\n", relacionais[0].simbolo, relacionais[0].denominador);
        return 1;
    }


//printf("nLidos = %d\n", nLidos);
fseek (textFile, -(nLidos), SEEK_CUR);
return 0;

}

int ParentesesEsquerdo(FILE* textFile){

SSimb relacionais[] = {
    {")", "parenteses_esquerdo"},
};

char lido[3], c;
lido[2] = '\0';
int nLidos = 0;

do {
    c = getc(textFile);
    if (c == EOF) return 0;
} while (isspace(c));

ungetc(c, textFile);

nLidos = fread (lido, sizeof(char), 1, textFile);


    if (strncmp(relacionais[0].simbolo, lido, strlen(relacionais[0].simbolo)) == 0){
        fseek (textFile, strlen(relacionais[0].simbolo)-(nLidos), SEEK_CUR);
        printf("%s, %s\n", relacionais[0].simbolo, relacionais[0].denominador);
        return 1;
    }


//printf("nLidos = %d\n", nLidos);
fseek (textFile, -(nLidos), SEEK_CUR);
return 0;

}

int main(){
    FILE* TextFile = fopen("compilador.txt", "r");
    while(relacional(TextFile) || operadorMaisMenos(TextFile) || ParentesesDireito(TextFile) || ParentesesEsquerdo(TextFile));


}
