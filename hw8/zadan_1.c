#include <stdio.h>

int data_input(int* arr, int n)
{
    int i = 0;
    for (; i < 10 && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}
int sum(int* arr, int n)
{
    int data = 0;
    for (int i = 0; i < n; i++, arr++)
        if (*arr > 0)
            data += *arr;
    return data;
}


int main(int argc, char** argv)
{
    int data_out[20] = { 0 };
    data_input(data_out, 20);
    printf("%d ", sum(data_out, 10));
    return 0;
}

