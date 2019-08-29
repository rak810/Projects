#include<stdio.h>
#define clear() printf("\033[H\033[J")

char a[9];
int w = 0, p = 0;
int move1, move2, i = 0, j = 0;

void board()
{
	clear();
	printf("\t\tTIC TAC TOE\n");
	printf("\t\t============\n");
	printf("\t  Player 1(X) | Player 2(O)\n");
	printf("\t  -------------------------\n");
	printf("\t\t %c | %c | %c\n", a[0], a[1], a[2]);
	printf("\t\t------------\n");
	printf("\t\t %c | %c | %c\n", a[3], a[4], a[5]);
	printf("\t\t------------\n");
	printf("\t\t %c | %c | %c\n", a[6], a[7], a[8]);
	printf("\t\t------------\n");
}

void init()
{
	for (int i = 0; i < 9; ++i)
	{
		a[i] = (i+1) + '0';
	}
}

void rowcheck()
{
	if(a[0] == 'X' && a[0] == a[1] && a[0] == a[2])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[3] == 'X' && a[3] == a[4] && a[3] == a[5])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[6] == 'X' && a[6] == a[7] && a[6] == a[8])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[0] == 'O' && a[0] == a[1] && a[0] == a[2])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else if(a[3] == 'O' && a[3] == a[4] && a[3] == a[5])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else if(a[6] == 'O' && a[6] == a[7] && a[6] == a[8])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else
	{
		w = 1;
	}
}

void columncheck()
{
	if(a[0] == 'X' && a[3] == a[0] && a[6] == a[0])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[1] == 'X' && a[4] == a[1] && a[7] == a[1])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[2] == 'X' && a[5] == a[2] && a[8] == a[2])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[0] == 'O' && a[3] == a[0] && a[6] == a[0])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else if(a[1] == 'O' && a[4] == a[1] && a[7] == a[1])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else if(a[2] == 'O' && a[5] == a[2] && a[8] == a[2])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else
	{
		w = 2;
	}
}

void crosscheck()
{
	if(a[0] == 'X' && a[4] == a[0] && a[8] == a[0])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[2] == 'X' && a[4] == a[2] && a[6] == a[2])
	{
		printf("Player 1 wins\n");
		p = 1;
	}
	else if(a[0] == 'O' && a[4] == a[0] && a[8] == a[0])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else if(a[2] == 'O' && a[4] == a[2] && a[6] == a[2])
	{
		printf("Player 2 wins\n");
		p = 1;
	}
	else if(a[0] != '1' && a[1] != '2' && a[2] != '3' && a[3] != '4' && a[4] != '5' && a[5] != '6' && a[6] != '7' && a[7] != '8' && a[8] != '9')
	{
		w = 3;
	}
}


void check()
{
	rowcheck();
	if(w == 1)
	{
		columncheck();
	}
	if(w == 2)
	{
		crosscheck();
	}
	if(w == 3)
	{
		printf("Draw\n");
		p = 1;
	}
}

int main()
{
	
	init();
	board();
	while(i+j < 9)
	{

		printf("Player 1 move :");
		scanf("%d", &move1);
		if(move1 > 9 && move1 < 1)
		{
			printf("Invalid move\n");
			printf("Player 1 new move : ");
			scanf("%d", &move1);
			a[move1 - 1] = 'X';
			i++;
			board();
			if(i >= 2 || j >= 2)
			{
				check();
				if(p == 1)
				{
					break;
				}
			}
		}
		else
		{
			a[move1 - 1] = 'X';
			i++;
			board();
			if(i >= 2 || j >= 2)
			{
				check();
				if(p == 1)
				{
					break;
				}
			}
		}
		printf("Player 2 move :");
		scanf("%d", &move2);
		if(move2 > 9 && move2 < 1)
		{
			printf("Invalid move\n");
			printf("Player 2 new move : ");
			scanf("%d", &move2);
			a[move2 - 1] = 'O';
			j++;
			board();
			if(i >= 2 || j >= 2)
			{
				check();
				if(p == 1)
				{
					break;
				}
			}
		}
		else
		{
			a[move2 - 1] = 'O';
			j++;
			board();
			if(i >= 2 || j >= 2)
			{
				check();
				if(p == 1)
				{
					break;
				}
			}
		}
		board();
	}

}