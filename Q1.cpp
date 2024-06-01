#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;

    node(int data){
        this ->data = data;
        this ->next = NULL;
    }
};

class Stack{
    private:
    node* top;
    
    public:
    Stack(){
        top  = NULL;
    }
    //push method
    void push(int d){
        node *newnode = new node(d);
        newnode->next = top;
        top = newnode;
    }
    // pop method
    int pop(){
        if(isempty()){
            cout<<"stack underflow "<<endl;
            return -1;
        }
        int popval = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        return popval;
    }
    bool isempty(){
        return top == NULL;
    }
    node* getTop() const {
        return top;
    }

};
void printStack(Stack& s, const string& label) {
    cout << label << ": ";
    for (node* i = s.getTop(); i != nullptr; i = i->next)
        cout << i->data << " ";
    cout << endl;
}


void towerofhanoi(int d, Stack &s,Stack &des,Stack &a){
    if(d==1){
        des.push(s.pop());
        printStack(s, "Source");
        printStack(a, "Auxiliary");
        printStack(des, "Destination");
        cout << endl;
    }
    else{
        towerofhanoi(d-1,s,a,des);
        des.push(s.pop());
        printStack(s, "Source");
        printStack(a, "Auxiliary");
        printStack(des, "Destination");
        cout << endl;
        towerofhanoi(d-1,a,des,s);
    }

}


int main()
{
    Stack source,destination,auxilary;
    int n;
    cout<<"enter number of disks"<<endl;
    cin>>n;
    for (int i = n; i>0; i--) {
        source.push(i);
    }
    cout << "Initial configuration:" << endl;
    printStack(source, "Source");
    printStack(auxilary, "Auxiliary");
    printStack(destination, "Destination");
    cout << endl;

    towerofhanoi(n,source,destination,auxilary);

   return 0;
}
