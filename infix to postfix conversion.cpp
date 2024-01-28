#include<iostream>
#include<cstring>
using namespace std;

struct stack {
    int size;
    int top;
    char* sz;
};


void push(stack* st, char x) {
    if (st->top == st->size - 1)
        cout << "stack overflow\n";
    else {
        st->top++;
        st->sz[st->top] = x;
    }
}

char pop(stack* st) {
    if (st->top == -1)
        return '\0'; // Return null character to indicate stack underflow or empty
    else {
        char x = st->sz[st->top];
        st->top--;
        return x;
    }
}

char stackTop(stack st) {
    if (st.top == -1)
        return '\0'; // Return null character to indicate empty stack
    return st.sz[st.top];
}

int isEmpty(stack st) {
    return st.top == -1; // Returns 1 if stack is empty, 0 otherwise
}

void Display(stack st) {
    for (int i = st.top; i >= 0; i--)
        cout << st.sz[i] << " ";
    cout << endl;
}

char *conver (char* infix);
int isOprand(char x);
int pre(char x);

int main() {
    char infix[] = "a+b*c-d/e";
    char* postfix = conver(infix);
    for (int i = 0;postfix[i] != '\0';i++)
        cout << postfix[i];

    cout << endl;

    return 0;
}
int isOperand(char x) {
    if (x == '+' or x == '-' or x == '/' or x == '*')
        return 0;
    return 1;
}

int pre(char x) {
    if (x == '+' or x == '-')
        return 1;
    else if (x == '/' or x == '*')
        return 2;
    return 0;
}


char* conver(char* infix) {
    stack st;
    st.size = strlen(infix);
    st.sz = new char[st.size ];
    char *postfix = new char[st.size + 1];
    st.top = -1;

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(stackTop(st)))
                push(&st, infix[i++]);
            else
                postfix[j++] = pop(&st);
        
        }
    }

    while (!isEmpty(st)) {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;

}


