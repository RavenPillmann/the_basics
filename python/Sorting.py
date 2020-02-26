# Sorting
import math

def printLst(lst):
	for i in range(len(lst)):
		print(lst)

	print("End of list")


def merge(left, right):
	lst = []

	leftInd = 0
	rightInd = 0

	while leftInd < len(left) and rightInd < len(right):
		if left[leftInd] < right[rightInd]:
			lst.append(left[leftInd])
			leftInd += 1
		else:
			lst.append(right[rightInd])
			rightInd += 1

	if leftInd < len(left):
		lst.extend(left[leftInd:])
	else:
		lst.extend(right[rightInd:])

	return lst


def mergeSort(lst):
	# First split, then mergeSort
	n = len(lst)

	if n <= 1:
		return lst

	left = []
	right = []
	midInd = math.floor(n / 2)

	left.extend(lst[:midInd])
	right.extend(lst[midInd:])

	return merge(mergeSort(left), mergeSort(right))


def partition(lst, leftInd, rightInd):
	pivot = lst[math.floor((leftInd + rightInd) / 2)]

	while leftInd <= rightInd:
		while lst[leftInd] < pivot:
			leftInd += 1
		while lst[rightInd] > pivot:
			rightInd -= 1

		if leftInd <= rightInd:
			val = lst[rightInd]
			lst[rightInd] = lst[leftInd]
			lst[leftInd] = val
			leftInd += 1
			rightInd -= 1

	return leftInd


def _quickSortHelper(lst, leftInd, rightInd):
	ind = partition(lst, leftInd, rightInd)

	if leftInd < ind - 1:
		_quickSortHelper(lst, leftInd, ind-1)
	if ind < rightInd:
		_quickSortHelper(lst, ind, rightInd)


def quickSort(lst):
	_quickSortHelper(lst, 0, len(lst)-1)
	return lst


def main():
	lst = []
	lst.append(41)
	lst.append(12)
	lst.append(90)
	lst.append(100)
	lst.append(43)
	lst.append(-12)
	lst.append(2)

	# sortedList = mergeSort(lst)
	sortedList = quickSort(lst)

	print(sortedList)


if __name__ == "__main__":
	main()