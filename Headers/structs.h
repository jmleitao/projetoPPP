#ifndef PROJECT_STRUCTURES_H
#define PROJECT_STRUCTURES_H

#define NUM_PLACES 3


typedef struct Student *StudentsList;
typedef struct Places *PlacesList;
typedef struct PointsOfInterest *PointsOfInterestList;

typedef struct StudentData {
    char *name;
    char *address;
    char *date_of_birth;
    char *phone_number;
} StudentData_t;

typedef struct StudentInterests {
    char *hot;
    char *favorite_places[NUM_PLACES];
    PointsOfInterestList other_points_of_interest;
} Student_Interests_t;


typedef struct Student {
    struct StudentData InfoStudent;
    struct StudentInterests InfoInterests;
    StudentsList next;
    int StudentCount;
} Student_t;


typedef struct PointsOfInterest {
    char *name;
    char *info;
    char *WorkingHours;
    int PointOfInterestCount;
    PointsOfInterestList next;
} PointsOfInterest_t;


typedef struct Places {
    char *name;
    PointsOfInterestList PointOfInterest;
    PlacesList next;
    int PlacesCount;
} Places_t;


StudentsList BuildStudentsList(void);

PlacesList BuildPlacesList(void);

PointsOfInterestList BuildPointsOfInterestList(void);

#endif //PROJECT_STRUCTURES_H

