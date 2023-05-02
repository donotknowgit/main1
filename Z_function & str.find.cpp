#include <iostream>
#include "string"
#include "vector"
using namespace std;

vector<int> StoVi(string str) {
    vector<int> vec;
    for (int i = 0; i < str.size(); i++) {
        vec.push_back(str[i]);
    }
    return vec;
}

int contains(string text, string str) {
    int count = 0;
    for (int i = 0; i < text.size() - str.size() + 1; i++) {
        bool equals = true;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] != text[i + j]) {
                equals = false;
                break;
            }
        }
        if (equals) {
            count++;
        }
    }
    return count;
}

vector<int> Z_func(vector<int> str) {
    vector<int> Z;
    for (int i = 0; i < str.size(); i++) { Z.push_back(INT_MAX); }
    int l = 0; int r = 0;
    for (int i = 1; i < str.size(); i++) {
        Z[i] = max(0, min(r - i, (Z[i - l])));
        while ((i + Z[i] < str.size()) && (str[i + Z[i]] == str[Z[i]])) {
            Z[i] += 1;
        }
        if (i + Z[i] > r) {
            l = i;
            r = i + Z[i];
        }
    }
    return Z;
}

int main() {
    string s = "123";
    string t = "1234512312";
    cout << contains(t, s) << endl;
    cout << "NULL, ";
    for (int i = 1; i < Z_func(StoVi(t)).size(); i++) {
        cout << Z_func(StoVi(t))[i] << ", ";
    }
    return 0;
}