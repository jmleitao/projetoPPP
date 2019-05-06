#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PlacesList.h"
#include "Headers/PointsOfInterestList.h"


int isEmptyPlaces(Places_t *head) { return head->next == NULL ? 1 : 0; }

int isEmptyPointsOfInterest(PointsOfInterest_t *head) { return head->next == NULL ? 1 : 0;}


int FindPlace(PlacesList head, PlacesList *before, PlacesList *current, char *key) {
    *before = head;
    *current = head->next;

    while ((*current) != NULL && strcmp((*current)->name, key) != 0) {
        *before = *current;
        *current = (*current)->next;
    }
    if ((*current) != NULL && strcmp((*current)->name, key) != 0) {
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

int RemovePlace(PlacesList head, char *key) {
    PlacesList current;
    PlacesList before;
    FindPlace(head, &before, &current, key);
    if (current != NULL) {
        before->next = current->next;
        free(current);
    }
    return 0;
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
            AlphaSortPointsOfInterestList(&(*start)->PointOfInterest,PointsOfInterestCount((*start)->PointOfInterest));
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
    head->PlacesCount = counter;
    return counter;
}

