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

// Função que remove o caracter '/n' numa string que é passada como argumento da função
int removeEnter(char *str) {
    int i = 0;
    while (*(str + i) != '\n')
        i++;
    *(str + i) = '\0';
    return 0;
}

/* Para evitar o gasto excessivo de memoria que uma alocação estática tem associado.Foi criada esta função que tem como
 * principal objetivo a essa otimização. A função recebe como parametors de entrada um double pointer para uma string
 * o tamanho inicial desta e o tamanho que irá ser alocado se o tamanho inicial não for suficiente para guardar toda
 * a informação na string.O double pointer é passado visto que a alocação de memoria dentro de uma rotina que é chamada
 * dentro da função main pode não ser eficaz e não resultar ficando essa memoria invisivel quando se regressa á função
 * main. Passando um double pointer esse problema fica resolvido.Esta função acaba por ter um funcionamento similar á
 * função getline da standart library e que é utilizada nesta aplicação.
 */
/*A memoria é realocada com recurso á função realloc()*/
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

//Função que recebe e protege a inserção de dados por parte do utilizador no campo do numero de telemovel verificando se este tem
//mesmo 9 digitos
//Recebe um double pointer para a string criada visto que durante a implementação parecia ser solução que trazia menos problemas
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

//Função que verifica se o ano tem 365 dias ou 366
//Recebe por isso um inteiro que representa o ano
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 0 : 1;
}

// Função que verifica a validade da data
// A range de Anos aceites varia entre 1900 e 9999
// Recebe como paramentros inteiros com o dia mês e ano
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

//Função que recebe e protege a inserção de dados por parte do utilizador no campo da data verificando se a data é valida
//Recebe um double pointer para a string criada visto que durante a implementação parecia ser solução que trazia menos
//problemas além de servir de treino no trabalho com double pointers
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

//Função que elimina espaços em branco no fim e no inicio de uma palavra/string
//Recebe um double pointer para a string criada visto que durante a implementação parecia ser solução que trazia menos
//problemas além de servir de treino no trabalho com double pointers
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

// Função que recebe um ponteiro para void e que termina o programa caso a memoria que foi allocada com recuso ao malloc()
// Teve sucesso.
void mallocFail(void *pointer) {
    if (pointer == NULL) {
        mallocFailMenu();
        exit(15);
    }

}

// Função que é responsavel por dar um delay com o tempo que é passado por parametro da função
// É utilizada para que os menus sejam mais automatizados.
void ConsolePause(double amount) {
    time_t current_time = time(0), start_time = time(NULL);
    while (difftime(current_time, start_time) < amount) {
        time(&current_time);
    }
}
