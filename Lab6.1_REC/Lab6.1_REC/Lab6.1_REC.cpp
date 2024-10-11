#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <iomanip> 

void generateArray(int a[], int k, int minValue, int maxValue) {
    std::srand(std::time(0));
    for (int i = 0; i < k; ++i) {
        a[i] = std::rand() % (maxValue - minValue + 1) + minValue;
    }
}

void printArray(const int a[], int k, int i = 0) {
    if (i == k) {
        std::cout << std::endl;
        return;
    }
    std::cout << std::setw(4) << a[i];
    printArray(a, k, i + 1);
}

void processArray(int a[], int k, int& count, int& sum, int i = 0) {
    if (i == k)
    {
        return;
    }
        
    if (a[i] < 0 || a[i] % 2 != 0) 
    { 
        sum += a[i];
        count++;
        a[i] = 0;
    }
    processArray(a, k, count, sum, i + 1);
}

int main() {
    const int k = 24;
    int a[k];
    int count = 0;
    int sum = 0;

    generateArray(a, k, -50, 15);

    std::cout << "a:\n";
    printArray(a, k);

    processArray(a, k, count, sum);

    std::cout << "\ncount: " << count << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    std::cout << "\nModified:\n";
    printArray(a, k);

    return 0;
}