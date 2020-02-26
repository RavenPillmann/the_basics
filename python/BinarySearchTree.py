# Binary Search Tree
from collections import deque

class Node(object):
	val = None
	left = None
	right = None
	parent = None
	visited = False

	def __init__(self, val):
		self.val = val

	def isLeftChild(self):
		if self.parent == None:
			return False

		parentNode = self.parent
		return parentNode.left != None and self.val == parentNode.left.val

	def print(self):
		print(self.val)


class BST(object):
	root = None


	def __init__(self, root):
		self.root = root


	def insert(self, val):
		pointer = self.root

		while pointer != None:
			if val < pointer.val:
				if pointer.left == None:
					pointer.left = Node(val)
					pointer.left.parent = pointer
					return
				else:
					pointer = pointer.left
			else:
				if pointer.right == None:
					pointer.right = Node(val)
					pointer.right.parent = pointer
					return
				else:
					pointer = pointer.right


	def findMinimum(self, node):
		if node.left == None:
			return node
		else:
			self.findMinimum(node.left)


	def remove(self, node, val):
		if node == None:
			return

		if node.val == val:
			if node.left == None and node.right == None:
				if node.isLeftChild():
					node.parent.left = None
				else:
					node.parent.right = None
				del node

			elif node.left == None and node.right != None:
				node.val = node.right.val
				node.left = node.right.left
				node.right = node.right.right

			elif node.left != None and node.right == None:
				node.val = node.left.val
				node.left = node.left.left
				node.right = node.left.right

			else:
				minNode = findMinimum(node.right)
				node.val = minNode.val
				if minNode.isLeftChild():
					minNode.parent.left = None
				else:
					minNode.parent.right = None

		elif node.val > val:
			self.remove(node.left, val)
		else:
			self.remove(node.right, val)


	def inOrderTraversal(self, node):
		if node != None:
			self.inOrderTraversal(node.left)
			print(node.val)
			self.inOrderTraversal(node.right)


	def postOrderTraversal(self, node):
		if node != None:
			self.postOrderTraversal(node.left)
			self.postOrderTraversal(node.right)
			print(node.val)


	def preOrderTraveral(self, node):
		if node != None:
			print(node.val)
			self.preOrderTraveral(node.left)
			self.preOrderTraveral(node.right)


	def resetToUnvisited(self, node):
		if node != None:
			self.inOrderTraversal(node.left)
			node.visited = False
			self.inOrderTraversal(node.right)


	def bfs(self):
		queue = deque()
		queue.append(self.root)

		while len(queue):
			node = queue.popleft()
			node.visited = True
			node.print()
			if node.left != None and not node.left.visited:
				queue.append(node.left)
			if node.right != None and not node.right.visited:
				queue.append(node.right)

		print("End of BFS")


	def dfs(self):
		node = self.root
		queue = deque()
		queue.append(node)

		self._dfsRecursive(queue)

		print("End of DFS")


	def _dfsRecursive(self, queue):
		node = queue.pop()
		print(node.val)
		node.visited = True

		if node.left != None and not node.left.visited:
			queue.append(node.left)
			self._dfsRecursive(queue)
		if node.right != None and not node.right.visited:
			queue.append(node.right)
			self._dfsRecursive(queue)


def main():
	bst = BST(Node(10))

	bst.insert(11)
	bst.insert(12)
	bst.insert(-1)
	bst.insert(4)
	bst.insert(9)

	bst.inOrderTraversal(bst.root)
	print("<EOT>")

	bst.bfs()

	bst.resetToUnvisited(bst.root)

	bst.dfs()

	bst.remove(bst.root, 4)
	bst.remove(bst.root, 9)

	bst.inOrderTraversal(bst.root)
	print("<EOT>")

	bst.remove(bst.root, 0)

	bst.inOrderTraversal(bst.root)
	print("<EOT>")


if __name__ == "__main__":
	main()