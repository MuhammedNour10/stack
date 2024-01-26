#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	void push(int x);
	int  pop();
	int peek(int pos);
	void Diplay();

} *top=NULL;

void Node::push(int x) {
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
int Node::pop(){
	Node* t;
	int x = -1;
	if (top == NULL)
		cout << "stack underflow\n";
	else {
		t = top;
		x = t->data;
		top = top->next;
		delete t;
	}
	return x;

}
int Node::peek(int pos) {
	Node* t=top;
	int i;
	for (i = 0;i < pos - 1 && t != NULL;i++)
		t = t->next;
	if (t)
		return t->data;
	else
		return -1;

}
void Node::Diplay() {
	Node* p = top;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	Node n;
	n.push(30);
	n.push(20);
	n.push(10);
	cout << n.pop() << "\n";
	n.Diplay();
}