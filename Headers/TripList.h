#ifndef PROJETO_TRIPLIST_H
#define PROJETO_TRIPLIST_H

int BuildTrip(TripList trip_head, PlacesList places_head, StudentsList students_head);

double EvaluateTrip(TripList trips_head, StudentsList students_head,PlacesList places_head);

int ResetPopularity(PlacesList head);
#endif //PROJETO_TRIPLIST_H
