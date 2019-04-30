#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"

int removeEnter(char *str) {
    int i = 0;
    while (*(str + i) != '\n')
        i++;
    *(str + i) = '\0';
    return 0;
}

char readstring(char **string, int init_size, int chunk) {
    int size = 0, i = 0;
    char c;
    *string = malloc(sizeof(char) * init_size);

    while ((c = getc(stdin)) != '\n') {
        if (size <= i) {
            size += chunk;
            *string = realloc(*string, size);
        }
        *(*(string) + i) = c;
        i++;
    }
    *(*(string) + i) = '\0';
    return 0;
}

int getHourAndMinute(Hour_t *time, int option, char *string, char *delimiter) {
    char *token;
    int i = 0;
    token = strtok(string, delimiter);
    while (token != NULL) {
        if (i == 0) {
            if (option == 0)
                time->start_hour = atoi(token);
            else
                time->end_hour = atoi(token);
        } else {
            if (option == 0)
                time->start_minute = atoi(token);
            else
                time->end_minute = atoi(token);
        }
        i++;
        token = strtok(NULL, delimiter);
    }
    return 0;
}

int getPhoneNumber(char **phone) {
    char *i;
    int count, found;
    do {
        printf("Insira o seu nº de Numero de Telemovel: ");
        readstring(phone, 9, 5);
        ClearBuffer();
        found = 1;
        count = 0;
        for (i = *phone; i < *phone + strlen(*phone) && found != 0; i++, count++) {
            if (isalpha(*i))
                found = 0;
        }
        if (count != 9 || found == 0) {
            printf("Numero Invalido!\n");
        }
    } while (found == 0 || count != 9);
    return 0;
}

