
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

		printf("              ���� 1�� %c -> %c \n", from[11], to[11]);

		print_star(to_do, a, b, c);
		print_underbar();

	}
	else {
		hanoi(n - 1, from, to, tmp, to_do, a, b, c);
		printf("              ���� %d�� %c -> %c \n", n, from[11], to[11]);



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

	//���ۻ��� print
	printf("                  ���ۻ���                 \n");
	print_star(n, a, b, c);
	print_underbar();

	//n�� ����
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

void hanoi_tower(int n, int* from, int* tmp, int* to, int to_do) {// �ϳ���Ÿ�� ����
	int i;
	if (n == 1) {
		to[strlen(to)] = from[strlen(from) - 1];  // from�� ����������� to���������� �̵�  
		from[strlen(from) - 1] = 0;       // from�� ���������� null ����(������ �����ؾ� �̵��� ��ó�� ���̱� ����) 

		for (i = to_do - 1; i >= 0; i--) {       // �� �迭�� �� ���
			print_star(n, from, tmp, to);
		}
		print_underbar();
	}
	else {
		hanoi_tower(n - 1, from, to, tmp, to_do);

		to[strlen(to)] = from[strlen(from) - 1];  // from�� ����������� to���������� �̵�  
		from[strlen(from) - 1] = 0;       // from�� ���������� null ����

		for (i = to_do - 1; i >= 0; i--) {        // �� �迭�� �� ���
			print_star(n, from, tmp, to);
		}
		print_underbar();

		hanoi_tower(n - 1, tmp, from, to, to_do);        // �� ����� ���
	}
}

int main(void) {
	int i;
	int n, to_do;
	int A[11] = { 0, }; // from���� ���� A 
	int B[11] = { 0, }; // temp�� ���� B 
	int C[11] = { 0, }; // to�� ���� C 



	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);
	to_do = n;

	for (i = 0; i < n; i++) {
		A[i] = i + 1;
	}

	printf("                  ���ۻ���                 \n");
	print_star(n, A, B, C);
	print_underbar();           // �� ����� ���

	hanoi_tower(n, A, B, C, to_do);        // hanoi_tower�� ��� �Լ� ȣ��


	return 0;
}


#include <stdio.h>
#include <string.h>
#define HEIGHT 6 // ž�� ���̸� HEIGHT���� ���� (���ȭ) 

char A[HEIGHT + 1] = { '6', '5', '4', '3', '2', '1' }; // from���� ���� A 
char B[HEIGHT + 1] = { '\0' }; // temp�� ���� B 
char C[HEIGHT + 1] = { '\0' }; // to�� ���� C 

void hanoi_tower(int n, char* from, char* tmp, char* to) { //�ϳ��� Ÿ�� ���� 
	int i;
	if (n == 1) {
		to[strlen(to)] = from[strlen(from) - 1];  // from�� ����������� to���������� �̵�  
		from[strlen(from) - 1] = '\0';       // from�� ���������� null ����(������ �����ؾ� �̵��� ��ó�� ���̱� ����) 

		for (i = HEIGHT - 1; i >= 0; i--)         // �� �迭�� �� ���
			printf("%c %c %c \n", A[i], B[i], C[i]);
		printf("A B C\n");            // �� ����� ���
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		to[strlen(to)] = from[strlen(from) - 1];  // from�� ����������� to���������� �̵�  
		from[strlen(from) - 1] = '\0';       // from�� ���������� null ����

		for (i = HEIGHT - 1; i >= 0; i--) {        // �� �迭�� �� ���
			printf("%c %c %c \n", A[i], B[i], C[i]);
		}
		printf("A B C\n\n");
		hanoi_tower(n - 1, tmp, from, to);        // �� ����� ���
	}
}

int main(void)
{
	int i;               // index���� ����

	for (i = HEIGHT; i >= 0; i--) {           // �ʱ� �迭�� �Է� �� ���� ���
		printf("%c %c %c\n", A[i], B[i], C[i]);
	}

	printf("A B C\n");            // �� ����� ���
	hanoi_tower(HEIGHT, A, B, C);        // hanoi_tower�� ��� �Լ� ȣ��
	getch();
	return 0;
}


//---------------------------------------------
#include <stdio.h>
#include <string.h>
#define HEIGHT 6 // ž�� ���̸� HEIGHT���� ���� (���ȭ) 


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

void hanoi_tower(int n, char* from, char* tmp, char* to) { //�ϳ��� Ÿ�� ���� 
	int i;
	if (n == 1) {
		to[strlen(to)] = from[strlen(from) - 1];  // from�� ����������� to���������� �̵�  
		from[strlen(from) - 1] = '\0';       // from�� ���������� null ����(������ �����ؾ� �̵��� ��ó�� ���̱� ����) 

		for (i = HEIGHT - 1; i >= 0; i--) {         // �� �迭�� �� ���
			printf("%c               %c               %c\n", from[i], tmp[i], to[i]);
		}
		print_underbar();            // �� ����� ���
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		to[strlen(to)] = from[strlen(from) - 1];  // from�� ����������� to���������� �̵�  
		from[strlen(from) - 1] = '\0';       // from�� ���������� null ����

		for (i = HEIGHT - 1; i >= 0; i--) {        // �� �迭�� �� ���
			printf("%c               %c               %c\n", from[i], tmp[i], to[i]);
		}
		print_underbar();
		hanoi_tower(n - 1, tmp, from, to);        // �� ����� ���
	}
}

main() {
	int i, n, d;               // index���� ����
	char A[11] = { '5','4','3', '2', '1' }; // from���� ���� A 
	char B[11] = { '\0' }; // temp�� ���� B 
	char C[11] = { '\0' }; // to�� ���� C 

	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);
	d = n;


	printf("                  ���ۻ���                 \n");
	for (i = n; i >= 0; i--) {           // �ʱ� �迭�� �Է� �� ���� ���
		printf("%c               %c               %c\n", A[i], B[i], C[i]);

	}

	print_underbar();            // �� ����� ���
	hanoi_tower(n, A, B, C);        // hanoi_tower�� ��� �Լ� ȣ��

	return 0;
}
