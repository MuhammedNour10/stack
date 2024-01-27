#include<iostream>
#include<stack>
#include<map>
using namespace std;

int isBalance(char* exp);
int main() {
	char A[] = "{([a+b)*[a+b])}";
	if (isBalance(A))
		cout << "Balanced\n";
	else
		cout << "Unbalanced\n";

}

int isBalance(char* exp) {
	int i;
	//create stack
	stack<char> st;
	//create map
	map<char, char> mapping;
 // Declare an iterator for the map
	map<char, char>::iterator itr;
	mapping['}'] = '{';
	mapping[')'] = '(';
	mapping[']'] = '[';

	for (i = 0;exp[i] != '\0';i++) {
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
			st.push(exp[i]);
		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if (st.empty()) return 0;

			char temp = st.top();
			itr = mapping.find(exp[i]);
			if (itr->second == temp) st.pop();

		}
           
	}
	return st.empty() ? 1 : 0;
}
