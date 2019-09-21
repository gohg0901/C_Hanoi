#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_underbar() {
	printf("-----A-----     -----B-----     -----C-----\n");
}

int print_star(int n,int d,int num) {
	int i,j;
	d++;
	for (i = 0; i < n; i++) {
		if (num == 0)
		for (j = 0; j < d; j++) {
			printf("*");
		}
		for (j = 0; j < 11 - d; j++) {
			printf(" ");
		}
		d++;
		printf("\n");
	}
	

}
void hanoi(int n,char from, char tmp, char to) {

	if (n == 1) {
		printf("              원반 1를 %c -> %c \n", from, to);
		print_star(n,0,to);
		print_underbar();
	}
	else {
		hanoi(n - 1 , from, to, tmp);
		printf("              원반 %d를 %c -> %c \n", n, from, to);
		print_star(n,0,to);
		print_underbar();
		hanoi(n - 1 , tmp, from, to);
	}

}

main() {
	int n;
	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);


	printf("                  시작상태                 \n");
	print_star(n,0,'A');
	print_underbar();

	//n번 돌림
	hanoi(n, 'A','B','C');

}
