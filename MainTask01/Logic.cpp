#include "Logic.h"

int* find_rows_in_ascending_order(int** matrix, int row, int column, int& rows_in_ascending_order_count)
{
	int* rows_in_ascending_order = new int[row];
	rows_in_ascending_order_count = 0;

	for (int i = 0; i < row; i++)
	{
		bool is_in_ascending_order = true;

		for (int j = 1; j < column; j++)
		{
			if (matrix[i][j - 1] >= matrix[i][j])
			{
				is_in_ascending_order = false;
				break;
			}
		}
		if (is_in_ascending_order)
		{
			rows_in_ascending_order[rows_in_ascending_order_count] = i;
			rows_in_ascending_order_count++;
		}
	}

	return rows_in_ascending_order;
}

int find_max_element(int** matrix, int row, int column)
{
	int rows_in_ascending_order_count;
	int* rows_in_ascending_order = find_rows_in_ascending_order(matrix, row, column, rows_in_ascending_order_count);
	int max = matrix[0][0];
	bool is_max_element_changed = false;

	for (int i = 0; i < rows_in_ascending_order_count; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (matrix[rows_in_ascending_order[i]][j] > max)
			{
				max = matrix[rows_in_ascending_order[i]][j];
				is_max_element_changed = true;
			}
		}
	}

	delete[] rows_in_ascending_order;

	return is_max_element_changed ? max : 0;
}