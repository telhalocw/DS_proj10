#ifndef STUBINARYTREE_H
#define STUBINARYTREE_H
#include "stuRecords10.h"

using namespace std;
const int TESTN = 10;


/**************************************************
 **Class: StuBinaryTree
 **Description: allows for creation of binary trees full of Stu data.
**************************************************/
class StuBinaryTree
{
private:
    //Pointers used for navigation
    struct TreeNode
    {
        Stu student;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

/**************************************************
 **Function: insert
 **Description: recursively traverses through tree until nullptr is reached,
 then a new node is created.
 **Parameters: &nodePtr and &newNode are pointers that traverse through the tree
**************************************************/
    void insert(TreeNode* &nodePtr, TreeNode* &newNode)
    {
        if (nodePtr == nullptr)
            nodePtr = newNode;
        else if (newNode->student.id < nodePtr->student.id) //compares id#s of stus
            insert(nodePtr->left, newNode); //search left branch
        else
            insert(nodePtr->right, newNode); //search right branch
    }

/**************************************************
 **Function: displayInOrder
 **Description: Recursively traverses tree using "InOrder" logic, displays
 student records accordingly.
 **Parameters: nodePtr is the pointer traversing through the tree
**************************************************/
    void displayInOrder(TreeNode* nodePtr) const
    {
        if(nodePtr)
        {
            displayInOrder(nodePtr->left);
            cout << left << setw(8) << nodePtr->student.id << " " << setw(25)
                 << nodePtr->student.name;
            for(int i = 0; i < TESTN; ++i)
            {
                cout << " " << setw(3) << *(nodePtr->student.testPtr + i)
                     << " ";
            }
            cout << endl;
            displayInOrder(nodePtr->right);
        }
    }
/**************************************************
 **Function: makeDeletion
 **Description: Takes care of the actual deletion of nodes.
 **Parameters: &nodePtr traverses the tree.
**************************************************/
    void makeDeletion(TreeNode* &nodePtr)
    {
        //Define temp pointer to use in reattaching left subtree
        TreeNode* tempNodePtr = nullptr;

        if(nodePtr == nullptr)
            cout << "Cannot delete empty node.\n";
        else if (nodePtr->right == nullptr)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left;  //reattach left child
            delete tempNodePtr;
        }
        else if (nodePtr->left == nullptr)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right; //reattach right child
            delete tempNodePtr;
        }
        //If node has 2 children
        else
        {
            //move one node to right
            tempNodePtr = nodePtr->right;
            //go to end left node
            while(tempNodePtr->left)
                tempNodePtr = tempNodePtr->left;
            //reattach left subtree
            tempNodePtr->left = nodePtr->left;
            tempNodePtr = nodePtr;
            //reattach right subtree
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }

    }

/**************************************************
 **Function: deleteNode
 **Description: specifies which node ought to be deleted, given integer input.
 Passes relevant pointer data to makeDeletion for actual deletion.
 **Parameters: idNum is the integer value (student ID) that needs deleted,
 &nodePtr is the pointer that traverses the tree
**************************************************/
    void deleteNode(int idNum, TreeNode* &nodePtr)
    {
        if (idNum < nodePtr->student.id)
            deleteNode(idNum, nodePtr->left);
        else if (idNum > nodePtr->student.id)
            deleteNode(idNum, nodePtr->right);
        else
            makeDeletion(nodePtr);
    }
/**************************************************
 **Function: destroySubTree
 **Description: deletes everything. Called by the destructor.
**************************************************/
    void destroySubTree(TreeNode* nodePtr)
    {
        if(nodePtr->left)
            destroySubTree(nodePtr->left);
        if(nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }



public:

    //Constructor
    StuBinaryTree()
    {
        root = nullptr;
    }

    //Destructor
    ~StuBinaryTree()
    {
        destroySubTree(root);
    }

/**************************************************
 **Function: insertNode
 **Description: creates a new Stu node to be passed to insert function
 **Parameters: stud is of Stu structure
**************************************************/
    void insertNode(Stu stud)
    {
        TreeNode* newNode = nullptr;

        newNode = new TreeNode;
        newNode->student = stud;
        newNode->left = newNode->right = nullptr;

        insert(root,newNode);
    }

/**************************************************
 **Function: displayInOrder (public)
 **Description: allows user to call displayInOrder (private), since
 displayInOrder (public) has access to private: TreeNode* root.
**************************************************/
    void displayInOrder() const
    {
        displayInOrder(root);
    }

/**************************************************
 **Function: searchNodeById
 **Description: traverses tree, if it finds the integer argument it is given,
 prints to console the Student record at that node.
 **Parameters: num is the integer student ID to be searched for
**************************************************/
    void searchNodeById(int num)
    {
        TreeNode *nodePtr = root;

        while(nodePtr)
        {
            if(nodePtr->student.id == num)
            {
                cout << "\nRecord found!\n";
                cout << left << setw(8) << nodePtr->student.id << " "
                     << setw(25) << nodePtr->student.name;
                for(int i = 0; i < TESTN; ++i)
                {
                    cout << " " << setw(3) << *(nodePtr->student.testPtr + i)
                         << " ";
                }
                cout << endl;
                return;
            }
            else if (num < nodePtr->student.id)
                nodePtr = nodePtr->left;
            else
                nodePtr = nodePtr->right;
        }
        cout << "\nRecord not found.\n";
    }

/**************************************************
 **Function: removeById
 **Description: calls the deleteNode function to delete the node specified
 by integer ID number
 **Parameters: num is the integer student ID to be searched for and deleted
**************************************************/
    void removeById(int idNum)
    {
        deleteNode(idNum, root);
    }

};

#endif // STUBINARYTREE_H
