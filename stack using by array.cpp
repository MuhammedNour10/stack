#include<iostream>
using namespace std;
struct stack {
	int size;
	int top;
	int* s;

};

void  create(stack* st) {
	printf("Enter the Array's size:");
	scanf_s("%d", &st.size);
	st.s = new int[st.size];
	st.top = -1;
}

int stackTop(stack st) {
	if (st.top == -1)
		return -1;
	return st.s[st.top];
}

int isEmpty(stack st) {
	if (st.top == -1)
		return 1;
	
		return 0;
}

int isFull(stack st) {
	if (st.top == st.size - 1)
		return 1;
	return 0;
}

void push(stack *st,int x) {
	if (st->top == st->size-1 )
		printf("stack overflow");
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}

int pop(stack* st) {
	int x = -1;
	if (st->top == -1)
		printf("stack underflow\n");
	else {
		x = st->s[st->top];
		st->top--;
	}
	return x;
}
void Display(stack* st) {
	int i;
	
			
	for (i = 0;i <= st->top;i++)
		printf("%d ", st->s[i]);
}

int peek(stack st, int pos) {
	int x = -1;
	if (st.top - pos + 1 < 0)
		return 0;
	else
		x = st.s[st.top - pos + 1];

		return x;
}
int main() {
	stack st;
	create(&st);


	push(&st, 5);
	push(&st, 15);
	push(&st, 20);
	push(&st, 30);

	cout << peek(st, 1)<<"\n";
	Display(&st);
}