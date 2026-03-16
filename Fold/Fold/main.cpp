#include <iostream>
#include <cassert>
using namespace std;

int fold(const vector<int>& vect, function<int(int, int)> f, int idx = 0) {
    if (idx == vect.size() - 1)
        return vect[idx];
    
    return f(vect[idx], fold(vect, f, idx + 1));
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int main() {
    vector<int> vect = {1, 2, 3, 4, 5};
    
    assert(fold(vect, add) == 15);
    assert(fold(vect, mult) == 120);
}
