#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str) {
    unordered_map<char, int> m1;
    string ans;
    for (int i = 0; i < str.length(); ++i)
    {
        if(m1.count(str[i]) == 0){
            m1[str[i]] = 1;
            ans += str[i];
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
