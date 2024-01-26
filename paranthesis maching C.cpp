#include <iostream>
#include <cstring> // for strlen
using namespace std;

struct Stack {
    int size;
    int top;
    char* s;
};
void Display(Stack st){
    int i;
    for (i = st.top;i >= 0;i--)
        cout << st.s[i] << " ";
}
void push(Stack* st, char x);
void pop(Stack* st);
int isEmpty(Stack st);
int isBalance(char* exp);

int main() {
    char exp[] = "((a+b)*(c-d)))";
    cout << "check: " << isBalance(exp) << endl;
    
    return 0;
}

int isBalance(char* exp) {
    Stack st;
    st.size = strlen(exp);
    st.s = new char[st.size];
    st.top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(&st, exp[i]);
        else if (exp[i] == ')') {
            if (isEmpty(st)) {
                delete[] st.s; // Free allocated memory
                return false;
            }
            pop(&st);
        }
    }
    delete[] st.s; // Free allocated memory
    return isEmpty(st) ? true : false;
}

void push(Stack* st, char x) {
    if (st->top == st->size - 1)
        cout << "stack overflow\n";
    st->top++;
    st->s[st->top] = x;
}

void pop(Stack* st) {
    if (st->top == -1)
        cout << "stack underflow\n";
    else
        st->top--;
}

int isEmpty(Stack st) {
    return st.top == -1 ? 1 : 0;
}
