#include "sort.h"

/**
 * swap - swaps the values of two elements in an array.
 *
 * @array: A pointer to an array of integers.
 * @num1: The index of the first element in the array that needs to be swapped.
 * @num2: The parameter "num2" is the index of the second
 *			element in the array that we want to swap.
 *
 * Return: Void
 */
void swap(int *array, size_t num1, size_t num2)
{
	int tmp;

	tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
}

/**
 * partiton - takes an array, a range of indices, and a pivot value,
 *				and rearranges the elements in the array
 * @arr: An array of integers that needs to be partitioned.
 * @small_val: the starting index of the subarray that needs
 *				to be partitioned.
 * @big_val: represents the index of the last element in the array.
 * @size: represents the size of the array "arr".
 *
 * Return: the index of the pivot element after partitioning the array.
 */
size_t partiton(int *arr, int small_val, int big_val, size_t size)
{
	int i, j;
	int pivot = arr[big_val];

	i = small_val - 1;
	for (j = small_val; j <= big_val - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, (i + 1), big_val);
	print_array(arr, size);
	return (i + 1);
}

/**
 * sort_recursive - recursively sorts an array of integers using
 *					the partitioning technique.
 * @array: Pointer to the array that needs to be sorted.
 * @small_val: The starting index of the array or subarray to be sorted.
 * @big_val: The index of the last element in the
 *				array that needs to be sorted.
 * @size: Size of the array. It is of type size_t.
 *
 * Return: void
 */
void sort_recursive(int *array, int small_val, int big_val, size_t size)
{
	int val;

	if (small_val < big_val)
	{
		val = partiton(array, small_val, big_val, size);

		sort_recursive(array, small_val, val - 1, size);
		sort_recursive(array, val + 1, big_val, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm.
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array.
 *
 * Return:Void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	sort_recursive(array, 0, size - 1, size);
}
