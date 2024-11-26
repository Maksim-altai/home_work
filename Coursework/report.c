
#include "temp_functions.h" 


extern uint8_t str_err[100];
extern int statistic_year[3];


int main(int argc, char* argv[])
{   int  a = 0,b = 0,i = 0;  
    b = choice(argc, argv);
    data temperatura[2000] = {0,0,0,0,0,0};
    if (argc > 2)
    {
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

            }
        }
        else if (b < 0)
        {
            b *= -1;
            if (b < 13)
            {
                 data_file(b, temperatura);
            }
            if (b == 13)
            {
                for (i = 1; i < 13; i++)
                {
                    data_file(i, temperatura), temperatura;
                    memset(str_err, 0, sizeof(str_err));
                    memset(temperatura, 0, sizeof(temperatura));
                }
                
            }

        }
        return 0;
       
    }
  else
   help();
  
    printf(" \n");
    return 0;
}
