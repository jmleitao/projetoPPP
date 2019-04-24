
#ifndef PROJECT_STRUCTURES_H
#define PROJECT_STRUCTURES_H

#define SIZE 50

typedef struct Student *StudentsList;
typedef struct Places *PlacesList;


typedef struct StudentData {
    char name[SIZE];
    char address[SIZE];
    char date_of_birth[SIZE];
    int phone_number;
} StudentData_t;


typedef struct Student {
    struct StudentData InfoStudent;
    struct Student *next;
} Student_t;


typedef struct Hour {
    int start_hour;
    int end_hour;
    int start_minute;
    int end_minute;
} Hour_t;


typedef struct PlacesData {
    struct Hour WorkingHours;
    char info[SIZE];
    char city[SIZE];
} PlacesData_t;


typedef struct Places {
    struct PlacesData InfoPlace;
    struct Places *next;
} Places_t;

typedef struct Date {
    int day;
    int month;
    int year;
} Date_t;


StudentsList BuildStudentsList();

PlacesList BuildPlacesList();

#endif //PROJECT_STRUCTURES_H

