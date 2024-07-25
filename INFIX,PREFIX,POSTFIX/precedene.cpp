#include <iostream>
#include <cstring>
using namespace std;

class INFIX_TO_POSTFIX {
public:
    // All data members public to avoid uncertain blockages...
    int capacity, top;
    char* arr;

   //constructor :
   INFIX_TO_POSTFIX(int size) : capacity(size), top(-1) { // Used initializer list
        arr = new char[capacity];
    }

    ~INFIX_TO_POSTFIX() {//destructor:
        delete[] arr;
    }

    bool isFULL() {
        return top == capacity - 1;//full checks:
    }

    bool isEmpty() {
        return top == -1;//empty checks
    }

    char STACK_TOP() {
        return arr[top];//returns the top of the stack
    }

    char STACK_BOTTOM() {
        return arr[0];//returns the bottom of the stack
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
        INFIX_TO_POSTFIX stack(s.length()); // Instance plus use of built-in length function

        for (char c : s) {// for loop then assings c=s[i]
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

    bool isOperator(char c) {
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
                return true;
            default:
                return false;
        }
    }

    int precedence(char op) {//checking the precedence of the operators
    //precedence sheet is also attached in the folder 
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
            case '%':
                return 2;
            case '^':
                return 3;
            default:
                return 0; // Return 0 for non-operators
        }
    }

    char* infix_to_postfix(const char* arr) {//bingo function to convert the game
        INFIX_TO_POSTFIX stack(strlen(arr) + 1); // Create a stack with appropriate size
        char* temp = new char[strlen(arr) + 1];//temp char array
        int i = 0; // Track the traversal of infix arr
        int j = 0; // Track and operate the traverse in postfix arr

        while (arr[i] != '\0') {
            if (isalnum(arr[i])) {
                temp[j++] = arr[i++];
            } else if (arr[i] == '(') {
                stack.push(arr[i++]);
            } else if (arr[i] == ')') {
                while (!stack.isEmpty() && stack.STACK_TOP() != '(') {
                    temp[j++] = stack.pop();
                }
                stack.pop(); // pop '('
                i++;
            } else if (isOperator(arr[i])) {
                while (!stack.isEmpty() && precedence(stack.STACK_TOP()) >= precedence(arr[i])) {
                    temp[j++] = stack.pop();
                }
                stack.push(arr[i++]);
            }
        }

        while (!stack.isEmpty()) {
            temp[j++] = stack.pop();
        }

        temp[j] = '\0';
        return temp;
    }
};

int main() {
    INFIX_TO_POSTFIX converter(100);
    const char* infixExpression = "(m-n)*(p+q)";
    char* postfixExpression = converter.infix_to_postfix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    delete[] postfixExpression;

    return 0;
}
