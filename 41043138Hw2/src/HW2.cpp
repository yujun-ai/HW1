#include <iostream>
#include <vector>
using namespace std;

// ���j��ƥͦ�����
void generatePowerset(vector<int>& set, vector<vector<int>>& powerset, vector<int> subset = {}, int index = 0) {
    if (index == set.size()) {
        // ��B�z���Ҧ������ɡA�N��e�l���[�J�쾭����
        powerset.push_back(subset);
        return;
    }
    // ���[�J��e������l�����A���j�B�z�U�@�Ӥ���
    generatePowerset(set, powerset, subset, index + 1);
    // �[�J��e������l�����A���j�B�z�U�@�Ӥ���
    subset.push_back(set[index]);
    generatePowerset(set, powerset, subset, index + 1);
}

// �D��ƥΩ�p��ê�^����
vector<vector<int>> powerset(vector<int>& set) {
    vector<vector<int>> result;
    generatePowerset(set, result);
    return result;
}

int main() {
    vector<int> set = { 1, 2, 3 }; // �w�q�@�ӥܨҶ��X
    vector<vector<int>> result = powerset(set); // �p�⾭��

    // ��X����
    cout << "Powerset: " << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int element : subset) {
            cout << element << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
