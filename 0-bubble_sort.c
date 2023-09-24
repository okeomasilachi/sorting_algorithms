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

	if (array[0] == '\0' || !array[0])
	{
		message("0-O", "O(n)\nn square\nn square\n");
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				sorted = true;
				swap(array, j, (j + 1));
				print_array(array, size);
			}
		}
		if (sorted == false)
		{
			break;
		}
	}
	message("0-O", "O(n)\nn square\nn square\n");
}
