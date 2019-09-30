
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define DISTINCTION 11
#define TOP 12

void print_underbar() {
	printf("-----A-----     -----B-----     -----C-----\n");
}

void star(int* a, int i) {
	int j;
	for (j = 0; j < a[i]; j++) {
		printf("*");
	}
	for (j = 0; j < 11 - a[i]; j++) {
		printf(" ");
	}
	printf("     ");
}

void print_star(int n, int a[], int b[], int c[]) {
	for (int i = 0; i < n; i++) {

		star(a, i);
		star(b, i);
		star(c, i);
		printf("\n");
	}
}

void hanoi(int n, int from[], int tmp[], int to[], int to_do, int a[], int b[], int c[]) {

	if (n == 1) {

		printf("              원반 1를 %c -> %c \n", from[11], to[11]);

		print_star(to_do, a, b, c);
		print_underbar();

	}
	else {
		hanoi(n - 1, from, to, tmp, to_do, a, b, c);
		printf("              원반 %d를 %c -> %c \n", n, from[11], to[11]);



		print_star(to_do, a, b, c);
		print_underbar();

		hanoi(n - 1, tmp, from, to, to_do, a, b, c);
	}

}

main() {
	int n, i, to_do;

	int a[13] = { 0, };
	int b[13] = { 0, };
	int c[13] = { 0, };

	a[DISTINCTION] = 65;
	b[DISTINCTION] = 66;
	c[DISTINCTION] = 67;


	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);
	to_do = n;
	a[TOP] = n - 1;

	for (i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	//시작상태 print
	printf("                  시작상태                 \n");
	print_star(n, a, b, c);
	print_underbar();

	//n번 돌림
	hanoi(n, a, b, c, to_do, a, b, c);
}

//----------------------------------------------
#include <stdio.h>

void print_underbar() {
	printf("-----A-----     -----B-----     -----C-----\n");
}

void star(int* a, int i) {
	int j;
	for (j = 0; j < a[i]; j++) {
		printf("*");
	}
	for (j = 0; j < 11 - a[i]; j++) {
		printf(" ");
	}
	printf("     ");
}

void print_star(int n, int a[], int b[], int c[]) {
	for (int i = 0; i < n; i++) {

		star(a, i);
		star(b, i);
		star(c, i);
		printf("\n");
	}
}

void hanoi_tower(int n, int* from, int* tmp, int* to, int to_do) {// 하노이타워 구현
	int i;
	if (n == 1) {
		to[strlen(to)] = from[strlen(from) - 1];  // from의 마지막블록을 to마지막으로 이동  
		from[strlen(from) - 1] = 0;       // from의 마지막꺼에 null 대입(원본을 삭제해야 이동한 것처럼 보이기 때문) 

		for (i = to_do - 1; i >= 0; i--) {       // 각 배열의 값 출력
			print_star(n, from, tmp, to);
		}
		print_underbar();
	}
	else {
		hanoi_tower(n - 1, from, to, tmp, to_do);

		to[strlen(to)] = from[strlen(from) - 1];  // from의 마지막블록을 to마지막으로 이동  
		from[strlen(from) - 1] = 0;       // from의 마지막꺼에 null 대입

		for (i = to_do - 1; i >= 0; i--) {        // 각 배열의 값 출력
			print_star(n, from, tmp, to);
		}
		print_underbar();

		hanoi_tower(n - 1, tmp, from, to, to_do);        // 각 기둥을 출력
	}
}

int main(void) {
	int i;
	int n, to_do;
	int A[11] = { 0, }; // from으로 사용될 A 
	int B[11] = { 0, }; // temp로 사용될 B 
	int C[11] = { 0, }; // to로 사용될 C 



	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);
	to_do = n;

	for (i = 0; i < n; i++) {
		A[i] = i + 1;
	}

	printf("                  시작상태                 \n");
	print_star(n, A, B, C);
	print_underbar();           // 각 기둥을 출력

	hanoi_tower(n, A, B, C, to_do);        // hanoi_tower의 재귀 함수 호출


	return 0;
}


#include <stdio.h>
#include <string.h>
#define HEIGHT 6 // 탑의 높이를 HEIGHT으로 정함 (상수화) 

char A[HEIGHT + 1] = { '6', '5', '4', '3', '2', '1' }; // from으로 사용될 A 
char B[HEIGHT + 1] = { '\0' }; // temp로 사용될 B 
char C[HEIGHT + 1] = { '\0' }; // to로 사용될 C 

void hanoi_tower(int n, char* from, char* tmp, char* to) { //하노이 타워 구현 
	int i;
	if (n == 1) {
		to[strlen(to)] = from[strlen(from) - 1];  // from의 마지막블록을 to마지막으로 이동  
		from[strlen(from) - 1] = '\0';       // from의 마지막꺼에 null 대입(원본을 삭제해야 이동한 것처럼 보이기 때문) 

		for (i = HEIGHT - 1; i >= 0; i--)         // 각 배열의 값 출력
			printf("%c %c %c \n", A[i], B[i], C[i]);
		printf("A B C\n");            // 각 기둥을 출력
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		to[strlen(to)] = from[strlen(from) - 1];  // from의 마지막블록을 to마지막으로 이동  
		from[strlen(from) - 1] = '\0';       // from의 마지막꺼에 null 대입

		for (i = HEIGHT - 1; i >= 0; i--) {        // 각 배열의 값 출력
			printf("%c %c %c \n", A[i], B[i], C[i]);
		}
		printf("A B C\n\n");
		hanoi_tower(n - 1, tmp, from, to);        // 각 기둥을 출력
	}
}

int main(void)
{
	int i;               // index변수 선언

	for (i = HEIGHT; i >= 0; i--) {           // 초기 배열의 입력 된 값을 출력
		printf("%c %c %c\n", A[i], B[i], C[i]);
	}

	printf("A B C\n");            // 각 기둥을 출력
	hanoi_tower(HEIGHT, A, B, C);        // hanoi_tower의 재귀 함수 호출
	getch();
	return 0;
}


//---------------------------------------------
#include <stdio.h>
#include <string.h>
#define HEIGHT 6 // 탑의 높이를 HEIGHT으로 정함 (상수화) 


void print_underbar() {
	printf("-----A-----     -----B-----     -----C-----\n");
}

void star(int* a, int i) {
	int j;
	for (j = 0; j < a[i]; j++) {
		printf("*");
	}
	for (j = 0; j < 11 - a[i]; j++) {
		printf(" ");
	}
	printf("     ");
}

void print_star(int n, int a[], int b[], int c[]) {
	for (int i = 0; i < n; i++) {

		star(a, i);
		star(b, i);
		star(c, i);
		printf("\n");
	}
}

void hanoi_tower(int n, char* from, char* tmp, char* to) { //하노이 타워 구현 
	int i;
	if (n == 1) {
		to[strlen(to)] = from[strlen(from) - 1];  // from의 마지막블록을 to마지막으로 이동  
		from[strlen(from) - 1] = '\0';       // from의 마지막꺼에 null 대입(원본을 삭제해야 이동한 것처럼 보이기 때문) 

		for (i = HEIGHT - 1; i >= 0; i--) {         // 각 배열의 값 출력
			printf("%c               %c               %c\n", from[i], tmp[i], to[i]);
		}
		print_underbar();            // 각 기둥을 출력
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		to[strlen(to)] = from[strlen(from) - 1];  // from의 마지막블록을 to마지막으로 이동  
		from[strlen(from) - 1] = '\0';       // from의 마지막꺼에 null 대입

		for (i = HEIGHT - 1; i >= 0; i--) {        // 각 배열의 값 출력
			printf("%c               %c               %c\n", from[i], tmp[i], to[i]);
		}
		print_underbar();
		hanoi_tower(n - 1, tmp, from, to);        // 각 기둥을 출력
	}
}

main() {
	int i, n, d;               // index변수 선언
	char A[11] = { '5','4','3', '2', '1' }; // from으로 사용될 A 
	char B[11] = { '\0' }; // temp로 사용될 B 
	char C[11] = { '\0' }; // to로 사용될 C 

	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);
	d = n;


	printf("                  시작상태                 \n");
	for (i = n; i >= 0; i--) {           // 초기 배열의 입력 된 값을 출력
		printf("%c               %c               %c\n", A[i], B[i], C[i]);

	}

	print_underbar();            // 각 기둥을 출력
	hanoi_tower(n, A, B, C);        // hanoi_tower의 재귀 함수 호출

	return 0;
}
