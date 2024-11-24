#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include <random>
#include <vector>
#include <__random/random_device.h>

class ArrayGenerator {
public:
  static std::vector<int> generateRandomArray(int size, int max_value = 6000) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, max_value);

    for (int i = 0; i < size; ++i) {
      arr[i] = dis(gen);
    }
    return arr;
  }

  ArrayGenerator() = default;

  static std::vector<int> generateDescendingArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
      arr[i] = size - i;
    }
    return arr;
  }


  static std::vector<int> generateNearlySortedArray(int size, int swap_count = 10) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
      arr[i] = i;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);

    for (int i = 0; i < swap_count; ++i) {
      int index1 = dis(gen);
      int index2 = dis(gen);
      std::swap(arr[index1], arr[index2]);
    }
    return arr;
  }
};


#endif //ARRAYGENERATOR_H
