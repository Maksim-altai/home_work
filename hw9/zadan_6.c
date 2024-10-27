#include <stdio.h>
#define SIZE_ARRAY 200

int input(int a[])
{
    int i = 0, fl = 0, c = 0, data[6] = { 0 }, neg = 1;
    while (c != '\n' && i < SIZE_ARRAY)
    {
        c = getchar();
        if ((c != ' ' && c != '\n' && c != '-'))
            data[fl++] = c;
        else if (c == ' ' || c == '\n')
        {
            for (int n = 0; n < fl; n++)
            {
                if (fl > 1)
                    a[i] *= 10;
                a[i] += data[n] - '0';
            }
            a[i] *= neg;
            i++;
            fl = 0;
            neg = 1;
        }
        else if (c == '-')
            neg = -1;
    }
    return i;
}

void output(int size, int a[])
{
    while (size--)
        printf("%d ", *a++);
}

int is_two_same(int size, int a[])
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size - 1; j++)
        {
            if (a[i] == a[j + 1])
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    int data_a[SIZE_ARRAY] = { 0 }, i = 0;
    i = input(data_a);
    printf("%d ", is_two_same(i, data_a));
    return 0;
}







