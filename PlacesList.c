#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PlacesList.h"
#include "Headers/PointsOfInterestList.h"


void yesOrno(void) {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t| Locais favoritos totalmente preenchidos deseja substituir  |\n");
    printf("\t\t\t\t\t\t\t\t\t|        algum dos locais anteriores para colocar este?      |\n");
    printf("\t\t\t\t\t\t\t\t\t|                                                            |\n");
    printf("\t\t\t\t\t\t\t\t\t|            0 - Sim                  1 - Não                |\n");
    printf("\t\t\t\t\t\t\t\t\t|                        =========                           |\n");
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
}


int isEmptyPlaces(Places_t *head) { return head->next == NULL ? 1 : 0; }


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


PlacesList SearchPlace(PlacesList head, char *key) {
    PlacesList before;
    PlacesList current;
    FindPlace(head, &before, &current,
              key);
    return current;
}


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

int DeletePlacesList(PlacesList head) {
    PlacesList current;
    while (!isEmptyPlaces(head)) {
        current = head;
        head = head->next;
        free(current);
    }
    free(head);
    return 0;
}

int PrintPlacesList(PlacesList head) {
    PlacesList current = head->next;
    while (current != NULL) {
        printf("--------------------\n");
        printf("Nome do Local: %s\n", current->name);
        current = current->next;
    }
    return 0;
}

PlacesList swapPlacesListNodes(PlacesList NodePointer1, PlacesList NodePointer2) {
    PlacesList temporary = NodePointer2->next;
    NodePointer2->next = NodePointer1;
    NodePointer1->next = temporary;
    return NodePointer2;
}


PlacesList AlphaSortPlacesAndPointsOfInterest(PlacesList *head, int numNodes) {
    head = &(*head)->next;
    PlacesList *start, node1;
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
            AlphaSortPointsOfInterestList(&(*start)->PointOfInterest, PointsOfInterestCount((*start)->PointOfInterest));
            start = &((*start)->next);
        }
    }
    return 0;
}


int PlacesCount(PlacesList head) {
    int counter = 0;
    PlacesList current = head->next;
    while (current != NULL) {
        current = current->next;
        counter++;
    }
    return counter;
}

int DisplayPlacesAndPointsOfInterest(PlacesList head) {
    PlacesList current_place = head->next;
    PointsOfInterestList current_point_of_interest;

    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t                 Locais e Pontos de Interesse\n\n");

    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        printf("\t\t\t\t\t\t\t\t\t   %s: \n", current_place->name);
        while (current_point_of_interest != NULL) {
            printf("\t\t\t\t\t\t\t\t\t\t\t   -> %s \n", current_point_of_interest->name);
            current_point_of_interest = current_point_of_interest->next;
        }
        printf("\n");
        current_place = current_place->next;
    }
    printf("\n\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    return 0;
}

int AddPlace(StudentsList student, PlacesList head, char *place) {
    int i, answer, found = 0;
    if (SearchPlace(head, place) != NULL) {
        for (i = 0; i < 3 && found == 0; i++) {
            if (student != NULL && strcmp(student->InfoInterests.favorite_places[i], "Not Defined") == 0) {
                student->InfoInterests.favorite_places[i] = place;
                found = 1;
            }
        }
        if (found == 0 && student != NULL) {
            yesOrno();
            ClearBuffer();
            scanf("%d", &answer);
            if (answer == 0) {
                printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
                printf("\t\t\t\t\t\t\t\t\t             > Qual dos locais pretende substiuir? <          \n");
                printf("\t\t\t\t\t\t\t\t\t                  1 - %s\n", student->InfoInterests.favorite_places[0]);
                printf("\t\t\t\t\t\t\t\t\t                  2 - %s\n", student->InfoInterests.favorite_places[1]);
                printf("\t\t\t\t\t\t\t\t\t                  3 - %s\n", student->InfoInterests.favorite_places[2]);
                printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
                scanf("%d", &answer);
                if (answer <= 2 && answer >= 1)
                    i = answer;
                student->InfoInterests.favorite_places[i - 1] = place;
            }
        }
    } else {
        printf("\t\t\t\t\t\t\t\t\t\t\t Este local não se encontra na lista de locais disponiveis\n");
    }
    return 0;
}


int sortFavPlacesArray(char **strings) {
    int i;
    char *temp;
    for (i = 0; i < 2; i++) {
        if (strcmp(strings[i], "Not Defined") == 0) {
            temp = malloc(sizeof(char) * strlen(strings[i + 1]));
            strcpy(temp, strings[i + 1]);
            strings[i + 1] = strdup(strings[i]);
            strings[i] = strdup(temp);
        }
    }
    return 0;
}

int RemovePlace(StudentsList student) {
    int i, j, key;
    do {
        ClearBuffer();
        ClearConsole();

        printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
        printf("\t\t\t\t\t\t\t\t\t             > Qual dos locais pretende remover? <            \n");
        for (i = 0, j = 1; i < 3; i++) {
            if (strcmp(student->InfoInterests.favorite_places[i], "Not Defined") != 0) {
                printf("\t\t\t\t\t\t\t\t\t                 %d - %s\n", j, student->InfoInterests.favorite_places[i]);
                j++;
            }
        }
        printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");

        if (j == 1) {
            key = -1;
            printf("\t\t\t\t\t\t\t\t\t\t\t O aluno ainda não tem locais favoritos definidos\n");
        } else {
            scanf("%d", &key);

            if (key < 4 && key > 0) {
                student->InfoInterests.favorite_places[key - 1] = "Not Defined";
                printf("\t\t\t\t\t\t\t\t\t\t\t Local removido com sucesso!!\n");
            } else
                printf("\t\t\t\t\t\t\t\t\t\t\t Opção invalida\n");
        }

    } while ((key >= 4 || key <= 0) && key != -1);

    sortFavPlacesArray(student->InfoInterests.favorite_places);
    return 0;
}