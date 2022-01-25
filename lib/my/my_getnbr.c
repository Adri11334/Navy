/*
** EPITECH PROJECT, 2021
** cpoolday04 task05
** File description:
** returns number sent as string
*/

int my_putchar(char c);
int my_strlen(char const *str);

int my_getnbr(char const *str)
{
    int sum = 0;

    for (int count = 0; str[count] >= '0' && str[count] <= '9'; count++) {
        sum = (str[count] - 48) + sum * 10;
    }
    return (sum);
}

/*static int ovf(int num)
{
    if ((num == '9') || (num == '8'))
        return (1);
    else
        return (0);
}

static int my_getnbr_end(char const *str, int count, int end, int bool)
{
    int sum = 0;

    while (count < end) {
        if (sum > 214748364) {
            return (0);
        }
        if (bool == 1 && sum == 214748364 && ovf(str[count])) {
            return (0);
        }
        if (bool == 0 && sum == 214748364 && str[count] == '9') {
            return (0);
        }
        sum = (str[count] - 48) + sum * 10;
        (count++);
    }
    return (sum);
}

static int my_getnbr_digcheck(char const *str, int count, int bool)
{
    int start = count;

    if (str[count] < '0' || '9' < str[count]) {
        return (0);
    }
    while (47 < str[count] && str[count] < 58) {
        (count++);
    }
    return (my_getnbr_end(str, start, count, bool));
}

int my_getnbr(char const *str)
{
    int count = 0;
    int num_neg = 0;
    int max_cycles = my_strlen(str);

    while ((str[count] == 43 || str[count] == 45) && (max_cycles != 0)) {
        if (str[count] == 45) {
            (num_neg++);
        }
        (count++);
        (max_cycles--);
    }
    if (num_neg % 2 == 1) {
        return (my_getnbr_digcheck(str, count, 0) * -1);
    }
    return (my_getnbr_digcheck(str, count, 1));
}
*/
