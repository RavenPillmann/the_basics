#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;


class Heap {
	protected:
		vector<int> heap;
	public:
		Heap() {
			heap = vector<int>();
		}

		static int get_left_child_index(int n) {
			return 2*n + 1;
		}

		static int get_right_child_index(int n) {
			return 2*n + 2;
		}

		static int get_parent_index(int n) {
			return floor((n - 1) / 2);
		}

		void print_heap() {
			int n = heap.size();

			for (int i=0; i<n; i++) {
				cout << heap[i] << " ";
			}

			cout << endl;
		}

		int get_size() {
			return heap.size();
		}
};


class MinHeap : public Heap {
	public:
		MinHeap() {
			Heap();
		}


		/**
		* 	Push the element to the last spot in the heap, then iteratively swap with parent elements if parents are smaller
		*/
		void push(int value) {
			heap.push_back(value);

			int index = heap.size() - 1;
			int parent_index = Heap::get_parent_index(index);

			while (heap[index] < heap[parent_index] && parent_index >= 0) {
				swap(heap[index], heap[parent_index]);
				index = parent_index;
				parent_index = Heap::get_parent_index(index);
			}
		}


		/**
		*	To pop, remove top element and replace with last
		*	Bubble down. Basically, compare element to both children.
		*	If no children, stop
		*	If one child and child smaller, swap
		*	If two children, if either are smaller, swap with smallest. If neither, don't swap at all
		*/
		int pop() {
			int top = heap.front();
			int temp = heap.back();
			heap.pop_back();
			heap[0] = temp;

			int index = 0;
			int left_child_index = Heap::get_left_child_index(index);
			int right_child_index = Heap::get_right_child_index(index);

			while (left_child_index < heap.size()) {

				// If only the node only has a left child, check if child is smaller than parent. If so, swap
				if (right_child_index >= heap.size()) {
					if (heap[left_child_index] < heap[index]) {
						swap(heap[left_child_index], heap[index]);
						index = left_child_index;
					} else {
						break;
					}
				}
				// Otherwise, check which of the children is smaller and swap with that child (if that child is smaller than the parent)
				else {
					if (heap[left_child_index] < heap[right_child_index] && heap[left_child_index] < heap[index]) {
						swap(heap[left_child_index], heap[index]);
						index = left_child_index;
					} else if (heap[right_child_index] < heap[left_child_index] && heap[right_child_index] < heap[index]) {
						swap(heap[right_child_index], heap[index]);
						index = right_child_index;
					} else {
						break;
					}
				}

				left_child_index = Heap::get_left_child_index(index);
				right_child_index = Heap::get_right_child_index(index); 
			}

			return top;
		}
};


int main() {
	MinHeap heap = MinHeap();
	heap.push(1);
	heap.push(0);
	heap.push(100);
	heap.push(20);
	heap.push(99);
	heap.push(-11);
	heap.push(22);
	heap.push(10);

	heap.print_heap();

	// This is heap sort: pop elements from a heap one by one
	int size = heap.get_size();
	for (int i = 0; i < size; i++) {
		cout << heap.pop() << " ";
	}
	cout << endl;

	return 0;
}
