#include <iostream>
#include "algorithms.h"



int main ()
{
  std::string array[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
  std::string key = "cherry";
  int size = sizeof(array) / sizeof(array[0]);
  
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "apple") << std::endl;
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "banana") << std::endl;
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "cherry") << std::endl;
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "date") << std::endl;
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "elderberry") << std::endl;
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "fig") << std::endl;
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "grape") << std::endl;
  std::cout << string_in_array_binary_search_recursive(array, 0, size - 1, "kiwi") << std::endl;
  return 0;
}