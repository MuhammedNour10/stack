#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
char *convert(char* infix);
bool isOperand(char x);
int pre(char x);
int main() {
	char infix[] = "a+b*c-d/e";
	char* postfix = convert(infix);
	for (int i = 0;postfix[i] != '\0';i++)
		cout << postfix[i] << " ";
}

char *convert(char* infix) {
	stack <char> st;
	char* postfix = new char[strlen(infix) + 1];
	int i=0, j=0;
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