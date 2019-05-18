#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <time.h>

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

int readstring(char **string, int init_size, int chunk) {
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

int getPhoneNumber(char **phone) {
    char *i;
    int count, found;
    do {
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
            printf("Insira o seu nº de Numero de Telemovel: ");
        }
    } while (found == 0 || count != 9);
    return 0;
}

int checkDate(int day, int month, int year) {
    int answer = 1;
    return answer;
}

int getDateOfBirth(char **date) {
    int found, day, month, year;
    do {
        found = 1;
        readstring(date, 9, 3);
        sscanf(*date, "%d/%d/%d", &day, &month, &year);
        if (day < 0 || day > 31 || month < 0 || month > 12 || year < 1900 ||
            year > 2030) { // tolerancia entre 1900 - 2030
            printf("Data Invalida! (dd/mm/yyyy)\n");
            printf("Insira a sua data de nascimento: ");
            found = 0;
        }
    } while (found == 0);
    return 0;
}


int strip(char **string) {
    char *last = *string + strlen(*string) - 1;

    while (last >= *string && isspace(*last)) {
        last--;
    }

    *(last + 1) = '\0';

    while (**string && isspace(**string)) {
        (*string)++;
    }
    return 0;
}

void ConsolePause(double amount) {
    time_t current_time = time(0), start_time = time(NULL);
    while (difftime(current_time, start_time) < amount) {
        time(&current_time);
    }
}