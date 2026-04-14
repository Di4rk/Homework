#include <iostream>
#include <vector>
#include <map>



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

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


int MaxLevel(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    Input(nlr);
    Input(lnr);


    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cout << MaxLevel(r) << endl;

    return 0;
}

void SumOfLevel(TREE t, int level, map<int,int> &p){
    if(t == nullptr ) return;
    p[level] += t -> key;
    SumOfLevel(t -> left, level + 1, p);
    SumOfLevel(t -> right, level + 1, p);
}

int MaxLevel(TREE t){
    if (t == nullptr) return 0;
    map<int,int> q;
    SumOfLevel(t, 0, q);

    int maxLevel = 0;
    int maxsum = q[0];
    for(auto x : q){
        if(x.second > maxsum){
            maxsum = x.second;
            maxLevel = x.first;
        }
    }
    return maxLevel;
}