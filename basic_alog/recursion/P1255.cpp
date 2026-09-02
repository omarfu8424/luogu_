#include <iostream>
#include <vector>


using namespace std;

class BIGINT {
    std::vector<int> numbers;

    static void normalize(std::vector<int> &v) {
        while (v.size() > 1 && v.back() == 0) {
            v.pop_back();
        }
    }

public:
    BIGINT() {
        numbers.push_back(0);
    }

    BIGINT(int value) {
        *this = value;
    }

    BIGINT &operator=(const int &r) {
        numbers.clear();
        if (r == 0) {
            numbers.push_back(0);
            return *this;
        }

        int x = r;
        while (x > 0) {
            numbers.push_back(x % 10);
            x /= 10;
        }
        return *this;
    }

    BIGINT &operator+=(const BIGINT &rhs) {
        int carry = 0;
        size_t maxLen = max(numbers.size(), rhs.numbers.size());
        std::vector<int> result(maxLen+1, 0);

        for (size_t i = 0; i < maxLen || carry; ++i) {
            int a = i < numbers.size() ? numbers[i] : 0;
            int b = i < rhs.numbers.size() ? rhs.numbers[i] : 0;
            int sum = a + b + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }

        numbers = std::move(result);
        normalize(numbers);
        return *this;
    }

    BIGINT operator+(const BIGINT &rhs) const {
        BIGINT temp = *this;
        temp += rhs;
        return temp;
    }

    BIGINT &operator-=(const BIGINT &rhs) {
        int borrow = 0;
        std::vector<int> result(numbers.size(), 0);

        for (size_t i = 0; i < numbers.size(); ++i) {
            int a = numbers[i];
            int b = i < rhs.numbers.size() ? rhs.numbers[i] : 0;
            int diff = a - b - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result[i] = diff;
        }

        numbers = std::move(result);
        normalize(numbers);
        return *this;
    }

    BIGINT operator-(const BIGINT &rhs) const {
        BIGINT temp = *this;
        temp -= rhs;
        return temp;
    }

    friend ostream &operator<<(ostream &os, const BIGINT &bigint) {
        for (int i = bigint.numbers.size() - 1; i >= 0; i--) {
            os << bigint.numbers[i];
        }
        return os;
    }
};





int main(){
    int n;  cin >> n;
    BIGINT p, pp;
    p = 1;
    pp = 0;
    while (n-- > 0) {
        p = p + pp;
        pp = p - pp;        
    }
    cout << p << '\n';
    
    return 0;
    
}