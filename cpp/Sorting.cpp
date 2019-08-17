#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

void print_output(vector<long> output) {
	int n = output.size();

	for (int i=0; i<n; i++) {
		cout << output[i] << " ";
	}

	cout << endl;
}


/**
*	O(n^2) time, O(1) space (In place swaps)
*	While unsorted, swap each neighboring element if they are out of order
*/
vector<long> bubble_sort(vector<long> vec) {
	bool unsorted = true;
	int n = vec.size();

	while (unsorted) {
		unsorted = false;

		for (int i=0; i<n-1; i++) {
			if (vec[i] > vec[i+1]) {
				swap(vec[i], vec[i+1]);
				unsorted = true;
			}
		}
	}

	return vec;
}


// Helper function for merge_sort
vector<long> merge(vector<long> first_half, vector<long> second_half) {
	vector<long> vec;
	int first_half_index = 0;
	int second_half_index = 0;

	while (first_half_index < first_half.size() && second_half_index < second_half.size()) {
		
		if (first_half[first_half_index] < second_half[second_half_index]) {
			vec.push_back(first_half[first_half_index]);
			first_half_index += 1;
		} else {
			vec.push_back(second_half[second_half_index]);
			second_half_index += 1;
		}
	}

	// If there are still elements in first half to merge, merge them
	if (first_half_index < first_half.size()) {
		for (int i=first_half_index; i<first_half.size(); i++) {
			vec.push_back(first_half[i]);
		}
	} else if (second_half_index < second_half.size()) {
		for (int i=second_half_index; i<second_half.size(); i++) {
			vec.push_back(second_half[i]);
		}
	}

	return vec;
}


/**
*	O(n log n) time
*	First, divide the vector into pieces. Then, merge the pieces together 
*/
vector<long> merge_sort(vector<long> vec) {
	int n = vec.size();
	
	// Base case: vector is size 0 or 1
	if (vec.size() <= 1) {
		return vec;
	}

	// Otherwise, get the first and second halves of the vec
	vector<long> first_half, second_half;

	for (int i=0; i<floor(n/2); i++) {
		first_half.push_back(vec[i]);
	}

	for (int i=floor(n/2); i<n; i++) {
		second_half.push_back(vec[i]);
	}

	// Then, merge the result of merge_sort on the first and second halves
	vector<long> sorted_vec = merge(merge_sort(first_half), merge_sort(second_half));

	return sorted_vec;
}


// Helper for quick_sort, this function will move all 
int partition(vector<long>& vec, int left_ind, int right_ind) {
	// TODO: 
	// Get the partition
	// Then swap things around the partition

	// Pick the partition. In this case, its the element between left and right indices
	long pivot = vec[floor(left_ind + right_ind) / 2];

	while (left_ind <= right_ind) {

		// Skip all the elements that are less than the pivot on the left side. We want those to stay there
		while (vec[left_ind] < pivot) {
			left_ind += 1;
		}

		// Skip all the elements greater than the pivot on the right side. We want those to stay there
		while (vec[right_ind] > pivot) {
			right_ind -= 1;
		}

		if (left_ind <= right_ind) {
			swap(vec[left_ind], vec[right_ind]);
			left_ind += 1;
			right_ind -= 1;
		}
	}

	return left_ind;
}


vector<long> quick_sort_helper(vector<long>& vec, int left_ind, int right_ind) {
	int index = partition(vec, left_ind, right_ind);

	if (left_ind < index - 1) {
		quick_sort_helper(vec, left_ind, index - 1);
	} if (index < right_ind) {
		quick_sort_helper(vec, index, right_ind);
	}

	return vec;
}

/**
*	We choose a pivot. Then, we move all items smaller than pivot to left, and larger than pivot to right, such that pivot ends up in its correct spot. Do this recursively.
*/
vector<long> quick_sort(vector<long> vec) {
	return quick_sort_helper(vec, 0, vec.size() - 1);
}


void radix_sort() {

}


/**
*	O(n^2) time, O(1) Space
*	Linearly scan the vector for the smallest element, move to the front. Repeat for the second smallest, etc
*/
vector<long> selection_sort(vector<long> vec) {
	int n = vec.size();
	int index_of_smallest;

	for (int i=0; i<n-1; i++) {
		index_of_smallest = i;

		for (int j=i+1; j<n; j++) {
			if (vec[j] < vec[index_of_smallest]) {
				index_of_smallest = j;
			}
		}

		swap(vec[i], vec[index_of_smallest]);
	}

	return vec;
}

 
int main() {
	vector<long> vec {-100, 10, -12312, 45, 1, 22, 2, 54, 1000, 5, 24, 17, 0};

	cout << "Bubble Sort..." << endl;
	print_output(bubble_sort(vec));
	cout << "Merge Sort..." << endl;
	print_output(merge_sort(vec));
	cout << "Selection Sort..." << endl;
	print_output(selection_sort(vec));
	cout << "Quick Sort..." << endl;
	print_output(quick_sort(vec));


	return 0;
}