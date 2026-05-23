#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (st.size() < 2) {
                    cerr << "Error: Not enough operands in the stack for operation " << token << endl;
                    return 0; // Return a default or error value
                }
                
                int a1 = st.top();
                st.pop();
                int a2 = st.top();
                st.pop();
                
                if (token == "+") {
                    st.push(a2 + a1);
                    cout << a2 << "+" << a1 << endl;
                } else if (token == "-") {
                    st.push(a2 - a1);
                    cout << a2 << "-" << a1 << endl;
                } else if (token == "*") {
                    st.push(a2 * a1);
                    cout << a2 << "*" << a1 << endl;
                } else if (token == "/") {
                    if (a1 == 0) {
                        cerr << "Error: Division by zero" << endl;
                        return 0; // Return a default or error value
                    }
                    st.push(a2 / a1);
                    cout << a2 << "/" << a1 << endl;
                }
            } else {
                try {
                    st.push(stoi(token));
                } catch (const invalid_argument& e) {
                    cerr << "Error: Invalid number format " << token << endl;
                    return 0; // Return a default or error value
                }
            }
        }
        
        if (st.size() != 1) {
            cerr << "Error: The stack does not contain exactly one element after processing all tokens" << endl;
            return 0; // Return a default or error value
        }
        
        return st.top();
    }
};
