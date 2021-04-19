#pragma once
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT_CICLE 8

typedef struct {
    double x;
    double y;
    double radius;
    double perimeter;
    double area;
} figure_circle;

// char* figure_calling(char*, char*, char*);
// char* search_brackets(char*, char);
// char* search_digit(char*, double*);
// char* search_comma(char*);
// char* end_string(char*);
double perimeter_circle(figure_circle circle);
double area_circle(figure_circle circle);
int test_circle(char*, char*, char*, figure_circle* circle, int);
