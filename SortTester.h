#ifndef SORTTESTER_H
#define SORTTESTER_H

#include <iostream>
#include <vector>

class SortTester {
public:
  static long long measureSortTime(std::vector<int> &arr, const bool useHybridSort, const int switcherNum) {
    auto start = std::chrono::high_resolution_clock::now();
    if (useHybridSort) {
      mySort(&arr[0], arr.size(), switcherNum);
    } else {
      mergeSort(arr, 0, arr.size() - 1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  }

private:
  static int *mySort(int *start, const size_t n, int switcherNum) {
    if (n < switcherNum) {
      int indx;
      for (int i = 1; i < n; ++i) {
        indx = i;
        while (indx > 0 && start[indx - 1] > start[indx]) {
          std::swap(start[indx - 1], start[indx]);
          --indx;
        }
      }
      return start;
    }
    auto l = mySort(start, n / 2, switcherNum);
    auto r = mySort(start + n / 2, n % 2 ? n / 2 + 1 : n / 2, switcherNum);
    int merged[n];
    for (int i = 0; i < n; ++i) {
      if (*l > *r && r != start + n || l == start + n / 2) {
        merged[i] = *r;
        ++r;
      } else {
        merged[i] = *l;
        ++l;
      }
    }
    for (int i = 0; i < n; ++i) {
      *(start + i) = merged[i];
    }
    return start;
  }

  static void merge(std::vector<int> &arr, const int left,
                    const int mid, const int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
      L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
      R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
      k++;
    }

    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
    }
  }


  static void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left >= right) {
      return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
};


#endif //SORTTESTER_H
