#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
//convert infix to postifx
char* convert(char* infix);
//check is char is operand or not
bool isOperand(char x);
//compare between two operator
int pre(char x);

//evalue the postfix
int evaluate(char* postfix);

int main() {
	char infix[] = "3*5+6/2-4";

	char* postfix = convert(infix);
	cout << "postfix expression:";
	for (int i = 0;postfix[i] != '\0';i++)
		cout << postfix[i] << " ";
	cout << endl;
	cout << evaluate(postfix)<<endl;
}

char* convert(char* infix) {
	stack <char> st;
	char* postfix = new char[strlen(infix) + 1];
	int i = 0, j = 0;
	while (infix[i] != '\0') {
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];

		else {
			if (st.empty() or pre(infix[i]) > pre(st.top()))
				st.push(infix[i++]);
			else {
				postfix[j++] = st.top();
				st.pop();
			}
		}

	}
	while (!st.empty()) {
		postfix[j++] = st.top();
		st.pop();
	}
	postfix[j] = '\0';

	return postfix;
}

bool isOperand(char x) {
	if (x == '+' or x == '-' or x == '*' or x == '/')
		return false;
	return true;

}

int pre(char x) {
	if (x == '+' or x == '-')
		return 1;
	else if (x == '*' or x == '/')
		return 2;
	return 0;
}
int evaluate(char* postfix) {
	stack<int> st;
	int i = 0,x1,x2,r;
	while (postfix[i] != '\0') {
		if (isOperand(postfix[i]))
			st.push(postfix[i++]-'0');
		else 
		{
			x2 = st.top();
			st.pop();
			x1 = st.top();
			st.pop();

			switch (postfix[i++]) {
			case '+':
				r = x1 + x2;break;
			case '-':
				r = x1 - x2;break;
			case '*': 
				r = x1 * x2;break;
			case '/':
				r = x1 / x2;break;
			}
			st.push(r);


		}
	}
	st.pop();
	return  r;	
}
