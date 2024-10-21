#include <iostream>
using namespace std;

// 遞迴函數
void generateSubsets(char set[], char subset[], int n, int currentIndex, int subsetIndex) {
    // 當前集合已經處理完時，顯示當前的子集合
    if (currentIndex == n) {
        cout << "{ ";
        for (int i = 0; i < subsetIndex; i++) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
        return;
    }
    generateSubsets(set, subset, n, currentIndex + 1, subsetIndex);
    subset[subsetIndex] = set[currentIndex];
    generateSubsets(set, subset, n, currentIndex + 1, subsetIndex + 1);
}

int main(void) {
    int n;
    cout << "請輸入集合的大小: ";
    cin >> n;
    char* set = new char[n];
    cout << "請輸入集合中的元素: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }
    char* subset = new char[n];  // 儲存子集合
    // 生成子集合
    cout << "集合的所有子集合如下:" << endl;
    generateSubsets(set, subset, n, 0, 0);
    // 釋放動態記憶體
    delete[] set;
    delete[] subset;
}
