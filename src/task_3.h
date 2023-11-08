/*
 * Author: Abdusamad 
 * Date: 08.11.2023
 * Name: Task 3
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfixExpression(const string& expression) {
    stack<int> st;

    for (char c : expression) {
        if (isdigit(c)) {
            st.push(c - '0');  // Convert the character to an integer
        } else if (c == '+' || c == '-' || c == '*') {
            if (st.size() < 2) {
                // Invalid postfix expression
                cerr << "Invalid postfix expression" << endl;
                return -1;
            }

            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            if (c == '+') {
                st.push(operand1 + operand2);
            } else if (c == '-') {
                st.push(operand1 - operand2);
            } else if (c == '*') {
                st.push(operand1 * operand2);
            }
        }
    }

    if (st.size() == 1) {
        return st.top();
    } else {
        // Invalid postfix expression
        cerr << "Invalid postfix expression" << endl;
        return -1;
    }
}

int main() {
    string expression;
    cin >> expression;

    int result = evaluatePostfixExpression(expression);

    if (result != -1) {
        cout << "Result: " << result << endl;
    } else {
        cout << "Invalid expression" << endl;
    }

    return 0;
}
