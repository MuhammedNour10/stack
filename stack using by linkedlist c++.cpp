#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
class stack {
private:
	Node* top;
public:
	stack();
	~stack();
	void push(int x);
	int pop();
	int peek(int pos);
	int isFull();
	int isEmpty();
	int stackTop();
	void Display();

};
 stack::stack() {
	top = NULL;


}

 void stack::push(int x) {
	 Node* temp=new Node;
	 if (temp == NULL)
		 cout << "stack overflow\n";
	 else {
		 temp->data = x;
		 temp->next = top;
		 top = temp;
	 }
 }

 int stack::pop() {
	 int x = -1;
	 Node* p;
	 if (top == NULL)
		 cout << "stack underflow\n";
	 else
	 {
		 p = top;
		 top = top->next;
		 x = p->data;
		 delete p;
	 }

	 return x;
 }

 int stack::peek(int pos) {
	 Node* t=top;
	 int i;
	 for (i = 0;i < pos - 1 && t != NULL;i++)
		 t = t->next;

	 if (t)
		 return t->data;
	 else
		 return -1;
 }

 void stack::Display() {
	 Node *p = top;
	 while (p) {
		 cout << p->data << " ";
		 p = p->next;
	 }
	 cout << "\n";
 }
 stack::~stack() {
	 Node* t = top;
	 while (top) {
		 top = top->next;
		 delete t;
		 t=top;
	 }
 }

 int stack::isEmpty() {
	 return top ? 0 : 1;
 }
 int stack::stackTop() {
	 if (top)
		 return top->data;
	 return -1;

}

int main() {
	stack s;
	s.push(30);
	s.push(20);
	s.push(10);
	//cout << s.pop() << "\n";
	cout << s.peek(1)<<endl;
	cout << s.stackTop() << endl;
	s.Display();
}