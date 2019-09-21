#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_underbar() {
	printf("-----A-----     -----B-----     -----C-----\n");
}

void hanoi(int n,char from, char tmp, char to) {

	if (n == 1) {
		printf("              원반 1를 %c -> %c \n", from, to);
		
		print_underbar();
	}
	else {
		hanoi(n - 1 , from, to, tmp);
		printf("              원반 %d를 %c -> %c \n", n, from, to);

		print_underbar();
		hanoi(n - 1 , tmp, from, to);
	}

}

main() {
	int n;
	int i, j;
	int d = 1;
	printf("input (1 <= n <= 10 ) : ");
	scanf_s("%d", &n);

	
	//시작상태 print
	printf("                  시작상태                 \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < d; j++) {
			printf("*");
		}
		d++;
		printf("\n");
	}
	print_underbar();

	//n번 돌림
	hanoi(n, 'A','B','C');

}
