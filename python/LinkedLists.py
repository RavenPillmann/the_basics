# Linked Lists

class Node(object):
	val = None
	next = None
	prev = None

	def __init__(self, value: int):
		self.val = value

	def addNext(self, next):
		self.next = next

	def addPrev(self, prev):
		self.prev = prev

	def print(self):
		print(str(self.val) + " ")


class ForwardLinkedList(object):
	head = None

	def __init__(self, head):
		self.head = head

	def append(self, node):
		pointer = self.head

		while (pointer.next != None):
			pointer = pointer.next

		pointer.next = node
		pointer.next.prev = pointer

	def remove(self, val):
		pointer = self.head

		if pointer.val == val:
			self.head = pointer.next
			return

		while (pointer.next != None):
			if pointer.next.val == val:
				ref = pointer.next
				pointer.next = pointer.next.next
				if pointer.next != None:
					pointer.next.prev = pointer
				return

			pointer = pointer.next

	def print(self):
		pointer = self.head

		while (pointer != None):
			pointer.print()
			pointer = pointer.next

		print("<EOL>")


def main():
	node1 = Node(1)
	node2 = Node(2)
	node3 = Node(3)
	node4 = Node(4)

	fll = ForwardLinkedList(node1)
	fll.append(node2)
	fll.append(node3)
	fll.append(node4)

	fll.print()

	fll.remove(2)
	fll.remove(4)

	fll.print()

	fll.remove(1)
	fll.remove(2)
	fll.remove(3)

	fll.print()


if __name__ == "__main__":
	main()


		