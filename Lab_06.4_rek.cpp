#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

double generateRandomDouble(double min, double max) {
    int randomInt = rand() % ((static_cast<int>(max - min + 1)) * 10);
    return min + static_cast<double>(randomInt) / 10.0;
}

void fillArrayWithRandomNumbers(vector<double>& arr, int size, double min, double max, int index = 0) {
    if (index >= size) {
        return;
    }

    arr[index] = generateRandomDouble(min, max);
    fillArrayWithRandomNumbers(arr, size, min, max, index + 1);
}

void PrintArr(const vector<double>& t, int size, int index = 0) {
    if (index >= size) {
        cout << "}" << endl;
        return;
    }

    cout << fixed << setprecision(2) << setw(7) << t[index];
    if (index < size - 1) {
        cout << ", ";
    }
    PrintArr(t, size, index + 1);
}

int sumElements(const vector<double>& arr, int size, int index = 0) {
    if (index >= size) {
        return 0;
    }

    double sum = 0;
    if (arr[index] > 0) {
        sum = arr[index];
    }
    return sum + sumElements(arr, size, index + 1);
}

double minAndMax(const vector<double>& arr, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return 1.0;
    }

    double product = 1;
    if (startIndex != endIndex) {
        product = arr[startIndex] * minAndMax(arr, startIndex + 1, endIndex);
    }
    return product;
}

void bubbleSort(vector<double>& t, int size, int index = 0, bool swapped = false) {
    if (index >= size - 1) {
        if (swapped) {
            bubbleSort(t, size - 1, 0, false);
        }
        return;
    }

    if (t[index] < t[index + 1] && static_cast<int>(t[index]) % 2 != 0 && static_cast<int>(t[index + 1]) % 2 != 0) {
        swap(t[index], t[index + 1]);
        swapped = true;
    }
    bubbleSort(t, size, index + 1, swapped);
}


int main() {
    double a = -50.0;
    double b = 50.0;
    int N;
    cout << "Enter length of array: ";
    cin >> N;

    const int SIZE = N;
    vector<double> arr(N);

    fillArrayWithRandomNumbers(arr, N, a, b);
    cout << "Array: {";
    PrintArr(arr, N);

    double result = sumElements(arr, N);
    double product = minAndMax(arr, 1, N - 1);

    cout << "===================================" << endl;
    cout << "Sum of positive elements: " << setw(10) << right << result << endl;
    cout << "Product Array: " << setw(10) << right << product << endl;
    cout << "===================================" << endl;

    bubbleSort(arr, N);
    cout << "Sorted array: {";
    PrintArr(arr, N);

    return 0;
}
