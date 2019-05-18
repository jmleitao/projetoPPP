#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H

#define ClearBuffer() stdin = freopen(NULL,"r",stdin)
#define ClearConsole() system("clear")
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

/*
- Position the Cursor:
  \033[<L>;<C>H*/

int removeEnter(char *str);

int getPhoneNumber(char **phone);

int getDateOfBirth(char **date);

int readstring(char **string, int init_size, int chunk);

int strip(char **string);

void ConsolePause(double x);

#endif //PROJECT_FUNCTIONS_H
