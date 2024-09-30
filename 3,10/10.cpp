#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>

//1
int sumOfDigits(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        while (num != 0) {
            sum += std::abs(num % 10);
            num /= 10;
        }
    }
    return sum;
}

//2
double averagePositive(const std::vector<int>& arr) {
    int sum = 0, count = 0;
    for (int num : arr) {
        if (num > 0) {
            sum += num;
            count++;
        }
    }
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}

//3
void maxNegativeElement(const std::vector<int>& arr) {
    int maxNegative = std::numeric_limits<int>::min();
    int pos = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0 && arr[i] > maxNegative) {
            maxNegative = arr[i];
            pos = i;
        }
    }
    if (pos != -1)
        std::cout << "Max negative element: " << maxNegative << " at position " << pos << std::endl;
    else
        std::cout << "No negative elements found." << std::endl;
}

//4
int mostFrequentNumber(const std::vector<int>& arr) {
    std::map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }

    int mostFrequent = arr[0];
    int maxCount = 0;
    for (const auto& pair : frequency) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }
    return mostFrequent;
}

//5
int maxOddIndexDivisibleBy3(const std::vector<int>& arr) {
    int maxElement = -1;
    for (int i = 1; i < arr.size(); i += 2) {
        if (arr[i] % 3 == 0 && arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

//6
void swapMaxEvenMinOdd(std::vector<int>& arr) {
    int maxEven = std::numeric_limits<int>::min(), maxEvenPos = -1;
    int minOdd = std::numeric_limits<int>::max(), minOddPos = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0 && arr[i] > maxEven) {
            maxEven = arr[i];
            maxEvenPos = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
            minOddPos = i;
        }
    }

    if (maxEvenPos != -1 && minOddPos != -1) {
        std::swap(arr[maxEvenPos], arr[minOddPos]);
    }
    else {
        std::fill(arr.begin(), arr.end(), 0);
    }
}

// 7
std::vector<int> intersection(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;
    for (int num : arr1) {
        if (std::find(arr2.begin(), arr2.end(), num) != arr2.end()) {
            result.push_back(num);
        }
    }
    return result;
}

std::vector<int> symmetricDifference(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;
    for (int num : arr1) {
        if (std::find(arr2.begin(), arr2.end(), num) == arr2.end()) {
            result.push_back(num);
        }
    }
    for (int num : arr2) {
        if (std::find(arr1.begin(), arr1.end(), num) == arr1.end()) {
            result.push_back(num);
        }
    }
    return result;
}

void menu() {
    std::cout << "Choose an option:\n";
    std::cout << "1. Сумма\n";
    std::cout << "2. Среднее арифметическое положительных элементов\n";
    std::cout << "3. Максимальный отрицательный элемент\n";
    std::cout << "4. Число, чаще всего встречающееся в массиве\n";
    std::cout << "5. Наибольший элемент с нечетными номерами, делящийся на 3\n";
    std::cout << "6. Поменять местами наибольший четный и наименьший нечетный элемент\n";
    std::cout << "7. Формирование третьего массива (пересечение и симметричная разность)\n";
    std::cout << "0. Выход\n";
}

int main() {
    int choice;
    std::vector<int> arr = { 12, 104, 81, -5, 3, 7, -2, 10 };
    std::vector<int> arr2 = { 3, 5, 7, 104 };

    do {
        menu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Sum of digits: " << sumOfDigits(arr) << std::endl;
            break;
        case 2:
            std::cout << "Average of positive elements: " << averagePositive(arr) << std::endl;
            break;
        case 3:
            maxNegativeElement(arr);
            break;
        case 4:
            std::cout << "Most frequent number: " << mostFrequentNumber(arr) << std::endl;
            break;
        case 5:
            std::cout << "Max element with odd index divisible by 3: " << maxOddIndexDivisibleBy3(arr) << std::endl;
            break;
        case 6:
            swapMaxEvenMinOdd(arr);
            std::cout << "Array after swap: ";
            for (int num : arr)
                std::cout << num << " ";
            std::cout << std::endl;
            break;
        case 7: {
            std::vector<int> inter = intersection(arr, arr2);
            std::vector<int> symDiff = symmetricDifference(arr, arr2);
            std::cout << "Intersection: ";
            for (int num : inter) std::cout << num << " ";
            std::cout << std::endl;
            std::cout << "Symmetric difference: ";
            for (int num : symDiff) std::cout << num << " ";
            std::cout << std::endl;
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
