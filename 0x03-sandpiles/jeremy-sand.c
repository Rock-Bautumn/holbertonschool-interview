#include "sandpiles.h"
/**
 * print_grid - Print 3x3 grid
 * @grid: a pair of 3x3 multidemential arrays
 * Return: NONE
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * is_stable - Chect to see if at equilirium.
 * @grid1: 3x3 multidemential array
 * @grid2: 3x3 multidemential array
 * Return: Status, 0 yes 1 no.
 */
int is_stable(int grid1[3][3], int grid2[3][3])
{
	int i, j, status = 0;

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			grid1[i][j] += grid2[i][j], grid2[i][j] = 0;
			if (grid1[i][j] >= 4)
				status = 1;
		}
	}
	return (status);
}
/**
 * redistrobution - Waits while indicies reach equalibruim
 * @grid1: 3x3 multidemential array
 * @grid2: 3x3 multidemential array
 * Return: NONE
 */
void redistrobution(int grid1[3][3], int grid2[3][3])
{
	int i, j, status = 1;

	while (status == 1)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] >= 4)
				{
					grid1[i][j] -= 4;
					i - 1 >= 0 ? grid2[i - 1][j] += 1 : 0;
					i + 1 < 3 ? grid2[i + 1][j] += 1 : 0;
					j - 1 >= 0 ? grid2[i][j - 1] += 1 : 0;
					j + 1 < 3 ? grid2[i][j + 1] += 1 : 0;
				}
			}
		}
		status = is_stable(grid1, grid2);
	}
}
/**
 * sandpiles_sum - function that computes the sum of two sandpiles.
 * @grid1: sandpile, a matrix, first grid.
 * @grid2: sandpile, a matrix, second grid.
 * Return: Nothing.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	if (is_stable(grid1, grid2))
		redistrobution(grid1, grid2);
}
