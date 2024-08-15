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
