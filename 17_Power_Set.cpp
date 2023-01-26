#include <bits/stdc++.h>
using namespace std;

void generateSet(vector<vector<int>>& result, vector<int>& setSoFar, const vector<int> &vec, int index) {
    if (index >= vec.size()) {
        result.push_back(setSoFar);
        return;
    }
    else {
        // recursion
        setSoFar.push_back(vec[index]);
        generateSet(result, setSoFar, vec, index + 1);
        // backtracking
        setSoFar.pop_back();
        generateSet(result, setSoFar, vec, index + 1);
    }
}

vector<vector<int>> generateSet(vector<int>& vec) {
    if (vec.size() == 0) {
        return {};
    }
    vector<vector<int>> result;
    vector<int> setSoFar;
    generateSet(result, setSoFar, vec, 0);
    return result;
}

int main() {
    
    return 0;
}