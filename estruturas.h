
#ifndef PROJECT_STRUCTURES_H
#define PROJECT_STRUCTURES_H


typedef struct Student *StudentsList;
typedef struct Places *PlacesList;


typedef struct StudentData {
    char name;
    char address;
    char date_of_birth;
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
    char info;
    char city;
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

