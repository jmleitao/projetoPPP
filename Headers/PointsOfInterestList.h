#ifndef PROJETO_POINTSOFINTERESTLIST_H
#define PROJETO_POINTSOFINTERESTLIST_H


int AddPointOfInterest(PlacesList head, PlacesList city);

int PointsOfInterestCount(PointsOfInterestList head);

PointsOfInterestList swapNodes(PointsOfInterestList NodePointer1, PointsOfInterestList NodePointer2);

PointsOfInterestList AlphaSortPointsOfInterestList(PointsOfInterestList *head, int numNodes);

#endif //PROJETO_POINTSOFINTERESTLIST_H
