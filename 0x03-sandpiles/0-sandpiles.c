#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
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
 * is_unstable_grid - Determines whether the grid is unstable or not
 * @grid: The grid to check for stability
 * Return: void
*/
int is_unstable_grid(int grid[3][3])
{
	int row = 0, col = 0;

	for (; row < 3; row++)
		for (col = 0; col < 3; col++)
			if (grid[row][col] > 3)
				return (true);

	return (false);
}
/**
 * sum_grids - Add two grids together
 * @dest: The first grid  to add, stores the result
 * @adding: The second grid that we are adding
 * Return: void
*/

void sum_grids(int dest[3][3], int adding[3][3])
{
	int row = 0, col = 0;

	for (; row < 3; row++)
		for (col = 0; col < 3; col++)
			dest[row][col] += adding[row][col];
}
/**
 * crumble_grid - Topples the grains of sand in the grid
 * @grid: The grid to redistribute
 * Return: void
*/

void crumble_grid(int grid[3][3])
{
	int row = 0, col = 0;
	int temp_grid[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (; row < 3; row++)
		for (col = 0; col < 3; col++)
			if (grid[row][col] >= 4)
			{
				grid[row][col] -= 4;

				/* N */
				if (row > 0)
					temp_grid[row - 1][col] += 1;

				/* S*/
				if (row < 2)
					temp_grid[row + 1][col] += 1;

				/* W */
				if (col > 0)
					temp_grid[row][col - 1] += 1;

				/* E */
				if (col < 2)
					temp_grid[row][col + 1] += 1;
			}
	sum_grids(grid, temp_grid);
}

/**
 * sandpiles_sum - Sums two grids and prints each unstable grid until stable
 * @grid1: The first grid
 * @grid2: The second grid
 * Return: void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int limit = 0;

	sum_grids(grid1, grid2);
	while (is_unstable_grid(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		crumble_grid(grid1);
		limit++;
		if (limit > 20)
			break;
	}
}
