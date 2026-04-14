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
bool DeleteNode(TNode* &, int);
void NLR(TNode*);
void process(Tree &, int);

void Insert(TNode* &root, int x){
    if(root == nullptr) root = CreateTNode(x);
    if(root->key == x) return;
    else if(root -> key > x){
        if(root->pLeft == nullptr)
            root -> pLeft = CreateTNode(x);
        else Insert(root->pLeft, x); 
    }
    else {
        if(root -> pRight == nullptr)
            root -> pRight = CreateTNode(x);
        else Insert(root -> pRight, x);
    }
}

bool DeleteNode(TNode* &root, int x){
    if(root == nullptr) return false;

    if(root->key > x) return DeleteNode(root -> pLeft, x);
    if(root->key < x) return DeleteNode(root -> pRight, x);

    TNode* p = root;

    if(p->pLeft == nullptr){
        root = root->pRight;
    }
    else if (p -> pRight == nullptr){
        root = root ->pLeft;
    }
    else{
        TNode* current = root;
        TNode* subcurrent = root -> pRight;
        while(subcurrent -> pLeft != nullptr){
            current = subcurrent;
            subcurrent = subcurrent -> pLeft;
        }

        root -> key = subcurrent -> key;
        if(current == root){
            current -> pRight = subcurrent -> pRight;
        }
        else 
            current -> pLeft = subcurrent -> pRight;
        p = subcurrent;
    }
    delete p;
    return true;
}

void NLR(TNode* p){
    if(p == nullptr) return;
    cout << p->key << " ";
    NLR(p->pLeft);
    NLR(p->pRight);
}

void process(Tree &T, int a){
    if (DeleteNode(T.root, a)) cout << "Da xoa nut " << a << "\n";
    else cout << "Khong tim thay nut " << a << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n, k; cin >> n;
    while(n--) {
        cin >> k;
        Insert(T.root, k);
    }
    int q, x; cin >> q;
    while(q--){
        cin >> x;
        process(T, x);
    }
    cout << "NLR: ";
    NLR(T.root);
    return 0;
}