#include <iostream>
using namespace std;

class stack_parenthesis_matching {
public:
    // All data members public to avoid uncertain blockages...
    int capacity, top;
    char* arr;

    stack_parenthesis_matching(int size) : capacity(size), top(-1) { // Used initializer list
        arr = new char[capacity];
    }

    ~stack_parenthesis_matching() {
        delete[] arr;
    }

    bool isFULL() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    int STACK_TOP() {
        return arr[capacity - 1];
    }

    int STACK_BOTTOM() {
        return arr[0];
    }

    int push(char val) {
        if (isFULL()) {
            cout << "STACK OVERFLOW\n";
            return -1;
        }
        return arr[++top] = val;
    }

    char pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek(int pos) {
        if (top - pos + 1 < 0) {
            cout << "NOT A VALID POSITION\n";
            return '\0';
        }
        return arr[top - pos + 1];
    }

    bool is_BALANCED(char left, char right) {
        return (left == '(' && right == ')') ||
               (left == '{' && right == '}') ||
               (left == '[' && right == ']');
    }

    bool isBalancedParentheses(const string& s) {
        stack_parenthesis_matching stack(s.length()); // Instance plus use of built-in length function

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.isEmpty() || !is_BALANCED(stack.pop(), c)) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
};

int main() {
    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    stack_parenthesis_matching spm1(test1.length());
    cout << test1 << " : " << (spm1.isBalancedParentheses(test1) ? "Balanced" : "Not Balanced") << endl;

    stack_parenthesis_matching spm2(test2.length());
    cout << test2 << " : " << (spm2.isBalancedParentheses(test2) ? "Balanced" : "Not Balanced") << endl;

    stack_parenthesis_matching spm3(test3.length());
    cout << test3 << " : " << (spm3.isBalancedParentheses(test3) ? "Balanced" : "Not Balanced") << endl;

    stack_parenthesis_matching spm4(test4.length());
    cout << test4 << " : " << (spm4.isBalancedParentheses(test4) ? "Balanced" : "Not Balanced") << endl;

    stack_parenthesis_matching spm5(test5.length());
    cout << test5 << " : " << (spm5.isBalancedParentheses(test5) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
