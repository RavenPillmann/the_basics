# Searching
import math

def binarySearchIterative(lst, val):
	left = 0
	right = len(lst) - 1

	while left < right:
		mid = math.floor((left + right) / 2)

		if val == lst[mid]:
			return mid
		if val < lst[mid]:
			right = mid
		else:
			left = mid + 1

	return -1


def main():
	lst = [2, 4, 8, 16, 32, 64, 128, 256]
	print(binarySearchIterative(lst, 128))
	print(binarySearchIterative(lst, 2))
	print(binarySearchIterative(lst, 16))

	print(binarySearchIterative(lst, 1))


if __name__ == "__main__":
	main()