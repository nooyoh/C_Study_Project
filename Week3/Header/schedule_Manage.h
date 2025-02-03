#ifndef SCHEDULE_MANAGE
#define SCHEDULE_MANAGE

void addSchedule(char* title, char* date);
void searchSchedule(char* date);
void deleteSchedule(int id);
void displaySchedules();
void menu();

// 일정 정보를 저장할 구조체
typedef struct Schedule {
    int id;
    char title[100];
    char date[20];
    struct Schedule* next;
} Schedule;

Schedule* head;
int id_counter;

#endif