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

void quick_sort() {

}

void radix_sort() {

}

void selection_sort() {

}

void insertion_sort() {

}
 
int main() {
	vector<long> vec {-100, 10, -12312, 45, 1, 22, 2, 54, 1000, 5, 24, 17, 0};

	cout << "Bubble Sort" << endl;
	print_output(bubble_sort(vec));
	cout << "Merge Sort" << endl;
	print_output(merge_sort(vec));

	return 0;
}