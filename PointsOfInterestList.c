#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"
#include "Headers/Menus.h"


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

int FavPointOfInterest(StudentsList student, char *key) {
    int answer = 1;
    if (SearchPointOfInterest(student->InfoInterests.other_points_of_interest, key) != NULL ||
        strcmp(student->InfoInterests.hot, key) == 0)
        answer = 0;
    return answer;
}

int AddPointOfInterest(StudentsList student, PlacesList places_head, char *key) {
    PlacesList current_place = places_head->next;
    PointsOfInterestList current = student->InfoInterests.other_points_of_interest->next;
    PointsOfInterestList point_of_interest = NULL;
    int found = 0;

    if (strncmp(key, "\n", 1) != 0) {
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
                point_of_interest->next = NULL;

                while (current->next != NULL && found != 1) {
                    if (strcmp(current->name, point_of_interest->name) == 0)
                        found = 1;
                    current = current->next;
                }
                if (found != 1) {
                    current->next = point_of_interest;
                    successPointOfInterest();
                    ClearConsole();
                }
            } else {
                noPointOfInterest();
                ClearConsole();
            }
        } else {
            alreadyFavPointOfInterest();
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


PointsOfInterestList AlphaSortPointsOfInterestList(PointsOfInterestList *head, int numNodes) {
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

int PointsOfInterestCount(PointsOfInterestList head) {
    int counter = 0;
    PointsOfInterestList current = head->next;
    while (current != NULL) {
        current = current->next;
        counter++;
    }
    return counter;
}

int RemovePointOfInterest(StudentsList student, char *key) {
    PointsOfInterestList head = student->InfoInterests.other_points_of_interest->next;
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
        } else {
            notFavPointOfInterest();
            ClearConsole();
        }
    }
    return 0;
}

int PrintandCheckPointsOfInterestList(StudentsList student, PlacesList head) {
    PlacesList current_place = head->next;
    PointsOfInterestList current_point_of_interest;
    printf("+------------------------------------------------------------+\n");
    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        while (current_point_of_interest != NULL) {
            if (SearchPointOfInterest(student->InfoInterests.other_points_of_interest,
                                      current_point_of_interest->name) == NULL) {
                printf("\t »» %s\n", current_point_of_interest->name);
            }

            current_point_of_interest = current_point_of_interest->next;
        }
        current_place = current_place->next;
    }
    printf("+------------------------------------------------------------+\n");
    return 0;
}

int PrintStudentPointsOfInterest(StudentsList student) {
    PointsOfInterestList current = student->InfoInterests.other_points_of_interest->next;
    printf("+------------------------------------------------------------+\n");
    while (current != NULL) {
        printf(" »» %s\n", current->name);
        current = current->next;
    }
    printf("+------------------------------------------------------------+\n");
    return 0;
}
