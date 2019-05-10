#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H

#define ClearBuffer() __fpurge(stdin)
#define ClearConsole() system("clear")
#define ConsolePause() getchar()
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

/*
- Position the Cursor:
  \033[<L>;<C>H*/

int removeEnter(char *str);

int getPhoneNumber(char **phone);

int getDateOfBirth(char **date);

int readstring(char **string, int init_size, int chunk);

int strip(char **string);

#endif //PROJECT_FUNCTIONS_H
