class Node:
    def __init__(self, d = None):
        self.data = d
        self.Next = None
    def __del__(self):
        print("Node is deleted")

class linkedlist:
    head = None
    
    def __init__(self, size):
        if size > 0:
            self.insertAtHead(int(input("Enter the head value: ")))
            for i in range(1, size):
                self.insertAtEnd(int(input("Enter the Node value: ")))
    
    def __del__(self):
        while not self.isEmpty():
            self.deleteFromStart()
        print("LinkedList is Deleted")
    
    def isEmpty(self):
        return self.head==None
    
    def display(self):
        first = self.head
        while first!=None:
            print(first.data,"->", sep='',end='')
            first = first.Next
        print("Null")
    
    def find(self, n):
        first = self.head
        while first!=None:
            if first.data == n:
                return True
            first = first.Next
        return False
    
    def insertAtHead(self, d):
        added = Node(d)
        added.Next = self.head
        self.head = added
    
    def insertAtEnd(self, d):
        if self.head!=None:
            first = self.head
            while first.Next!=None:
                first = first.Next
            added = Node(d)
            first.Next = added
        else:
            self.head = Node(d)
    
    def insertNode(self, ind, d):
        if ind==0:
            self.insertAtHead(d)
        else:
            first = self.head
            for i in range(ind):
                second = first
                first = first.Next
            added = Node(d)
            added.Next = second.Next
            second.Next = added
    
    def deleteFromStart(self):
        if self.head!=None:
            d = self.head
            self.head = d.Next
            del d

    def deleteFromEnd(self):
        if self.head!=None:
            first = self.head
            second = None
            while first.Next!=None:
                second = first
                first = first.Next
            if second!=None:
                ToDel = second.Next
                second.Next = None
                del ToDel
            else:
                self.head=None
    
    def deleteNode(self, d):
        first = self.head
        flag = 1
        while first.Next!=None:
            flag = 1
            if first.Next.data==d:
                ToDel = first.Next
                first.Next = first.Next.Next
                del ToDel
                flag = 0

            if first.Next!=None and flag:
                first = first.Next
        
        if self.head.data==d:
            self.deleteFromStart()
    
    def merge(self, l):
        first = self.head
        while first.Next!=None:
            first = first.Next
        first.Next = l.head
    
    def remDub(self):
        aa =  linkedlist(0)
        if self.head!=None:
            flag = 0
            aa.head =  Node(self.head.data)
            first = self.head.Next
            while first!=None:
                flag=0
                f = aa.head
                while f!=None:
                    if f.data==first.data:
                        flag = 1
                        break
                    
                    f = f.Next
                
                if not flag:
                    aa.insertAtEnd(first.data)
                
                first = first.Next
            
        
        return aa
    
    
    def intersection(self, l):
        aa =  linkedlist(0)
        if self.head!=None or l.head!=None:
            flag = 0
            
            first = self.head
            while first!=None:
                flag=0
                f = l.head
                while f!=None:
                    if f.data==first.data:
                        flag = 1
                        break
                    
                    f = f.Next
                
                if flag:
                    aa.insertAtEnd(first.data)
                
                first = first.Next
            
        
        return aa
    
    
    def reverse(self):
        if self.head!=None and self.head.Next!=None:
            first = None
            second = self.head
            third = second.Next
            while third!=None:
                second.Next = first
                first = second
                second = third
                third = second.Next
            
            second.Next = first
            self.head = second
        
    
    
    def Sort(self):
        if self.head!=None and self.head.Next!=None:
            first = self.head
            while first!=None:
                second = first.Next
                while second!=None:
                    if first.data > second.data:
                        temp = first.data
                        first.data = second.data
                        second.data = temp
                    
                    second = second.Next
                
                first = first.Next
            
        
    


class stackList:

    def __init__(self):
        self.arr=[]
    
    def Push(self, x):
        self.arr.append(x)
    
    
    def Pop(self):
        if self.isEmpty():
            print("Pop: Stack is Empty...")
        self.arr.pop()
    
    
    def Top(self):
        if self.isEmpty():
            return "Top: Stack is Empty..."
        return self.arr[-1]
    
    
    def isEmpty(self):
        return len(self.arr)==0
    


class stackLinkedList:
    def __init__(self, size):
        self.arr = linkedlist(size)
        self.top = None
        self.flag = 0
    
    def Push(self, x):
        self.arr.insertAtEnd(x)
        self.top = x
        self.flag = 1
    
    
    def Pop(self):
        if not self.isEmpty():
            self.arr.deleteFromEnd()
        else:
            print("Pop: Stack is already Empty!!!")
        
        self.flag = 0
    
    
    def Top(self):
        if self.flag:
            return self.top
        
        if not self.isEmpty():
            first = self.arr.head
            while first.Next!=None:
                first=first.Next
            
            self.top = first.data
            flag = 1
            return self.top
        else:
            return "Top: Stack is Empty"
    
    def isEmpty(self):
        return self.arr.isEmpty()
    


class QueueList:
	
    def __init__(self):
        self.arr = []
    
    def EnQueue(self, x):
        self.arr.insert(0, x)
        
    def deQueue(self):
        if self.isEmpty():
            return "Dequeue: Queue is Empty..."
        self.arr.pop()
    
    
    def peek(self):
        if self.isEmpty():
            return "Peek: Queue is Empty"
        
        return self.arr[-1]
    
    
    def isFull(self):
        return False
    
    
    def isEmpty(self):
        return len(self.arr)==0
    


class QueueLinkedList:
    def __init__(self, size):
        self.arr = linkedlist(size)
    
    def EnQueue(self, x):
        self.arr.insertAtEnd(x)
    
    
    def deQueue(self):
        if self.isEmpty():
            print("DeQueue: Queue is Empty")
            return
        
        self.arr.deleteFromStart()
    
    
    def peek(self):
        if self.isEmpty():
            return "Peek: Queue is Empty"
        
        return self.arr.head.data
    
    
    def isFull(self):
        return False
    
    def isEmpty(self):
        return self.arr.isEmpty()
    



def Q1():
	A =  linkedlist(int(input("Enter the length of the linkedlist: ")))
	print("IsNull:", A.isEmpty())
	A.display()
	
	if(A.find(int(input("Enter the integer you want to find in linkedList: ")))):
		print("The number lies in the linkedList...")
	
	else:
		print("The number is not found in the linkedList...")
	
	A.insertAtHead(int(input("Enter the Value to add in the start of the linkedList: ")))
	
	A.display()
	
	A.insertAtEnd(int(input("Enter the Value to add in the end of the linkedList: ")))
	
	A.display()
	
	A.insertNode(int(input("Enter the index to add value in the linkedList: ")), int(input("Enter the Value to add in the required index of the linkedList: ")))
	
	A.display()
	
	print("Deleting From Start")
	A.deleteFromStart()
	A.display()
	print("Deleting From End")
	A.deleteFromEnd()
	A.display()
	
	A.deleteNode(int(input("Enter number to del from all the list: ")))
	A.display()
	
	print("removing Duplicates: ", end='')
	A = A.remDub()
	A.display()
    
	print("Reverese: ", end='')
	A.reverse()
	A.display()
	
	print("Sorted: ", end='')
	A.Sort()
	A.display()
 
	print("\nMake a new LinkedList for interaction checks!!!")
	B =  linkedlist(int(input("Enter the length of the new linkedList: ")))
	C = A.intersection(B)
	print("Intersection: ", end='')
	C.display()
    
    A.merge(B)
    print("merge: ", end = '')
    A.display()


def Q2aa():
    B =  stackList()
    print("Pushing '10' in stack...")
    B.Push(10)
    print("\nPrinting Top of the Stack")
    print(B.Top())
    print("\nPopping element from the Stack")
    B.Pop()
    print("\nPrinting Top of the Stack")
    print(B.Top())
    print("\nPushing '3' in the Stack")
    B.Push(3)
    print("\nPrinting Top of the Stack")
    print(B.Top())
    print("\nPopping element from the Stack")
    B.Pop()
    print("\nPrinting Top of the Stack")
    print(B.Top())
    print()


def Q2ab():
    A =  stackLinkedList(3)
    print("\nPrinting Top of the Stack")
    print(A.Top())
    print("\nPopping element from the Stack")
    A.Pop()
    print("\nPrinting Top of the Stack")
    print(A.Top())
    print("\nPushing '3' in the Stack")
    A.Push(3)
    print("\nPrinting Top of the Stack")
    print(A.Top())
    print("\nPopping element from the Stack")
    A.Pop()
    print("\nPrinting Top of the Stack")
    print(A.Top())
    print()


def Q2ba():
    A =  QueueList()
    print("\nEnqueuing '10' from the Queue")
    A.EnQueue(10)
    print("\nPeeking the Queue")
    print(A.peek())
    print("\nDequeuing element from the Queue")
    A.deQueue()
    print("\nPeeking the Queue")
    print(A.peek())
    A.EnQueue(11)
    print("\nPeeking the Queue")
    print(A.peek())
    print("\nDequeuing element from the Queue")
    A.deQueue()
    print("\nPeeking the Queue")
    print(A.peek())
    print()


def Q2bb():
    A =  QueueLinkedList(3)
    print("\nEnqueuing '10' from the Queue")
    A.EnQueue(10)
    print("\nPeeking the Queue")
    print(A.peek())
    print("\nDequeuing element from the Queue")
    A.deQueue()
    print("\nPeeking the Queue")
    print(A.peek())
    A.EnQueue(11)
    print("\nPeeking the Queue")
    print(A.peek())
    print("\nDequeuing element from the Queue")
    A.deQueue()
    print("\nPeeking the Queue")
    print(A.peek())
    print()


if __name__ == "__main__":
    Q1()

    print("\n\nStack with List")
    print()
    Q2aa()

    print("\n\nStack with LinkedList")
    print()
    Q2ab()

    print("\n\nQueue with List")
    print()
    Q2ba()

    print("\n\nQueue with LinkedList")
    print()
    Q2bb()