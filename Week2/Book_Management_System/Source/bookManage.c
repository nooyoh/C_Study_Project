#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "bookManage.h"

void drw(int bgColor, int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}

// 도서 대출 함수
void borrowbook()
{
	char bookname[BOOK_NAME_SIZE] = { 0, };

	printf("\n\n대출할 도서의 이름을 입력해주세요 : ");
	gets(bookname);

	for (i = 0; i < bookindex; i++)
	{
		if (!strcmp(bookname, booklist[i].name))
		{
			if (booklist[i].isborrowed == 0)
			{
				booklist[i].isborrowed = 1;
				printf("대출되었습니다.\n\n");
				printf("\n계속하려면 아무 키나 입력하세요...");
				_getch();
				return;
			}
			else
			{
				printf("위 도서는 이미 대출되었습니다.\n\n");
				printf("\n계속하려면 아무 키나 입력하세요...");
				_getch();
				return;
			}
		}
	}

	printf("위 이름을 가진 도서가 없습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

// 도서 반납 함수
void returnbook()
{
	char bookname[BOOK_NAME_SIZE] = { 0, };

	printf("\n\n반납할 도서의 이름을 입력해주세요 : ");
	gets(bookname);

	for (i = 0; i < bookindex; i++)
	{
		if (!strcmp(bookname, booklist[i].name))
		{
			if (booklist[i].isborrowed == 1)
			{
				booklist[i].isborrowed = 0;
				printf("반납되었습니다.\n\n");
				printf("\n계속하려면 아무 키나 입력하세요...");
				_getch();
				return;
			}
			else
			{
				printf("위 도서는 대출 상태가 아닙니다.\n\n");
				printf("\n계속하려면 아무 키나 입력하세요...");
				_getch();
				return;
			}
		}
	}

	printf("위 이름을 가진 도서가 없습니다.\n\n");
	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

// 도서 등록 함수
void registerbook()
{
	char yesorno[10] = { 0, };
	char bookname[BOOK_NAME_SIZE] = { 0, };
	char bookauth[BOOK_AUTH_SIZE] = { 0, };
	char bookpubl[BOOK_PUBL_SIZE] = { 0, };

	printf("\n\n등록할 도서의 이름을 입력하세요 : ");
	gets(bookname);
	printf("등록할 도서의 저자를 입력하세요 : ");
	gets(bookauth);
	printf("등록할 도서의 출판사를 입력하세요 : ");
	gets(bookpubl);
	printf("도서명 : %s\n저  자 : %s\n출판사 : %s\n위 내용이 맞습니까? (예/아니요) : ", bookname, bookauth, bookpubl);
	gets(yesorno);

	if (strcmp(yesorno, "예"))
	{
		printf("\n\n도서 등록을 취소합니다.\n\n");
		printf("\n계속하려면 아무 키나 입력하세요...");
		_getch();
		return;
	}

	strcpy(booklist[bookindex].name, bookname);
	strcpy(booklist[bookindex].auth, bookauth);
	strcpy(booklist[bookindex].publ, bookpubl);
	booklist[bookindex].isborrowed = 0;
	bookindex++;

	fprintf(fp, "\n%s,%s,%s", bookname, bookauth, bookpubl);

	printf("\n도서 등록이 완료되었습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

// 도서 목록 출력 함수
void printbook()
{
	printf("\n\n");
	if (!bookindex)
	{
		printf("도서 목록이 비었음\n\n");
		printf("\n계속하려면 아무 키나 입력하세요...");
		_getch();
		return;
	}
	for (i = 0; i < bookindex; i++)
	{
		printf("=======================\n");
		printf("도서명 : %s\n", booklist[i].name);
		printf("저  자 : %s\n", booklist[i].auth);
		printf("출판사 : %s\n", booklist[i].publ);
		printf("대출상태 : %s\n", (booklist[i].isborrowed == 1) ? "대출 중인 책" : "대출 가능한 책");
	}
	printf("=======================\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

// 도서 검색 메뉴 함수
void searchmenu()
{
	char input[20] = { 0, };

	printf("\n\n[도서명검색] [저자검색] [출판사검색] : ");
	gets(input);

	if (!strcmp(input, "도서명검색"))
		searchbookbyname();
	else if (!strcmp(input, "저자검색"))
		searchbookbyauth();
	else if (!strcmp(input, "출판사검색"))
		searchbookbypubl();
	else
	{
		printf("\n\n잘못된 입력입니다.\n\n");
		printf("\n계속하려면 아무 키나 입력하세요...");
		_getch();
	}
}

// 책 제목으로 검색
void searchbookbyname()
{
	int namelength;    // 검색할 책 이름의 길이
	int samecnt;       // 책 이름 한 글자씩 비교, 같으면 1씩 증가
	int searchcnt = 0; // 총 검색된 도서 개수
	char bookname[BOOK_NAME_SIZE] = { 0, };

	printf("\n\n도서명을 입력하세요 : ");
	gets(bookname);

	namelength = strlen(bookname);
	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		samecnt = 0;
		for (j = 0; j < namelength; j++)
		{
			if (bookname[j] == booklist[i].name[j])
				samecnt++;
			else
				break;
		}
		if (samecnt == namelength)
		{
			printf("=======================\n");
			printf("도서명 : %s\n", booklist[i].name);
			printf("저  자 : %s\n", booklist[i].auth);
			printf("출판사 : %s\n", booklist[i].publ);
			printf("대출상태 : %s\n", (booklist[i].isborrowed == 1) ? "대출 중인 책" : "대출 가능한 책");
			searchcnt++;
		}
	}
	if (searchcnt)
		printf("=======================\n\n");
	else
		printf("검색한 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

// 책 저자로 검색
void searchbookbyauth()
{
	int searchcnt = 0;
	char bookauth[BOOK_AUTH_SIZE] = { 0, };

	printf("\n\n저자의 이름을 입력하세요 : ");
	gets(bookauth);

	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		if (!strcmp(booklist[i].auth, bookauth))
		{
			printf("=======================\n");
			printf("도서명 : %s\n", booklist[i].name);
			printf("저  자 : %s\n", booklist[i].auth);
			printf("출판사 : %s\n", booklist[i].publ);
			printf("대출상태 : %s\n", (booklist[i].isborrowed == 1) ? "대출 중인 책" : "대출 가능한 책");
			searchcnt++;
		}
	}

	if (searchcnt)
		printf("=======================\n\n");
	else
		printf("검색한 저자의 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

// 책 출판사로 검색
void searchbookbypubl()
{
	int searchcnt = 0;
	char bookpubl[BOOK_PUBL_SIZE] = { 0, };

	printf("\n\n출판사 이름을 입력하세요 : ");
	gets(bookpubl);

	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		if (!strcmp(booklist[i].publ, bookpubl))
		{
			printf("=======================\n");
			printf("도서명 : %s\n", booklist[i].name);
			printf("저  자 : %s\n", booklist[i].auth);
			printf("출판사 : %s\n", booklist[i].publ);
			printf("대출상태 : %s\n", (booklist[i].isborrowed == 1) ? "대출 중인 책" : "대출 가능한 책");
			searchcnt++;
		}
	}

	if (searchcnt)
		printf("=======================\n\n");
	else
		printf("검색한 출판사의 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}