// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }

};

void treeTraversal(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << "-> ";
    treeTraversal(root->right);
    treeTraversal(root->left);

}

//Node* insert(Node* root, int d) {
//    if (root = NULL)
//        return new Node(d);
//
//    if (d < root->data)
//        root->right = insert(root->right, d);
//    else
//        root->left = insert(root->left, d);
//}

//int main()
//{
//    std::cout << "Hello World!\n";
//    Node* a = new Node(1);
//    a->right = new Node(2);
//    a->right->right = new Node(3);
//    a->right->right->right = new Node(6);
//    a->right->right->right->right = new Node(7);
//    a->right->right->right->right->right = new Node(8);
//
//    a->right->right->left = new Node(9);
//    a->right->right->left->right = new Node(10);
//    a->right->right->left->right->right = new Node(11);
//
//    a->right->right->left->right->left = new Node(12);
//    a->right->right->left->right->left->right = new Node(13);
//
//    treeTraversal(a);
//    return 0;
//
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
