
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
bool isFather(Tree, int, int);
void run(int, Tree);

void Insert(TNode* &T, int x){
    if(T == NULL){
        T = CreateTNode(x);
    }
    else{
        TNode *p = T;
        while(1){
            if(p->key > x){
                if(p->pLeft == NULL){
                    p->pLeft = CreateTNode(x);
                    break;
                }
                else p = p->pLeft;
            }
            else{
                if(p->pRight == NULL){
                    p->pRight = CreateTNode(x);
                    break;
                }
                else p = p->pRight;
            }
        }
    }
}

bool isFather(Tree T, int a, int b){
    TNode *curr = T.root;
    while(curr != NULL){
        if(curr->key == a){
            if (curr -> pLeft != NULL && curr->pLeft->key == b) return true;
            if (curr -> pRight != NULL && curr->pRight->key == b) return true;
            return false;
        }
        else if (curr->key > a) {
            curr = curr->pLeft;
        }
        else 
            curr = curr->pRight;
    }
    return false;
}

void run(int x, Tree T){
    while(x--){
        int a,b;
        cin >> a >> b;
        if(isFather(T, a, b)){
            cout << a << " la cha cua " << b << "\n";
        }
        else if(isFather(T, b ,a)){
            cout << b << " la cha cua " << a << "\n";
        }
        else cout << a << " va " << b << " khong co quan he cha con" << "\n";
    }
}







int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T.root, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);
    
    return 0;
}
