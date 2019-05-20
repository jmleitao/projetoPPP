#ifndef PROJETO_POINTSOFINTERESTLIST_H
#define PROJETO_POINTSOFINTERESTLIST_H

int PointsOfInterestCount(PointsOfInterestList head);

int isEmptyPointsOfInterest(PointsOfInterest_t *head);

int
FindPointOfInterest(PointsOfInterestList head, PointsOfInterestList *before, PointsOfInterestList *current, char *key);

int AddPointOfInterest(StudentsList student, PlacesList places_head, char *key);

int RemovePointOfInterest(StudentsList student, char *key);

int PrintStudentPointsOfInterest(StudentsList student,int option);

int PointsOfInterestPopularity(PlacesList head, StudentsList students_head);

int HotPointOfInterestPopularity(PlacesList head, StudentsList students_head);

int PrintandCheckPointsOfInterestList(StudentsList student, PlacesList head);

int RemoveHotPointOfInterest(StudentsList student);

int AddHotPointOfInterest(PlacesList head,StudentsList student, char *key);

int AlphaSortPointsOfInterestList(PointsOfInterestList *head, int numNodes);

int PopSortPointsOfInterestList(PointsOfInterestList *head, int numNodes);

PointsOfInterestList SearchPointOfInterest(PointsOfInterestList head, char *key);

PointsOfInterestList swapNodes(PointsOfInterestList NodePointer1, PointsOfInterestList NodePointer2);

#endif //PROJETO_POINTSOFINTERESTLIST_H
