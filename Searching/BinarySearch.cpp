#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& a, int target) {
    int low= 0, high= (int)a.size() - 1;
    while (low<= high) {
        int mid = low+ (high- low) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) low= mid + 1;
        else high= mid - 1;
    }
    return -1;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    cout << binarySearch(a, 7) << "\n";   // 3
    cout << binarySearch(a, 4) << "\n";   // -1
}
