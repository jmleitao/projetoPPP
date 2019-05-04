#ifndef PROJECT_FILES_H
#define PROJECT_FILES_H

int createfile(char *name, char *extension);

int PrintPlaces();

int LoadStudentsList(StudentsList node);

int LoadPlacesList(PlacesList head);

int LoadStudentsFile(StudentsList node);

int AppendToStudentsList(StudentsList head, StudentData_t student_data, Student_Interests_t student_interests);

int LoadPlacesFile(PlacesList head);

#endif //PROJECT_FILES_H
