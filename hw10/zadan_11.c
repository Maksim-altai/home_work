#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define SIZE_LINE 2048

struct data
{
    char line[SIZE_LINE];
    int count1;
    int num;
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

int massiv(struct data* dat)
{
    char buffer[50] = { 0 };
    for (int i = 0, n = 0; i <= dat->count1; i++)
    {
        if (dat->line[i] != ' ' && dat->line[i] != '\0' && dat->line[i] != '\n')
            buffer[n++] = dat->line[i];
        else if (dat->line[i] == ' ' || dat->line[i] == '\0' || dat->line[i] != '\n')
        {
            buffer[n] = '\0';
            if (buffer[n - 1] == 'a')
                dat->num++;
            n = 0;
        }
    }
    return dat->num;
}


int main(void)
{
    char f_in[] = "input.txt";
    char f_out[] = "output.txt";
    struct data buffer = { {0},0,0 };
    FILE* fp_in, * fp_out;

    if ((fp_in = fopen(f_in, "r")) == NULL)
    {
        printf("Error occured while opening input file!");
        return 1;
    }
    if ((fp_out = fopen(f_out, "w")) == NULL)
    {
        printf("Error occured while opening output file!");
        return 1;
    }

    input_file(fp_in, &buffer);
    fprintf(fp_out, "%d ", massiv(&buffer));

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}



