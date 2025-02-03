#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule_Manage.h"

// 일정 추가 함수
void addSchedule(char* title, char* date) {
    Schedule* newSchedule = (Schedule*)malloc(sizeof(Schedule));
    newSchedule->id = id_counter++;
    strcpy(newSchedule->title, title);
    strcpy(newSchedule->date, date);
    newSchedule->next = head;
    head = newSchedule;
    printf("일정 추가 완료: %s (%s)\n", title, date);
}

// 일정 검색 함수
void searchSchedule(char* date) {
    Schedule* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->date, date) == 0) {
            printf("ID: %d, 제목: %s, 날짜: %s\n", temp->id, temp->title, temp->date);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("해당 날짜의 일정이 없습니다.\n");
    }
}

// 일정 삭제 함수
void deleteSchedule(int id) {
    Schedule* temp = head;
    Schedule* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("일정을 찾을 수 없습니다.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    free(temp);
    printf("ID %d 일정 삭제 완료.\n", id);
}

// 일정 출력 함수
void displaySchedules() {
    Schedule* temp = head;
    if (temp == NULL) {
        printf("저장된 일정이 없습니다.\n");
        return;
    }
    while (temp != NULL) {
        printf("ID: %d | 제목: %s | 날짜: %s\n", temp->id, temp->title, temp->date);
        temp = temp->next;
    }
}

// 메뉴
void menu() {
    int choice, id;
    char title[100], date[20];

    while (1) {
        printf("\n[일정 관리 프로그램]\n");
        printf("1. 일정 추가\n");
        printf("2. 일정 검색\n");
        printf("3. 일정 삭제\n");
        printf("4. 일정 목록 보기\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar();  // 버퍼 비우기

        switch (choice) {
        case 1:
            printf("제목: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;
            printf("날짜 (YYYY-MM-DD): ");
            fgets(date, sizeof(date), stdin);
            date[strcspn(date, "\n")] = 0;
            addSchedule(title, date);
            break;
        case 2:
            printf("검색할 날짜 (YYYY-MM-DD): ");
            fgets(date, sizeof(date), stdin);
            date[strcspn(date, "\n")] = 0;
            searchSchedule(date);
            break;
        case 3:
            printf("삭제할 일정 ID: ");
            scanf("%d", &id);
            deleteSchedule(id);
            break;
        case 4:
            displaySchedules();
            break;
        case 5:
            printf("프로그램 종료.\n");
            return;
        default:
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }
}