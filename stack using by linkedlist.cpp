#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
}*top=NULL;

void push(int x) {
	Node* temp = (Node*) malloc(sizeof(Node));
	if (temp == NULL)
		printf("stack overflow\n");
	else 
	{
		temp->data = x;
		temp->next = top;
		top = temp;

	}
}

int pop() {
	int x = -1;
	Node* t;
	if (top == NULL)
		printf("stack is underflow\n");
	else
	{
		t = top;
		x = t->data;
		top = top->next;
		delete t;
	}
	return x;
}


void Display() {
	Node* p = top;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}

int peek(int pos) {
	Node* p=top;
	int i;

		for (i = 0;i < pos - 1 && p != NULL;i++)
			p = p->next;

		if (p)
			return p->data;
		else
			return -1;
	}

int main() {
	push(10);
	push(20);
	push(30);
	cout<<pop()<<"\n";
	Display();
	cout << peek(1);
}