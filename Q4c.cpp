#include <iostream>
using namespace std;

const int rowA = 5, colA = 6;
const int rowB = 6, colB = 5;

int A[rowA][colA] = {
        {0 , 0 , 0 , 0 , 9, 0},
        {0 , 8 , 0 , 0 , 0, 0},
        {4 , 0 , 0 , 2 , 0, 0},
        {0 , 0 , 0 , 0 , 0, 5},
        {0 , 0 , 2 , 0 , 0, 0}
};
int B[rowB][colB] = {
        {0 , 0 , 0 , 2 , 0},
        {0 , 5 , 0 , 8 , 0},
        {0 , 0 , 1 , 0 , 4},
        {0 , 2 , 0 , 0 , 0},
        {1 , 0 , 0 , 1 , 0},
        {0 , 0 , 5 , 0 , 0}
};

class node {
public:
    int row;
    int col;
    int data;
    node *next;

    node (int r,int c, int val) {
        row=r;
        col=c;
        data=val;
    }
};

class LinkedList {
public:
    node *head;

    LinkedList () {
        this -> head = nullptr;
    }

    bool isEmpty() {
        return this -> head == nullptr;
    }

    void print() {
        if (!isEmpty()) {
            node *temp = this -> head;
            cout << "Row" << '\t' << "Col" << '\t' << "Data" << endl;
            while (temp!= nullptr) {
                cout << temp -> row << "\t" << temp -> col << "\t" << temp -> data << endl;
                temp = temp -> next;
            }
        } else {
            cout << "List empty" << endl;
        }
    }

    void insert(int row, int col, int data) {
        node *newNode = new node(row, col, data);
        newNode -> next = this -> head;
        this -> head = newNode;
    }

    void deleteNode(int index) {
        node *temp = this -> head;
        int i = 0;
        while (temp -> next != nullptr && i < index - 1) {
            temp = temp -> next;
            i++;
        }
        temp -> next = temp -> next -> next;
        delete temp -> next;
    }
};

void multiply(LinkedList* mat1, LinkedList* mat2, LinkedList* mat3) {
    if (mat1 -> isEmpty() || mat2 -> isEmpty()) {
        return;
    } else {
        node *tempA = mat1 -> head;
        while (tempA != nullptr) {
            node *tempB = mat2 -> head;
            while (tempB != nullptr) {
                if (tempA -> col == tempB -> row) {
                    mat3 -> insert(tempA -> row, tempB -> col, tempA -> data * tempB -> data);
                }
                tempB = tempB -> next;
            }
            tempA = tempA -> next;
        }
    }

    node *tempC1 = mat3 -> head;
    while (tempC1 != nullptr) {
        int r1 = tempC1 -> row;
        int c1 = tempC1 -> col;
        node *tempC2 = mat3 -> head;
        int i = 0;
        while (tempC2 != nullptr) {
            if (tempC2->col == c1 && tempC2->row == r1) {
                if (tempC2 -> data != tempC1 -> data) {
                    tempC1->data += tempC2->data;
                    mat3 -> deleteNode(i);
                }
            }
            i += 1;
            tempC2 = tempC2->next;
        }
        tempC1 = tempC1 -> next;
    }
}

int main() {
    auto list1 = new LinkedList();
    auto list2 = new LinkedList();
    auto list3 = new LinkedList();

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            if (A[i][j] != 0) {
                list1 -> insert(i, j, A[i][j]);
            }
        }
    }

    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            if (B[i][j]!= 0) {
                list2 -> insert(i, j, B[i][j]);
            }
        }
    }

    multiply(list1, list2, list3);
    list3 -> print();

    return 0;
