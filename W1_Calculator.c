#include <stdio.h>

void calculator() {
	int count = 0;
	double num1, num2, result;
	char op;
	int inputForm;

	printf("===========Calculator===========\n");
	printf("연산식을 \"숫자1 연산자 숫자2\" 형식으로 작성하시오.\n");
	printf("ex) 1 + 2\n");
	printf("지원 연산자: +, -, *, /\n\n");

	do {
		printf("연산식을 입력하세요: ");
		inputForm = scanf("%lf %c %lf", &num1, &op, &num2);

		if (inputForm != 3) {
			printf("입력 형식이 잘못되었습니다. 연산식을 다시 입력하세요.\n");
			while (getchar() != '\n');
		}

	} while (inputForm != 3);

	switch (op) {
		case '+':
			result = num1 + num2;
			printf("결과값: %.2lf\n", result);
			break;
		case '-':
			result = num1 - num2;
			printf("결과값: %.2lf\n", result);
			break;
		case '*':
			result = num1 * num2;
			printf("결과값: %.2lf\n", result);
			break;
		case '/':
			if (num2 == 0) {
				printf("Error: 0으로 나눌 수 없습니다.\n");
			}
			else {
				result = num1 / num2;
				printf("결과값: %.2lf\n", result);
			}
			break;
		default:
			printf("Error: 지원하지 않는 연산자입니다.\n");
			break;
	}
}

int main() {
	int select;

	do {
		printf("계산기를 이용하시려면 '1'을 프로그램 종료를 원하시면 '0'을 눌러주세요: ");
		if (scanf("%d", &select) != 1) { 
			printf("잘못된 입력입니다. 숫자를 입력하세요.\n");
			while (getchar() != '\n');
			continue;
		}

		switch (select) {
		case 1:
			calculator();
			break;
		case 0:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}
	} while (select != 0);

	return 0;
}