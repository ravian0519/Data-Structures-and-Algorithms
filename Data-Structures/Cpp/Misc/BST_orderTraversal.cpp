#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	
	Node(int D){
		data = D;
	}
	
	~Node(){
		cout<<"Node is deleted"<<endl;
	}
};

class BST{
	public:
		Node* head = NULL;
		
		BST(int s){
			if (s>0){
				cout<<"Enter the head value: ";
				int h;
				cin>>h;
				head = new Node(h);
				Node* first = head;
				for(int i=1; i<s; i++){
					cout<<"Enter the node's Data: ";
					int d;
					cin>>d;
					insertNode(d);
				}
			}
		}
		
		~BST(void){
			cout<<"BST is Deleted"<<endl;
			while(head!=NULL){
				deleteNode(head->data);
			}
		}
		
		bool isNull(){
			return head==NULL;
		}
		
		bool find(int n){
			Node *first = head;
			while(first!=NULL){
				if(first->data == n){
					return true;
				}
				else if(first->data>n){
					first = first->right;
				}
				else{
					first = first->left;
				}
			}
			return false;
		}
		
		Node* findMin(){
			if(head==NULL){
				return NULL;
			}
			Node* first = head;
			while(first->left!=NULL){
				first = first->left;
			}
			return first;
		}
		Node* findMax(){
			if(head==NULL){
				return NULL;
			}
			Node* first = head;
			while(first->right!=NULL){
				first = first->right;
			}
			return first;
		}
		Node* findMin(Node* start){
			Node* first = start;
			while(first->left!=NULL){
				first = first->left;
			}
			return first;
		}
		Node* findMax(Node* start){
			Node* first = start;
			while(first->right!=NULL){
				first = first->right;
			}
			return first;
		}
		
		void insertNode(int d){
			Node* first = head;
			Node* p = NULL;
			while(first!=NULL){
				p = first;
				if(first->data>d){
					first = first->left;
				}else if(first->data<d){
					first = first->right;
				}else{
					cout<<"Node Already Exists!!!"<<endl;
					return;
				}
			}
			first = new Node(d);
			if(p!=NULL){
				first->parent = p;
			}
		}
		
		
		void deleteNodeCase2(Node* first){
			if(first->parent==NULL){
				if(first->left==NULL){
					head = first->right;
					delete first;
				}else if(first->right==NULL){
					head = first->left;
					delete first;
				}
			}else if(first->left==NULL){
				if(first->parent->left->data==first->data){
					Node* sec = first->right;
					first->parent->left = sec;
					delete first;
				}else{
					Node* sec = first->right;
					first->parent->right = sec;
					delete first;
				}
			}else{
				if(first->parent->left->data==first->data){
					Node* sec = first->left;
					first->parent->left = sec;
					delete first;
				}else{
					Node* sec = first->left;
					first->parent->right = sec;
					delete first;
				}
			}
		}
		
		void deleteNodeCase3(Node* first){
			Node* TBR = findMin(first->right);
			int temp = TBR->data;
			deleteNode(TBR->data);
			first->data = temp;
		}
		
		void deleteNode(int d){
			Node* first = head;
			while(first!=NULL){
				if(first->data>d){
					first = first->left;
				}else if(first->data<d){
					first = first->right;
				}else{
					if(first->left==NULL&&first->right==NULL){
						delete first;
					}else if(first->left==NULL||first->right==NULL){
						deleteNodeCase2(first);
					}else{
						deleteNodeCase3(first);
					}
				}
			}
		}
		
		void preOrderTraversal(Node* node){
			if (node == NULL){
		        return;
			}
		    cout<<(node->data);
		    preOrderTraversal(node->left);
		    preOrderTraversal(node->right);
		}
		void postOrderTraversal(Node* node){
			if (node == NULL){
		        return;
			}
		    postOrderTraversal(node->left);
		    postOrderTraversal(node->right);
		    cout<<(node->data);
		}
		void inOrderTraversal (Node* node){
			if (node == NULL){
		        return;
			}
		    inOrderTraversal(node->left);
		    cout<<(node->data);
		    inOrderTraversal(node->right);
		}
		
};



void Q1(){
	cout<<"Enter the length of the BST: ";
	int s;
	cin>> s;
	BST* A = new BST(s);
	cout<<"IsNull: "<<A->isNull()<<endl;
	
	A->inOrderTraversal(A->head);
	A->preOrderTraversal(A->head);
	A->postOrderTraversal(A->head);
//	cout<<"Enter the integer you want to find in BST: ";
//	int f;
//	cin>>f;
//	if(A->find(f)){
//		cout<<"The number lies in the BST..."<<endl;
//	}
//	else{
//		cout<<"The number is not found in the BST..."<<endl;
//	}
	
//	cout<<"Enter the Value to add in the BST: ";
//	int as;
//	cin>> as;
//	A->insertNode(as);

//	cout<<"Enter number to del from the BST: ";
//	int d;
//	cin>>d;
//	A->deleteNode(d);
}

int main(){
	Q1();
}
