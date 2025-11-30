#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } 
        else if (val < mini) {
            long long encoded = 2LL * val - mini;  // encode
            st.push(encoded);
            mini = val;
        } 
        else {
            st.push(val);
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        long long top = st.top();
        st.pop();

        if (top < mini) {
            // decode previous minimum
            mini = 2LL * mini - top;
        }
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        long long t = st.top();
        if (t < mini)
            return mini;   // real top
        else
            return t;
    }

    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return mini;
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Top: " << ms.top() << endl;       // 2
    cout << "Min: " << ms.getMin() << endl;    // 2

    ms.pop();   // remove 2

    cout << "Top: " << ms.top() << endl;       // 7
    cout << "Min: " << ms.getMin() << endl;    // 3

    ms.pop();   // remove 7

    cout << "Top: " << ms.top() << endl;       // 3
    cout << "Min: " << ms.getMin() << endl;    // 3

    return 0;
}
