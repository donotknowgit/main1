#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Hash {
public:
    int num; char letter;
    Hash(int num, char letter) { this->num = num; this->letter = letter; };
    friend ostream& operator << (ostream& out, Hash& L);
};
ostream& operator << (ostream& out, Hash& L) { out << L.letter << "=>" << L.num; return out; }

int main() {

    ifstream fin("C:/Users/Alex/Desktop/=)/fin.txt");
    ofstream fout("C:/Users/Alex/Desktop/=)/fout.txt");
    string pass;
    getline(fin, pass);
    int a = int('A');
    int* A = &a;
    unsigned s = (unsigned(std::time(nullptr)) * 73129 + 95121) % (pass.size() - 50);
    for (int turn = 0; turn < 100; turn++) {
        int sum = 0;
        cout << endl << endl << endl << "turn_____" << turn + 1 << "__________" << endl;
        vector<Hash> vec;
        int a = int('a');
        int* A = &a;
        for (int i = 0; i < 26; i++) {
            int n = 0;
            for (int j = s; j < s + 50; j++) {
                if (pass[j] == char(*A)) { n++; }
            }
            if (n > 0) { Hash vec2(n, char(*A)); vec.push_back(vec2); };
            sum += n;
            a++;
        }
        a = int('A');
        for (int i = 0; i < 26; i++) {
            int n = 0;
            for (int j = s; j < s + 50; j++) {
                if (pass[j] == char(*A)) { n++; }
            }
            if (n > 0) { Hash vec2(n, char(*A)); vec.push_back(vec2); };
            sum += n;
            a++;
        }
        for (int i = 0; i < vec.size(); i++) { cout << vec[i] << '\t'; }
        cout << endl << "letters__" << sum << "__________";
        s = (s * 73129 + 95121) % (pass.size() - 50);
    }
    fin.close(); fout.close();
    return 0;
}
