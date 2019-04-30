#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H

#define ClearBuffer() __fpurge(stdin)
#define ClearConsole() system("clear")

int removeEnter(char *str);

char readstring(char **string, int init_size, int chunk);

int getPhoneNumber(char **phone);

int getHourAndMinute(Hour_t *time, int option, char *string, char *delimiter);

#endif //PROJECT_FUNCTIONS_H

