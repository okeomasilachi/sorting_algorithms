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

	if (!array || !array[1])
	{
		message("2-O", "n square\nn square\nn square\n");
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
			swap(array, i, pos);
			print_array(array, size);
		}
	}
	message("2-O", "n square\nn square\nn square\n");
}
