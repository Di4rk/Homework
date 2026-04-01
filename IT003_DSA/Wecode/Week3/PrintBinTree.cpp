
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
void NLR(TNode *);
void NRL(TNode *);
void LNR(TNode *);
void LRN(TNode *);
void RNL(TNode *);
void RLN(TNode *);


void Insert(Tree &T, int x){
    if(T.root == NULL){
        T.root = CreateTNode(x);
    }
    else{            
        TNode *p = T.root;
        while(true){
        if(p->key == x){
            break;
        }
        else if (p->key > x){
            if(p->pLeft == nullptr){
                p->pLeft = CreateTNode(x);
                break;
            }
            else{
                p = p->pLeft;
            }
        }
        else {
            if (p->pRight == nullptr){
                p->pRight = CreateTNode(x);
                break;
            }
            else {
                p = p->pRight;
            }
        }
        }
    }
}

void NLR(TNode *p){
    if (p == nullptr) return;

    cout << p->key << " ";

    NLR(p->pLeft);
    NLR(p->pRight);
}

void NRL(TNode *p){
    if (p == nullptr) return;

    cout << p->key << " ";
    
    NRL(p->pRight);
    NRL(p->pLeft);
}

void LNR(TNode *p){
    if (p == nullptr) return;

    LNR(p->pLeft);
    cout << p->key << " ";
    LNR(p->pRight);
}

void RNL(TNode *p){
    if (p == nullptr) return;

    RNL(p->pRight);
    cout << p->key << " ";
    RNL(p->pLeft);
}

void LRN(TNode *p){
    if (p == nullptr) return;

    LRN(p->pLeft);    
    LRN(p->pRight);
    cout << p->key << " ";
}

void RLN(TNode *p){
    if (p == nullptr) return;
 
    RLN(p->pRight);
    RLN(p->pLeft);   
    cout << p->key << " ";
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
    
    cout << "NRL: ";
    NRL(T.root);
    cout << "\n";

    cout << "LNR: ";
    LNR(T.root);
    cout << "\n";

    cout << "LRN: ";
    LRN(T.root);
    cout << "\n";

    cout << "RLN: ";
    RLN(T.root);
    cout << "\n";

    cout << "RNL: ";
    RNL(T.root);
    
    return 0;
}
