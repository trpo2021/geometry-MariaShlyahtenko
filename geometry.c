#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    double x;
    double y;
    double r;
    char str[100];
    int flag = 0,i=0;
    char circle[6] = "circle";
    char* ykaz = str;
    char* kon_ykaz = str;
    char* new_ykaz;
    char* end;

    fgets(str, sizeof(str), stdin);

    while (isalpha(*kon_ykaz) != 0)
        kon_ykaz++;

    if ((kon_ykaz==6) && (strncasecmp(str,  circle , 6) == 0)) {
        ykaz = kon_ykaz;
        new_ykaz = ykaz;

        while (*new_ykaz != 10) {
            if (*new_ykaz == '(') {
                ykaz = new_ykaz;
                flag = 1;
                break;
            }
            new_ykaz++;
        }

        if (flag == 0) {
            printf("ERROR: expected 'circle' \n");
            return 0;
        }

        while (isdigit(*ykaz) == 0) //1-ое число
        {
            if ((*ykaz == ' ') || (*ykaz == '('))
                ykaz++;
            else {
                printf("ERROR 'X'\n");
                return 0;
            }
        }

        if (isdigit(*ykaz) != 0) {
            x = strtod(ykaz, &end);
            ykaz = end;
        }

        while (isdigit(*ykaz) == 0) //2-ое число
        {
            if (*ykaz == ' ')
                ykaz++;
            else {
                printf("ERROR 'Y'\n");
                return 0;
            }
        }

        if (isdigit(*ykaz) != 0) {
            y = strtod(ykaz, &end);
            ykaz = end;
        }

        new_ykaz = ykaz;
        flag = 0;

        while (*new_ykaz != 10) {
            if ((*new_ykaz != ' ') && (*new_ykaz != ',')) {
                printf("ERROR ','\n");
                return 0;
            } else if (*new_ykaz == ',') {
                ykaz = new_ykaz;
                flag = 1;
                break;
            } else
                new_ykaz++;
        }

        if (flag == 0)
            printf("ERROR ','");

        while (isdigit(*ykaz) == 0) //3-е число
        {
            if ((*ykaz == ' ') || (*ykaz == ','))
                ykaz++;
            else {
                printf("ERROR 'Radius'\n");
                return 0;
            }
        }

        if (isdigit(*ykaz) != 0) {
            r = strtod(ykaz, &end);
            ykaz = end;
        }

        flag = 0;
        new_ykaz = ykaz;

        while (*new_ykaz != 10) {
            if ((*new_ykaz != ' ') && (*new_ykaz != ')')) {
                printf("ERROR ')'\n");
                return 0;
            } else if (*new_ykaz == ')') {
                ykaz = new_ykaz;
                flag = 1;
                break;
            } else
                new_ykaz++;
        }

        if (flag == 0) {
            printf("ERROR ')'\n");
            return 0;
        }

        ykaz++;

        while (*ykaz != 10) {
            if (*ykaz!= ' ') {
                printf("ERROR: no unexpected \n");
                return 0;
            } else
                ykaz++;
        }
        printf("data entered correctly\n");
        return 0;
    }

    else
        printf("ERROR: expected 'circle'\n");
    return 0;
}
