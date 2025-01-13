#ifndef BOOK_MANAGEMENT
#define BOOK_MANAGEMENT

#define BOOK_NAME_SIZE 50
#define BOOK_AUTH_SIZE 30
#define BOOK_PUBL_SIZE 30

void drw(int bgColor, int textColor);
void borrowbook();   // 도서 대출 함수
void returnbook();   // 도서 반납 함수
void registerbook(); // 도서 등록 함수
void printbook();    // 도서 목록 출력 함수
void searchmenu();   // 도서 검색 메뉴 함수
void searchbookbyname(); // 도서명으로 검색
void searchbookbyauth(); // 저자로 검색
void searchbookbypubl(); // 출판사로 검색

typedef struct _book {
	char name[BOOK_NAME_SIZE]; // 책 제목
	char auth[BOOK_AUTH_SIZE]; // 책 저자
	char publ[BOOK_PUBL_SIZE]; // 책 출판사
	int isborrowed;   // 대출 상태가 아니면 0, 대출된 상태이면 1
}Book;

enum colorName
{
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

FILE* fp;
Book booklist[100];
int bookindex;
int i, j;

#endif // !BOOK_MANAGEMENT