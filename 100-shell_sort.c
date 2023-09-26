#include "sort.h"

/**
* shell_sort - shell sort alglorithm using Knuth Sequence
* @array: array to sort
* @size: size of array
*
* Return: 0
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	gap = 1;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;

	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
