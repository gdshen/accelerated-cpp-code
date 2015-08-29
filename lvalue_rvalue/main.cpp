#include <iostream>
#include <vector>

using namespace std;

void printInt(int &i) {
    cout << "lvalue refercence " << i << "\n";
}
//
void printInt(int &&i) {
    cout << "rvalue reference " << i << "\n";
}

int main() {
    int e = 7;
//    printInt(e);
    printInt(6);

    vector<int> v{1, 2, 3, 6};
    auto t(std::move(v));

    cout << v.size() << "\n";
    for (const auto &i : v) {
        cout << i << " " << "\n";
    }

    for (const auto &i : t) {
        cout << i << " " << "\n";
    }
    return 0;
}