#include <iostream>
#include <cstring>
#include <cctype> // For tolower function

using namespace std;

char stack[30];
int top = -1, len;

void push(char ele) {
    if (top == len - 1) {
        cout << "STACK OVERFLOW\n";
    } else {
        top++;
        stack[top] = ele;
    }
}

char pop() {
    if (top == -1) {
        cout << "STACK UNDERFLOW\n";
        return '\0'; 
    } else {
        char ele = stack[top];
        top--;
        return ele;
    }
}

int Palindrome(char str[]) {
    int actualLen = 0;

    
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            push(tolower(str[i]));
            actualLen++;
        }
    }

    
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            if (tolower(str[i]) != pop()) {
                return 0; 
            }
        }
    }

    return 1; 
}


void reverseString(char str[]) {
    cout << "Reversed string: ";
    for (int i = len - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}

int main() {
    char m[30];
    cout << "Enter string to check: ";
    cin.getline(m, 30);

    len = strlen(m);

    
    reverseString(m);

    if (Palindrome(m)) {
        cout << "String is a palindrome\n";
    } else {
        cout << "String is not a palindrome\n";
    }

    return 0;
}