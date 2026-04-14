#include <iostream>
#include <vector>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}


int MaxGroup(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);
    cout << MaxGroup(r);
    return 0;
}

int MaxGroup(TREE p){
    if(p == nullptr) return 0;

    int sum = p->key;
    if(p->left != nullptr && p->right != nullptr) sum += p->left->key + p->right->key;
    else if(p->right != nullptr) sum += p->right->key;
    else if(p->left != nullptr) sum += p->left->key;

    int subleft = MaxGroup(p->left);
    int subright = MaxGroup(p->right);

    if(sum < subleft) sum = subleft;
    if(sum < subright) sum = subright;
    
    return sum;
}
