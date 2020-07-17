#include <iostream>
using namespace std;

struct bintree_node  //struct is a user define data type of that varaible whose address this pointer going to be store.
// (*) behaves has a pointer
{
    bintree_node *left; //It means left pointer..
    bintree_node *right;//It means right pointer..
    int data;
};
class bst
{
    bintree_node *root;

public:
    bst()
    {
        root = NULL;
    }
    int isEmpty()
    {
        return (root == NULL);
    }
    void insert(int item);
    void displayBinTree();
    void printBinTree(bintree_node *);
};
// For inserting..
void bst::insert(int item)
{
    bintree_node *p = new bintree_node;
    bintree_node *parent;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    parent = NULL;
    if (isEmpty())
        root = p;
    else
    {
        bintree_node *ptr;
        ptr = root;
        while (ptr != NULL)
        {
            parent = ptr;
            if (item > ptr->data)
                ptr = ptr->right;//If user insert value or item, is greater than the parent node then the value or item paced on right node.
            else
                ptr = ptr->left;
        }
        if (item < parent->data)
            parent->left = p;//If user insert value or item, is smaller than the parent node then the value or item paced on left node.
        else
            parent->right = p;
    }
}
//For displaying..
void bst::displayBinTree()
{
    printBinTree(root);
}
//For print..
void bst::printBinTree(bintree_node *ptr)
{
    if (ptr != NULL)
    {
        printBinTree(ptr->left);
        cout << "  " << ptr->data << "     "; 
        printBinTree(ptr->right);
    }
}
int main()
//inserting the values..
{
    bst b;
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(29);
    b.insert(45);
    b.insert(30);

    cout << "Binary tree created: " << endl;
    b.displayBinTree();
}

//Output:

// 5 10 15 20 29 30 45 