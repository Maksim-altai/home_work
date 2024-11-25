
#include "temp_functions.h" 

extern FILE* file_input;
extern FILE* file_output;
extern uint8_t str_err[100];
extern int statistic_year[3];


int main(int argc, char* argv[])
{
    data temperatura[2000] = {0,0,0,0,0,0};
    if (argc > 1)
    {
        int  a = 0,b = 0,i = 0;
        b = choice(argc, argv);
        if (b  > 0)
        {
            if (b < 13)
            {
                print_month(data_file(b, temperatura), temperatura);
            }
            if (b == 13)
            {
                for ( i = 1; i < 13; i++)
                {
                    print_month(data_file(i, temperatura), temperatura);
                    memset(str_err, 0, sizeof(str_err));
                    memset(temperatura, 0, sizeof(temperatura));
                }
                printf("Year statistic averedge is: %d ,min is: %d ,max is: %d \n", statistic_year[0] / 12, statistic_year[1], statistic_year[2]);
            }
       
            fclose(file_input);
        }
        else if (b < 0)
        {
            b *= -1;
            char out_file[] = "out_statistic.txt";
            write_temperature(out_file);
            if (b < 13)
            {
                month_print(data_file(b, temperatura), temperatura);
                printf("Recording statistic is fail :out_static.txt \n");
            }
            if (b == 13)
            {
                for (i = 1; i < 13; i++)
                {
                    month_print(data_file(i, temperatura), temperatura);
                    memset(str_err, 0, sizeof(str_err));
                    memset(temperatura, 0, sizeof(temperatura));
                }
                fprintf(file_output,"Year statistic averedge is: %d ,min is: %d ,max is: %d \n", statistic_year[0] / 12, statistic_year[1], statistic_year[2]);
                printf("Recording statistic is fail :out_static.txt \n");
            }
            fclose(file_output);
        }
        return 0;
    }
    else
    printf(" \n");
    return 0;
}
