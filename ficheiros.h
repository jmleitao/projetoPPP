#ifndef PROJECT_FILES_H
#define PROJECT_FILES_H

int createfile(char *name, char *extension);

int PrintPlaces();

int LoadStudentsList(StudentsList node);

int LoadStudentsFile(StudentsList node);

int AppendToStudentsList(StudentsList head, StudentData_t student);

#endif //PROJECT_FILES_H
