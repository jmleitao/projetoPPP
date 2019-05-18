#ifndef PROJETO_PLACESLIST_H

int isEmptyPlaces(PlacesList head);

int FindPlace(PlacesList head, PlacesList *before,
              PlacesList *current, char *key);

PlacesList SearchPlace(PlacesList head, char *key);

int DeletePlacesList(PlacesList head);

int PrintPlacesList(PlacesList head);

int PlacesCount(PlacesList head);

int DeletePointsOfInterestList(PointsOfInterestList head);

int DisplayPlacesAndPointsOfInterest(PlacesList head);

int DisplayPlacesAndPointsOfInterestWithPopularity(PlacesList head);

int AddPlace(StudentsList student, PlacesList head, char *place);

int RemovePlace(StudentsList student);

int PrintPlaces(StudentsList student, PlacesList head);

int PlacesPopularity(PlacesList places_head, StudentsList student);

int isInFavPlaces(StudentsList student, char *place);

int PopSortPlacesAndPointsOfInterest(PlacesList *head, int numNodes);

PlacesList swapPlacesListNodes(PlacesList NodePointer1, PlacesList NodePointer2);

int AlphaSortPlacesAndPointsOfInterest(PlacesList *head, int numNodes);

void successAddPlace(void);

void justPause(void);

#define PROJETO_PLACESLIST_H

#endif //PROJETO_PLACESLIST_H
