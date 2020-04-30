#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        int height;
        node *leftChild;
        node *rightChild;
} *root = NULL;

int heightOfTree(node *p) {
        int leftHeight = p && p->leftChild ? p->leftChild->height : 0;
        int rightHeight = p && p->rightChild ? p->rightChild->height : 0;

        return max(leftHeight, rightHeight) + 1;
}

int balanceFactor(node *p) {
        int leftHeight = p && p->leftChild ? p->leftChild->height : 0;
        int rightHeight = p && p->rightChild ? p->rightChild->height : 0;

        return leftHeight - rightHeight;
}

node* LLRotation(node *p) {
        return NULL;
}

node* LRRotation(node* p) {
        return NULL;
}

node* RRRotation(node* p) {
        node *pr = p->rightChild;
        node *prl = pr->leftChild;

        p->rightChild = prl;
        pr->leftChild = p;

        p->height = heightOfTree(p);
        pr->height = heightOfTree(pr);

        if ( root == p )
                return pr;

        return pr;
}

node* RLRotation(node* p) {
        return NULL;
}

node* Insert(node *p, int data) {
        if ( p == NULL ) {
                p = new node();
                p->data = data;
                p->height = 1;
                p->leftChild = p->rightChild;
                return p;
        }

        if ( p->data >= data )
                p->leftChild = Insert(p->leftChild, data);
        else if ( p->data < data )
                p->rightChild = Insert(p->rightChild, data);

        p->height = heightOfTree(p);

        if ( balanceFactor(p) == 2 && balanceFactor(p->leftChild) == 1 )
                return LLRotation(p);
        else if ( balanceFactor(p) == 2 && balanceFactor(p->leftChild) == -1 )
                return LRRotation(p);
        else if ( balanceFactor(p) == -2 && balanceFactor(p->rightChild) == -1 )
                return RRRotation(p);
        else if ( balanceFactor(p) == -2 && balanceFactor(p->rightChild) == 1 )
                return RLRotation(p);

        return p;
}

void levelOrderTraversal(node *root) {
        queue < node* > q;
        q.push(root);

        while ( !q.empty() ) {
                node *t = q.front();
                q.pop();

                printf("%d ", t->data);

                if ( t->leftChild )
                        q.push(t->leftChild);

                if ( t->rightChild )
                        q.push(t->rightChild);
        }
        printf("\n");
}

/* AVL tree :
                        10(p)                                    20(pr)
                          \             RR Rotation             /  \
                          20(pr)       ------------>       (p)10    30
                         /  \                                   \
                  (prl)NULL  30                                NULL(prl)
*/

int main()
{
        root = Insert(root, 10);
        root = Insert(root, 20);
        root = Insert(root, 30);

        levelOrderTraversal(root);

        return 0;
}
