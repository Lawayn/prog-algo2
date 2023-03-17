#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->value = value;
        this->left=NULL;
        this->right=NULL;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if (this->value>value){
            if(this->left==NULL){
                this->left = new SearchTreeNode(value);
            } else {
                this->left->insertNumber(value);
            }
        } else if(this->value<value){
            if(this->right==NULL){
                this->right = new SearchTreeNode(value);
            } else {
                this->right->insertNumber(value);
            }
        }

    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        int tailleLeft = 0;
        int tailleRight = 0;

        if(left==NULL && right==NULL){
            return 1;
        } else if(left!=NULL && right==NULL){
            tailleLeft = 1 + left->height();
            return tailleLeft;
        } else if(left ==NULL && right != NULL){
            tailleRight = 1 + right->height();
            return tailleRight;
        } else{
            tailleLeft = 1 + left->height();
            tailleRight = 1 + right->height();
            if(tailleLeft>tailleRight){
                return tailleLeft;
            } else{
                return tailleRight;
            }
        }

    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        int nbrLeft = 0;
        int nbrRight = 0;

        if(left!=NULL){
            nbrLeft = left->nodesCount();
        }
        if(right!=NULL){
            nbrRight = right->nodesCount();
        }

        return nbrLeft + nbrRight +1;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->left==NULL&& this->right==NULL){
            return true;
        }
        return false;
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree

        if(isLeaf()==false){
            if(left!=NULL){
                left->allLeaves(leaves, leavesCount);
            }
            if (right!=NULL){
                right->allLeaves(leaves, leavesCount);
            }
        } else{
            leaves[leavesCount]= this;
            leavesCount++;
        }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel

        if(left!=NULL){
            left->inorderTravel(nodes, nodesCount);
        } else{
            nodes[nodesCount] = left;
            nodesCount++;
            nodes[nodesCount] = this;
        }

    }

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
	}

	Node* find(int value) {
        // find the node containing value
		return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}
