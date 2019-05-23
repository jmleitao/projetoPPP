#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"
#include "Headers/Menus.h"
#include "Headers/StudentsList.h"
#include "Headers/files.h"

/*Maior parte das funções tem coportamento semelhante ás funções presentes no ficheiro PlacesList.c*/
/*As que são diferentes foram comentadas*/

int isEmptyPointsOfInterest(PointsOfInterest_t *head) { return head->next == NULL ? 1 : 0; }

int
FindPointOfInterest(PointsOfInterestList head, PointsOfInterestList *before, PointsOfInterestList *current, char *key) {
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


PointsOfInterestList SearchPointOfInterest(PointsOfInterestList head, char *key) {
    PointsOfInterestList before;
    PointsOfInterestList current;
    FindPointOfInterest(head, &before, &current, key);
    return current;
}
// Função que verifica se o ponto de interesse do aluno é hot ou não
int FavPointOfInterest(StudentsList student, char *key) {
    int answer = 1;
    if (SearchPointOfInterest(student->InfoInterests.other_points_of_interest, key) != NULL ||
        strcmp(student->InfoInterests.hot, key) == 0)
        answer = 0;
    return answer;
}
// Função que adiciona um ponto de interesse á lista de pontos de interesse favoritos do aluno
int AddPointOfInterest(StudentsList student, PlacesList places_head, char *key) {
    PlacesList current_place = places_head->next;
    PointsOfInterestList current = student->InfoInterests.other_points_of_interest;
    PointsOfInterestList new = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t)), point_of_interest = NULL;
    mallocFail(new);
    int found = 0;

    if (strncmp(key, "\n", 1) == 0) {
        noPointOfInterest();
        ClearBuffer();
    } else {
        if (FavPointOfInterest(student, key) != 0) {

            if (strcmp(student->InfoInterests.hot, key) == 0)
                point_of_interest = SearchPointOfInterest(current_place->PointOfInterest, key);

            while (current_place != NULL && point_of_interest == NULL) {
                point_of_interest = SearchPointOfInterest(current_place->PointOfInterest, key);
                current_place = current_place->next;
            }

            if (point_of_interest != NULL) {
                new->name = point_of_interest->name;
                new->info = point_of_interest->info;
                new->WorkingHours = point_of_interest->WorkingHours;
                new->Popularity = point_of_interest->Popularity;
                new->next = NULL;

                if (current->next == NULL) {
                    current->next = new;
                    successPointOfInterest();
                    ClearConsole();
                    found = 1;
                }
                while (current->next != NULL && found != 1) {
                    if (strcmp(current->name, new->name) == 0)
                        found = 1;
                    current = current->next;
                }
                if (found != 1) {
                    current->next = new;
                    successPointOfInterest();
                    ClearConsole();
                }
            } else {
                noPointOfInterest();
                ClearConsole();
            }
        } else {
            alreadyFavPointOfInterest();
            ClearConsole();
        }

    }
    return 0;
}

PointsOfInterestList swapNodes(PointsOfInterestList NodePointer1, PointsOfInterestList NodePointer2) {
    PointsOfInterestList temporary = NodePointer2->next;
    NodePointer2->next = NodePointer1;
    NodePointer1->next = temporary;
    return NodePointer2;
}


int AlphaSortPointsOfInterestList(PointsOfInterestList *head, int numNodes) {
    head = &((*head)->next);
    PointsOfInterestList *start, node1;
    int i, j, sorted;

    for (i = 0, sorted = 1; i <= numNodes && sorted != 0; i++) {
        start = head;
        sorted = 0;
        for (j = 0; j < numNodes - 1 - i; j++) {
            node1 = *start;
            if (strcmp(node1->name, node1->next->name) > 0) {
                *start = swapNodes(node1, node1->next);
                sorted = 1;
            }
            start = &((*start)->next);
        }
    }
    return 0;
}

int PopSortPointsOfInterestList(PointsOfInterestList *head, int numNodes) {
    head = &((*head)->next);
    PointsOfInterestList *start, node1;
    int i, j, sorted;

    for (i = 0, sorted = 1; i <= numNodes && sorted != 0; i++) {
        start = head;
        sorted = 0;
        for (j = 0; j < numNodes - 1 - i; j++) {
            node1 = *start;
            if (node1->Popularity < node1->next->Popularity) {
                *start = swapNodes(node1, node1->next);
                sorted = 1;
            }
            start = &((*start)->next);
        }
    }
    return 0;
}


int PointsOfInterestCount(PointsOfInterestList head) {
    int counter = 0;
    PointsOfInterestList current = head->next;
    while (current != NULL) {
        current = current->next;
        counter++;
    }
    return counter;
}

// Função que marca um dos pontos de interesse favoritos do aluno como sendo Hot
int AddHotPointOfInterest(PlacesList places_head, StudentsList student, char *key) {
    int found = 0;
    PointsOfInterestList head = student->InfoInterests.other_points_of_interest;
    PointsOfInterestList current;
    PointsOfInterestList before;
    PlacesList current_head = places_head->next;

    while (current_head != NULL && found != 1) {
        if (SearchPointOfInterest(current_head->PointOfInterest, key) != NULL) {
            found = 1;
        }
        current_head = current_head->next;
    }
    if (strncmp(student->InfoInterests.hot, "Not Defined", 11) != 0) {
        if (found == 1) {
            ClearConsole();
            removeFirst();
            ClearConsole();
        } else {
            noPointOfInterest();
            ClearConsole();
        }
    } else {
        if (strcmp(student->InfoInterests.hot, key) != 0 &&
            (SearchPointOfInterest(student->InfoInterests.other_points_of_interest, key) == NULL) && found == 1) {
            student->InfoInterests.hot = strdup(key);
            successPointOfInterestHot();
            ClearConsole();
        } else if (SearchPointOfInterest(student->InfoInterests.other_points_of_interest, key) != NULL && found == 1) {
            FindPointOfInterest(head, &before, &current, key);
            if (current != NULL) {
                before->next = current->next;
                free(current);
                ClearConsole();
            }
            student->InfoInterests.hot = strdup(key);
            successPointOfInterestHot();
            ClearConsole();
        } else {
            if (found == 1) {
                alreadyFavPointOfInterest();
                ClearConsole();
            } else {
                noPointOfInterest();
                ClearConsole();
            }
        }
    }
    return 0;
}

// Função encarregue de desmarcar o ponto de interesse hot do aluno e de adicionar de novo esse ponto á lista de pontos
// de interesse favoritos
int RemoveHotPointOfInterest(PlacesList places_head, StudentsList student) {
    int found = 0;
    PointsOfInterestList new = NULL, point_of_interest_head = student->InfoInterests.other_points_of_interest;
    PlacesList head = places_head->next;

    while (head != NULL && found != 1) {
        if ((new = SearchPointOfInterest(head->PointOfInterest, student->InfoInterests.hot)) != NULL)
            found = 1;
        head = head->next;
    }
    while (point_of_interest_head->next != NULL) {
        point_of_interest_head = point_of_interest_head->next;
    }
    if (new != NULL) {
        AppendToPointsOfInterestList(point_of_interest_head, new);
        student->InfoInterests.hot = "Not Defined";
        successUncheckedPointOfInterest();
        ClearConsole();
    }
    return 0;
}

int RemovePointOfInterest(StudentsList student, char *key) {
    PointsOfInterestList head = student->InfoInterests.other_points_of_interest;
    PointsOfInterestList current;
    PointsOfInterestList before;

    if (strcmp(student->InfoInterests.hot, key) == 0) {
        student->InfoInterests.hot = "Not Defined";
        successremovePointOfInterest();
        ClearConsole();
    } else {
        FindPointOfInterest(head, &before, &current, key);
        if (current != NULL) {
            before->next = current->next;
            free(current);
            successremovePointOfInterest();
            ClearConsole();
        } else {
            notFavPointOfInterest();
            ClearConsole();
        }
    }
    return 0;
}
// Função que da print dos pontos de interesse do aluno mas não mostra os que ele já tem marcados como favoritos
int PrintandCheckPointsOfInterestList(StudentsList student, PlacesList head) {
    int i;
    PlacesList current_place = head->next;
    PointsOfInterestList current_point_of_interest;
    printf("+---------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t\tPontos de Interesse\n");
    printf("+---------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------+\n");
    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        while (current_point_of_interest != NULL) {
            if (SearchPointOfInterest(student->InfoInterests.other_points_of_interest,
                                      current_point_of_interest->name) == NULL && strcmp(student->InfoInterests.hot,
                                                                                         current_point_of_interest->name) !=
                                                                                  0) {
                printf("\t »» %s\n", current_point_of_interest->name);
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
            }

            current_point_of_interest = current_point_of_interest->next;
        }
        current_place = current_place->next;
    }
    printf("+---------------------------------"
           "----------------------------------"
           "----------------------------------"
           "----------------------------------"
           "-----------------------------+\n");
    return 0;
}

int PrintStudentPointsOfInterest(StudentsList student, int option) {
    int line = 5;
    PointsOfInterestList current = student->InfoInterests.other_points_of_interest->next;
    printf("+------------------------------------------------------------+\n");
    printf("                 Pontos de Interesse do Aluno\n\n");
    if (strcmp(student->InfoInterests.hot, "Not Defined") != 0 && option != 1) {
        printf("\t»» %s\n", student->InfoInterests.hot);
        line += 1;
    }
    while (current != NULL) {
        printf("\t»» %s\n", current->name);
        current = current->next;
        line += 1;
    }
    printf("+------------------------------------------------------------+\n");
    return line;
}

int PointsOfInterestPopularity(PlacesList head, StudentsList students_head) {
    int found;
    PlacesList places_head;
    PointsOfInterestList student_interests, point_of_interest, points_of_interest_list_head;
    StudentsList current_student = students_head->next;

    while (current_student != NULL) {
        student_interests = current_student->InfoInterests.other_points_of_interest->next;
        while (student_interests != NULL) {
            found = 0;
            places_head = head->next;
            while (places_head != NULL && found != 1) {
                points_of_interest_list_head = places_head->PointOfInterest;
                if ((point_of_interest = SearchPointOfInterest(points_of_interest_list_head,
                                                               student_interests->name)) != NULL) {
                    point_of_interest->Popularity += 1;
                    found = 1;
                }
                places_head = places_head->next;
            }
            student_interests = student_interests->next;
        }
        current_student = current_student->next;
    }
    return 0;
}

// Função que calcula a popularidade do ponto de interesse hot de cada um dos alunos
int HotPointOfInterestPopularity(PlacesList head, StudentsList students_head) {
    int found;
    char *student_interest;
    PlacesList places_head;
    StudentsList current_student = students_head->next;
    PointsOfInterestList point_of_interest, points_of_interest_list_head;
    while (current_student != NULL) {
        found = 0;
        places_head = head->next;
        student_interest = current_student->InfoInterests.hot;
        while (places_head != NULL) {
            points_of_interest_list_head = places_head->PointOfInterest;
            if ((point_of_interest = SearchPointOfInterest(points_of_interest_list_head, student_interest)) != NULL) {
                point_of_interest->Popularity += 1;
                found = 1;
            }
            if (found == 1)
                places_head = NULL;
            else
                places_head = places_head->next;
        }
        current_student = current_student->next;
    }
    return 0;
}

