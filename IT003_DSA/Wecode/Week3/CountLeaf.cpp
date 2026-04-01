
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
int DemNutLa(TNode *);

void Insert(Tree &T, int x){
    if(T.root == nullptr) {
        T.root = CreateTNode(x); 
    }
    else {
        TNode *p = T.root;
        while(1){
            if(p->key > x){
                if(p->pLeft == nullptr){
                    p->pLeft = CreateTNode(x);
                    break;
                }
                else p = p->pLeft;
            }
            else{
                if(p->pRight == nullptr){
                    p->pRight = CreateTNode(x);
                    break;
                }
                else p = p->pRight;
            }
        }
    }
}

int DemNutLa(TNode *p){
    if(p == nullptr) return 0;
    if(p->pLeft == nullptr && p->pRight == nullptr) return 1;
    else return DemNutLa(p->pLeft) + DemNutLa(p->pRight);
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
    
    cout << "#LeafNodes: " << DemNutLa(T.root);
    
    return 0;
}
