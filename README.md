# projetoPPP
by João Leitão and Pedro Rodrigues

# structs.c
    Ficheiro de código fonte de linguagem C (.c) que contem:
        - Uma função usada para criar uma lista ligada de Alunos --> BuildStudentsList().

            StudentsList BuildStudentsList() {                                  --> Função cria o header da lista ligada
                StudentsList head = (StudentsList) malloc(sizeof(StudentsList));    dos alunos
                if (head != NULL) {
                    sprintf(head->InfoStudent.name, "%d", -1);                  --> Inicialização de todos os valores
                    sprintf(head->InfoStudent.address, "%d", -1);                   com um valores de controlo (-1) para
                    sprintf(head->InfoStudent.date_of_birth, "%d", -1);             facilitar o degug caso este seja
                    head->InfoStudent.phone_number = -1;                            necessário.
                    head->next = NULL;
                }
                return head;
            }

        - Uma função usada para criar uma lista ligada de Pontos de Interesse --> BuildPlacesList().

            PlacesList BuildPlacesList() {                                   --> Função cria o header da lista ligada
                PlacesList head = (PlacesList) malloc(sizeof(PlacesList));       dos Pontos de Interesse
                if (head != NULL) {
                    sprintf(head->InfoPlace.city, "%d", -1);
                    sprintf(head->InfoPlace.info, "%d", -1);
                    head->InfoPlace.WorkingHours.start_hour = -1;            --> Inicialização de todos os valores
                    head->InfoPlace.WorkingHours.end_hour = -1;                  com um valores de controlo (-1) para
                    head->InfoPlace.WorkingHours.end_minute = -1;                facilitar o degug caso este seja
                    head->InfoPlace.WorkingHours.end_minute = -1;                necessário.
                    head->next = NULL;
                }
                return head;
            }

# structs.h
    Ficheiro de cabeçalhos de linguagem C (.h) que que contem:
        - Os cabeçalhos das funções descritas anteriormente --> StudentsList BuildStudentsList();
                                                            --> PlacesList BuildPlacesList();
        -Todas as estruturas que vão ser utilizadas nos diversos ficheiros de codigo fonte e que devem portanto
        estar acessiveis a estes sendo por isso colocadas ficheiro de cabeçalhos (.h).
        (Estruturas permitem-nos criar conceitos num computador do que é o mundo e o que este tem).

            -Estruturas e breve descrição:

                # Estrutura de um aluno:

                    typedef struct Student {
                        struct InfoStudent InfoStudent; --> Dados pessoais do aluno.
                        struct Student *next;           --> Ponteiro que vai apontar para o proximo "aluno".
                    } Student_t;                            (nó da lista alocada dinamicamente na memória).


                # Estrutura dos dados de um aluno:

                    typedef struct StudentData {
                        char name;          --> Nome do aluno.
                        char address;       --> Morada do aluno.
                        char date_of_birth; --> Data de nascimento do aluno.
                        int phone_number;   --> Numero de telemóvel do aluno.
                    } StudentData_t;

                # Estrutura de um Ponto de Interesse:

                   typedef struct Places {
                       struct PlacesData InfoPlace; --> Informação sobre o Ponto de Interesse.
                       struct Places *next;         --> Ponteiro que vai apontar para o proximo "ponto de interesse".
                   } Places_t;                          (nó da lista alocada dinamicamente na memória).

                # Estrutura dos dados do Ponto de Interesse:

                    typedef struct PlacesData {
                        struct Hour WorkingHours;   --> Informação sobre o Horário de funcionamento.
                        char info;                  --> Descrição do Ponto de Interesse.
                        char city;                  --> Nome do Ponto de Interesse (nome da cidade).
                    } PlacesData_t;

                # Estrutura do Horário de funcionamento de um Ponto de Interesse:

                    typedef struct Hour {
                        int start_hour;   --> Hora de Abertura do Ponto de Interesse ao publico.
                        int end_hour;     --> Hora de Fecho do Ponto de Interesse ao publico.
                        int start_minute; --> Minuto de Abertura do Ponto de Interesse ao publico associado à hora
                                              de abertura.
                        int end_minute;   --> Minuto de Fecho do Ponto de Interesse ao publico associado à hora
                                              de fecho.
                    } Hour_t;

                # Estrutura dos Dias do ano:

                    typedef struct Date {
                        int day;            --> Dia do ano.
                        int month;          --> Mês do ano.
                        int year;           --> Ano ao qual os dois anteriores se referem.
                    } Date_t;

# files.h
    Ficheiro de cabeçalhos de linguagem C (.h) que que contem:
    - Os cabeçalhos das funções descritas anteriormente --> createfile()
                                                        --> PrintPlaces()
                                                        --> LoadStudentsList()
                                                        --> LoadStudentsFile()

# files.c
    Ficheiro de código fonte de linguagem C (.c) que contem:
        -Uma função para criar um ficheiro na pasta do projeto caso este não exista --> createfile()

               int createfile(char *name, char *extension) {      --> Recebe um nome para o ficheiro a extensão do mesmo
                   FILE *fp;                                          e cria o ficheiro(abrindo-o em modo "w" e depois
                   int len = strlen(name) + strlen(extension) + 1;    fecha o ficheiro.
                   char *file = malloc(sizeof(char) * len);

                   sprintf(file, "%s%s", name, extension);

                   fp = fopen(file, "w");
                   fclose(fp);

                   free(file);

                   return 0;
               }

        -Uma função para dar display dos Pontos de Interesse que estão escritos no ficheiro Places.txt --> PrintPlaces()

                int PrintPlaces(void) {
                    FILE *fp;
                    char *line = malloc(sizeof(char) * 256);

                    fp = fopen("Places", "r");          --> Tenta abrir o ficheiro Places.txt

                    if (fp == NULL)
                        createfile("Places", ".txt");   --> Se não existir Places.txt ou seja fp == NULL então é criado
                                                            o ficheiro

                    while ((fgets(line, sizeof(line), fp) != NULL)) {
                        printf("%s", line);
                    }

                    free(line);
                    fclose(fp);

                    return 0;
                }
        -Uma função que dado o ficheiro onde vão ser guardados os estudantes carrega a lista ligada dos estudantes
         cada vez que o programa é inicializado --> LoadStudentsList()

                int LoadStudentsList(StudentsList head) {
                    FILE *fp;
                    fp = fopen("Students.txt", "r");   --> Tenta abrir o ficheiro Places.txt

                    Student_t *new_student = (Student_t *) malloc(sizeof(Student_t));
                    Student_t *student = head;

                    if (fp == NULL)                    --> Se não existir Students.txt ou seja fp == NULL então é criado
                        createfile("Students", ".txt");    o ficheiro

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
         -Uma função que insere os dados no ficheiro Students.txt onde está ser guardada a informação relativa a cada
          estudante --> LoadStudentsFile()

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
