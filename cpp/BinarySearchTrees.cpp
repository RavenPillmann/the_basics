#include <iostream>
#include <vector>
using namespace std;

class Node {
	public:
		int value;
		Node* left;
		Node* right;

		Node(int _value) {
			value = _value;
			left = NULL;
			right = NULL;
		}
};


class BinarySearchTree {
	private:
		Node* root;

		Node* insert_node(Node* _node, int _value) {
			if (_node == NULL) {
				Node* new_node = new Node(_value);
				return new_node;
			}

			int value = _node->value;

			if (_value < value) {
				_node->left = insert_node(_node->left, _value);
			} else {
				_node->right = insert_node(_node->right, _value);

			}

			return _node;
		}

		Node* find_minimum(Node* _node) {
			while (_node->left != NULL) {
				_node = _node->left;
			}

			return _node;
		}

		Node* remove_node(Node* _node, int _value) {
			
			// Base Case 1: No node found
			if (_node == NULL) {
				return _node;
			}

			// Base Case 2: Found the node!!
			if (_node->value == _value) {
				Node* left = _node->left;
				Node* right = _node->right;

				// Case 1: No children, just remove
				if (left == NULL && right == NULL) {
					delete _node;
					_node = NULL;
				}
				// Case 2: Right child but not left, set the node to its right child
				else if (left == NULL) {
					Node* temp = _node;
					_node = _node->right;
					delete temp; // Deallocate memory
				}
				// Case 3: Left child but not right, set the node to its left child
				else if (right == NULL) {
					Node* temp = _node;
					_node = _node->left;
					delete temp;
				}
				// Case 4: Both children. Find the minimum value of right subtree
				else {
					Node* temp = find_minimum(_node->right); // Find minimum value in right subtree
					_node->value = temp->value; // Set the node's value to the minimum value in right subtree
					_node->right = remove_node(_node->right, temp->value); // delete the minimum value from right subtree
				}

				return _node;		
			}

			int value = _node->value;

			if (_value < value) {
				_node->left = remove_node(_node->left, _value);
			} else {
				_node->right = remove_node(_node->right, _value);
			}

			return _node;
		}

		void in_order_traversal(Node* node) {
			if (node != NULL) {
				in_order_traversal(node->left);
				cout << node->value << " ";
				in_order_traversal(node->right);
			}
		}

		void pre_order_traversal(Node* node) {
			if (node != NULL) {
				cout << node->value << " ";
				in_order_traversal(node->left);
				in_order_traversal(node->right);
			}
		}

		void post_order_traversal(Node* node) {
			if (node != NULL) {
				in_order_traversal(node->left);
				in_order_traversal(node->right);
				cout << node->value << " ";
			}
		}

	public:
		BinarySearchTree(Node& _root) {
			root = &_root;
		}

		Node* insert(int _value) {
			Node* new_node = insert_node(root, _value);
			return new_node;
		}

		void visit_in_order() {
			cout << "Visit in order..." << endl;
			in_order_traversal(root);
			cout << endl;
		}

		void visit_pre_order() {
			cout << "Visit pre-order..." << endl;
			pre_order_traversal(root);
			cout << endl;
		}

		void visit_post_order() {
			cout << "Visit post-order..." << endl;
			post_order_traversal(root);
			cout << endl;
		}

		Node* remove(int _value) {
			root = remove_node(root, _value);
			return root;
		}
};


int main() {
	Node node_1 = Node(1);
	Node node_0 = Node(0);
	Node node_2 = Node(2);

	BinarySearchTree bst = BinarySearchTree(node_1);
	bst.insert(2);
	bst.insert(-12);
	bst.insert(52);
	bst.insert(19);

	// Expect: 1, -12, 2, 19, 52
	bst.visit_pre_order();
	// Expect: -12, 1, 2, 19, 52
	bst.visit_in_order();
	bst.visit_post_order();

	bst.remove(2);
	bst.remove(10);
	bst.visit_in_order();
	bst.remove(1);
	bst.visit_in_order();

	return 0;
}
