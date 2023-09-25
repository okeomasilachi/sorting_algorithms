#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 *					order using the selection sort algorithm.
 * @array: Pointer to the first element of an array of integers.
 * @size: The size of the array, which is the number of
 *			elements in the array.
 *
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t pos, i, j;
	FILE *file = NULL;
	int tmp;

	if (!array || !array[1])
	{
		file = fopen("2-O", "w");
		fputs("n square\nn square\nn square\n", file);
		fclose(file);
		return;
	}
	for (i = 0; i < (size - 1); i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		if (pos != i)
		{
			/* swap(array, i, pos); */
			tmp = array[i];
			array[i] = array[pos];
			array[pos] = tmp;
			print_array(array, size);
		}
	}
	file = fopen("2-O", "w");
	fputs("n square\nn square\nn square\n", file);
	fclose(file);
}
