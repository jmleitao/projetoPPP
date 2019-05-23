#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"

/* Os ficheiros que contém os dados dos alunos e dos locais juntamente com o executavel e makefile escontram-se na
 * pasta cmake-build-debug.Para correr o programa é só entrar nessa pasta e fazer ./Projeto.No caso de não existir
 * um executavel basta utilizar o comando make.Caso os ficheiros que contém os dados dos alunos ou dos locais não
 * existirem serão emitidas mensagens de erro.No caso do ficheiro dos alunos o programa encarrega-se de criar um novo
 * ficheiro para colocar todas as novas contas criadas no programa.No caso dos locais o programa irá terminar com uma
 * mensagem de erro.Para o caso de existirem problemas e se perderem estes ficheiros deixei um backup na pasta Info.
 */

// PATH dos ficheiros que contem as contas dos alunos e os dados dos locais e pontos de interesse
#define STUDENTSPATH "Students.txt"
#define PLACESPATH "Places.txt"

//Função responsavel por criar um ficheiro recebe como paramentros o nome do ficheiro e a sua extensão
int createfile(char *name, char *extension) {
    FILE *fp;
    int len = strlen(name) + strlen(extension) + 1;
    char *file = malloc(sizeof(char) * len);
    mallocFail(file);

    sprintf(file, "%s%s", name, extension);

    fp = fopen(file, "w");
    fclose(fp);

    free(file);

    return 0;
}

// Função responsavel por adicionar um estudante no fim da lista ligada dos alunos
// Recebe a cabeça da lista ligada de alunos e as estruturas de dados correspendentes aos seus dados pessoais e interesses
int AppendToStudentsList(StudentsList head, StudentData_t student_data, Student_Interests_t student_interests) {
    StudentsList current = head;
    StudentsList newStudent = (StudentsList) malloc(sizeof(Student_t));
    mallocFail(newStudent);

    newStudent->InfoStudent = student_data;
    newStudent->InfoInterests = student_interests;
    newStudent->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStudent;
    return 0;
}

// Função responsavel por adicionar um ponto de interesse no fim da lista ligada de pontos de interesse
// Recebe a cabeça da lista ligada de pontos de interesse e o node que vai ser adicionado
int AppendToPointsOfInterestList(PointsOfInterestList head, PointsOfInterestList point_of_interest_data) {
    PointsOfInterestList current = head;
    PointsOfInterestList newPointOfInterest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
    mallocFail(newPointOfInterest);

    newPointOfInterest->name = point_of_interest_data->name;
    newPointOfInterest->WorkingHours = point_of_interest_data->WorkingHours;
    newPointOfInterest->info = point_of_interest_data->info;
    newPointOfInterest->Popularity = point_of_interest_data->Popularity;

    newPointOfInterest->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPointOfInterest;
    return 0;
}

// Função responsavel por adicionar um local no fim da lista ligada de locais
// Recebe a cabeça da lista ligada de locais,o node que vai ser adicionado a esta e a cabeça da lista ligada de pontos
// de interesse que este node da lista de locais vai conter no seu interior.
int AppendToPlacesList(PlacesList places_head, PointsOfInterestList points_of_interest_head, PlacesList place_data) {
    PlacesList current = places_head;
    PlacesList newPlace = (PlacesList) malloc(sizeof(Places_t));
    mallocFail(newPlace);

    newPlace->name = place_data->name;
    newPlace->PointOfInterest = points_of_interest_head;
    newPlace->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPlace;
    return 0;
}

// Função responsavel por carregar a informação do ficheiro dos alunos na lista ligada que irá conter todos os alunos
// Recebe por isso a cabeça da lista ligada de alunos
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
    mallocFail(new_student);
    mallocFail(points_of_interest);

    fp = fopen(STUDENTSPATH, "r");

    if (fp == NULL) {
        printf("+-----------------------------------------------------------------------+\n");
        printf("|         Não existe ficheiro de Dados dos Alunos no disco!!!!          |\n");
        printf("|                          Este foi criado!                             |\n");
        printf("+-----------------------------------------------------------------------+\n");
        ConsolePause(4);
        ClearConsole();
        createfile("Students", ".txt");
    } else {
        while ((getline(&line1, &len, fp) != EOF)) {
            points_of_interest_head = BuildPointsOfInterestList();
            line2 = malloc(sizeof(char) * len);
            mallocFail(line2);
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
            mallocFail(line3);

            strcpy(line3, line1);
            i = 0;
            while (line3[0] != delimiter3[0]) {
                getline(&line1, &len, fp);
                line3 = malloc(sizeof(char) * len);
                mallocFail(line3);
                strcpy(line3, line1);
                removeEnter(line3);
                new_student->InfoInterests.favorite_places[i] = strdup(line3);
                i++;
            }
            i = 0;
            while (line3[0] != delimiter2[0]) {
                getline(&line1, &len, fp);
                line3 = malloc(sizeof(char) * len);
                mallocFail(line3);
                strcpy(line3, line1);
                if (i == 0 && line3[0] != delimiter2[0]) {
                    removeEnter(line3);
                    strip(&line3);
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

// Função responsavel por carregar o ficheiro de alunos antes de o programa terminar de forma a salvaguardar todas as
// modificações efetuadas durante o tempo em que a aplicação esteve a correr.
// Recebe por isso a cabeça da lista ligada de alunos.
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

// Função responsavel por carregar a lista ligada de Locais com informações provenientes do ficheiro de Locais
// Recebe por isso a cabeça da lista de locais por onde vai começar a carregar a informação
int LoadPlacesList(PlacesList head) {
    FILE *fp;
    int i = 0, j;

    PointsOfInterestList point_of_interest_head;

    PlacesList new_place = (PlacesList) malloc(sizeof(Places_t));
    mallocFail(new_place);
    new_place->next = NULL;
    new_place->PointOfInterest = NULL;

    PointsOfInterestList new_point_of_interest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
    new_point_of_interest->next = NULL;
    mallocFail(new_point_of_interest);

    char *line1 = NULL, *line2 = NULL, *token = NULL;
    char delimiter1[1] = "-", delimiter2[1] = "|", delimiter3[1] = ">", *info = NULL;
    size_t len;

    fp = fopen(PLACESPATH, "r");

    if (fp == NULL) {
        printf("+-----------------------------------------------------------------------+\n");
        printf("|         Não existe ficheiro de Dados dos locais no disco!!!!          |\n");
        printf("| Por favor adicione um ou verifique se o caminho para este é o correto |\n");
        printf("+-----------------------------------------------------------------------+\n");
        ConsolePause(4);
        ClearConsole();
        exit(0);
    } else {
        while (getline(&line1, &len, fp) != EOF) {
            point_of_interest_head = BuildPointsOfInterestList();
            point_of_interest_head->next = NULL;

            line2 = malloc(sizeof(char) * len);
            mallocFail(line2);
            strncpy(line2, line1 + 1, len - 1);
            removeEnter(line2);
            strip(&line2);
            new_place->name = strdup(line2);
            getline(&line1, &len, fp);
            getline(&line1, &len, fp);


            while (line2[0] != delimiter3[0]) {
                info = malloc(sizeof(char) * len * 10);
                mallocFail(info);
                memset(info, 0, len * 10);

                while (line1[0] != delimiter1[0] && line1[0] != delimiter3[0]) {
                    if (i == 0) {
                        line2 = malloc(sizeof(char) * len);
                        mallocFail(line2);
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

