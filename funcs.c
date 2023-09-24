#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * message - writes a given message to a file with the
 *          specified filename.
 * @filename: A string representing the name of the file
 *          to be created or overwritten.
 * @mess: Pointer to a constant character array, which
 *          represents the * message that will be written
 *          to the file.
 *
 * Return: void
 */
void message(const char *filename, const char *mess)
{
	FILE *file = NULL;

	file = fopen(filename, "w");
	fputs(mess, file);
	fclose(file);
}

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
