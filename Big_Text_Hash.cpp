#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class big_integer {
public:
    static const int BASE = 1000000000;
    std::vector<int> _digits;
    bool _is_negative;
    big_integer(std::string str);
    void _remove_leading_zeros();
    big_integer() {};
    friend std::ostream& operator <<(std::ostream& os, const big_integer& bi);
    operator std::string() const;
    const big_integer operator *(const big_integer& right) {
        big_integer result;
        result._digits.resize(_digits.size() + right._digits.size());
        for (size_t i = 0; i < _digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < right._digits.size() || carry != 0; ++j) {
                long long cur = result._digits[i + j] +
                    _digits[i] * 1LL * (j < right._digits.size() ? right._digits[j] : 0) + carry;
                result._digits[i + j] = static_cast<int>(cur % big_integer::BASE);
                carry = static_cast<int>(cur / big_integer::BASE);
            }
        }
        result._is_negative = _is_negative != right._is_negative;
        result._remove_leading_zeros();
        return result;
    }
};

big_integer::big_integer(std::string str) {
    if (str.length() == 0) {
        this->_is_negative = false;
    }
    else {
        if (str[0] == '-') {
            str = str.substr(1);
            this->_is_negative = true;
        }
        else {
            this->_is_negative = false;
        }
        for (long long i = str.length(); i > 0; i -= 9) {
            if (i < 9)
                this->_digits.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->_digits.push_back(atoi(str.substr(i - 9, 9).c_str()));
        }
        this->_remove_leading_zeros();
    }
}

void big_integer::_remove_leading_zeros() {
    while (this->_digits.size() > 1 && this->_digits.back() == 0) {
        this->_digits.pop_back();
    }
    if (this->_digits.size() == 1 && this->_digits[0] == 0) this->_is_negative = false;
}

std::ostream& operator <<(std::ostream& os, const big_integer& bi) {
    if (bi._digits.empty()) os << 0;
    else {
        if (bi._is_negative) os << '-';
        os << bi._digits.back();
        char old_fill = os.fill('0');
        for (long long i = static_cast<long long>(bi._digits.size()) - 2; i >= 0; --i) {
            os << std::setw(9) << bi._digits[i];
        }

        os.fill(old_fill);
    }

    return os;
}

int main() {
    ifstream fin("C:/Users/Alex/Desktop/=)/fin.txt");
    string file, str;
    while (!fin.eof()) {
        getline(fin, str);
        file += str;
        if (!fin.eof()) {
            file += '\n';
        }
    }
    big_integer prod("1");
    unsigned s = (unsigned(std::time(nullptr)) * 73129 + 95121) % file.size();
    for (int k = 0; k < 10; k++) {
        for (int i = s; i < s + 100; i++) {
            int ch = int(file[i]);
            big_integer c(to_string(int(file[i])));
            prod = prod * c;
        }
        cout << prod << endl << endl;
        big_integer pro("1");
        prod = pro;
        s = (s * 73129 + 95121) % file.size();
    }
    fin.close();
    return 0;
}
