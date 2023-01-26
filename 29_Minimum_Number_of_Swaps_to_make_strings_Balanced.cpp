#include <bits/stdc++.h>
using namespace std;

int minSwaps(string str) {
    string unpurified = "";
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '[') {
            unpurified.push_back('[');
        }
        else if(str[i] == ']') {
            if(!unpurified.empty() && unpurified.back() == '[') {
                unpurified.pop_back();
            }
            else {
                unpurified.push_back(str[i]);
            }
        }
    }
    
    int open = unpurified.size() / 2;
    return ((open + 1) / 2);
}

int main() {

    return 0;
}