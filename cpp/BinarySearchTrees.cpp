#include <iostream>
#include <deque>
using namespace std;

class Node {
	public:
		long value;
		Node* left;
		Node* right;
		bool is_visited;

		Node(long _value) {
			value = _value;
			left = NULL;
			right = NULL;
			is_visited = false;
		}
};


class BinarySearchTree {
	private:
		Node* root;

		Node* insert_node(Node* _node, long _value) {
			if (_node == NULL) {
				Node* new_node = new Node(_value);
				return new_node;
			}

			long value = _node->value;

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

		Node* remove_node(Node* _node, long _value) {
			
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

			long value = _node->value;

			if (_value < value) {
				_node->left = remove_node(_node->left, _value);
			} else {
				_node->right = remove_node(_node->right, _value);
			}

			return _node;
		}

		void set_all_nodes_unvisited(Node* node) {
			if (node != NULL) {
				set_all_nodes_unvisited(node->left);
				node->is_visited = false;
				set_all_nodes_unvisited(node->right);
			}
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

		void dfs(Node* node) {
			// Check if we're no longer on the tree
			if (node == NULL) {
				return;
			}

			// Visit the node. In this case, visiting is just printing the value.
			cout << node->value << " ";

			// Keeping track of nodes we visit allows us to skip those nodes, which means we won't be in a loop
			node->is_visited = true;

			if (node->left != NULL && !node->left->is_visited) dfs(node->left);
			if (node->right != NULL && !node->right->is_visited) dfs(node->right);
		}

		void bfs(Node* node) {
			deque<Node *> to_visit;
			to_visit.push_back(node);

			Node* visiting;
			while (!to_visit.empty()) {
				visiting = to_visit.front();
				to_visit.pop_front();

				cout << visiting->value << " ";

				visiting->is_visited = true;
				if (visiting->left && !visiting->left->is_visited) to_visit.push_back(visiting->left);
				if (visiting->right && !visiting->right->is_visited) to_visit.push_back(visiting->right);
			}
		}

	public:
		BinarySearchTree(Node& _root) {
			root = &_root;
		}

		Node* insert(long _value) {
			Node* new_node = insert_node(root, _value);
			return new_node;
		}

		Node* remove(long _value) {
			root = remove_node(root, _value);
			return root;
		}

		void unvisit_all_nodes() {
			cout << "Unvisiting all nodes" << endl;
			set_all_nodes_unvisited(root);
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

		void depth_first_search() {
			cout << "Depth First Search" << endl;
			dfs(root);
			cout << endl;
		}

		void breadth_first_search() {
			cout << "Breadth First Search" << endl;
			bfs(root);
			cout << endl;
		}
};


int main() {
	// Construct the BST
	Node node_1 = Node(10);

	BinarySearchTree bst = BinarySearchTree(node_1);
	bst.insert(3);
	bst.insert(-12);
	bst.insert(52);
	bst.insert(19);
	bst.insert(2);
	bst.insert(-22);
	bst.insert(43);
	bst.insert(10);
	bst.insert(123);
	bst.insert(414);
	bst.insert(-1000);
	bst.insert(200);

	// Test traversals
	bst.visit_pre_order();
	bst.visit_in_order();
	bst.visit_post_order();
	bst.depth_first_search();

	// Unvisit all nodes
	bst.unvisit_all_nodes();

	bst.breadth_first_search();

	// Test removal
	bst.remove(2);
	bst.remove(999);
	bst.visit_in_order();
	bst.remove(10);
	bst.visit_in_order();
	bst.remove(10);
	bst.visit_in_order();

	return 0;
}
