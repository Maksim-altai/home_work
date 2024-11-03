
#define SIZE_LINE 1024
#include <stdio.h>
#include <string.h>
#include <stdint.h>


struct data
{
    char line[SIZE_LINE];
    int count1;
};
void input_file(FILE* f, struct data* dat)
{
    dat->count1 = 0;
    do
    {
        dat->line[dat->count1] = getc(f);
    } 
    while ((dat->line[dat->count1] != EOF) && (dat->line[dat->count1++] != '\n'));
    dat->line[dat->count1] = '\0';
}
void change_file(uint8_t* pp, struct data* dat)
{
    for (int i = 0; i < dat->count1; i++)
    {
        if (*(pp + i) == 'a')
            *(pp + i) = 'b';
        else if (*(pp + i) == 'b')
            *(pp + i) = 'a';
        else if (*(pp + i) == 'A')
            *(pp + i) = 'B';
        else if (*(pp + i) == 'B')
            *(pp + i) = 'A';
    }
}


int main(void)
{
    char f_in[] = "input.txt";
    char f_out[] = "output.txt";
    struct data buffer;
    uint8_t* p = 0;
    p = (uint8_t*)&buffer;
    FILE* fp_in, * fp_out;

    if ((fp_in = fopen(f_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    if ((fp_out = fopen(f_out, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    input_file(fp_in, &buffer);
    change_file(p, &buffer);
    fprintf(fp_out, "%s ", p);
    
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
