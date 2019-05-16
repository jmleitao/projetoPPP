#ifndef PROJETO_POINTSOFINTERESTLIST_H
#define PROJETO_POINTSOFINTERESTLIST_H

int PointsOfInterestCount(PointsOfInterestList head);

int isEmptyPointsOfInterest(PointsOfInterest_t *head);

int
FindPointOfInterest(PointsOfInterestList head, PointsOfInterestList *before, PointsOfInterestList *current, char *key);

int AddPointOfInterest(StudentsList student, PlacesList places_head, char *key);

int RemovePointOfInterest(StudentsList student, char *key);

int PrintStudentPointsOfInterest(StudentsList student);

int PrintandCheckPointsOfInterestList(StudentsList student, PlacesList head);

PointsOfInterestList SearchPointOfInterest(PointsOfInterestList head, char *key);

PointsOfInterestList swapNodes(PointsOfInterestList NodePointer1, PointsOfInterestList NodePointer2);

PointsOfInterestList AlphaSortPointsOfInterestList(PointsOfInterestList *head, int numNodes);


#endif //PROJETO_POINTSOFINTERESTLIST_H
