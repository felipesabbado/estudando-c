#include <stdio.h>
#include <string.h>

// variaveis globais
char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

// funcoes
void abertura() {
    printf("*************************\n");
    printf("*     Jogo da Forca     *\n");
    printf("*************************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra) {
    int achou = 0;

    for (int j = 0; j < tentativas; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {

        // a letra já foi chutada?
        int achou = jachutou(palavrasecreta[i]);

        if (achou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
}

// main
int main() {
    int acertou = 0;
    int enforcou = 0;

    escolhepalavra();

    abertura();

    do {
        // imprime a palavra secreta
        desenhaforca();

        // captura um novo chute
        chuta();

    } while (!acertou && !enforcou);
}
