#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, char from, char tmp, char to) {
	
	if (n == 1) {
		printf("���� 1�� %c -> %c \n",from,to);
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("���� %d�� %c -> %c \n",n,from,to);
		hanoi(n - 1, tmp, from, to);
	}
}

main() {
	int n;

	printf("input : ");
	scanf("%d",&n);
	

	hanoi(n, 'A', 'B', 'C');
}