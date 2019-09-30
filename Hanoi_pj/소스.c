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

void print_hanoi(int n, int *a, int *b, int *c) {
	for (int i = 0; i < n; i++) {
		star(a, i);
		star(b, i);
		star(c, i);
		printf("\n");
	}
}

void hanoi(int n, int *from, int *tmp, int *to,int todo) {
	if (n == 1) {

		printf("              원반 1를 %c -> %c \n",from[12],to[12]);
		//계산

		//출력
		print_hanoi(todo,from,tmp,to);
		print_underbar();

	}
	else {
		hanoi(n - 1, from, to, tmp, todo);
		printf("              원반 %d를 %c -> %c \n", n, from[12], to[12]);
		//계산

		//출력
		print_hanoi(todo, from, tmp, to);
		print_underbar();

		hanoi(n - 1, tmp, from, to, todo);
		printf("              원반 %d를 %c -> %c \n", n, from[12], to[12]);
		//계산

		//출력
		print_hanoi(todo, from, tmp, to);
		print_underbar();
	}
}





main() {
	int n, i, todo;
	int a[13] = { 0, };
	int b[13] = { 0, };
	int c[13] = { 0, };
	a[12] = 65;
	b[12] = 66;
	c[12] = 67;

	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);

	todo = n;

	for (i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	printf("                  시작상태                 \n");
	print_hanoi(n,a,b,c);
	print_underbar(); 

	hanoi(n, a, b, c, todo);
}