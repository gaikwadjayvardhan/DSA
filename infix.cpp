#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string out = "";

    for (char c : s) {
        if (isalnum(c)) {          // operand
            out += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                out += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else { // operator
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                out += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        out += st.top();
        st.pop();
    }
    return out;
}

int main() {
    string infix;
    cout << "Enter infix: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix) << "\n";
}
