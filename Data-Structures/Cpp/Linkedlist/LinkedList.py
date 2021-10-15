class ListNode :
    def __init__(self, val: int) -> None:
        self.val: int = val
        self.next: "ListNode" = None

class LinkedList:
    def __init__(self):
        self.dummy_head = ListNode(0)
        self.length = 0
    
    def size(self) :
        return self.length

    def empty(self) :
        return self.dummy_head.next == None
    
    def append(self, num: int) :
        ptr = self.dummy_head.next
        prev = self.dummy_head
        while ptr :
            prev = ptr
            ptr = ptr.next
        node = ListNode(num)
        prev.next = node
        self.length += 1
    
    def insert(self, index: int, num: int) :
        i = 0
        ptr = self.dummy_head.next
        prev = self.dummy_head

        while ptr and i != index :
            prev = ptr
            ptr = ptr.next
            i += 1
        if i != index :
            raise IndexError
        node = ListNode(num)
        next_node = prev.next
        prev.next = node
        node.next = next_node
        self.length += 1

    def delete(self, index) :
        prev = self.dummy_head
        ptr = self.dummy_head.next

        i = 0
        while ptr and i != index :
            prev = ptr
            ptr = ptr.next
            i += 1
        
        if i != index :
            raise IndexError
        
        prev.next = ptr.next
        deleted_node_value = ptr.val
        del ptr
        self.length -= 1

        return deleted_node_value
    
    def display(self) :
        ptr = self.dummy_head.next
        print("[", end="")
        while ptr :
            print(f"{ptr.val}", end="")
            if ptr.next :
                print(", ", end="")
            ptr = ptr.next
        print("]")
        # length = self.length
        # print(f"{length=}")