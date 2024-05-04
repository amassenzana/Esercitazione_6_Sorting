#include <iostream>
#include <chrono>
#include <vector>
#include <unistd.h>
#include <numeric>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std;

// void printvec(vector<int>& v){
//     int n = v.size();
//     for(int i = 0; i < n; i++){
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

void testSort(vector<int>& vec){
    vector<int> v = vec;

    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
    SortLibrary::BubbleSort(v);
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "\tBS" << ": " << duration << "ms";

    v = vec;

    t_begin = std::chrono::steady_clock::now();
    SortLibrary::MergeSort(v);
    t_end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "\tMS" << ": " << duration << "ms";
}



int main(int argc, char **argv){

    int n = stoi(argv[1]);
    cout << "Dimension of the problem: " << n << endl;
    vector<int> v1(n);
    int k;
    srand(time(NULL));

    cout << "\nReverse vector:\t\t";
    k = n;
    generate(v1.begin(), v1.end(), [&k](){return k--;});
    testSort(v1);

    cout << "\nOrdinate vector:\t\t";
    k = 0;
    generate(v1.begin(), v1.end(), [&k](){return k++;});
    testSort(v1);


    cout << "\nRandom Vector (0,n):\t";
    generate(v1.begin(), v1.end(), [&n](){return rand()%n;});
    testSort(v1);

    cout << "\nRandom Vector (0,500):\t";
    generate(v1.begin(), v1.end(), [&n](){return rand()%501;});
    testSort(v1);

    cout << "\nRandom Vector (0,2000):";
    generate(v1.begin(), v1.end(), [&n](){return rand()%2000;});
    testSort(v1);


    cout << "\n";
    return 0;
}

