#include <stdio.h>

int data_input(int* arr, int n)
{
    int i = 0;
    for (; i < 12 && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}
float mean(int* arr, int n)
{
    float data = 0;
    for (int i = 0; i < n; i++)
        data += arr[i];
    return data /= n;
}
int main(int argc, char** argv)
{
    int data_out[15] = { 0 };
    data_input(data_out, 15);
    printf("%.2f ", mean(data_out, 12));
    return 0;
}
