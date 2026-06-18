# Fabricio Lima Medeiros

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None



class LinkedList:
    def __init__(self):
        self.head = None

   
    def append(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return

        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    
    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")



def quick_sort(head):
    if head is None or head.next is None:
        return head

   
    pivot = head
    less_head = less_tail = None
    equal_head = equal_tail = None
    greater_head = greater_tail = None

    current = head

    while current:
        if current.data < pivot.data:
            if not less_head:
                less_head = less_tail = Node(current.data)
            else:
                less_tail.next = Node(current.data)
                less_tail = less_tail.next

        elif current.data == pivot.data:
            if not equal_head:
                equal_head = equal_tail = Node(current.data)
            else:
                equal_tail.next = Node(current.data)
                equal_tail = equal_tail.next

        else:
            if not greater_head:
                greater_head = greater_tail = Node(current.data)
            else:
                greater_tail.next = Node(current.data)
                greater_tail = greater_tail.next

        current = current.next

    less_head = quick_sort(less_head)
    greater_head = quick_sort(greater_head)

    return concatenate(less_head, equal_head, greater_head)


def concatenate(less, equal, greater):
    head = tail = None

    for part in [less, equal, greater]:
        if part:
            if not head:
                head = tail = part
            else:
                tail.next = part

            while tail.next:
                tail = tail.next

    return head


lista = LinkedList()

valores = [30, 10, 50, 20, 40]
for v in valores:
    lista.append(v)

print("Lista original:")
lista.display()

lista.head = quick_sort(lista.head)

print("Lista ordenada:")
lista.display()