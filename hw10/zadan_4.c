
#include <stdio.h>
#include <string.h>
#include <stdint.h>
const int LINE_WIDTH = 1024;


int main(void)
{
    char input[] = "input.txt";
    char output[] = "output.txt";
    struct data_input
    {
        char line[LINE_WIDTH];
        int count1;
        int count2;
    }data;
    uint8_t* p = 0;
    p = (uint8_t*)&data;
    FILE* f_in,* f_out;

    if ((f_in = fopen(input, "r")) == NULL)
    {
        printf("Error occured while opening input file!");
        return 1;
    }
    if ((f_out = fopen(output, "w")) == NULL)
    {
        printf("Error occured while opening output file!");
        return 1;
    }

    data.count1 = 0;
    do
    {
        data.line[data.count1] = getc(f_in);
        if (data.line[data.count1] == ' ')
            data.count2 = data.count1;
    } while ((data.line[data.count1] != EOF) && (data.line[data.count1++] != '\n'));
    data.line[data.count1] = '\0';


    char buffer[50];
    int n = 0;
    for (int i = 0; i < data.count2; i++, n++) 
    {
        for (int j = i + 1; j < data.count2; j++)
        {
            if (*(p + i) == *(p + j))
            {
                i += 2;
                j += 2;
            }
        }
        buffer[n] = *(p + i);
    }
    buffer[n] = '\0';
    char buffer_2[50];
    n = 0;
    for (int i = data.count2 + 1; i < data.count1; i++, n++)
    {
        for (int j = i + 1; j < data.count1; j++)
        {
            if (*(p + i) == *(p + j))
            {
                i += 2;
                j += 2;
            }
        }
        buffer_2[n] = *(p + i);
    }
    buffer_2[n] = '\0';
    for(int i = 0; buffer[i] != '\0'; i++)
        for(n = 0; buffer_2[n] != '\0';n++)
            if(buffer[i] == buffer_2[n])
                fprintf(f_out, "%c ", buffer[i]);

    fclose(f_in);
    fclose(f_out);
    return 0;
}
