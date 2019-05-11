#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"

// Ficheiros dos alunos e locais estão na pasta cmake-build-debug
// Se for necessário alterar estes paths é só ir copiar os paths do desses ficheiros e dar paste aqui
// Caso contrario o programa encarrega-se de criar estes ficheiros automaticamente e deixa-os vazios
// No caso do ficheiro dos alunos não existe grande problema mas no caso dos locais iremos ter um ficheiro sem locais
// Para ir recuperar a informação dos locais deixei um backup destes na pasta Info que vem com o projeto
// É so ir la dar copy paste da informação

#define STUDENTSPATH "Students.txt"
#define PLACESPATH "Places.txt"


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

int AppendToPointsOfInterestList(PointsOfInterestList head, PointsOfInterestList point_of_interest_data) {
    PointsOfInterestList current = head;
    PointsOfInterestList newPointOfInterest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));

    newPointOfInterest->name = point_of_interest_data->name;
    newPointOfInterest->WorkingHours = point_of_interest_data->WorkingHours;
    newPointOfInterest->info = point_of_interest_data->info;

    newPointOfInterest->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPointOfInterest;
    return 0;
}

int AppendToPlacesList(PlacesList places_head, PointsOfInterestList points_of_interest_head, PlacesList place_data) {
    PlacesList current = places_head;
    PlacesList newPlace = (PlacesList) malloc(sizeof(Places_t));

    newPlace->name = place_data->name;
    newPlace->PointOfInterest = points_of_interest_head;
    newPlace->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPlace;
    return 0;
}

int LoadStudentsList(StudentsList head) {
    FILE *fp;
    PointsOfInterestList points_of_interest_head;
    StudentsList new_student = (StudentsList) malloc(sizeof(Student_t));
    PointsOfInterestList points_of_interest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
    char *token = NULL, *line1 = NULL, *line2 = NULL, *line3 = NULL;
    char delimiter[1] = "|", delimiter2[1] = "@", delimiter3[1] = "-";
    size_t len;
    int i = 0;
    new_student->next = NULL;
    points_of_interest->next = NULL;
    points_of_interest->info = NULL;

    fp = fopen(STUDENTSPATH, "r");

    if (fp == NULL) {
        printf("Não existe ficheiro de dados no disco!\n");
        printf("Este foi criado!\n");
        createfile("Students", ".txt");
    } else {
        while ((getline(&line1, &len, fp) != EOF)) {
            points_of_interest_head = BuildPointsOfInterestList();
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
                    points_of_interest->name = strdup(line3);
                    AppendToPointsOfInterestList(points_of_interest_head, points_of_interest);
                }
                i++;
            }
            getline(&line1, &len, fp);
            new_student->InfoInterests.other_points_of_interest = points_of_interest_head;
            AppendToStudentsList(head, new_student->InfoStudent, new_student->InfoInterests);
            i = 0;
        }
        fclose(fp);
    }
    free(line1);
    free(line2);
    free(line3);
    return 0;
}

int LoadStudentsFile(StudentsList head) {
    FILE *fp;
    int i;
    head = head->next;
    Student_t *student = head;


    fp = fopen(STUDENTSPATH, "w");

    if (head != NULL) {
        while (student != NULL) {
            PointsOfInterestList points_of_interest = student->InfoInterests.other_points_of_interest->next;

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
            while (points_of_interest != NULL) {
                fprintf(fp, "%s\n", points_of_interest->name);
                points_of_interest = points_of_interest->next;
            }
            fprintf(fp, "@\n\n");
            student = student->next;
        }
    }
    fclose(fp);
    return 0;
}

int LoadPlacesList(PlacesList head) {
    FILE *fp;
    int i = 0, j;

    PointsOfInterestList point_of_interest_head;

    PlacesList new_place = (PlacesList) malloc(sizeof(Places_t));
    new_place->next = NULL;
    new_place->PointOfInterest = NULL;

    PointsOfInterestList new_point_of_interest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
    new_point_of_interest->next = NULL;

    char *line1 = NULL, *line2 = NULL, *token = NULL;
    char delimiter1[1] = "-", delimiter2[1] = "|", delimiter3[1] = ">", *info = NULL;
    size_t len;

    fp = fopen(PLACESPATH, "r");

    if (fp == NULL) {
        printf("Não existe ficheiro de dados no disco!\n");
        printf("Este foi criado!\n");
        createfile("Places", ".txt");
    } else {
        while (getline(&line1, &len, fp) != EOF) {
            point_of_interest_head = BuildPointsOfInterestList();
            point_of_interest_head->next = NULL;

            line2 = malloc(sizeof(char) * len);
            strncpy(line2, line1 + 1, len - 1);
            removeEnter(line2);
            strip(&line2);
            new_place->name = strdup(line2);
            getline(&line1, &len, fp);
            getline(&line1, &len, fp);


            while (line2[0] != delimiter3[0]) {
                info = malloc(sizeof(char) * len * 10);
                memset(info, 0, len * 10);

                while (line1[0] != delimiter1[0] && line1[0] != delimiter3[0]) {
                    if (i == 0) {
                        line2 = malloc(sizeof(char) * len);
                        strncpy(line2, line1 + 2, len - 2);
                        removeEnter(line2);
                        token = strtok(line2, delimiter2);
                        j = 0;
                        while (token != NULL) {
                            if (j == 0)
                                new_point_of_interest->name = strdup(token);
                            else
                                new_point_of_interest->WorkingHours = strdup(token);
                            token = strtok(NULL, delimiter2);
                            j++;
                        }
                    } else {
                        if (line1[0] != delimiter1[0] && line1[0] != delimiter3[0]) {
                            getline(&line1, &len, fp);
                            line2 = strdup(line1);
                            strcat(info, line2);
                        }
                    }
                    i++;
                }
                i = 0;
                new_point_of_interest->info = strndup(info, strlen(info) - 2);
                AppendToPointsOfInterestList(point_of_interest_head, new_point_of_interest);
                getline(&line1, &len, fp);
            }
            AppendToPlacesList(head, point_of_interest_head, new_place);
            if (getc(fp) == '#')
                fseek(fp, -1, SEEK_CUR);
            else
                *line1 = EOF;
        }
        fclose(fp);
    }
    free(line1);
    free(line2);

    return 0;
}


int LoadPlacesFile(PlacesList head) {
    FILE *fp;
    head = head->next;
    PlacesList place = head;

    fp = fopen(PLACESPATH, "w");

    if (head != NULL) {
        while (place != NULL) {
            fprintf(fp, "#%s\n", place->name);
            fprintf(fp, ">\n");
            place->PointOfInterest = place->PointOfInterest->next;
            while (place->PointOfInterest != NULL) {
                fprintf(fp, "@ %s|%s|\n", place->PointOfInterest->name, place->PointOfInterest->WorkingHours);
                fprintf(fp, "%s", place->PointOfInterest->info);
                if (place->PointOfInterest->next != NULL)
                    fprintf(fp, "-\n");
                place->PointOfInterest = place->PointOfInterest->next;
            }
            fprintf(fp, ">\n\n");
            place = place->next;
        }
    }
    fclose(fp);
    return 0;
}

int PrintPlaces(void) {
    FILE *fp;
    char *line = malloc(sizeof(char) * 256);

    fp = fopen(PLACESPATH, "r");

    if (fp == NULL) {
        printf("Não existe ficheiro de dados no disco!\n");
        printf("Este foi criado!\n");
        createfile("Places", ".txt");
    }
    while ((fgets(line, sizeof(line), fp) != NULL)) {
        printf("%s", line);
    }

    free(line);
    fclose(fp);
    return 0;
}
