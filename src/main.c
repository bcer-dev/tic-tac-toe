#include <stdio.h>
#include <stdbool.h>

#define X 0
#define Y 1

void print_grid();
void swap_player();
bool determine_winner();

char GRID[3][3] = 
{
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'}
};

bool CURRENT_PLAYER = X;

int main()
{
	bool has_winner = false;
	while (!has_winner)
	{
		int row, column;

		print_grid();
		printf("Player: %c\nPlease enter a row and column: ", CURRENT_PLAYER == X ? 'X' : 'Y');
		scanf("%i%i", &row, &column);

		if (row > 3 || row < 1 || column > 3 || column < 1)
			continue;

		if (GRID[row - 1][column - 1] != '-')
		{
			printf("That space is already taken! Please try again!\n");
			continue;
		}
		else
		{
			GRID[row - 1][column - 1] = CURRENT_PLAYER == X ? 'X' : 'Y';
			swap_player();
		}
	}
	return 0;
}

// Print the game board (grid) to the console so that the 
// players can see how the game is going.
void print_grid()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c ", GRID[i][j]);
		}
		printf("\n");
	}
}

// Switch between X and O
void swap_player()
{
	CURRENT_PLAYER = CURRENT_PLAYER == X ? Y : X;
}