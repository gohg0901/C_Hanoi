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

void star(int *a,int i) {
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

		star(a,i);
		star(b, i);
		star(c, i);
		printf("\n");
	}
}

void hanoi(int n,int from[], int tmp[], int to[],int to_do) {
	
	if (n == 1) {
	
		printf("              원반 1를 %c -> %c \n", from[11], to[11]);
		
		print_star(to_do, from, tmp, to);
		print_underbar();
	
	}
	else {
		hanoi(n - 1 , from, to, tmp,to_do);
		printf("              원반 %d를 %c -> %c \n", n, from[11], to[11]);

	

		print_star(to_do, from, tmp, to);
		print_underbar();

		hanoi(n - 1 , tmp, from, to, to_do);
	}

}

main() {
	int n,i,to_do;

	int a[13] = { 0, };
	int b[13] = { 0, };
	int c[13] = { 0, };
	
	a[DISTINCTION] = 65;
	b[DISTINCTION] = 66;
	c[DISTINCTION] = 67;


	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);
	to_do = n;
	a[TOP] = n-1;

	for (i = 0; i < n; i++) {
		a[i] = i+1;
	}

	//시작상태 print
	printf("                  시작상태                 \n");
	print_star(n,a,b,c);
	print_underbar();

	//n번 돌림
	hanoi(n,a,b,c,to_do);
}