#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    random_device x;
    mt19937 rng(x());
    uniform_int_distribution<mt19937::result_type> dist(10, 15);
    cout << dist(rng);
}