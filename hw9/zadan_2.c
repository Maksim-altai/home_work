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

int find_max_array(int size, int a[])
{
    int max = *a;
    for (int i = 1; i < size; i++)
        if (a[i] > max) 
            max = a[i];
    return max;
}

int main()
{
    int data_a[SIZE_ARRAY] = { 0 }, i = 0;
    i = input(data_a);
    find_max_array(i, data_a);
    printf("%d " ,find_max_array(i, data_a));
    return 0;
}






