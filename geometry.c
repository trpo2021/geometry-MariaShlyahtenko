
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    double x;
    double y;
    double r;
    char str[100];
    int flag = 0;
    char circle[6] = "circle";
    char* point = str;
    char* end_point = str;
    char* new_point;
    char* end;

    fgets(str, sizeof(str), stdin);

    while (isalpha(*end_point) != 0)
        end_point++;

    if ((end_point - point) <= 6) {
        if (strncasecmp(str, circle, 6) == 0)
            flag = 1;
    } else if (strncasecmp(str, circle, end_point - point) == 0)
        flag = 1;
    if (flag == 1) {
        flag = 0;
        point = end_point;
        new_point = point;

        while (*new_point != 10) {
            if (*new_point == '(') {
                point = new_point;
                flag = 1;
                break;
            }
            new_point++;
        }

        if (flag == 0) {
            printf("ERROR: expected 'circle' (\n");
            return 0;
        }

        while (isdigit(*point) == 0) // 1-ое число
        {
            if ((*point == ' ') || (*point == '('))
                point++;
            else {
                printf("ERROR X\n");
                return 0;
            }
        }

        if (isdigit(*point) != 0) {
            x = strtod(point, &end);
            point = end;
         printf ("x=%f\n", x);

        }

        while (isdigit(*point) == 0) // 2-е число
        {
            if (*point == ' ')
                point++;
            else {
                printf("ERROR Y\n");
                return 0;
            }
        }

        if (isdigit(*point) != 0) {
           y = strtod(point, &end);
            point = end;
            printf ("y= %f\n", y);
        }

        new_point = point;
        flag = 0;

        while (*new_point != 10) {
            if ((*new_point != ' ') && (*new_point != ',')) {
                printf("ERROR ,\n");
                return 0;
            } else if (*new_point== ',') {
                point = new_point;
                flag = 1;
                break;
            } else
                new_point++;
        }

        if (flag == 0)
            printf("ERROR ,");

        while (isdigit(*point) == 0) // 3-е число
        {
            if ((*point == ' ') || (*point == ','))
                point++;
            else {
                printf("ERROR Radius\n");
                return 0;
            }
        }

        if (isdigit(*point) != 0) {
            r = strtod(point, &end);
            point = end;
            printf ("r=%f\n", r);

        }

        flag = 0;
        new_point = point;

        while (*new_point!= 10) {
            if ((*new_point != ' ') && (*new_point != ')')) {
                printf("ERROR )\n");
                return 0;
            } else if (*new_point== ')') {
                point = new_point;
                flag = 1;
                break;
            } else
                new_point++;
        }

        if (flag == 0) {
            printf("ERROR )\n");
            return 0;
        }

        point++;

        while (*point != 10) {
            if (*point != ' ') {
                printf("ERROR: no items expected\n");
                return 0;
            } else
                point++;
        }
        printf("data entered correctly\n");
        return 0;
    }

    else
        printf("ERROR: expected 'circle'\n");
    return 0;
}
