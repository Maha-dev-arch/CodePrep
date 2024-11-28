#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class OwnQueue {
protected:
    stack<int> stackA, stackB;

public:
    OwnQueue(stack<int> stackA, stack<int> stackB) : stackA(stackA), stackB(stackB) {}
    OwnQueue() {}

    void queue(int a) {
        stackA.push(a);
    }
    int dequeueUtil(bool pop) {
        int ret;
        if (stackB.empty()) {
            while (!stackA.empty()) {
                stackB.push(stackA.top());
                stackA.pop();
            }
        }

        if (stackB.empty()) {
            throw out_of_range("Stack is empty");
        }

        ret = stackB.top();
        if (pop)
            stackB.pop();
        return ret;
    }

    void dequeue() {
        dequeueUtil(true);
    }
    int front() {
        return dequeueUtil(false);
    }

    bool isEmpty() {
        if (stackA.empty() && stackB.empty())
            return true;
        else
            return false;
    }
};

//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//
//    OwnQueue qObj;
//    vector<int> vectorRes;
//    int q;
//
//    cin >> q;
//    for (int i = 0; i < q; i++) {
//        int command, num;
//        cin >> command;
//        try {
//            switch (command) {
//            case 1:
//                cin >> num;
//                qObj.queue(num);
//                break;
//            case 2:
//                qObj.dequeue();
//                break;
//            case 3:
//                vectorRes.push_back(qObj.front());
//                break;
//            }
//        }
//        catch (out_of_range e) {
//            cout << e.what();
//        }
//    }
//
//    for (int i = 0; i < vectorRes.size(); i++)
//        cout << vectorRes[i] << endl;
//
//    return 0;
//}
