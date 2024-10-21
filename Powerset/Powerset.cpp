#include <iostream>
using namespace std;

// ���j���
void generateSubsets(char set[], char subset[], int n, int currentIndex, int subsetIndex) {
    // ��e���X�w�g�B�z���ɡA��ܷ�e���l���X
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
    cout << "�п�J���X���j�p: ";
    cin >> n;
    char* set = new char[n];
    cout << "�п�J���X��������: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }
    char* subset = new char[n];  // �x�s�l���X
    // �ͦ��l���X
    cout << "���X���Ҧ��l���X�p�U:" << endl;
    generateSubsets(set, subset, n, 0, 0);
    // ����ʺA�O����
    delete[] set;
    delete[] subset;
}
