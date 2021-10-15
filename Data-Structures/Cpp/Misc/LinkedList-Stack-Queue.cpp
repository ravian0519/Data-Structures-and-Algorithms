#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* Next;
	
	~Node(){
		cout<<"Node is deleted"<<endl;
	}
};

class linkedlist{
	public:
		Node* head = NULL;
		
		linkedlist(int s){
			if (s>0){
				head = new Node();
				cout<<"Enter the head value: ";
				cin>>head->data;
				Node* first = head;
				for(int i=1; i<s; i++){
					Node* second = new Node();
					first->Next = second;
					first = second;
					cout<<"Enter the node's Data: ";
					cin>>first->data;
				}
			}
		}
		
		~linkedlist(void){
			while(!isNull()){
			    deleteFromStart();
			}
			cout<<"LinkedList is Deleted"<<endl;
		}
		
		bool isNull(){
			return head==NULL;
		}
		
		void print(){
			Node *first = head;
			while(first!=NULL){
				cout<<first->data<<"->";
				first = first->Next;
			}
			cout<<"Null"<<endl;
		}
		
		bool find(int n){
			Node *first = head;
			while(first!=NULL){
				if(first->data == n){
					return true;
				}
				first = first->Next;
			}
			return false;
		}
		
		void insertAtHead(int d){
			Node* added = new Node();
			added->Next = head;
			head = added;
			head->data = d;
		}
		
		void insertAtEnd(int d){
			if(head!=NULL){
				Node *first = head;
				while(first->Next!=NULL){
					first = first->Next;
				}
				Node* added = new Node();
				first->Next = added;
				added->data = d;
			}else{
				head = new Node();
				head->data = d;
			}
		}
		
		void insertNode(int ind, int d){
			if(ind==0){
				insertAtHead(d);
			}else{
				Node *first = head;
				Node *second;
				for(int i=0; i<ind; i++){
					second = first;
					first = first->Next;
				}
				Node* added = new Node();
				added->data = d;
				added->Next = second->Next;
				second->Next = added;
			}
		}
		
		void deleteFromStart(){
			if(head!=NULL){
				Node* d = head;
				head = head->Next;
				delete d;
			}
		}
		
		void deleteFromEnd(){
			if(head!=NULL){
				Node *first = head;
				Node* second = NULL;
				while(first->Next!=NULL){
					second = first;
					first = first->Next;
				}
				if(second!=NULL){
					Node* ToDel = second->Next;
					second->Next = NULL;
					delete ToDel;
				}else{
					head=NULL;
				}
			}
		}
		
		void deleteNode(int d){
			Node*  first = head;
			int flag = 1;
			while(first->Next!=NULL){
				flag = 1;
				if(first->Next->data==d){
					Node* ToDel = first->Next;
					first->Next = first->Next->Next;
					delete ToDel;
					flag = 0;
				}
				if(first->Next!=NULL&&flag){
					first = first->Next;
				}
				
			}
			if(head->data==d){
				deleteFromStart();
			}
		}
		
		void merge(linkedlist* l){
			Node *first = head;
			while(first->Next!=NULL){
				first = first->Next;
			}
			first->Next = l->head;
		}
		
		linkedlist* remDub(){
			linkedlist* aa = new linkedlist(0);
			if(head!=NULL){
				int flag = 0;
				aa->head = new Node();
				aa->head->data = head->data;
				Node *first = head->Next;
				while(first!=NULL){
					flag=0;
					Node* f = aa->head;
					while(f!=NULL){
						if(f->data==first->data){
							flag = 1;
							break;
						}
						f = f->Next;
					}
					if(!flag){
						aa->insertAtEnd(first->data);
					}
					first = first->Next;
				}
			}
			return aa;
		}
		
		linkedlist* intersection(linkedlist* l){
			linkedlist* aa = new linkedlist(0);
			if(head!=NULL||l->head!=NULL){
				int flag = 0;
				
				Node *first = head;
				while(first!=NULL){
					flag=0;
					Node* f = l->head;
					while(f!=NULL){
						if(f->data==first->data){
							flag = 1;
							break;
						}
						f = f->Next;
					}
					if(flag){
						aa->insertAtEnd(first->data);
					}
					first = first->Next;
				}
			}
			return aa;
		}
		
		void reverse(){
			if(head!=NULL&&head->Next!=NULL){
				Node* first = NULL;
				Node* second = head;
				Node* third = second->Next;
				while(third!=NULL){
					second->Next = first;
					first = second;
					second = third;
					third = second->Next;
				}
				second->Next = first;
				head = second;
			}
		}
		
		void Sort(){
			if(head!=NULL&&head->Next!=NULL){
				Node* first = head;
				Node* second;
				for(first; first!=NULL; first=first->Next){
					for(second = first->Next; second!=NULL; second=second->Next){
						if(first->data>second->data){
							int temp = first->data;
							first->data = second->data;
							second->data = temp;
						}
					}
				}
			}
		}
};

class stackList{
	
	int size;
	int top = -1;
	int* arr;
	
	public:
		
		stackList(int n){
			size = n;
			arr = new int[size];
		}
		
		void push(int x){
			if(top==size-1){
				cout<<"Stack is full!!!"<<endl;
				return;
			}
			top++;
			arr[top]=x;
		}
		
		void pop(){
			if(!isEmpty()){
				top--;
			}else{
				cout<<"Pop: Stack is already Empty"<<endl;
			}
		}
		
		
		int Top(){
			if(!isEmpty()){
				return arr[top];
			}
			cout<<"Top: Stack is Empty!!!"<<endl;
			return 0;
		}
		
		bool isEmpty(){
			return top==-1;
		}
};

class stackLinkedList{
	
	int flag = 0;
	int top;
	linkedlist* arr;
	
	public:
		
		stackLinkedList(int n){
			arr = new linkedlist(n);
		}
		
		void push(int x){
			arr->insertAtEnd(x);
			top = x;
			flag = 1;
		}
		
		void pop(){
			if(!arr->isNull()){
				arr->deleteFromEnd();
			}else{
				cout<<"Pop: Stack is already Empty!!!"<<endl;
			}
			flag = 0;
		}
		
		int Top(){
			arr->print();
			if(flag){
				return top;
			}
			if(!arr->isNull()){
				Node* first = arr->head;
				while(first->Next!=NULL){
					first=first->Next;
				}
				top = first->data;
				flag = 1;
				return top;
			}else{
				cout<<"Top: Stack is Empty"<<endl;
				return 0;
			}
		}
		
		bool isEmpty(){
			return arr->head==NULL;
		}
};

class QueueList{
	
	int size;
	int front=-1;
	int back=-1;
	int* arr;
	
	public:
		QueueList(int n){
			
			size = n;
			arr = new int[n];
		}
		
		void EnQueue(int x){
			if(isFull()){
				cout<<"Queue is OverFlowed!!!"<<endl;
				return;
			}
			back++;
			arr[back]=x;
			
			if(front==-1){
				front++;
			}
		}
		
		void deQueue(){
			if(isEmpty()){
				cout<<"DeQueue: Queue is Empty"<<endl;
				return;
			}
			front++;
		}
		
		int peek(){
			if(isEmpty()){
				cout<<"Peek: Queue is Empty"<<endl;
				return 0;
			}
			return arr[front];
		}
		
		bool isFull(){
			return back==size-1;
		}
		
		bool isEmpty(){
			return front==-1||front>back;
		}
};

class QueueLinkedList{
	
	int size;
	int front=-1;
	int back=-1;
	linkedlist* arr;
	
	public:
		QueueLinkedList(int n){
			arr = new linkedlist(n);
		}
		
		void EnQueue(int x){
			arr->insertAtEnd(x);
		}
		
		void deQueue(){
			if(isEmpty()){
				cout<<"DeQueue: Queue is Empty"<<endl;
				return;
			}
			arr->deleteFromStart();
		}
		
		int peek(){
			if(isEmpty()){
				cout<<"Peek: Queue is Empty"<<endl;
				return 0;
			}
			return arr->head->data;
		}
		
		bool isFull(){
			return false;
		}
		
		bool isEmpty(){
			return arr->isNull();
		}
};


void Q1(){
	cout<<"Enter the length of the linkedlist: ";
	int s;
	cin>> s;
	linkedlist* A = new linkedlist(s);
	cout<<"IsNull: "<<A->isNull()<<endl;
	A->print();
	
	cout<<"Enter the integer you want to find in linkedList: ";
	int f;
	cin>>f;
	if(A->find(f)){
		cout<<"The number lies in the linkedList..."<<endl;
	}
	else{
		cout<<"The number is not found in the linkedList..."<<endl;
	}
	
	cout<<"Enter the Value to add in the start of the linkedList: ";
	int as;
	cin>> as;
	A->insertAtHead(as);
	
	A->print();
	
	cout<<"Enter the Value to add in the end of the linkedList: ";
	int ae;
	cin>> ae;
	A->insertAtEnd(ae);
	
	A->print();
	
	int ind, ac;
	cout<<"Enter the Value to add in the required index of the linkedList: ";
	cin>> ac;
	cout<<"Enter the index to add value in the linkedList: ";
	cin>>ind;
	A->insertNode(ind, ac);
	
	A->print();
	
	cout<<"Deleting From Start"<<endl;
	A->deleteFromStart();
	A->print();
	cout<<"Deleting From End"<<endl;
	A->deleteFromEnd();
	A->print();
	
	cout<<"Enter number to del from all the list: ";
	int d;
	cin>>d;
	A->deleteNode(d);
	A->print();
	
	cout<<"removing Duplicates"<<endl;
	A = A->remDub();
	A->print();
	
	cout<<"Reverese: ";
	A->reverse();
	A->print();
	
	cout<<"Sorted: ";
	A->Sort();
	A->print();
	
	cout<<endl<<"Make a new LinkedList for interaction!!!"<<endl;
	cout<<"Enter the length of the linkedlist: ";
	int ns;
	cin>> ns;
	linkedlist* B = new linkedlist(ns);
	linkedlist* C = A->intersection(B);
	cout<<"Intersection: ";
	C->print();
	
	cout<<"Merging the Lists..."<<endl;
	A->merge(B);
	A->print();
	
	delete A;
	delete B;
	delete C;
}

void Q2aa(){
    cout<<"Making stacklist of size 10"<<endl;
	stackList* B = new stackList(10);
	cout<<"Pushing 10 in stack"<<endl;
	B->push(10);
	cout<<"Fetching the top of stack"<<endl;
	cout<<B->Top()<<endl<<endl;
	cout<<"Popping..."<<endl;
	B->pop();
	cout<<B->Top()<<endl<<endl;
	cout<<"Pushing 3 in stack"<<endl;
	B->push(3);
	cout<<"Fetching the top of stack"<<endl;
	cout<<B->Top()<<endl<<endl;
	delete B;
}

void Q2ab(){
	stackLinkedList* A = new stackLinkedList(3);
	cout<<A->Top()<<endl;
	cout<<"Popping..."<<endl;
	A->pop();
	cout<<"Fetching the top of stack"<<endl;
	cout<<A->Top()<<endl;
	cout<<"Pushing 3 in stack"<<endl;
	A->push(3);
	cout<<"Fetching the top of stack"<<endl;
	cout<<A->Top()<<endl;
	delete A;
}

void Q2ba(){
    cout<<"Making Queuelist of size 10"<<endl;
	QueueList* A = new QueueList(10);
    cout<<"Enqueue 10 in stacklist..."<<endl;
	A->EnQueue(10);
    cout<<"Peeking in stacklist..."<<endl;
	cout<<A->peek()<<endl<<endl;
    cout<<"Dequeuing the stacklist..."<<endl;
	A->deQueue();
    cout<<"Peeking in stacklist..."<<endl;
	cout<<A->peek()<<endl<<endl;
    cout<<"Dequeuing the stacklist..."<<endl;
	A->deQueue();
    cout<<"Enqueue 11 in stacklist..."<<endl;
	A->EnQueue(11);
    cout<<"Peeking in stacklist..."<<endl;
	cout<<A->peek()<<endl<<endl;
	delete A;
}

void Q2bb(){
	QueueLinkedList* A = new QueueLinkedList(10);
    cout<<"Enqueue 10 in stacklist..."<<endl;
	A->EnQueue(10);
    cout<<"Peeking in stacklist..."<<endl;
	cout<<A->peek()<<endl<<endl;
    cout<<"Dequeuing the stacklist..."<<endl;
	A->deQueue();
    cout<<"Peeking in stacklist..."<<endl;
	cout<<A->peek()<<endl<<endl;
    cout<<"Dequeuing the stacklist..."<<endl;
	A->deQueue();
    cout<<"Enqueue 11 in stacklist..."<<endl;
	A->EnQueue(11);
    cout<<"Peeking in stacklist..."<<endl;
	cout<<A->peek()<<endl<<endl;
	delete A;
}

int main(){
	Q1();
	
	cout<<endl<<endl<<"Stack with List"<<endl<<endl;
	Q2aa();
	
	cout<<endl<<endl<<"Stack with LinkedList"<<endl<<endl;
	Q2ab();
	
	cout<<endl<<endl<<"Queue with List"<<endl<<endl;
	Q2ba();
	
	cout<<endl<<endl<<"Queue with LinkedList"<<endl<<endl;
	Q2bb();
}
