#include<iostream>
#include<string>
using namespace std;

struct Node {
    int data;
    Node* next;
    //constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push method
    void push(int d) {
        Node* newnode = new Node(d);
        newnode->next = top;
        top = newnode;
    }

    // Pop and return value
    int pop() {
        if (isempty()) {
            cout << "Stack underflow!" << endl;
            return -1; // Return a default value indicating failure
        }
        int popvalue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popvalue;
    }

    // Peek
    int peek() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value indicating failure
        }
        return top->data;
    }

    bool isempty() {
        return top == NULL;
    }
};

bool check(string exp) {
    Stack my;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            my.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (my.isempty()) {
                return false; // No opening parenthesis to match
            } 
            else if ((c == ')' && my.peek() == '(') ||
                       (c == '}' && my.peek() == '{') ||
                       (c == ']' && my.peek() == '[')) {
                my.pop();
            } 
            else {
                return false; // Mismatched parenthesis
            }
        }
    }
    return my.isempty(); // True if stack is empty (all parenthesis matched)
}

int main() {
    string exp;
    cout<<"enter your expression to check Parenthese "<<endl;
    getline(cin,exp);
    if (check(exp)) {
        cout << "Parentheses are balanced" << endl;
    } 
    else {
        cout << "Parentheses are not balanced" << endl;
    }
    return 0;            
}
