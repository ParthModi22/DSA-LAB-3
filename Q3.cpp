#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this ->data=data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Doublylink{
    private:
    Node* head;
    Node* tail;

    public:
    Doublylink(){
        head = NULL;
        tail = NULL;
    }

    // code to insert at end
    void insert(int val){
        Node * nn = new Node(val);
        if(head ==NULL || head->next==NULL){
            head = tail = nn;
        }
        else{
            tail ->next = nn;
            nn ->prev = tail;
            tail = nn;
        }
    }
    // implement insertion sort
    void  insertionsort(){
        if( head ==NULL){
            return;
        }
        Node* curr = head->next;
        while(curr != NULL){
            int key = curr->data;
            Node* prevnode = curr ->prev;
            while(prevnode != NULL && prevnode->data > key){
                prevnode ->next->data = prevnode->data;
                prevnode = prevnode->prev;
            }
            if (prevnode == nullptr){
                head->data = key;
            }
            else{
            prevnode->next->data = key;
            curr = curr->next;
            }
        }
    }
    void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
        cout << endl;
    }

};

int main()
{
    Doublylink dll;
    int n,val;
    cout<<"enter number of elements "<<endl;
    cin>>n;
    cout<<"enter the elements "<<endl;
    for(int i=0;i<n;i++){
        cin>>val;
        dll.insert(val);
    }
    cout << "Original list: ";
    dll.display();

    // Perform insertion sort
    dll.insertionsort();

    cout << "Sorted list: ";
    dll.display();
   return 0;
}