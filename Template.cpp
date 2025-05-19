#include <iostream>
using namespace std;

template<typename T>
T maxx(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << maxx<int>(3, 7) << endl;
    cout << maxx<double>(3, 7) << endl;
    cout << maxx<float>(3, 7) << endl;
    return 0;
}

