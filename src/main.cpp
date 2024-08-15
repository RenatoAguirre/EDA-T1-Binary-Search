#include <iostream>

int string_in_array_secuential_search(std::string array[], int size, std::string key);

/* 
  * The compare() function compares two strings:
  * 
  * int compare (const string& string-name) const;
  * 
  * This function returns the following values according to the matching cases:
  * 
  * Returns 0 if both the strings are the same.
  * Returns < 0 (less than zero) if the value of the character of the first string is smaller as compared to the second string input.
  * Results out to be > 0 (greater than zero) when the second string is greater in comparison
  * "https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus"
*/
int string_in_array_binary_search_recursive(std::string sorted_array[], int low, int size, std::string key);




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