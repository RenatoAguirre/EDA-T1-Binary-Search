import matplotlib.pyplot as plt

"""
Extract from the output of the program
(base) ➜  src git:(main) ✗ ./out
Reading queries
Queries read
Setup done.

Running binary search with 10.000 words
Sorting dictionary10000
Dictionary sorted
Sort time: 8 milliseconds
Searching dictionary10000
Binary search: 140 found, 9860 not found
search done in 16 milliseconds


Running sequential search with 10.000 words
reading from file: ../data/D10000.txt
Dictionary read
Sequential search: 140 found, 9860 not found
Sequential search done in: 1837 milliseconds


-------------------------
Running binary search with 50.000 words
Sorting dictionary50000
Dictionary sorted
Sort time: 47 milliseconds
Searching dictionary50000
Binary search: 3519 found, 46481 not found
search done in 87 milliseconds


Running sequential search with 50.000 words
reading from file: ../data/D50000.txt
Dictionary read
Sequential search: 3519 found, 46481 not found
Sequential search done in: 43587 milliseconds


-------------------------
Running binary search with 100.000 words
Sorting dictionary100000
Dictionary sorted
Sort time: 102 milliseconds
Searching dictionary100000
Binary search: 13882 found, 86118 not found
search done in 186 milliseconds


-------------------------
Running sequential search with 100.000 words
reading from file: ../data/D100000.txt
Dictionary read
Sequential search: 13882 found, 86118 not found
Sequential search done in: 167108 milliseconds


-------------------------
Running binary search with 200.000 words
Sorting dictionary200000
Dictionary sorted
Sort time: 217 milliseconds
Searching dictionary200000
Binary search: 55567 found, 144433 not found
search done in 404 milliseconds


Running sequential search with 200.000 words
reading from file: ../data/D200000.txt
Dictionary read
Sequential search: 55567 found, 144433 not found
Sequential search done in: 620368 milliseconds


-------------------------
Running binary search with 400.000 words
Sorting dictionary400000
Dictionary sorted
Sort time: 461 milliseconds
Searching dictionary400000
Binary search: 222806 found, 177194 not found
search done in 865 milliseconds


Running sequential search with 400.000 words
reading from file: ../data/D400000.txt
Dictionary read
Sequential search: 222806 found, 177194 not found
Sequential search done in: 2062273 milliseconds
"""

data = {
    "binary_search": [16, 87, 186, 404, 865],
    "sort": [
        8,
        47,
        102,
        246117,
    ],
    "binnary_search_plus_sort": [24, 134, 288, 621, 1326],
    "sequential_search": [1837, 43587, 167108, 620368, 2062273],
    "n": [10000, 50000, 100000, 200000, 400000],
}
data_without_sequential_search = {
    "binary_search": [16, 87, 186, 404, 865],
    "sort": [8, 47, 102, 217, 461],
    "binnary_search_plus_sort": [24, 134, 288, 621, 1326],
    "n": [10000, 50000, 100000, 200000, 400000],
}

# figure 1
plt.plot(data["n"], data["binnary_search_plus_sort"], label="binnary_search_plus_sort")
plt.plot(data["n"], data["sequential_search"], label="sequential_search")
plt.legend()
plt.xlabel("n")
plt.ylabel("time (ms)")
plt.title("Binary search vs Sequential search")
plt.show()

"""
#figure 2
plt.plot(
    data["n"], data_without_sequential_search["binary_search"], label="binary_search"
)
plt.plot(data["n"], data_without_sequential_search["sort"], label="sort")
plt.plot(
    data["n"],
    data_without_sequential_search["binnary_search_plus_sort"],
    label="binnary_search_plus_sort",
)
plt.legend()
plt.xlabel("n")
plt.ylabel("time (ms)")
plt.title("Binary search")
plt.show()
"""
