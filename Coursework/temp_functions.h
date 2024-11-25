#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct 
{
    uint16_t year;
    uint8_t mounth;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    char temperature;
}data;

int choice(int array,char **arr);

uint8_t file_cmd(const char* arr);

uint8_t read_temperature(char* arr);

uint8_t write_temperature(char* arr);

bool error(char* p);

uint16_t data_file(int b, data* p);

void print_month(uint16_t b, data* p);

void month_print(uint16_t b, data* p);


