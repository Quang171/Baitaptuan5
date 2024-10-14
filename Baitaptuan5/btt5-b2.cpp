#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> blum_numbers(int N) {
    vector<int> primes, blum_list;
    for (int i = 2; i < N; i++) {
        if (is_prime(i) && (i % 4 == 3)) primes.push_back(i);
    }
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            int product = primes[i] * primes[j];
            if (product < N) blum_list.push_back(product);
        }
    }
    sort(blum_list.begin(), blum_list.end());
    return blum_list;
}

bool check_blum_number(vector<int>& blum_list, int M) {
    return binary_search(blum_list.begin(), blum_list.end(), M);
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> blum_list = blum_numbers(N);
    bool is_blum = check_blum_number(blum_list, M);
    
    for (int blum : blum_list) cout << blum << " ";
    cout << endl << (is_blum ? "YES" : "NO") << endl;
    
    return 0;
}