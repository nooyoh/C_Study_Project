#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "bookManage.h"

int main(void)
{
	i = 0;
	bookindex = 0;
	char fpname[BOOK_NAME_SIZE];
	char fpauth[BOOK_AUTH_SIZE];
	char fppubl[BOOK_PUBL_SIZE];
	char input[10] = {0, };

	system("title 도서 종합 관리 프로그램");
	drw(D_VIOLET, WHITE);

	fp = fopen("booklist.txt", "a+"); // "a+" : 읽기/쓰기 모드 파일이 없으면 생성, 있으면 파일 유지하며 수정
	if (fp == NULL) {
		printf("파일 열기에 실패했습니다.\n");
		return 1;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%[^,], %[^,], %[^\n]", booklist[i].name, booklist[i].auth, booklist[i].publ);
		fgetc(fp);
		booklist[i].isborrowed = 0;
		bookindex++;
		i++;
	}

	while (1)
	{
		system("cls");
		printf("[대출] [반납] [도서등록] [목록출력] [검색] [종료] : ");
		gets(input);

		if (!strcmp(input, "대출"))
			borrowbook();
		else if (!strcmp(input, "반납"))
			returnbook();
		else if (!strcmp(input, "도서등록"))
			registerbook();
		else if (!strcmp(input, "목록출력"))
			printbook();
		else if (!strcmp(input, "검색"))
			searchmenu();
		else if (!strcmp(input, "종료"))
		{
			printf("\n\n도서 관리 프로그램을 종료합니다.\n\n");
			return 0;
		}
		else
		{
			printf("\n\n잘못된 입력입니다. 다시 입력해주세요.\n\n");
			printf("\n계속하려면 아무 키나 입력하세요...");
			_getch();
			continue;
		}
	}

	fclose(fp);

	return 0;
}