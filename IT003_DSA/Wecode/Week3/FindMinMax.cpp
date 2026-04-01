
#include <iostream>
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
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
void InMinMax(Tree);


void Insert(Tree &T, int x){
    if(T.root == nullptr){
        T.root = CreateTNode(x);
    }
    else{
        TNode *p = T.root;
        while(1){
            if(p->key < x){
                if(p->pRight == nullptr){
                    p->pRight = CreateTNode(x);
                    break;
                }
                else p = p->pRight;
            }
            else{
                if(p->pLeft == nullptr){
                    p->pLeft = CreateTNode(x);
                    break;
                }
                else p = p->pLeft;
            }
        }
    }
}

void InMinMax(Tree T){
    TNode *p = T.root;
    TNode *left = p, *right = p;
    while (left->pLeft != nullptr){
        left = left->pLeft;
    }
    while (right->pRight != nullptr){
        right = right->pRight;
    }
    cout << "Min: " << left->key << endl;
    cout << "Max: " << right->key;

}



int main()
{
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    
    InMinMax(T);
    
    return 0;
}
