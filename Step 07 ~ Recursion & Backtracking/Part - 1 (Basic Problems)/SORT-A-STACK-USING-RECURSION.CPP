#include <bits/stdc++.h>
using namespace std;

// pre-requisite : reverse a stack using recursion
void insertSorted(std::stack<int>& stack, int element) {
    if (stack.empty() || element > stack.top()) {
        stack.push(element);
        return;
    }

    int topElement = stack.top();
    stack.pop();
    insertSorted(stack, element);
    stack.push(topElement);
}

void sortStack(std::stack<int>& stack) {
    if (!stack.empty()) {
        int topElement = stack.top();
        stack.pop();
        sortStack(stack);
        insertSorted(stack, topElement);
    }
}