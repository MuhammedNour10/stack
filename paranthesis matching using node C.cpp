#include<iostream>
#include<cstring>
using namespace std;

struct Node {
	int data;
	Node* next;
}*top=NULL;

void push(char x){
	Node* t = new Node;
	if (t == NULL)
		cout << "stack overflow\n";
	else 
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

void pop() {
	char x=-1;
	Node* t = top;
	if (t == NULL)
		cout << "stack underflow\n";
	else
	{
		x = t->data;
		top = top->next;
		delete t;

	}
	

}
void Display() {
	Node* p = top;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int peek(char pos) {
	Node* t = top;
	if (top == 0)
		return -1;
	return t->data;
}

int isEmpty() {
	Node* t = top;
	if (t == NULL)
		return 1;
	return 0;
}

int isBalance(char* exp) {
	int size=0,i;
	size = strlen(exp);
	for (i = 0;exp[i]!='\0';i++) {
		if (exp[i] == '(')
			push(exp[i]);
		else if (exp[i] == ')')
		{
			if (isEmpty())
				return 0;
			pop();
		}
	}
	return isEmpty() ? 1 : 0;
}

int main() {
	char s[] = "((a+b)*(a-b))";
	cout << isBalance(s)<<endl;
}