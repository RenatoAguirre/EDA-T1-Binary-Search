#include <iostream>
#include <fstream>
#include "algorithms.h"

/*
  * We read the file and insert each line into the array
  * luckily we know how many lines the files have so we can use a fixed size array
  * and don't have to dinamically allocate memory
  * 
  * @params std::string filename: the name of the file to read
  * @params std::string array[]: the array of strings to fill
  * @params int size: the size of the array
  * @return void
*/
void read_file_and_insert_into_array(std::string filename, std::string array[], int size)
{
  std::ifstream file(filename);
  if (!file) std::cerr << "Could not open the file!" << std::endl;

  if (file.is_open())
  {
    std::cout << "File opened" << std::endl;
    for (int i = 0; i < size; i++)
    {
      std::getline(file, array[i]);
    }
    file.close();
  }
}


int main ()
{
  const int SIZE = 10000;
  std::string array[SIZE];
  read_file_and_insert_into_array("../data/D100000.txt", array, SIZE);
  std::cout << array[0] << std::endl;
  return 0;
}