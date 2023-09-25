#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *              using the bubble sort algorithm.
 * @array: The parameter `array` is a pointer to an integer array.
 * @size: The parameter `size` represents the number of elements
 *        in the array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool sorted = false;
	int tmp;

	if (array[0] == '\0' || !array[0])
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				sorted = true;
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		if (sorted == false)
			break;
	}
}
