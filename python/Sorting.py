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


def main():
	lst = []
	lst.append(41)
	lst.append(12)
	lst.append(90)
	lst.append(100)
	lst.append(43)
	lst.append(-12)
	lst.append(2)

	sortedList = mergeSort(lst)

	print(sortedList)


if __name__ == "__main__":
	main()