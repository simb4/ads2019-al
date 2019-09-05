#include <iostream>

using namespace std;


struct node {
    int val;
    node *nxt;
    node(int val) {
        this->nxt = NULL;
        this->val = val;
    }
    node(int val, node *nxt) {
        this->nxt = nxt;
        this->val = val;
    }
} *head;

void addBegin(int x) {
    if (head == NULL) { // if list is empty
        head = new node(x);
    } else { // list is not empty
        node *v = new node(x, head);
        head = v;
    }
}

void del(int val) {
    node *v = head, *prev = head;
    while(v != NULL && v->val != val) {
        prev = v;
        v = v->nxt;
    }
    if (v == NULL) {
        cout << "not found\n";
    } else {
        if (v == head) {
            head = v->nxt;
        } else {
            prev->nxt = v->nxt;
        }
        delete v;
    }
}

void print() {
    node *v = head;
    while (v != NULL) {
        cout << v->val << ' ';
        v = v->nxt;
    }
    cout << "\n";
}
/*
    function should insert x after first occurence of y
    for ex:
    1 2 3 4 5
    insert(6, 3)
    1 2 3 6 4 5
*/
void insertAfter(int x, int y) {
    //
}

/*
    function should return position of first occ of val
    in linked list starting from *v
*/
int findPos(node *v, int val) {
}


int main() {

    addBegin(2);
    addBegin(1);
    addBegin(3);
    addBegin(4);
    print();
    del(1);
    print();
    del(4);
    print();

    return 0;
}