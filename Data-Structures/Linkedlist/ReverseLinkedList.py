def reversedLinkedList(head):
  prev = None
  curr = head
  nisql = head.next

  while True:
    curr.next = prev

    if not nisql:
      break

    tmp_curr = curr
    curr = nisql
    nisql = curr.next
    prev = tmp_curr
    
  return curr
