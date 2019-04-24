# projetoPPP

# structs.c
    Ficheiro de código fonte de linguagem C (.c) que contem:
        - Uma função usada para criar uma lista ligada de Alunos --> BuildStudentsList()
        - Uma função usada para criar uma lista ligada de Pontos de Interesse --> BuildPlacesList()
# structs.h
    Ficheiro de cabeçalhos de linguagem C (.c) que que contem:
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


