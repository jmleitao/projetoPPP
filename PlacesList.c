#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PlacesList.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/Menus.h"
#include "Headers/StudentsList.h"

// Função que verifica se a lista de locais está vazia
// Recebe a cabeça da lista e retorna 1 se estiver vazia e 0 caso contrario
int isEmptyPlaces(Places_t *head) { return head->next == NULL ? 1 : 0; }

/*Função que procura um local na lista ligada de locais com o nome "key" e se encontrar atualiza o paramentro current
 * com esse node.O parametro before é atualizado com o node antes do current o que dá jeito para a função que remove um
 * local(se os locais favoritos do aluno estivessem implementados como uma lista como incialmente estavam mas não estão..
 * por isso afuncinalidade foi removida por não ser necessária).A função é utilizada na mesma para procurar um local na
 * lista de locais por isso recebe a cabeça da lista.
 */
int FindPlace(PlacesList head, PlacesList *before, PlacesList *current, char *key) {
    *before = head;
    *current = head->next;

    while ((*current) != NULL && (strcmp((*current)->name, key) != 0)) {
        *before = *current;
        *current = (*current)->next;
    }
    if ((*current) != NULL && (strcmp((*current)->name, key) != 0)) {
        *current = NULL;
    }
    return 0;
}

// Função que chama a função anterior e que apenas devolve o node se este for encontrado e NULL caso contrario
PlacesList SearchPlace(PlacesList head, char *key) {
    PlacesList before;
    PlacesList current;
    FindPlace(head, &before, &current,
              key);
    return current;
}

// Função que recebe a cabeça da lista de pontos de interesse que se encontra dentro dos locais e dá free de todos
// os nós desta lista na memoria
// Encontra-se no ficheiro Places.c só mesmo por forma a facilitar a leitura do codigo e o sentido lógico do mesmo
int DeletePointsOfInterestList(PointsOfInterestList head) {
    PointsOfInterestList current;
    while (!isEmptyPointsOfInterest(head)) {
        current = head;
        head = head->next;
        free(current);
    }
    free(head);
    return 0;
}

// Função que recebe a cabeça da lista de Locais e dá free de todos os nós desta lista na memoria
int DeletePlacesList(PlacesList head) {
    PlacesList current;
    while (!isEmptyPlaces(head)) {
        current = head;
        DeletePointsOfInterestList(current->PointOfInterest);
        head = head->next;
        free(current);
    }
    free(head);
    return 0;
}

// Função que recebe dois nós de uma lista ligada de locais e reajanja os ponteiros com o objetivo de os reordenar
PlacesList swapPlacesListNodes(PlacesList NodePointer1, PlacesList NodePointer2) {
    PlacesList temporary = NodePointer2->next;
    NodePointer2->next = NodePointer1;
    NodePointer1->next = temporary;
    return NodePointer2;
}

// Função que serve para ordenar alfabéticamente a lista de locais
// Recebe a cabeça da lista de locais e o numero de nodes desta
int AlphaSortPlacesAndPointsOfInterest(PlacesList *head, int numNodes) {
    head = &(*head)->next;
    PlacesList *start, node1, current;
    int i, j, sorted;

    for (i = 0, sorted = 1; i <= numNodes && sorted != 0; i++) {
        start = head;
        sorted = 0;
        for (j = 0; j < numNodes - 1 - i; j++) {
            node1 = *start;
            if (strcmp(node1->name, node1->next->name) > 0) {
                *start = swapPlacesListNodes(node1, node1->next);
                sorted = 1;
            }
            start = &((*start)->next);
        }

    }
    current = *head;
    while (current != NULL) {
        AlphaSortPointsOfInterestList(&current->PointOfInterest, PointsOfInterestCount(current->PointOfInterest));
        current = current->next;
    }
    return 0;
}

// Função que serve para ordenar por popularidade a lista ligada
int PopSortPlacesAndPointsOfInterest(PlacesList *head, int numNodes) {
    head = &(*head)->next;
    PlacesList *start, node1, current;
    int i, j, sorted;

    current = *head;
    while (current != NULL) {
        PopSortPointsOfInterestList(&current->PointOfInterest, PointsOfInterestCount(current->PointOfInterest));
        current = current->next;
    }
    for (i = 0, sorted = 1; i <= numNodes && sorted != 0; i++) {
        start = head;
        sorted = 0;
        for (j = 0; j < numNodes - 1 - i; j++) {
            node1 = *start;
            if (node1->Popularity == node1->next->Popularity &&
                node1->PointOfInterest->next->Popularity < node1->next->PointOfInterest->next->Popularity) {
                *start = swapPlacesListNodes(node1, node1->next);
                sorted = 1;
            } else if (node1->Popularity < node1->next->Popularity) {
                *start = swapPlacesListNodes(node1, node1->next);
                sorted = 1;
            }
            start = &((*start)->next);
        }
    }
    return 0;
}
// Função que serve para Contar o numero de locais que a lista ligada de locais contém
int PlacesCount(PlacesList head) {
    int counter = 0;
    PlacesList current = head->next;
    while (current != NULL) {
        current = current->next;
        counter++;
    }
    return counter;
}

// Função de Print de locais e pontos de interesse
int DisplayPlacesAndPointsOfInterest(PlacesList head) {
    PlacesList current_place = head->next;
    PointsOfInterestList current_point_of_interest;

    printf("+------------------------------------------------------------+\n");
    printf("                 Locais e Pontos de Interesse\n\n");

    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        printf("   %s: \n\n", current_place->name);
        while (current_point_of_interest != NULL) {
            printf("   -> %s  \n", current_point_of_interest->name);
            current_point_of_interest = current_point_of_interest->next;
        }
        printf("\n");
        current_place = current_place->next;
    }
    justPause();
    printf("\n+------------------------------------------------------------+\n\n");
    ClearBuffer();
    getchar();
    ClearConsole();
    return 0;
}

// Função de Print de locais e pontos de interesse
int DisplayPlacesAndPointsOfInterestWithInfo(PlacesList head) {
    int i;
    PlacesList current_place = head->next;
    PointsOfInterestList current_point_of_interest;

    printf("+---------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------+\n");
    printf("\t\t\t\t\t\t\t\t   Locais e Pontos de Interesse\n\n");

    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        printf("   %s: \n", current_place->name);
        while (current_point_of_interest != NULL) {
            printf("\t -> %s\n", current_point_of_interest->name);
            printf("\t\t Horário: %s\n", current_point_of_interest->WorkingHours);
            printf("\t\t Descrição:");
            i = 0;
            while (current_point_of_interest->info[i] != '\0') {
                if (current_point_of_interest->info[i] == '\n') {
                    printf("%c", current_point_of_interest->info[i]);
                    printf("\t\t\t\t");
                } else {
                    printf("%c", current_point_of_interest->info[i]);
                }
                i++;
            }
            printf("\n\t\t\t\t\t\t\t\t\t\t--------------------------------\n\r\n");
            current_point_of_interest = current_point_of_interest->next;
        }
        printf("\n");
        current_place = current_place->next;
    }
    printf("+---------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------+\n");
    justPause();
    ClearBuffer();
    getchar();
    ClearConsole();
    return 0;
}
// Função de Print de locais e pontos de interesse
int DisplayPlacesAndPointsOfInterestWithPopularity(PlacesList head) {
    PlacesList current_place = head->next;
    PointsOfInterestList current_point_of_interest;

    printf("+------------------------------------------------------------+\n");
    printf("                 Locais e Pontos de Interesse\n\n");

    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        printf("   %s (Popularidade %d): \n\n", current_place->name, current_place->Popularity);
        while (current_point_of_interest != NULL) {
            printf("   -> %s   (Popularidade %d)\n", current_point_of_interest->name,
                   current_point_of_interest->Popularity);
            current_point_of_interest = current_point_of_interest->next;
        }
        printf("\n");
        current_place = current_place->next;
    }
    justPause();
    printf("\n+------------------------------------------------------------+\n\n");
    ClearBuffer();
    getchar();
    ClearConsole();
    return 0;
}

int isInFavPlaces(StudentsList student, char *place) {
    int i, found = 0;
    for (i = 0; i < 3 && found != 1; i++) {
        if (strcmp(student->InfoInterests.favorite_places[i], place) == 0) {
            found = 1;
        }
    }
    return found;
}
// Função de Print de locais apenas
int PrintPlaces(StudentsList student, PlacesList head) {
    int lines = 7;
    PlacesList current = head->next;
    printf("+------------------------------------------------------------+\n");
    printf("Locais:\n");
    while (current != NULL) {
        if (isInFavPlaces(student, current->name) != 1) {
            printf("\t-> %s\n", current->name);
            lines++;
        }
        current = current->next;
    }
    printf("+------------------------------------------------------------+\n");
    return lines;
}
// Função que é responsavel por adicionar o nome do local ao array de strings que contem os locais favoritos do utilizador
int AddPlace(StudentsList student, PlacesList head, char *place) {
    int i, answer, found = 0;

    if (isInFavPlaces(student, place) == 1) {
        alreadyFavPlace();
        ClearConsole();
    } else if (SearchPlace(head, place) != NULL) {
        for (i = 0; i < 3 && found == 0; i++) {
            if (student != NULL && strcmp(student->InfoInterests.favorite_places[i], "Not Defined") == 0) {
                student->InfoInterests.favorite_places[i] = place;
                found = 1;
                successAddPlace();
            }
        }
        if (found == 0 && student != NULL) {
            yesOrno();
            ClearBuffer();
            scanf("%d", &answer);
            ClearConsole();
            if (answer == 1) {
                printf("+------------------------------------------------------------+\n");
                printf("             > Qual dos locais pretende substiuir? <          \n");
                printf("                  1 - %s\n", student->InfoInterests.favorite_places[0]);
                printf("                  2 - %s\n", student->InfoInterests.favorite_places[1]);
                printf("                  3 - %s\n", student->InfoInterests.favorite_places[2]);
                printf("                                                              \n");
                printf("                  ____________                                \n");
                printf("+------------------------------------------------------------+\n");
                gotoxy(25,7);
                ClearBuffer();
                scanf("%d", &answer);
                ClearConsole();
                if (answer <= 2 && answer >= 1)
                    i = answer;
                student->InfoInterests.favorite_places[i - 1] = place;
            }
        }
    } else {
        noPlace();
        ClearConsole();
    }
    ClearConsole();
    return 0;
}

// Função que dá sort do vetor de strigs dos locais favoritos do utilizador deixando o local "Not Defined" no fim o array
// "Not defined" é o valor que é inicializado no array por default e que serve para marcar a posição do array como não
// contendo nenhum local
int sortFavPlacesArray(char **strings) {
    int i;
    char *temp;
    for (i = 0; i < 2; i++) {
        if (strcmp(strings[i], "Not Defined") == 0) {
            temp = malloc(sizeof(char) * strlen(strings[i + 1]));
            mallocFail(temp);
            strcpy(temp, strings[i + 1]);
            strings[i + 1] = strdup(strings[i]);
            strings[i] = strdup(temp);
        }
    }
    return 0;
}

// Função que serve para remover um local das preferencias do utlizador colocando "Not Defined" na posição respetiva
int RemovePlace(StudentsList student) {
    int i, j, key;
    do {
        ClearBuffer();
        ClearConsole();

        printf("+------------------------------------------------------------+\n");
        printf("            > Qual dos locais pretende remover? <            \n");
        for (i = 0, j = 1; i < 3; i++) {
            if (strcmp(student->InfoInterests.favorite_places[i], "Not Defined") != 0) {
                printf("                  %d - %s\n", j, student->InfoInterests.favorite_places[i]);
                j++;
            }
        }
        printf("\n                  _____________                             \n");
        printf("+------------------------------------------------------------+\n");

        gotoxy(25, 3 + j);

        if (j == 1) {
            ClearConsole();
            key = -1;
            noFav();
            ClearConsole();
        } else {
            scanf("%d", &key);

            if (key < 4 && key > 0) {
                student->InfoInterests.favorite_places[key - 1] = "Not Defined";
                ClearConsole();
                successRemovePlace();
                ClearConsole();
            } else
                printf("Opção invalida\n");
        }

    } while ((key >= 4 || key <= 0) && key != -1);

    sortFavPlacesArray(student->InfoInterests.favorite_places);
    return 0;
}
// Função que calcula a popularidade de cada local o que vai ser util para classificar a viagem
int PlacesPopularity(PlacesList places_head, StudentsList students_head) {
    int i;
    PlacesList place;
    StudentsList current_student = students_head->next;

    while (current_student != NULL) {
        for (i = 0; i < 3; i++) {
            if ((place = SearchPlace(places_head, current_student->InfoInterests.favorite_places[i])) != NULL)
                place->Popularity += 1;
        }
        current_student = current_student->next;
    }
    return 0;
}