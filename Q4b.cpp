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

class linkedList {
public:
    node *head;
    linkedList () {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void print() {
        if (!isEmpty()) {
            node *temp = head;
            cout << "Row" << '\t' << "Col" << '\t' << "Data" << endl;
            while (temp!= nullptr) {
                cout << temp -> row << "\t" << temp -> col << "\t" << temp -> data << endl;
                temp = temp -> next;
            }
        } 
        else {
            cout << "List empty" << endl;
        }
    }

    void insert(int row, int col, int val){ //at tail
    node* n=new node(row,col,val);
    n->next=nullptr;
    if(isEmpty()){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
};

int main() {
    linkedList l1,l2;
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            if (A[i][j] != 0) {
                l1.insert(i, j, A[i][j]);
            }
        }
    }
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            if (B[i][j]!= 0) {
                l2.insert(i, j, B[i][j]);
            }
        }
    }
    cout << "Matrix A: "<< endl;
    l1.print();
    cout << "Matrix B: "<< endl;
    l2.print();
}