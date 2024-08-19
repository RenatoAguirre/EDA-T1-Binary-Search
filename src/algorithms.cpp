#include <iostream>


int string_in_array_secuential_search(std::string array[], int size, std::string key)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == key)
    {
      return i;
    }
  }
  return -1;
}

int string_in_array_binary_search_recursive(std::string sorted_array[], int low, int size, std::string key)
{   
  if (size < low) // string not found
  {
    return -1;
  }
  int half = low + ((size - low) / 2);
  //std::cout << "half: " << half << std::endl;
  if (key.compare(sorted_array[half]) == 0) // base case
  {  
    return half;
  }
  else if (key.compare(sorted_array[half]) < 0) // string is less than the middle element, ignore second half
  { 
    return string_in_array_binary_search_recursive(sorted_array, low, half - 1, key);
  }
  else  // string is bigger, ignore the first half
  { 
    return string_in_array_binary_search_recursive(sorted_array, half + 1 , size, key);
  };
  return -1;
}

void merge(std::string arr[], int left, int half, int right) {
    int n1 = half - left + 1;
    int n2 = right - half;

    std::string* leftArr = new std::string[n1];
    std::string* rightArr = new std::string[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[half + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr; //important
    delete[] rightArr;
}

void mergeSort(std::string arr[], int left, int right) {
    if (left < right) {
        int half = left + (right - left) / 2;

        mergeSort(arr, left, half);
        mergeSort(arr, half + 1, right);

        merge(arr, left, half, right);
    }
}
