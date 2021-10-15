#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Linkedlist {
    public:
        Linkedlist() {
            head = NULL;
        }

        ~Linkedlist() { 
        };

        void insertNode(int index, int val) {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = NULL;
            Node* currptr = head;
            Node* nextptr;
            if (index==0)
            {
                newNode->next = currptr;
                head = newNode;
                return;
            }
            
            for (int i = 1; i != index; i++)
            {
                currptr = currptr->next;
            }
            nextptr = currptr->next;
            currptr->next = newNode;
            newNode->next = nextptr;
        }

        void insertAtHead(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            Node* ptr = head;
            newNode->next = ptr;
            head = newNode;
        }

        void insertAtEnd(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            if (head == NULL)
            {
                head = newNode;
                return;
            }            
            Node* ptr = head;
            while(ptr->next!=NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }

        bool findNode(int x) {
            Node* ptr = head;
            while (ptr!=NULL)
            {
                if (ptr->data==x)
                {
                    return true;
                }
                ptr = ptr->next;
            }
            return false;
        }

        bool deleteNode(int x) {
            Node* currptr = head;

            if (currptr->data==x)
            {
                head = currptr->next;
                return true;
            }
            
            while (currptr!=NULL)
            {
                if (currptr->next->data==x)
                {
                    currptr->next = currptr->next->next;
                    return true;
                }
                currptr = currptr->next;
            }
            return false;
        }

        bool deleteFromStart() {
            Node* ptr = head;
            if (head!=NULL)
            {
                head = ptr->next;
                return true;
            }
            return false;
        }

        bool deleteFromEnd() {
            Node* ptr = head;
            while (ptr!=NULL)
            {
                if (ptr->next->next==NULL)
                {
                    ptr->next = NULL;
                    return true;
                }
                ptr = ptr->next;
            }
            return false;
        }

        void displayList() {

            if (head == NULL)
            {
                cout<<"NULL"<<endl;
                return;
            }
            
            Node* ptr = head;
            while (ptr!=NULL)
            {
                cout<<ptr->data<<"->";
                ptr = ptr->next;
            }
            cout<<"NULL"<<endl;
            
        }

        void reverseList() {

            Node* prevptr = NULL;
            Node* currptr = head;
            Node* nextptr;

            while (currptr!=NULL)
            {
                nextptr = currptr->next;
                currptr->next = prevptr;

                prevptr = currptr;
                currptr = nextptr;
            }
            head = prevptr;
        }

        bool isEmpty() {
            if (head==NULL)
            {
                return true;
            }
            return false;
        }

    private:
        Node* head;
};

int main() {

    cout<<"------------------------"<<endl;

    Linkedlist* ll = new Linkedlist();

    cout<<"is Linked list Empty: "<<ll->isEmpty()<<endl;
    ll->insertAtEnd(5);
    ll->insertAtEnd(12);
    ll->insertAtEnd(14);
    ll->insertAtEnd(72);
    ll->displayList();
    cout<<"is Linked list Empty: "<<ll->isEmpty()<<endl;

    ll->insertAtHead(4);
    ll->insertAtHead(3);
    ll->insertAtHead(2);
    ll->insertAtHead(1);
    ll->displayList();
    ll->insertNode(2,45);
    ll->displayList();

    ll->reverseList();
    ll->displayList();
    cout<<"Finding Node data "<<5<<": "<<ll->findNode(5)<<endl;
    cout<<"Finding Node data "<<7<<": "<<ll->findNode(7)<<endl;
    cout<<"Finding Node data "<<32<<": "<<ll->findNode(32)<<endl;
    cout<<"Finding Node data "<<45<<": "<<ll->findNode(45)<<endl;

    ll->displayList();
    ll->deleteNode(45);
    ll->deleteNode(72);
    ll->deleteFromStart();
    ll->deleteFromEnd();
    ll->displayList();


    delete ll;

    cout<<"------------------------"<<endl;

    return 0;
}