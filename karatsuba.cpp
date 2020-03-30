#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string karatsuba(string x, string y) {
    // ensure numbers have the same length
    while (x.size() < y.size()) {
        x.insert(0, "0");
    }
    while (y.size() < x.size()) {
        y.insert(0, "0");
    }
    int n = x.size();
    int n2 = (n + 1) >> 1;
    if (n == 1) {  // base case
        string ret = to_string((x[0] - '0') * (y[0] - '0'));
        return ret;
    }
    // decompose x and y
    string x1, x0, y1, y0;
    x1 = x.substr(0, n2);
    x0 = x.substr(n2, n - n2);
    y1 = y.substr(0, n2);
    y0 = y.substr(n2, n - n2);

    string z0, z2, z1, a;
    z0 = karatsuba(x0, y0);
    z2 = karatsuba(x1, y1);
    ll x1ll, x0ll, y1ll, y0ll;
    x1ll = stoll(x1, nullptr, 10);
    x0ll = stoll(x0, nullptr, 10);
    y1ll = stoll(y1, nullptr, 10);
    y0ll = stoll(y0, nullptr, 10);
    string sumxStr = to_string(x0ll + x1ll);
    string sumyStr = to_string(y0ll + y1ll);
    a = karatsuba(sumxStr, sumyStr);
    z1 = to_string(stoll(a, nullptr, 10) - stoll(z0, nullptr, 10) -
                   stoll(z2, nullptr, 10));
    ll z0ll = stoll(z0, nullptr, 10);
    for (int i = 0; i < n - n2; i++) {
        z1 += "0";
    }
    for (int i = 0; i < 2 * (n - n2); i++) {
        z2 += "0";
    }
    ll z1ll = stoll(z1, nullptr);
    ll z2ll = stoll(z2, nullptr);
    ll retll = z2ll + z1ll + z0ll;
    string ret = to_string(retll);
    return ret;
}

int main() {
    string x = "123456";
    string y = "777888";
    cout << karatsuba(x, y) << endl;
    return 0;
}