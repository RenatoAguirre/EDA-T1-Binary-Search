#include <iostream>
#include <fstream>
#include "algorithms.h"
#include <chrono>

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
    //std::cout << "File opened" << std::endl;
    for (int i = 0; i < size; i++)
    {
      std::getline(file, array[i]);
    }
    file.close();
  }
}

/*
  *reads query text file and stores it in an array
  * @params array of strings
*/
void get_queries(std::string query_array[])
{
  const int SIZE = 1000000;
  read_file_and_insert_into_array("../data/Nc.txt", query_array, SIZE);
}


/*
  * We search the query array in the dictionary array using the sequential search algorithm
  * we also count how many finds we had and how many words were not found
  * @params std::string dictionary[]: the array of strings to search
  * @params std::string query_array[]: the array of strings to search for
  * @params int size: the size of the dictionary array
  * @return void
*/
void search_in_dictionary_sequential(std::string dictionary[], std::string query_array[], int size)
{ 
  int found = 0;
  int not_found = 0; 
  for (int i = 0; i < size; i++)
  {
    int search = string_in_array_secuential_search(dictionary, size, query_array[i]);
    if (search != -1)
    {
      found++;
    }
    else
    {
      not_found++;
    }
  }
  std::cout << "Sequential search: " << found << " found, " << not_found << " not found" << std::endl;
}

/*
  * We search the query array in the dictionary array using the binary search algorithm
  * we also count how many finds we had and how many words were not found
  * @params std::string dictionary[]: the array of strings to search
  * @params std::string query_array[]: the array of strings to search for
  * @params int size: the size of the dictionary array
  * @return void
*/
void search_in_dictionary_binary(std::string dictionary[], std::string query_array[], int size)
{
  int found = 0;
  int not_found = 0;
  for (int i = 0; i < size; i++)
  {
    int search = string_in_array_binary_search_recursive(dictionary, 0, size, query_array[i]);
    if (search != -1)
    {
      found++;
    }
    else
    {
      not_found++;
    }
  }
  std::cout << "Binary search: " << found << " found, " << not_found << " not found" << std::endl;
}

/* 
  * this functions reads the dictionary file and stores it in an array
  * then it runs the sequential search algorithm and times it 
  * @params int DICTIONARY_SIZE: the size of the dictionary array
  * @params std::string query_array[]: the array of strings to search for
  * @return void
*/
void run_and_time_sequential_search(const int DICTIONARY_SIZE, std::string query_array[])
{
  /* get dictionary */
  
  std::string* dictionary_array = new std::string[DICTIONARY_SIZE];

  const std::string filename = "../data/D" + std::to_string(DICTIONARY_SIZE) + ".txt";
  std::cout << "reading from file: " << filename << std::endl;
  read_file_and_insert_into_array(filename, dictionary_array, DICTIONARY_SIZE);
  std::cout << "Dictionary read" << std::endl;
  
  
  /* search queries and time it */
  auto start = std::chrono::high_resolution_clock::now();
  search_in_dictionary_sequential(dictionary_array, query_array, DICTIONARY_SIZE);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Sequential search done in: " << duration.count() << " milliseconds" << std::endl;

  delete[] dictionary_array;
}

/* 
  * this functions reads the dictionary file and stores it in an array
  * then it runs the binary search algorithm and times it 
  * also it times the sorting of the dictionary array separately
  * @params int DICTIONARY_SIZE: the size of the dictionary array
  * @params std::string query_array[]: the array of strings to search for
  * @return void
*/
void run_and_time_binary_search(const int DICTIONARY_SIZE, std::string query_array[])
{
  /* get dictionary */
  
  std::string* dictionary_array = new std::string[DICTIONARY_SIZE];
  const std::string filename = "../data/D" + std::to_string(DICTIONARY_SIZE) + ".txt";
  //std::cout << "reading from file: " << filename << std::endl;
  read_file_and_insert_into_array(filename, dictionary_array, DICTIONARY_SIZE);
  //std::cout << "Dictionary read" << std::endl;
  
  /* sort and time dictionary array*/
  std::cout << "Sorting dictionary" << std::to_string(DICTIONARY_SIZE) << std::endl;
  auto sort_start = std::chrono::high_resolution_clock::now();

  std::sort(dictionary_array, dictionary_array + DICTIONARY_SIZE);
  
  auto sort_end = std::chrono::high_resolution_clock::now();
  auto sort_duration = std::chrono::duration_cast<std::chrono::milliseconds>(sort_end - sort_start);
  std::cout << "Dictionary sorted" << std::endl;
  std::cout << "Sort time: " << sort_duration.count() << " milliseconds" << std::endl;
  
  /* search queries and time it */
  std::cout << "Searching dictionary" << std::to_string(DICTIONARY_SIZE) << std::endl;
  auto start = std::chrono::high_resolution_clock::now();
  search_in_dictionary_binary(dictionary_array, query_array, DICTIONARY_SIZE);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "search done in " << duration.count() << " milliseconds" << std::endl;

  delete[] dictionary_array;
}

/*
  * Main function
  * runs the binary search and sequential search algorithms with different sizes of dictionaries and logs the time it took to run
  * @params void
  * @return int
*/
int main ()
{
  /* get queries */
  std::cout << "Reading queries" << std::endl;
  const int QUERY_SIZE = 1000000;
  //std::cout << QUERY_SIZE << std::endl;
  std::string* query_array = new std::string[QUERY_SIZE];
  get_queries(query_array);
  std::cout << "Queries read" << std::endl;
  std::cout << "Setup done. \n" << std::endl;

  /*10000*/
  /* run binary search */
  std::cout << "Running binary search with 10.000 words" << std::endl;
  run_and_time_binary_search(10000, query_array);

  std::cout << "\n" << std::endl;

  std::cout << "Running sequential search with 10.000 words" << std::endl;
  /* run_sequential_search */
  run_and_time_sequential_search(10000, query_array);

  std::cout << "\n" << std::endl;
  std::cout << "-------------------------" << std::endl;
  /* 50000 */
  /* run binary search */
  std::cout << "Running binary search with 50.000 words" << std::endl;
  run_and_time_binary_search(50000, query_array);

  std::cout << "\n" << std::endl;

  std::cout << "Running sequential search with 50.000 words" << std::endl;
  /* run_sequential_search */
  run_and_time_sequential_search(50000, query_array);

  std::cout << "\n" << std::endl;
  std::cout << "-------------------------" << std::endl;
  /*100000*/
  /* run binary search */
  std::cout << "Running binary search with 100.000 words" << std::endl;
  run_and_time_binary_search(100000, query_array);

  std::cout << "\n" << std::endl;
  std::cout << "-------------------------" << std::endl;


  std::cout << "Running sequential search with 100.000 words" << std::endl;
  /* run_sequential_search */
  run_and_time_sequential_search(100000, query_array);

  std::cout << "\n" << std::endl;
  std::cout << "-------------------------" << std::endl;
  /*200000*/
  /* run binary search */
  std::cout << "Running binary search with 200.000 words" << std::endl;
  run_and_time_binary_search(200000, query_array);

  std::cout << "\n" << std::endl;

  std::cout << "Running sequential search with 200.000 words" << std::endl;
  /* run_sequential_search */
  run_and_time_sequential_search(200000, query_array);

  std::cout << "\n" << std::endl;
  std::cout << "-------------------------" << std::endl;

  /*400000*/
  /* run binary search */
  std::cout << "Running binary search with 400.000 words" << std::endl;
  run_and_time_binary_search(400000, query_array);

  std::cout << "\n" << std::endl;

  std::cout << "Running sequential search with 400.000 words" << std::endl;
  /* run_sequential_search */
  run_and_time_sequential_search(400000, query_array);
  
  delete[] query_array;
  return 0;
}