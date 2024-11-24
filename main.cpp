#include <iostream>
#include <vector>

#include "ArrayGenerator.h"
#include "SortTester.h"


void setArray(const std::vector<int> &arr) {
  constexpr int threshold = 15;
  std::vector<int> arrCopy = arr;
  long long mergeSortTime = SortTester::measureSortTime(arrCopy, false, threshold);
  arrCopy = arr;
  long long hybridSortTime = SortTester::measureSortTime(arrCopy, true, threshold);
  std::cout << "Время для Merge Sort: " << mergeSortTime << " mks\n";
  std::cout << "Время для Hybrid Merge Sort: " << hybridSortTime << " mks\n";
  std::cout << std::endl;
}

int main() {
  std::vector<int> sizes = {500, 600, 700, 800, 900, 1000, 2000, 5000, 10000};
  std::cout << "Cлучайный массив" << std::endl;
  for (int size: sizes) {
    std::cout << "Размер массива: " << size << std::endl;
    std::cout << std::endl;
    auto randomArray = ArrayGenerator::generateRandomArray(size);
    setArray(randomArray);
  }
  std::cout << "##################################";
  std::cout << std::endl;

  std::cout << "Массив, отсортированный по невозрастанию" << std::endl;
  for (int size: sizes) {
    std::cout << "Размер массива: " << size << std::endl;
    std::cout << std::endl;
    auto descendingArray = ArrayGenerator::generateDescendingArray(size);
    setArray(descendingArray);
  }
  std::cout << "##################################";
  std::cout << std::endl;
  std::cout << "Почти отсортированный массив" << std::endl;
  for (int size: sizes) {
    std::cout << "Размер массива: " << size << std::endl;
    std::cout << std::endl;
    auto nearlySortedArray = ArrayGenerator::generateNearlySortedArray(size);
    setArray(nearlySortedArray);
    std::cout << std::endl;
  }

  return 0;
}
