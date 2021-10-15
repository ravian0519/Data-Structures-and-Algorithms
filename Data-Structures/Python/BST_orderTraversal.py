class Node:
    def __init__(self, d):
        self.data = d
        self.left = None
        self.right = None
        self.parent = None
	
    def __del__(self):
        print("Node is deleted")
	


class BST:
    head = None
    
    def __init__(self, s):
    # BST(int s):
        if s>0:
            self.head = Node(int(input("Enter the head value: ")))
            first = self.head
            for i in range(1, s):
            # for(int i=1 i<s i++):
                # print(
                # int d
                # cin>>d
                self.insertNode(int(input("Enter the node's Data: ")))
            
        
    
    
    def __del__(self):
        print("BST is Deleted")
        
    def isNull(self):
        return self.head==None
    
    
    def find(self, n):
        first = self.head
        while first!=None:
            if first.data == n:
                return True
            
            elif first.data>n:
                first = first.right
            
            else:
                first = first.left
            
        
        return False
    
    def findMin(self, start=head):
        first = start
        while first.left!=None:
            first = first.left
        
        return first
    
    def findMax(self, start=head):
        first = start
        while first.right!=None:
            first = first.right
        
        return first
    
    
    def insertNode(self, d):
        first = self.head
        p = None
        while first!=None:
            p = first
            if first.data>d:
                first = first.left
            elif first.data<d:
                first = first.right
            else:
                print("Node Already Exists!!!")
                return
        first = Node(d)
        if p!=None:
            first.parent = p
            if d<p.data:
                p.left = first
            else:
                p.right = first
        else:
            self.head = first
        
    def deleteNodeCase2(self, first):
        if first.parent==None:
            if first.left==None:
                self.head = first.right
                del first
            elif first.right==None:
                self.head = first.left
                del first
            
        elif first.left==None:
            if first.parent.left.data==first.data:
                sec = first.right
                first.parent.left = sec
                del first
            else:
                sec = first.right
                first.parent.right = sec
                del first
            
        else:
            if first.parent.left.data==first.data:
                sec = first.left
                first.parent.left = sec
                del first
            else:
                sec = first.left
                first.parent.right = sec
                del first
    
    def deleteNodeCase3(self, first):
        TBR = self.findMin(first.right)
        temp = TBR.data
        self.deleteNode(TBR.data)
        first.data = temp
    
    
    def deleteNode(self, d):
        first = self.head
        while first!=None:
            if first.data>d:
                first = first.left
            elif first.data<d:
                first = first.right
            else:
                if first.left==None and first.right==None:
                    del first
                elif first.left==None or first.right==None:
                    self.deleteNodeCase2(first)
                else:
                    self.deleteNodeCase3(first)
                
    def preOrderTraversal(self, node):
        if node == None:
            return
        
        print(node.data, end=", ")
        self.preOrderTraversal(node.left)
        self.preOrderTraversal(node.right)
    
    def postOrderTraversal(self, node):
        if (node == None):
            return
        
        self.postOrderTraversal(node.left)
        self.postOrderTraversal(node.right)
        print(node.data, end=", ")
    
    def inOrderTraversal(self, node):
        if (node == None):
            return
        
        self.inOrderTraversal(node.left)
        print(node.data, end=", ")
        self.inOrderTraversal(node.right)
    
def Q1():
    A = BST(int(input("Enter the length of the BST: ")))
    print("IsNull: ", A.isNull())

    A.inOrderTraversal(A.head)
    print()
    A.postOrderTraversal(A.head)
    print()
    A.preOrderTraversal(A.head)
    print()

if __name__=="__main__":
	Q1()

