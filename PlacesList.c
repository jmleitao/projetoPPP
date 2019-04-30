//
// Created by pedro on 29-04-2019.
//
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PlacesList.h"


int isEmptyPlaces(Places_t *head) { return head->next == NULL ? 1 : 0; }



int FindPlace(PlacesList head, PlacesList *before,
              PlacesList *current, char *key) {
    *before = head;
    *current = head->next;

    while ((*current) != NULL && !strcmp((*current)->name, key)) {
        *before = *current;
        *current = (*current)->next;
    }
    if ((*current) != NULL && !strcmp((*current)->name, key)) {
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


int DeletePlacesList(PlacesList head) {
    Places_t *current;
    while (!isEmptyPlaces(head)) {
        current = head;
        head = head->next;
        free(current);
    }
    free(head);
    return 0;
}

