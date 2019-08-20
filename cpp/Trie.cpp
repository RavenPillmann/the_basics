#include <iostream>
#include <string>
using namespace std;


// Each node in a Trie contains references to other Nodes, as well as a potential value
class Node {
	private:
		int value = -1;
		Node* chars[26];

	public:
		Node() {}

		static int get_chars_index(char c);

		void set_value(int val) {
			value = val;
		}

		int get_value() {
			return value;
		}

		Node* get_next_node(int index) {
			return chars[index];
		}

		void set_next_node(int index, Node* new_node) {
			chars[index] = new_node;
		}
};


int Node::get_chars_index(char c) {
	// Assume that chars are all lowercase

	int index = int(c) - 97;
	return index;
}


class Trie {
	private:
		Node* root;

		void recursive_add(Node* node, string key, int val, int ind) {
			if (node == NULL) {
				// Then we need to create a node
				node = new Node();
			} 

			if (ind == key.length() - 1) {
				node->set_value(val);
				return;
			}

			int index = Node::get_chars_index(key[ind]);
			if (node->get_next_node(index) == NULL) {
				Node* next_node = new Node();
				node->set_next_node(index, next_node);
			}
			recursive_add(node->get_next_node(index), key, val, ind + 1);
		}

		int recursive_lookup(Node* node, string key, int ind) {
			if (node == NULL) {
				return -1;
			} else if (key.length() - 1 == ind) {
				return node->get_value();
			}

			int index = Node::get_chars_index(key[ind]);
			return recursive_lookup(node->get_next_node(index), key, ind+1);
		}

		void recursive_remove(Node* node, string key, int ind) {
			if (node == NULL) {
				return;
			} else if (key.length() - 1 == ind) {
				node->set_value(-1);
				return;
			}

			int index = Node::get_chars_index(key[ind]);
			recursive_remove(node->get_next_node(index), key, ind+1);
		}

	public:
		Trie(Node* node) {
			root = node;
		}	

		void add_key_value(string key, int val) {
			recursive_add(root, key, val, 0);
		}

		int lookup_key(string key) {
			return recursive_lookup(root, key, 0);
		}

		void remove_key(string key) {
			return recursive_remove(root, key, 0);
		}
};


int main() {
	Node* root = new Node();

	Trie trie = Trie(root);

	trie.add_key_value("hello", 22);
	trie.add_key_value("goodbye", 43);
	trie.add_key_value("goodstuff", 98);

	cout << "Value of hello: " << trie.lookup_key("hello") << endl;
	cout << "Value of hell: " << trie.lookup_key("hell") << endl;
	cout << "Value of goodbye: " << trie.lookup_key("goodbye") << endl;
	cout << "Value of goodstuff: " << trie.lookup_key("goodstuff") << endl;

	trie.remove_key("goodbye");

	cout << "Value of goodbye (after removing goodbye): " << trie.lookup_key("goodbye") << endl;
	cout << "Value of goodstuff (after removing goodbye): " << trie.lookup_key("goodstuff") << endl;

	return 0;
}