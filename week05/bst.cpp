#include <iostream>
#include <cassert>
using namespace std;

struct node {
	int val, height;
	node *left;
	node *right;
	node(int val) {
		this->height = 0;
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void out(node* v, int spaces=0) {
	if (v == nullptr) return;
	cout << '!' << spaces << ' ' << v->val << ' ' << v->left << "\n";
	out(v->left, spaces + 2);
	for (int i = 0; i < spaces; i++) cout << "\t";
	out(v->right, spaces + 2);
}

int get_h(node *v) {
	if (v == nullptr) return -1;
	return v->height;
}

// node* add_node(node *v, int new_val) {
// pass reference to pointer. so if I change reference (for example root variable) inside of function,
// it will change actual variable of pointer.
// see reference.cpp for explanation
void add_node(node *&v, int new_val) {
	if (v == nullptr) {
		v = new node(new_val);
		assert(v->left == nullptr);
		return;
	}
	if (new_val <= v->val) {
		// v->left will be initialized inside this call
		add_node(v->left, new_val);
	} else {
		add_node(v->right, new_val);
	}
	v->height = max(get_h(v->left), get_h(v->right)) + 1;
}

int main () {

	node *root;
	while(true) {
		int x;
		cin >> x;
		if (x == 0) break;
		// if root is NULL (or nullptr - is newer replacement of NULL)
		// root will be initialized in first if since we accept reference in function
		add_node(root, x);
		assert(root->left == nullptr);
		out(root);
	}

	cout << root->height << "\n";

	return 0;
}
