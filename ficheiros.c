#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "estruturas.h"
#include "ficheiros.h"

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

int PrintPlaces(void) {
    FILE *fp;
    char *line = malloc(sizeof(char) * 256);

    fp = fopen("Places", "r");

    if (fp == NULL)
        createfile("Places", ".txt");

    while ((fgets(line, sizeof(line), fp) != NULL)) {
        printf("%s", line);
    }

    free(line);
    fclose(fp);

    return 0;
}

int LoadStudentsList(StudentsList head) {
    FILE *fp;
    fp = fopen("Students.txt", "r");
    Student_t *new_student = (Student_t *) malloc(sizeof(Student_t));
    Student_t *student = head;

    if (fp == NULL)
        createfile("Students", ".txt");

    while ((fscanf(fp, "%s", new_student->InfoStudent.name)) != EOF) {

        fscanf(fp, "%d %s %s", &(new_student->InfoStudent.phone_number), (new_student->InfoStudent.date_of_birth),
               (new_student->InfoStudent.address));

        if (head == NULL) {
            new_student->next = head;
            head = new_student;
        } else {
            while (student->next != NULL) {
                student = student->next;
            }
            student->next = new_student;
        }
    }

    free(new_student);
    fclose(fp);
    return 0;
}

int LoadStudentsFile(StudentsList head) {
    FILE *fp;
    fp = fopen("Students", "w");
    Student_t *student = head;

    if (head != NULL) {
        while (student != NULL) {

            fprintf(fp, "%s ", student->InfoStudent.name);
            fprintf(fp, "%d", student->InfoStudent.phone_number);
            fprintf(fp, " %s", student->InfoStudent.date_of_birth);
            fprintf(fp, " %s", student->InfoStudent.address);
            student = student->next;
        }
    }
    fclose(fp);
    return 0;
}