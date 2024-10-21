#include <iostream>
#include <stack>
using namespace std;

int AckermannNonRecursive(int m, int n) {
    stack<int> s;
    s.push(m);
    while (!s.empty()) {
        m = s.top();
        s.pop();
        if (m == 0) n = n + 1;
        else if (n == 0) {
            s.push(m - 1);
            n = 1;
        }else {
            s.push(m - 1);
            s.push(m);
            n = n - 1;
        }
    }
    return n;
}

int Ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;;
    }
    else if (n == 0) {
        return Ackermann(m - 1, 1);
    }
    else {
        return  Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

int main(void) {
    int m, n;
    while (true)
    {
        cout << "¿é¤J­È(m,n)¡G";
        cin >> m >> n;
        cout << Ackermann(m,n) << endl;//»¼°j
        cout << AckermannNonRecursive(m, n) << endl;//«D»¼°j
    }
}