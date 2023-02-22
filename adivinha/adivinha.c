#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	// Imprime o cabeçalho do jogo
	printf("*******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
	printf("*******************************************\n");
	
	int segundos = time(0);
	srand(segundos);
	
	int numerogrande = rand();
	int numerosecreto = numerogrande % 100;
	
	int palpite;
	int ganhou = 0;
	int numero_tentativas = 0;
	double pontos = 1000;
	
	while(!ganhou) {
		numero_tentativas++;
		printf("Tente adivinhar em qual número o computador pensou.\n");
		printf("Digite um número inteiro de 0 a 99: ");
		scanf("%d", &palpite);
		
		if(palpite < 0) {
			printf("Você não pode chutar números negativos, tente novamente.\n");
			numero_tentativas--;
			
			continue;
		}
		
		int acertou = palpite == numerosecreto;
		int maior = palpite > numerosecreto;
		
		if(acertou) {
			printf("Parabéns! Você acertou na %dº tentativa!\n", numero_tentativas);
			
			ganhou = 1;
		}
		else if(maior) {
			printf("Seu palpite é maior que o número secreto.\n");
		}
		else {
			printf("Seu palpite é menor que o número secreto.\n");
		}
		
		double pontosperdidos = (double) abs(palpite - numerosecreto) / 2;
		pontos -= pontosperdidos;
	}
	
	printf("Total de pontos: %.1f\n", pontos);
	printf("Fim de Jogo!\n");
	
	return 0;
}