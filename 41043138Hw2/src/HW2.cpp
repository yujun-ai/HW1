#include <iostream>
#include <vector>
using namespace std;

// 遞迴函數生成冪集
void generatePowerset(vector<int>& set, vector<vector<int>>& powerset, vector<int> subset = {}, int index = 0) {
    if (index == set.size()) {
        // 當處理完所有元素時，將當前子集加入到冪集中
        powerset.push_back(subset);
        return;
    }
    // 不加入當前元素到子集中，遞迴處理下一個元素
    generatePowerset(set, powerset, subset, index + 1);
    // 加入當前元素到子集中，遞迴處理下一個元素
    subset.push_back(set[index]);
    generatePowerset(set, powerset, subset, index + 1);
}

// 主函數用於計算並返回冪集
vector<vector<int>> powerset(vector<int>& set) {
    vector<vector<int>> result;
    generatePowerset(set, result);
    return result;
}

int main() {
    vector<int> set = { 1, 2, 3 }; // 定義一個示例集合
    vector<vector<int>> result = powerset(set); // 計算冪集

    // 輸出冪集
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
