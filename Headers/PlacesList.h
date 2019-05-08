#ifndef PROJETO_PLACESLIST_H

int isEmptyPlaces(PlacesList head);

int FindPlace(PlacesList head, PlacesList *before,
              PlacesList *current, char *key);

int RemovePlace(PlacesList head, char *key);

PlacesList SearchPlace(PlacesList head, char *key);

int DeletePlacesList(PlacesList head);

int PrintPlacesList(PlacesList head);

int PlacesCount(PlacesList head);

int DeletePointsOfInterestList(PointsOfInterestList head);

int DisplayPlacesAndPointsOfInterest(PlacesList head);

int AddPlace(StudentsList student, char *place);

PlacesList swapPlacesListNodes(PlacesList NodePointer1, PlacesList NodePointer2);

PlacesList AlphaSortPlacesAndPointsOfInterest(PlacesList *head, int numNodes);

#define PROJETO_PLACESLIST_H

#endif //PROJETO_PLACESLIST_H
