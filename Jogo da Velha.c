#include <stdio.h>
#include <locale.h>

////////////////////////////////
// FUNÇÃO QUE MOSTRA NA TELA  //
//    O TABULEIRO DO JOGO	  //
////////////////////////////////

void mostrarJogo(int m[3][3])
{
	system("cls");
	int l, c;
	printf("\n");
	for (l = 0; l < 3; l++)
	{
		for (c = 0; c < 3; c++)
		{
			switch (m[l][c])
			{
			case -1:
			{
				printf("+ ");
				break;
			}
			case 1:
			{
				printf("O ");
				break;
			}
			case 2:
			{
				printf("X ");
				break;
			}
			}
		}
		printf("\n");
	}
	printf("\n");
}

//////////////////////////////////
// FUNÇÃO QUE TESTA SE O EXISTE //
//		JOGADAS POSSÍVEIS   	//
//////////////////////////////////

int checarSituacao(int m[3][3])
{
	int i, j, cont;
	for (i = 0, cont = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (m[i][j] == -1)
			{
				cont++;
			}
		}
	}
	if (cont == 0)
	{
		return 1;
	}
	return 0;
}

////////////////////////////////
//	JOGADOR 1 OU 2 FAZEM SUA  //
//	 JOGADA E O TABULEIRO É   //
//	   MOSTRADO NOVAMENTE     //
////////////////////////////////

void jogar(int m[3][3], int jog)
{
	int l, c, flag;
	for (flag = 1; flag;)
	{
		printf("Jogador %d - Escreva a linha e a coluna que deseja prencher: ", jog);
		scanf("%d", &l);
		scanf("%d", &c);
		if (m[l][c] == -1)
		{
			m[l][c] = jog;
			flag = 0;
		}
		else
		{
			printf("Posição já preenchida, tente novamente.\n");
		}
	}
	mostrarJogo(m);
}

////////////////////////////////
// FUNÇÃO QUE TESTA SE UM DOS //
// JOGADORES VENCEU NA RODADA //
// 			 ATUAL			  //
////////////////////////////////

int teste(int m[3][3], int jog)
{
	int i, j, cont;
	for (i = 0; i < 3; i++)
	{
		for (j = 0, cont = 0; j < 3; j++)
		{
			if (m[i][j] == jog)
			{
				cont++;
			}
			if (cont == 3)
			{
				return 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0, cont = 0; j < 3; j++)
		{
			if (m[j][i] == jog)
			{
				cont++;
			}
			if (cont == 3)
			{
				return 1;
			}
		}
	}
	for (i = 0, j = 0, cont = 0; i < 3; i++, j++)
	{
		if (m[j][i] == jog)
		{
			cont++;
		}
		if (cont == 3)
		{
			return 1;
		}
	}
	for (i = 0, j = 2, cont = 0; i < 3; i++, j--)
	{
		if (m[j][i] == jog)
		{
			cont++;
		}
		if (cont == 3)
		{
			return 1;
		}
	}
	return 0;
}

////////////////////////////////
//  FUNÇÃO QUE INICIA O JOGO  //
////////////////////////////////

char jogo(int vencedor)
{
	int m[3][3], jogA, jogB, l, c, cont;
	for (l = 0; l < 3; l++)
	{
		for (c = 0; c < 3; c++)
		{
			m[l][c] = -1;
		}
	}
	jogA = 1;
	jogB = 2;
	while (vencedor == 'c')
	{
		jogar(m, jogA);
		if (teste(m, jogA))
		{
			return 'A';
		}
		if (checarSituacao(m))
		{
			return 'c';
		}
		jogar(m, jogB);
		if (teste(m, jogB))
		{
			return 'B';
		}
		if (checarSituacao(m))
		{
			return 'c';
		}
	}
}

////////////////////////////////
//	 FUNÇÃO MAIN QUE MOSTRA	  //
//     O RESULTADO DO JOGO	  //
////////////////////////////////

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char ganhador = 'c'; // 1 = O jogA | 2 = X jogB
	ganhador = jogo(ganhador);
	if (ganhador == 'c')
	{
		printf("Não houve um vencedor.");
	}
	else
	{
		printf("O vencedor do jogo foi o jogador %c!", ganhador);
	}
	return 0;
}
