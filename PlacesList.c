#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PlacesList.h"


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

