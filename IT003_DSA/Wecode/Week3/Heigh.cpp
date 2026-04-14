
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p = new TNode;
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(TNode* &, int);
int GetHeight(TNode *);

void Insert(TNode* &root, int x){
    if(root == nullptr) {
        root = CreateTNode(x);
        return;
    }
    else {
        if(root -> key == x) return;
        else if (root -> key > x){
            if(root -> pLeft == nullptr) {
                root -> pLeft = CreateTNode(x);
            }
            else Insert(root->pLeft, x);
        } 
        else {
            if(root -> pRight == nullptr ){
                root -> pRight = CreateTNode(x);
            }
            else Insert(root->pRight, x);
        }
    }

}

int GetHeight(TNode *p){
    if (p == nullptr) return 0;
    if (p->pLeft == nullptr && p->pRight == nullptr) return 0;
    int hLeft = GetHeight(p->pLeft);
    int hRight = GetHeight(p -> pRight);
    return 1 + (hLeft > hRight ? hLeft : hRight);
}


int main()
{
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T.root, data);
        n--;
    }
    
    cout << "Height: " << GetHeight(T.root);
    
    return 0;
}
