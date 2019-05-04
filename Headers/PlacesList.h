#ifndef PROJETO_PLACESLIST_H

int isEmptyPlaces(PlacesList head);

int FindPlace(PlacesList head, PlacesList *before,
              PlacesList *current, char *key);

int RemovePlace(PlacesList head, char *key);

PlacesList SearchPlace(PlacesList head, char *key);

int DeletePlacesList(PlacesList head);

int PrintPlacesList(PlacesList head);

int DeletePointsOfInterestList(PointsOfInterestList head);

#define PROJETO_PLACESLIST_H

#endif //PROJETO_PLACESLIST_H
