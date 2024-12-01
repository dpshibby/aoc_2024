#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

#define LIST_LEN 1000

int
main (int argc, char *argv[])
{
	FILE *input = fopen ("input.txt", "r");
	if (input == NULL)
	{
		printf ("input file not found\n");
		exit (1);
	}

	int bytes_read;
	size_t nbytes = 64;
	char *line;

	/* lists known to be 1000 long */
	int list1[LIST_LEN];
	int list2[LIST_LEN];

	size_t distance = 0;

	for (int i = 0; i < LIST_LEN; i++)
	{
		bytes_read = getline (&line, &nbytes, input);
		sscanf (line, "%d %d", &list1[i], &list2[i]);
	}

	int arr_len = sizeof(list1) / sizeof(list1[0]);
	array_sort(list1, arr_len);
	array_sort(list2, arr_len);

	
	for (int i = 0; i < LIST_LEN; i++) {
		distance += abs(list1[i] - list2[i]);
	}

	/* %zu is for size_t printing */
	printf("distance: %zu\n", distance);

	return 0;
}
