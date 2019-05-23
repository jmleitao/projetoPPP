#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H

// Macro que é portavel em todos os sistemas operativos visto que para limpar o buffer reabre o ficheiro stdin
#define ClearBuffer() stdin = freopen(NULL,"r",stdin)

// Macro que verifica o sistema operativo e consoante este executa o comando para limpar o Terminal
#if defined(__WIN32__) || defined(__WIN64__)
#define ClearConsole() system("cls")
#elif defined(__APPLE__) || defined(__unix__) || defined(__linux__)
#define ClearConsole() system("clear")
#endif

// Macro responsavel por deslocar o cursor no Terminal
/*
- Position the Cursor:
  \033[<Line>;<Column>H
  */
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

int removeEnter(char *str);

int getPhoneNumber(char **phone);

int getDateOfBirth(char **date);

int readstring(char **string, int init_size, int chunk);

int strip(char **string);

void ConsolePause(double x);

void mallocFail(void *pointer);

int isLeapYear(int year);

int isDateValid(int day, int month, int year);

#endif //PROJECT_FUNCTIONS_H
