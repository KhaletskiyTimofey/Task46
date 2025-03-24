#include "Logic.h"

int find_row_with_max_count_of_similar_numbers(int** matrix, int row, int column)
{
	int row_idx = 0;
	int max_similar_numbers_count = 0;

	for (int i = 0; i < row; i++)
	{
		int max_count = 0;

		for (int j = 1; j < column; j++)
		{
			if (matrix[i][j - 1] == matrix[i][j])
			{
				max_count += max_count > 0 ? 1 : 2;
				if (max_count > max_similar_numbers_count)
				{
					max_similar_numbers_count = max_count;
					row_idx = i;
				}
			}
			else
			{
				max_count = 0;
			}
		}
	}

	return row_idx;
}