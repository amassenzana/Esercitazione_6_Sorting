#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "SortingAlgorithm.hpp"
#include <iomanip>

using namespace std;

void testSort(vector<int>& vec, double& tB, double& tM){
    vector<int> v = vec;

    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
    SortLibrary::BubbleSort(v);
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
    tB = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();


    v = vec;

    t_begin = std::chrono::steady_clock::now();
    SortLibrary::MergeSort(v);
    t_end = std::chrono::steady_clock::now();
    tM = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();

}



int main(int argc, char **argv){
    if (argc < 2){
        cerr << "Inserisci la dimensione da linea di comando";
        return 0;
    }

    int n = stoi(argv[1]);
    cout << "Dimension of the problem: " << n << endl;
    vector<int> v1(n);
    int k;
    srand(time(NULL));
    double tB, tM;

    cout << "-----First attempt-----" << endl;
    cout << "Ordinate vector:\t\t";
    k = 0;
    generate(v1.begin(), v1.end(), [&k](){return k++;});
    testSort(v1, tB, tM);
    cout << "\tBS" << ": " << tB << "ms";
    cout << "\tMS" << ": " << tM << "ms" << endl;


    cout << "Reverse vector:\t\t";
    k = n;
    generate(v1.begin(), v1.end(), [&k](){return k--;});
    testSort(v1, tB, tM);
    cout << "\tBS" << ": " << tB << "ms";
    cout << "\tMS" << ": " << tM << "ms" << endl;


    cout << "Random Vector (0,n):\t";
    generate(v1.begin(), v1.end(), [&n](){return rand()%n;});
    testSort(v1, tB, tM);
    cout << "\tBS" << ": " << tB << "ms";
    cout << "\tMS" << ": " << tM << "ms" << endl;


    cout << "Random Vector (0,500):\t";
    generate(v1.begin(), v1.end(), [&n](){return rand()%501;});
    testSort(v1, tB, tM);
    cout << "\tBS" << ": " << tB << "ms";
    cout << "\tMS" << ": " << tM << "ms" << endl;


    cout << "Random Vector (0,2000):";
    generate(v1.begin(), v1.end(), [&n](){return rand()%2000;});
    testSort(v1, tB, tM);
    cout << "\tBS" << ": " << tB << "ms";
    cout << "\tMS" << ": " << tM << "ms" << endl;




    cout << "\n\n----Calculating mean over 30 test----" << endl;
    cout << fixed << setprecision(1);
    double totalBS = 0, totalMS = 0; k = n;

    // ORDINATED VECTOR
    totalBS = 0; totalMS = 0; k = 0;
    generate(v1.begin(), v1.end(), [&k](){return k++;});
    for(size_t i = 0; i < 30; i++){
        testSort(v1, tB, tM);
        totalBS += tB;
        totalMS += tM;
    }
    cout << "Ordinated vector:\t\t"
         << "\tBS" << ": " << totalBS/30 << "ms"
         << "\t\tMS" << ": " << totalMS/30 << "ms" << endl;


    // REVERSE VECTOR
    generate(v1.begin(), v1.end(), [&k](){return k--;});
    for(size_t i = 0; i < 30; i++){
        testSort(v1, tB, tM);
        totalBS += tB;
        totalMS += tM;
    }
    cout << "Reverse vector:\t\t"
         << "\tBS" << ": " << totalBS/30 << "ms"
         << "  \tMS" << ": " << totalMS/30 << "ms" << endl;



    // RANDOM VECTOR [0,n]
    totalBS = 0; totalMS = 0;
    for(size_t i = 0; i < 30; i++){
        generate(v1.begin(), v1.end(), [&n](){return rand()%n;});
        testSort(v1, tB, tM);
        totalBS += tB;
        totalMS += tM;
    }
    cout << "Random Vector (0,n):\t"
         << "\tBS" << ": " << totalBS/30 << "ms"
         << "  \tMS" << ": " << totalMS/30 << "ms" << endl;


    // RANDOM VECTOR [0,500]
    totalBS = 0; totalMS = 0;
    for(size_t i = 0; i < 30; i++){
        generate(v1.begin(), v1.end(), [&n](){return rand()%501;});
        testSort(v1, tB, tM);
        totalBS += tB;
        totalMS += tM;
    }
    cout << "Random Vector (0,500):\t"
         << "\tBS" << ": " << totalBS/30 << "ms"
         << "  \tMS" << ": " << totalMS/30 << "ms" << endl;


    // RANDOM VECTOR [0,2000]
    totalBS = 0; totalMS = 0;
    for(size_t i = 0; i < 30; i++){
        generate(v1.begin(), v1.end(), [&n](){return rand()%2001;});
        testSort(v1, tB, tM);
        totalBS += tB;
        totalMS += tM;
    }
    cout << "Random Vector (0,2000):"
         << "\tBS" << ": " << totalBS/30 << "ms"
         << "  \tMS" << ": " << totalMS/30 << "ms" << endl;



    return 0;
}

