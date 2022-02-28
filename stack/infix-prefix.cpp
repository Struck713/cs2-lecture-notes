
#include "stack.hpp"
#include <iostream>
#include <string>

typedef std::string String;

String infix_to_postfix(const char expr[]) {
    stack<String> S;
    char token;
    String rhs, lhs, op;
    int i = 0;

    while (expr[i] != 0) {
        token = expr[i];
        if (token == ')') {
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(lhs + rhs + op);
        } else if (token != '(') {
            S.push(String(1, token));
        }
        ++i;
    }
    return S.pop();
}

String infix_to_prefix(const char expr[]) {
        stack<String> S;
    char token;
    String rhs, lhs, op;
    int i = 0;

    while (expr[i] != 0) {
        token = expr[i];
        if (token == ')') {
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(op + lhs + rhs);
        } else if (token != '(') {
            S.push(String(1, token));
        }
        ++i;
    }
    return S.pop();
}

bool isOperand(char ch) {
    return ('0' <= ch) && (ch <= '9');
}

int charToInt(char ch) {
    return ch - int('0');
}

int eval(int lhs, char op, int rhs) {
    switch (op) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/': return lhs / rhs;
    }
    return 0;
}

// REQUIRES: valid postfix expression (exp)
int EvalPostfix(const char expr[]) {
    stack<int> S;
    int lhs, rhs;
    int i = 0;
    while (expr[i] != 0) {
        if (isOperand(expr[i])) {
            S.push(charToInt(expr[i]));
        } else {
            rhs = S.pop();
            lhs = S.pop();
            S.push(eval(lhs, expr[i], rhs));
        }
        ++i;
    }
    return S.pop();
}