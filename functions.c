#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/Menus.h"

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
    mallocFail(*string);

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

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 0 : 1;
}

int isDateValid(int day, int month, int year) {
    int answer = 0, min = 1900, max = 9999;

    if (year > max || year < min)
        answer = 1;
    if ((month > 12 || month < 1))
        answer = 1;
    if (day < 1 || day > 31)
        answer = 1;
    if (month == 2) {
        if (!isLeapYear(year)) {
            if (day > 29)
                answer = 1;
        } else if (day > 28)
            answer = 1;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            answer = 1;
    }
    return answer;
}

int getDateOfBirth(char **date) {
    int found, day, month, year;
    do {
        found = 1;
        readstring(date, 9, 3);
        sscanf(*date, "%d/%d/%d", &day, &month, &year);
        if (isDateValid(day, month, year)) {
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

void mallocFail(void *pointer) {
    if (pointer == NULL) {
        mallocFailMenu();
        exit(15);
    }

}

void ConsolePause(double amount) {
    time_t current_time = time(0), start_time = time(NULL);
    while (difftime(current_time, start_time) < amount) {
        time(&current_time);
    }
}
