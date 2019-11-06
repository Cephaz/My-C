/*
** ETNA PROJECT, 01/10/2019 by zhou_p
** my_sort_intarr.c
** File description:
**      Code is poetry..
*/

void my_sort_intarr(int *array, int size)
{
	int i;
	int j;
	int imin;
	int sub;

	i = 0;
	while (i < size - 1) {
		imin = i;
		j = i;
		while (j < size) {
			if (array[j] < array[imin]) {
				imin = j;
			}
			++j;
		}
		sub = array[imin];
		array[imin] = array[i];
		array[i] = sub;
		++i;
	}
}
