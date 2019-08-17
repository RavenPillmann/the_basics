#include <iostream>
using namespace std;

class Node {
	private:
		int value;
		Node* next;
		Node* prev;
	public:
		Node (int _value) {
			value = _value;
			next = NULL;
			prev = NULL;
		}

		Node () {};	

		void set_next(Node* _next) {
			next = _next;
		}

		int get_value() {
			return value;
		}

		Node* get_next() {
			return next;
		}

		void set_prev(Node* _prev) {
			prev = _prev;
		}

		Node* get_prev() {
			return prev;
		}	
};


class LinkedList {
	protected:
		Node* head;
	public:
		LinkedList(Node& _head) {
			head = &_head;
		}

		Node get_head() {
			return *head;
		}

		void append_node(Node& node_to_append) {
			Node* end = forward_traversal();

			Node* to_append;
			to_append = &node_to_append;

			end->set_next(to_append);
		}

		Node* remove_node(int value) {
			Node* current = head;
			Node* temp;

			if (current->get_value() == value) {
				head = current->get_next();
				return current;
			}

			while (current->get_next() != NULL) {
				if (current->get_next()->get_value() == value) {
					Node* temp = current->get_next();
					current->set_next(current->get_next()->get_next());
					break;
				}
				current = current->get_next();
			}

			return temp;
		}

		Node* forward_traversal() {
			Node* current = head;

			while (current->get_next() != NULL) {
				current = current->get_next();
			}

			return current;
		}

		void print_list() {
			Node* current = head;

			do {
				int val = current->get_value();
				cout << val << " ";
				current = current->get_next();
			} while (current != NULL);

			cout << endl;
		}
};


class DoublyLinkedList : public LinkedList {
	public:
		void append_node(Node& node_to_append) {
			Node* end = forward_traversal();

			Node* to_append;
			to_append = &node_to_append;

			end->set_next(to_append);
			end->get_next()->set_prev(end);
		}
};


int main() {
	Node head = Node(1);
	Node node_2 = Node(2);
	Node node_3 = Node(3);
	Node node_4 = Node(4);

	LinkedList linked_list = LinkedList(head);

	linked_list.append_node(node_2);
	linked_list.append_node(node_3);
	linked_list.append_node(node_4);

	linked_list.print_list();
	linked_list.remove_node(3);
	linked_list.print_list();
	linked_list.remove_node(4);
	linked_list.print_list();
	linked_list.remove_node(1);
	linked_list.print_list();

	return 0;
}

