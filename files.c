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

int AppendToStudentsList(StudentsList head, StudentData_t student_data, Student_Interests_t student_interests) {
    StudentsList current = head;
    StudentsList newStudent = (StudentsList) malloc(sizeof(Student_t));

    newStudent->InfoStudent = student_data;
    newStudent->InfoInterests = student_interests;
    newStudent->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStudent;
    return 0;
}

int LoadStudentsList(StudentsList head) {
    FILE *fp;
    StudentsList new_student = (StudentsList) malloc(sizeof(Student_t));
    new_student->next = NULL;
    char *token = NULL, *line1 = NULL, *line2 = NULL, *line3 = NULL;
    char delimiter[1] = "|", delimiter2[1] = "@", delimiter3[1] = "-";
    size_t len;
    int i = 0;

    fp = fopen("Students.txt", "r");

    if (fp == NULL) {
        printf("Não existe ficheiro de dados no disco!\n");
        printf("\tEste foi criado!");
        createfile("Students", ".txt");
    } else {
        while ((getline(&line1, &len, fp) != EOF)) {
            line2 = malloc(sizeof(char) * len);
            strcpy(line2, line1);
            token = strtok(line2, delimiter);
            while (token != NULL && i < 4) {
                switch (i) {
                    case 0:
                        new_student->InfoStudent.name = strdup(token);
                        break;
                    case 1:
                        new_student->InfoStudent.address = strdup(token);
                        break;
                    case 2:
                        new_student->InfoStudent.date_of_birth = strdup(token);
                        break;
                    case 3:
                        removeEnter(token);
                        new_student->InfoStudent.phone_number = strdup(token);
                        break;
                    default:
                        printf("ERROR!");
                        break;
                }
                token = strtok(NULL, delimiter);
                i++;
            }
            getline(&line1, &len, fp);
            line3 = malloc(sizeof(char) * len);
            strcpy(line3, line1);
            i = 0;
            while (line3[0] != delimiter3[0]) {
                getline(&line1, &len, fp);
                line3 = malloc(sizeof(char) * len);
                strcpy(line3, line1);
                removeEnter(line3);
                new_student->InfoInterests.favorite_places[i] = strdup(line3);
                i++;
            }
            i = 0;
            while (line3[0] != delimiter2[0]) {
                getline(&line1, &len, fp);
                line3 = malloc(sizeof(char) * len);
                strcpy(line3, line1);
                if (i == 0 && line3[0] != delimiter2[0]) {
                    removeEnter(line3);
                    new_student->InfoInterests.hot = strdup(line3);
                } else if (i != 0 && line3[0] != delimiter2[0]) {
                    removeEnter(line3);
                    new_student->InfoInterests.other_points_of_interest[i - 1] = strdup(line3);
                }
                i++;
            }
            getline(&line1, &len, fp);
            new_student->InfoInterests.num_points = i - 2;
            AppendToStudentsList(head, new_student->InfoStudent, new_student->InfoInterests);
            i = 0;
        }
    }
    free(line1);
    free(line2);
    free(line3);
    fclose(fp);
    return 0;
}

int LoadStudentsFile(StudentsList head) {
    FILE *fp;
    int i;
    head = head->next;
    Student_t *student = head;

    fp = fopen("Students.txt", "w");

    if (head != NULL) {
        while (student != NULL) {

            fprintf(fp, "%s|", student->InfoStudent.name);
            fprintf(fp, "%s|", student->InfoStudent.address);
            fprintf(fp, "%s|", student->InfoStudent.date_of_birth);
            fprintf(fp, "%s\n", student->InfoStudent.phone_number);
            fprintf(fp, "@\n");
            for (i = 0; i < 3; i++) {
                fprintf(fp, "%s\n", student->InfoInterests.favorite_places[i]);
            }
            fprintf(fp, "-\n");
            fprintf(fp, "%s\n", student->InfoInterests.hot);
            for (i = 0; i < 15 && i < student->InfoInterests.num_points; i++) {
                fprintf(fp, "%s\n", student->InfoInterests.other_points_of_interest[i]);
            }
            fprintf(fp, "@\n\n"); //sndkadkandkadnsad /n
            student = student->next;
        }
    }
    fclose(fp);
    return 0;
}

int LoadPlacesList(PlacesList head) {
    FILE *fp;
    int i = 0;
    PlacesList new_place = (PlacesList) malloc(sizeof(Places_t));
    PointsOfInterestList new_point_of_interest;
    char *line1 = NULL, *line2 = NULL, *info = NULL;
    size_t len;

    fp = fopen("Places.txt", "r");

    if (fp == NULL) {
        printf("Não existe ficheiro de dados no disco!\n");
        printf("\tEste foi criado!");
        createfile("Places", ".txt");
    } else {
        while (getline(&line1, &len, fp) != EOF) {
            line2 = malloc(sizeof(char) * len);
            strncpy(line2, line1 + 2, len - 2);
            removeEnter(line2);
            new_place->name = line2;
            getline(&line1, &len, fp);
            while (line1[0] != '>') {
                if (i == 0) {
                    strncpy(line2, line1 + 2, len - 2);
                    removeEnter(line2);
                    new_point_of_interest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
                    new_point_of_interest->name = line2;
                } else {
                    info = calloc(sizeof(char)*len,0);
                    while (line1[0] != '@') {
                        getline(&line1, &len, fp);
                        strcpy(line2, line1);
                        if (strlen(info) < strlen(info)+strlen(line2)) {
                            info = realloc(info,2*len);
                        } strcat(info, line2);
                    }
                }
                i++;
                getline(&line1, &len, fp);
            }

        }
    }
    return 0;
}

int PrintPlaces(void) {
    FILE *fp;
    char *line = malloc(sizeof(char) * 256);

    fp = fopen("Places.txt", "r");

    if (fp == NULL) {
        printf("Não existe ficheiro de dados no disco!\n");
        printf("\tEste foi criado!");
        createfile("Places", ".txt");
    }
    while ((fgets(line, sizeof(line), fp) != NULL)) {
        printf("%s", line);
    }

    free(line);
    fclose(fp);

    return 0;
}
