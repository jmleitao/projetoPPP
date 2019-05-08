#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"


int AddPointOfInterest(PlacesList head, PlacesList city) {
    //PointsOfInterest_t point_of_interest_data;
    PlacesList current = head;
    PlacesList newPlace = (PlacesList) malloc(sizeof(Places_t));


    if (SearchPlace(head, city->name) == NULL) {



        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPlace;

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