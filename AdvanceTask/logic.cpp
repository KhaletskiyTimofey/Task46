#include "logic.h"

bool is_this_element_saddle(int** matrix, int row, int column, int x, int y)
{
	int saddle_element = matrix[x][y];
	bool is_element_saddle = true;

	for (int i = 0; i < row; i++)
	{
		if (i != y)
		{
			if (saddle_element <= matrix[i][x])
			{
				is_element_saddle = false;
				break;
			}
		}
	}
	for (int i = 0; i < column; i++)
	{
		if (i != x)
		{
			if (saddle_element >= matrix[y][i])
			{
				is_element_saddle = false;
				break;
			}
		}
	}

	return is_element_saddle;
}

int count_saddle_elements(int** matrix, int row, int column)
{
	int saddle_element = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			saddle_element += is_this_element_saddle(matrix, row, column, j, i);
		}
	}

	return saddle_element;
}