/*
** EPITECH PROJECT, 2021
** cpoolday04 task06
** File description:
** array sorting function
*/

static void my_swap_int(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void my_sort_int_array(int *array, int size)
{
    int min = 0;

    for (int i = 1; i < size; i++) {
        if (array[min] > array[i])
            min = i;
    }
    my_swap_int(&array[0], &array[min]);
    if (size > 1)
        my_sort_int_array(&array[1], size - 1);
}
