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
bool isBrother(Tree, int, int);
void run(int, Tree);

void Insert(TNode* &root, int x){
    if(root == NULL) root = CreateTNode(x);
    else {
        TNode *p = root;
        while(1){
            if(p->key > x){
                if(p->pLeft == nullptr) {
                    p->pLeft = CreateTNode(x);
                    break;
                }
                else p = p->pLeft;
            }
            else if (p-> key < x){
                if(p->pRight == nullptr){
                    p->pRight = CreateTNode(x);
                    break;
                }
                else p = p -> pRight;
            }
            else break;
        }
    }
}

bool isBrother(Tree T, int a, int b){
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    TNode* p = T.root;
    while(p != nullptr){
        if (p -> pLeft != nullptr && p -> pRight != nullptr)
            if(p -> pLeft -> key == a && p -> pRight -> key == b) return true;
        if(p -> key > a) p = p->pLeft;
        else p = p ->pRight;
    }
    return false;
}

void run(int x, Tree T){
    while(x--){
        int a,b;
        cin >> a >> b;
        if(isBrother(T,a,b)) cout << a << " va " << b << " la anh em\n";
        else cout << a << " va " << b << " khong phai la anh em\n";
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
