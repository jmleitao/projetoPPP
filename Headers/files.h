#ifndef PROJECT_FILES_H
#define PROJECT_FILES_H

int createfile(char *name, char *extension);

int LoadStudentsList(StudentsList node);

int LoadPlacesList(PlacesList head);

int LoadStudentsFile(StudentsList node);

int AppendToStudentsList(StudentsList head, StudentData_t student_data, Student_Interests_t student_interests);

int AppendToPointsOfInterestList(PointsOfInterestList head, PointsOfInterestList point_of_interest_data);

#endif //PROJECT_FILES_H
