#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *next;
};

void addElementLast(node *&root, int data) {
        if ( root == NULL ) { // Adding very first element which is called root
                root = new node();
                root->data = data;
                root->next = root;
        } else {
                node *temp = new node();
                temp->data = data;

                node *p = root;
                node *q = NULL;
                do {
                        q = p;
                        p = p->next;
                } while ( p != root );

                if ( p == q ) { // When circular linked list has only one element
                        temp->next = p;
                        p->next = temp;
                } else {
                        q->next = temp;
                        temp->next = p;
                }
        }
}

void display(node *root) {
        if ( root == NULL ) {
                cout << "Element does not exist in circular linked list" << endl;
                return;
        }
        node *p = root;
        do {
                cout << p->data << " ";
                p = p->next;
        } while ( p != root );
        cout << endl;
}

void addElement(node *&root, int data) {
        node *p = root;
        node *q = NULL;
        if ( data >= root->data ) { // If value is greater or equal to root data
                do {
                        if ( p->data > data )
                                break;
                        q = p;
                        p = p->next;
                } while ( p != root );
        } else {
                do {
                        q = p;
                        p = p->next;
                } while ( p != root );

        }

        node *temp = new node();
        temp->data = data;
        temp->next = p;

        q->next = temp;

        if ( data < root->data ) // If given data is less than root data then root is needed to update
                root = temp;
}

int main()
{
        node *root = NULL;

        addElementLast(root, 10);
        addElementLast(root, 20);
        addElementLast(root, 30);
        addElementLast(root, 40);
        addElementLast(root, 50);

        cout << "Sorted circular linked list : ";
        display(root);

        addElement(root, 100);
        addElement(root, 35);
        addElement(root, 5);
        addElement(root, 10);

        cout << "After adding elements : ";
        display(root);

        return 0;
}
