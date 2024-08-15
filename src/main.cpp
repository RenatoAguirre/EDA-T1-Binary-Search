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


int main ()
{
  std::string array[] = {"ada", "bsad", "cdasd", "ddasd", "eee"};
  std::string key = "cdasd";
  int size = sizeof(array) / sizeof(array[0]);
  int result = string_in_array_secuential_search(array, size, key);
  if (result != -1)
  {
    std::cout << "Element found at index: " << result << std::endl;
  }
  else
  {
    std::cout << "Element not found" << std::endl;
  }
  return 0;
}