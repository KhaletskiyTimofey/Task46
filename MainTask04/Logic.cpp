#include "Logic.h"

void find_two_positive_numbers(int** matrix, int column, int row_id, int& first_number_id, int& second_number_id)
{
	first_number_id = -1;
	second_number_id = -1;

	for (int i = 0; i < column; i++)
	{
		if (matrix[row_id][i] > 0)
		{
			if (first_number_id == -1)
			{
				first_number_id = i;
			}
			else
			{
				second_number_id = i;
				return;
			}
		}
	}

	first_number_id = -1;
	return;
}

int calculate_sum(int** matrix, int row, int column)
{
	int sum = 0;

	for (int i = 0; i < row; i++)
	{
		int first_number_id, second_number_id;

		find_two_positive_numbers(matrix, column, i, first_number_id, second_number_id);

		if (first_number_id != -1)
		{
			for (int j = first_number_id + 1; j < second_number_id; j++)
			{
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}