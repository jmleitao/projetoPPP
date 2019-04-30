#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"


int createfile(char *name, char *extension) {
    FILE *fp;
    int len = strlen(name) + strlen(extension) + 1;
    char *file = malloc(sizeof(char) * len);

    sprintf(file, "%s%s", name, extension);

    fp = fopen(file, "w");
    fclose(fp);

    free(file);

    return 0;
}

int AppendToStudentsList(StudentsList head, StudentData_t student_data) {
    StudentsList current = head;
    StudentsList newStudent = (StudentsList) malloc(sizeof(Student_t));

    newStudent->InfoStudent = student_data;
    newStudent->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStudent;
    return 0;
}

int LoadStudentsList(StudentsList head) {
    FILE *fp;
    StudentsList new_student = (StudentsList) malloc(sizeof(StudentData_t));
    int i = 0;
    char *token = NULL, *line1 = NULL, *line2 = NULL, delimiter[2] = "|";
    size_t len;

    fp = fopen("Students.txt", "r");

    if (fp == NULL) {
        createfile("Students", ".txt");
    } else {
        getline(&line1, &len, fp);
        while ((getline(&line1, &len, fp) != EOF)) {
            line2 = malloc(sizeof(char) * strlen(line1));
            strcpy(line2, line1);
            token = strtok(line2, delimiter);
            while (token != NULL && i < 4) {
                switch (i) {
                    case 0:
                        new_student->InfoStudent.name = token;
                        break;
                    case 1:
                        new_student->InfoStudent.address = token;
                        break;
                    case 2:
                        new_student->InfoStudent.date_of_birth = token;
                        break;
                    case 3:
                        removeEnter(token);
                        new_student->InfoStudent.phone_number = token ;
                        break;
                    default:
                        printf("ERROR!");
                        break;
                }
                token = strtok(NULL, delimiter);
                i++;
            }
            AppendToStudentsList(head, new_student->InfoStudent);
            i = 0;
        }
        free(line1);
        fclose(fp);
    }
    return 0;
}

int LoadStudentsFile(StudentsList head) {
    FILE *fp;
    fp = fopen("Students.txt", "w");
    Student_t *student = head;
    if (head != NULL) {
        while (student != NULL) {

            fprintf(fp, "%s|", student->InfoStudent.name);
            fprintf(fp, "%s|", student->InfoStudent.address);
            fprintf(fp, "%s|", student->InfoStudent.date_of_birth);
            fprintf(fp, "%s\n", student->InfoStudent.phone_number);
            student = student->next;
        }
    }
    fclose(fp);
    return 0;
}


int PrintPlaces(void) {
    FILE *fp;
    char *line = malloc(sizeof(char) * 256);

    fp = fopen("Places.txt", "r");

    if (fp == NULL)
        createfile("Places", ".txt");

    while ((fgets(line, sizeof(line), fp) != NULL)) {
        printf("%s", line);
    }

    free(line);
    fclose(fp);

    return 0;
}