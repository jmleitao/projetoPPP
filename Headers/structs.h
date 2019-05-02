#ifndef PROJECT_STRUCTURES_H
#define PROJECT_STRUCTURES_H

#define NUM_POINTS_OF_INTEREST 50


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
    char *other_points_of_interest[NUM_POINTS_OF_INTEREST];
    char *favorite_places[3];
    int num_points;
} Student_Interests_t;


typedef struct Student {
    struct StudentData InfoStudent;
    struct StudentInterests InfoInterests;
    struct Student *next;
    int StudentCount;
} Student_t;

typedef struct Hour {
    char *OpeningHour;
    char *ClosingHour;
} Hour_t;

typedef struct PointsOfInterest {
    char *name;
    char *info;
    struct Hour WorkingHours;
    struct PointsOfInterest *next;
} PointsOfInterest_t;


typedef struct Places {
    char *name;
    PointsOfInterestList PointOfInterest;
    PlacesList next;
} Places_t;


StudentsList BuildStudentsList(void);

PlacesList BuildPlacesList(void);

PointsOfInterestList BuildPointsOfInterestList(void);

#endif //PROJECT_STRUCTURES_H

