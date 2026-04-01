
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
int DemNutLe(TNode *);


void Insert(Tree &T, int x){
    if(T.root == nullptr){
        T.root = CreateTNode(x);
    }
    else{
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

int DemNutLe(TNode *p){
    if (p == nullptr) return 0;
    if(p->key % 2 != 0) return 1 + DemNutLe(p->pLeft) + DemNutLe(p->pRight);
    else return DemNutLe(p->pLeft) + DemNutLe(p->pRight);
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
    
    cout << "#OddNodes: " << DemNutLe(T.root);
    
    return 0;
}
