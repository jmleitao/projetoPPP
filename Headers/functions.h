#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H

#define ClearBuffer() __fpurge(stdin)
#define ClearConsole() system("clear")
#define ConsolePause() getchar()

int removeEnter(char *str);

int getPhoneNumber(char **phone);

int getDateOfBirth(char **date);

char readstring(char **string, int init_size, int chunk);


#endif //PROJECT_FUNCTIONS_H
