#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule_Manage.h"

Schedule* head = NULL;
int id_counter = 1;  // 일정 ID 자동 증가

int main() {
    menu();
    return 0;
}