#include "temp_functions.h"    
FILE* file_input = 0;
FILE* file_output = 0;
uint8_t str_err[100] = { 0 };
int statistic_year[3] = { 0 };



int choice(int array, char** arr)
{
    int i = 1;
    int b = 0;
    if (!memcmp(arr[i], "-h", 2))
    {
       return 0;
    }
    if (!memcmp(arr[i], "-f", 2))
    {
        i++;
        if (i < array)
        {
            if (read_temperature(arr[i])) 
            {
                i++;
                if (i < array)
                {
                    if (!memcmp(arr[i], "-m", 2))
                    {
                        i++;
                        if (i < array)
                        {
                            sscanf(arr[i],"%d",&b);
                            if (b > 12 || b <= 0)
                                return 0;
                            else
                                return b;
                        }
                        return 0;
                    }
                    if (!memcmp(arr[i], "-o", 2))
                    {
                        i++;
                        if (i < array)
                        {
                            sscanf(arr[i], "%d", &b);
                            if (b > 12 || b <= 0)
                                return 0;
                            else
                                return ( -1 * b);
                        }
                        return -13;
                    }
                }
                return 13;  
            }
            return 0;
        }

    }
    return 0;
}

uint8_t file_cmd(const char* arr)
{
    uint16_t n = strlen(arr);
    char file_data[100] = {"\0"};
    for (int c = n; c ; c--)
    {
        if (arr[c] == '.')
        {
            int j = 0;
            for (; arr[c] != '\0'; j++)
            {
                c++;
                file_data[j] = arr[c];
            }
            file_data[j] = '\0';
            if (!memcmp(file_data, "csv", 3))
            {
                return 1;
            }
            break;
        }
    }   
    return 0;
}

uint8_t read_temperature(char* arr)
{
    if (file_cmd(arr))
    {
        if ((file_input = fopen(arr, "r")) == NULL)
        {
            printf("Error occured while opening input file! \n");
            return 0;
        }
        return 1;
    }
    printf("Error opening input file! \n");
    return 0;
}

uint8_t write_temperature(char* arr)
{
        if ((file_output = fopen(arr, "w")) == NULL)
        {
            perror("Error occured while opening output file! \n");
            return 0;
        }
        return 1;
}

bool error(char* p)
{
    int i = 0;
    while (*(p + i))
    {
        if (*(p + i) == '-' || *(p + i) >= '0' && *(p + i) <= '9' || *(p + i) == '\n')
            i++;
        else
            return true;
    }
    return false;
}

uint16_t data_file(int b, data* p)
{
    fseek(file_input, 0, SEEK_SET);
    uint8_t s_err = 0;
    char row[2000];
    char* meaning;
    bool err_temp = false;
    uint16_t count = 0, fl_struct = 0, count_err = 0;
    while (!feof(file_input))
    {
        fgets(row, 0x7f, file_input);
        meaning = strtok(row, ";");
        while (meaning != NULL)
        {

            if(fl_struct == 0)
            {
                p[count].year = atoi(meaning);
                meaning = strtok(NULL, ";");
            }
            if(fl_struct == 1)
            {
                p[count].mounth = atoi(meaning);
                meaning = strtok(NULL, ";");
            }
            if(fl_struct==2)
            {
                p[count].day = atoi(meaning);
                meaning = strtok(NULL, ";");
            }
            if(fl_struct==3)
            {
                p[count].hour = atoi(meaning);
                meaning = strtok(NULL, ";");
            }
            if(fl_struct==4)
            {
                p[count].minute = atoi(meaning);
                meaning = strtok(NULL, ";");
            }
            if(fl_struct==5)
            {
                err_temp = error(meaning);
                p[count].temperature = atoi(meaning);
                meaning = strtok(NULL, ";");
            }
            fl_struct++;
        }
        fl_struct = 0;
        if (p[count].mounth == b && !err_temp)
            count++;
        if (p[count].mounth == b && err_temp)
        {
            str_err[s_err++] = count_err + 1;
            err_temp = false;
        }
        if (p[count].mounth > b)
            return count;
        count_err++;
    }
    return count;
}

void print_month(uint16_t b, data* p)
{
    static uint16_t num = 0;
    uint8_t ernum = 0;
    while (str_err[ernum] != 0)
    {
        if (b == 0)
        {
            printf("  Error temp fail temp.csv str = %d \n", str_err[ernum]);
            return;
        }
        ernum++;
    }
    if (!num)
        printf("  #   Year Month Nuvalue Ervalue MonthAvg MonthMax MonfMin \n");
    printf(" %2d  %5d %3d %6d %7d", num, p->year, p->mounth, b, ernum);
    int y = 0, minimum = p->temperature, maximum = p->temperature;
    for (uint8_t i = 0; i < b; i++)
    {
        y += p[i].temperature;
        if (minimum < p[i].temperature)
            minimum = p[i].temperature;
        if (maximum > p[i].temperature)
            maximum = p[i].temperature;
    }

    y /= b;
    statistic_year[0] += y;
    if (statistic_year[1] > minimum)
        statistic_year[1] = minimum;
    if (statistic_year[2] < maximum)
        statistic_year[2] = maximum;
    printf(" %7d %9d %7d \n", y, minimum, maximum);
    num++;
}

void help()
{
    printf("Temp statistic application. Pleas enter key: \n");
    printf("-h for help. \n");
    printf("-f file_name(.csv) for load this file.\n");
    printf("-m xx statistic for xx month. \n");
    printf("Primer: -f file_name(.csv) (statistic YAER) or -m 2 (statistic MOUNTH 2) \n");
}