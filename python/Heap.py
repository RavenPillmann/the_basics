# Heap
from collections import deque
import math

class MinHeap(object):
	heap = None

	def __init__(self):
		self.heap = deque()

	def getParentIndex(self, ind):
		return math.floor((ind - 1) / 2)

	def getLeftChildIndex(self, ind):
		return 2 * ind + 1

	def getRightChildIndex(self, ind):
		return 2 * ind + 2

	def insert(self, item):
		# insert at end, bubble up is parent is > self
		self.heap.append(item)
		indItem = len(self.heap) - 1
		indParent = self.getParentIndex(indItem)

		while (indParent >= 0 and self.heap[indParent] > self.heap[indItem]):
			swapItem = self.heap[indItem]
			self.heap[indItem] = self.heap[indParent]
			self.heap[indParent] = swapItem

			indItem = indParent
			indParent = self.getParentIndex(indItem)


	def pop(self):
		# get item at top, replace with item at end, bubble down
		returnVal = self.heap[0]
		self.heap[0] = self.heap.pop()

		ind = 0

		while self.getLeftChildIndex(ind) < len(self.heap):
			leftInd = self.getLeftChildIndex(ind)
			rightInd = self.getRightChildIndex(ind)

			if rightInd >= len(self.heap):
				if (self.heap[ind] > self.heap[leftInd]):
					swapItem = self.heap[leftInd]
					self.heap[leftInd] = self.heap[ind]
					self.heap[ind] = swapItem
					ind = leftInd
				else:
					break 

			else:
				if self.heap[rightInd] < self.heap[ind] and self.heap[rightInd] < self.heap[leftInd]:
					swapItem = self.heap[rightInd]
					self.heap[rightInd] = self.heap[ind]
					self.heap[ind] = swapItem
					ind = rightInd
				elif self.heap[leftInd] < self.heap[ind] and self.heap[leftInd] < self.heap[rightInd]:
					swapItem = self.heap[leftInd]
					self.heap[leftInd] = self.heap[ind]
					self.heap[ind] = swapItem
					ind = leftInd 

		return returnVal


	def print(self):
		for i in range(len(self.heap)):
			print(self.heap[i])

		print("End of heap")


def main():
	heap = MinHeap()

	heap.insert(1)
	heap.insert(10)
	heap.insert(11)
	heap.insert(5)
	heap.insert(94)
	heap.insert(-123)
	heap.insert(-2)
	heap.insert(15)

	heap.print()

	print(heap.pop())
	print(heap.pop())
	print(heap.pop())
	print(heap.pop())
	print(heap.pop())
	print("done popping")

	heap.print()


if __name__ == "__main__":
	main()