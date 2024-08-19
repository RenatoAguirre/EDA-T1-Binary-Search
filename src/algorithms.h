#include <iostream>

/*
  * The scuential search algorithm
  * is a simple algorithm that searches for a target value within a list. 
  * by using a for loop to iterate over the list and compare each element to the target value.
  * @params std::string array[]: the array of strings to search
  * @params int size: the size of the array
  * @params std::string key: the string to search
  * @return int: the index of the string in the array ([-1] if the string isn't found)
*/
int string_in_array_secuential_search(std::string array[], int size, std::string key);

/* 
  * The binary search algorithm is a more efficient algorithm for searching for a target value within a list.
  * it works by comparing the target value to the middle element of the list.
  * If the target value is equal to the middle element, the search is successful.
  * If the target value is less than the middle element, the search continues on the first half of the list.
  * If the target value is greater than the middle element, the search continues on the second half of the list.
  * 
  * 
  * We compare the strings by using the compare() function from the string class.
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
  * 
  * 
  * @params std::string sorted_array[]: the array of strings to search
  * @params int low: the lower bound of the array
  * @params int size: the size of the array
  * @params std::string key: the string to search
  * @return int: the index of the string in the array ([-1] if the string isn't found)
*/
int string_in_array_binary_search_recursive(std::string sorted_array[], int low, int size, std::string key);


/*
* The merge function is a helper function for the mergeSort function.
* It merges two subarrays of arr[].
* First subarray is arr[left..half]
* Second subarray is arr[half+1..right]
* @params std::string arr[]: the array of strings to merge
* @params int left: the left index of the array
* @params int half: the middle index of the array
* @params int right: the right index of the array
*/
void merge(std::string arr[], int left, int half, int right);




/*
* The mergeSort function is a recursive function that sorts the array of strings.
* It divides the array into two halves, calls itself for the two halves, and then merges the two halves.
* @params std::string arr[]: the array of strings to sort
* @params int left: the left index of the array
* @params int right: the right index of the array
*/
void mergeSort(std::string arr[], int left, int right);

