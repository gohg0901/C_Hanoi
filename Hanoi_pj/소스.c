#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef struct _stack {
	int s[11];
	int top;

}Stack;

void push(Stack* a, int i) {

	a->top = a->top + 1;
	a->s[a->top] = i;
}

int pop(Stack* a) {

	a->top = a->top - 1;
	return a->s[a->top + 1];
}

void hanoi(int n, Stack *from, Stack *tmp, Stack *to) {
	
	if (n == 1) {
		push(to, 1);
		pop(from);

		
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("¿ø¹Ý %d¸¦ %d -> %d \n",n,from,to);
		printf("-----A-----     -----B-----     -----C-----\n");
		hanoi(n - 1, tmp, from, to);
	}
}

main() {
	int n;
	int x;

	Stack from;
	Stack tmp;
	Stack to;

	from.top = -1;
	tmp.top = -1;
	to.top = -1;


	printf("input (1 <= n <= 10 ) : ");
	scanf("%d",&n);

	//push(&A, 8);
	//x = pop(&A);
	//printf("%d \n", x);


	hanoi(n, &from, &tmp, &to);
	printf("-----A-----     -----B-----     -----C-----\n");





}
