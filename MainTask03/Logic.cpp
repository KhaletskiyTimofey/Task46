#include "Logic.h"

int find_row_with_max_count_of_numbers_in_ascending_order(int** matrix, int row, int column)
{
	int max_numbers_in_ascending_order_count = 0;

	for (int i = 0; i < row; i++)
	{
		int max_count = 0;

		for (int j = 1; j < column; j++)
		{
			if (matrix[i][j - 1] < matrix[i][j])
			{
				max_count += max_count > 0 ? 1 : 2;
				if (max_count > max_numbers_in_ascending_order_count)
				{
					max_numbers_in_ascending_order_count = max_count;
				}
			}
			else
			{
				max_count = 0;
			}
		}
	}

	return max_numbers_in_ascending_order_count;
}