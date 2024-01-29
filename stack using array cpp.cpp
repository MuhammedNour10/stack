#include<iostream>
using namespace std;
template <class T>
class Stack{
private:
	int size;
	int top;
	T* sz;
public:
	Stack();
	Stack(int size);
	
	void push(T x);
	T pop();
	void Dsiplay();
	T stackTop();
	bool isEmpty();
	bool isFull();


};
template<class T>
Stack<T>::Stack() {
	sz = NULL;
}
template <class T>
Stack<T>::Stack(int size) {
	this->size = size;
	sz = new T[size + 1];
	top = -1;
}
template <class T>
void Stack<T>::push(T x){
	if (top == size)
		cout << "stack overflow\n";
	else {
		top++;
		sz[top] = x;
	}
}
template <class T>
T Stack<T>::pop() {
	T x = -2;
	if (top == -1)
		return x;
	else
	{
		x = sz[top];
		top--;
	}
	return x;
}
template <class T>
void Stack<T>::Dsiplay() {
	int i;
	for (i = top;i >= 0;i--)
		cout << sz[i] << " ";
	cout << "\n";
}
template <class T>
bool Stack<T>::isEmpty() {
	if (top == -1)
		return true;
	return false;
}
template <class T>
bool Stack<T>::isFull() {
	if (top == size - 1)
		return true;
	return false;
}
template <class T>
T Stack<T>::stackTop() {
	if (top == -1)
		return -1;
	return sz[top];
}
int main() {
	Stack<char> st(5);
	st.push('A');
	st.push('B');
	st.push('C');
	cout << st.pop() << endl;
	cout << st.stackTop() << endl;
	st.Dsiplay();

}