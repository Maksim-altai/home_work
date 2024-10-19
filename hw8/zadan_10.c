#include <stdio.h>
#define size_arr 20
#define size_ent_arr 12

int data_input(int* arr, int n)
{
    int i = 0;
    for (; i < 12 && i < n; arr++, i++)
        scanf("%d", arr);
    return i;
}
void sdvig_vpravo(int* arr, int n)
{
     int dvig = arr[--n];
     while (n > 0)
       arr[n--] = arr[n - 1];
     *arr = dvig;
    
}

int main(int argc, char** argv)
{
    int data_out[15] = { 0 };
    data_input(data_out, 20);
    for(int i = 0; i < 4; i++){
        sdvig_vpravo(data_out, 12);
    }
    output(data_out, 12);
    return 0;
}

void output(int* arr, int n)
{
    while (n--)
        printf("%d ", *arr++);
}
