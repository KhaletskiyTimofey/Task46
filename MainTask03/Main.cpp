#include <time.h>
#include "Logic.h"
#include "Utils.h"

int main()
{
	srand(time(0));

	int row, column;

	cout << "Enter size of matrix (rows columns): ";
	cin >> row >> column;

	int min_number, max_number;

	cout << "Enter min and max numbers: ";
	cin >> min_number >> max_number;

	int** matrix = new int* [row];

	init_matrix(matrix, row, column, min_number, max_number);

	cout << matrix_to_string(matrix, row, column) << endl;
	cout << "Max count of numbers in ascending order: " << find_row_with_max_count_of_numbers_in_ascending_order(matrix, row, column) << endl;

	delete_matrix(matrix, row, column);

	return 0;
}