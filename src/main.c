#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define X 0
#define O 1

void print_grid();
void swap_player();
bool check_tie();
bool check_rows();
bool check_cols();
bool chec_diag();
bool has_winner();

char GRID[3][3] = 
{
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'}
};

bool CURRENT_PLAYER = X;

int main()
{
	bool game_running = true;
	while (game_running)
	{
		int row, column;

		printf("\n*****************************************\n\n");
		print_grid();
		printf("\nPlayer: %c\nPlease enter a row and column: ", CURRENT_PLAYER == X ? 'X' : 'O');

		if (scanf("%i%i", &row, &column) < 2)
			exit(1);

		if (row > 3 || row < 1 || column > 3 || column < 1)
			continue;

		if (GRID[row - 1][column - 1] != '-')
		{
			printf("That space is already taken! Please try again!\n");
			continue;
		}
		else
		{
			GRID[row - 1][column - 1] = CURRENT_PLAYER == X ? 'X' : 'O';

			if (check_tie())
			{
				printf("TIE!\n");
				game_running = false;
			}

			if (has_winner())
			{
				printf("\n");
				print_grid();
				printf("\nWinner: %c\n", CURRENT_PLAYER == X ? 'X' : 'O');
				game_running = false;
			}

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
	CURRENT_PLAYER = CURRENT_PLAYER == X ? O : X;
}

// Ends the game if no spaces are left.
bool check_tie()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (GRID[i][j] == '-')
				return false;
		}
	}
	return true;
}

// Checks if there are 3 of the same letter in a row
bool check_rows()
{
	for (int i = 0; i < 3; i++)
	{
		if (GRID[i][0] != '-' && GRID[i][0] == GRID[i][1] && GRID[i][1] == GRID[i][2])
			return true;
	}

	return false;
}

// Checks if there are 3 of the same letter in a column
bool check_cols()
{
	// for every row, check the column
	for (int i = 0; i < 3; i++)
	{
		if (GRID[0][i] != '-' && GRID[0][i] == GRID[1][i] && GRID[1][i] == GRID[2][i])
			return true;
	}

	return false;
}

// Checks diagonally to see if there is a winner
bool chec_diag()
{
	if (GRID[0][0] != '-' && GRID[0][0] == GRID[1][1] && GRID[1][1] == GRID[2][2])
		return true;

	else if (GRID[0][2] != '-' && GRID[0][2] == GRID[1][1] && GRID[1][1] == GRID[2][0])
		return true;

	return false;
}

bool has_winner()
{
	return check_rows() || check_cols() || chec_diag();
}