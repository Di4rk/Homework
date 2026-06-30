#include <iostream>
#include <fstream>

using namespace std;

struct Word {
	string Text;
	string Explanation;
};

void loadData(Word dictionary[], int &n) {
	string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getline(cin>>ws, s);
        dictionary[i].Text = s;
        getline(cin>>ws, s);
        dictionary[i].Explanation = s;
    }
}
void saveData(Word dictionary[], int n) {
    for (int i = 0; i < n; i++) {
        cout << dictionary[i].Text << endl << dictionary[i].Explanation << endl;
    }
}
void Sort(Word [], int );

int main() {
    Word *dictionary = new Word[15000];
	int n;
	loadData(dictionary, n);
	Sort(dictionary, n);

	saveData(dictionary, n);
	delete [] dictionary;
	return 0;
}

void quicksort(Word x[], int low, int high) {
    if(low < high) {
        string pivot = x[high].Text;
        int i = low - 1;

        for(int j = low; j < high; ++j) {
            if(x[j].Text < pivot) {
                ++i;
                swap(x[i], x[j]);
            }
        }
        swap(x[i+1], x[high]);
        int pi = i + 1;

        quicksort(x, low, pi - 1);
        quicksort(x, pi + 1, high);
    }
}

void Sort(Word x[], int n) {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    if(n > 0) {
        quicksort(x, 0, n - 1);
    }
}