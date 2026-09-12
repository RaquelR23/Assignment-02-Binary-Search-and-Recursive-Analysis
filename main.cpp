#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
// This function searches for the key by repeatedly
// cutting the search range in half.
// It returns the index of the key or -1 if not found.
int BinarySearch_I(const vector<int> &numbers, int key, int &comparisons)
{
    int low = 0;
    int high = static_cast<int>(numbers.size()) - 1;

    // Start the comparison counter at 0.
    comparisons = 0;

    // Continue searching while the range is not empty.
    while (low <= high)
    {
        // Find the middle position.
        int mid = low + (high - low) / 2;

        // Compare the middle element with the key.
        comparisons++;

        if (numbers[mid] < key)
        {
            // The key must be in the right half.
            low = mid + 1;
        }
        else
        {
            // We know numbers[mid] is not less than key,
            // so check if it is greater than key.
            comparisons++;

            if (numbers[mid] > key)
            {
                // The key must be in the left half.
                high = mid - 1;
            }
            else
            {
                // The middle element is equal to the key.
                return mid;
            }
        }
    }

    // The key was not found.
    return -1;
}

// Recursive Binary Search
// This function works like the iterative version,
// but it searches one half of the vector by calling itself.
int BinarySearch_R(const vector<int> &numbers, int low, int high, int key, int &comparisons)
{
    // Base case:
    // If low is greater than high, there are no elements left.
    if (low > high)
    {
        return -1;
    }

    // Find the middle position.
    int mid = low + (high - low) / 2;

    // Compare the middle element with the key.
    comparisons++;

    if (numbers[mid] < key)
    {
        // Search the right half recursively.
        return BinarySearch_R(numbers, mid + 1, high, key, comparisons);
    }
    else
    {
        // We know numbers[mid] is not less than key,
        // so check if it is greater than key.
        comparisons++;

        if (numbers[mid] > key)
        {
            // Search the left half recursively.
            return BinarySearch_R(numbers, low, mid - 1, key, comparisons);
        }
        else
        {
            // The middle element is equal to the key.
            return mid;
        }
    }
}

// Linear Search
// This function checks every element from left to right.
// It returns the index of the key or -1 if not found.
int LinearSearch(const vector<int> &numbers, int key, int &comparisons)
{
    // Start the comparison counter at 0.
    comparisons = 0;

    // Check each element one at a time.
    for (int i = 0; i < static_cast<int>(numbers.size()); i++)
    {
        // Compare the current element with the key.
        comparisons++;

        if (numbers[i] == key)
        {
            // The key was found.
            return i;
        }
    }

    // The key was not found.
    return -1;
}

// This function runs one test using all three
// search methods and displays their results.
void RunTest(const vector<int> &numbers, int key)
{
    // Variables used to count comparisons.
    int iterativeComparisons = 0;
    int recursiveComparisons = 0;
    int linearComparisons = 0;

    // Run iterative binary search.
    int iterativeIndex =
        BinarySearch_I(numbers, key, iterativeComparisons);

    // Run recursive binary search.
    int recursiveIndex =
        BinarySearch_R(numbers, 0, static_cast<int>(numbers.size()) - 1, key, recursiveComparisons);

    // Run linear search.
    int linearIndex =
        LinearSearch(numbers, key, linearComparisons);

    cout << "Searching for: " << key << endl;

    // Display the iterative binary search result.
    if (iterativeIndex == -1)
    {
        cout << "Iterative Binary Search: Not found";
    }
    else
    {
        cout << "Iterative Binary Search: Index "
             << iterativeIndex;
    }

    cout << " | Comparisons: "
         << iterativeComparisons << endl;

    // Display the recursive binary search result.
    if (recursiveIndex == -1)
    {
        cout << "Recursive Binary Search: Not found";
    }
    else
    {
        cout << "Recursive Binary Search: Index "
             << recursiveIndex;
    }

    cout << " | Comparisons: "
         << recursiveComparisons << endl;

    // Display the linear search result.
    if (linearIndex == -1)
    {
        cout << "Linear Search: Not found";
    }
    else
    {
        cout << "Linear Search: Index "
             << linearIndex;
    }

    cout << " | Comparisons: "
         << linearComparisons << endl;

    cout << "----------------------------------------" << endl;
}

int main()
{
    // Binary search requires the vector to be sorted.
    vector<int> numbers = {
        2, 4, 7, 10, 11, 32, 45, 87};

    // Display the sorted vector.
    cout << "Sorted Vector: ";

    for (int number : numbers)
    {
        cout << number << " ";
    }

    cout << endl;
    cout << "========================================" << endl;

    // Test 1: First element.
    RunTest(numbers, 2);
    // Test 2: Last element.
    RunTest(numbers, 87);
    // Test 3: Middle element.
    RunTest(numbers, 10);
    // Test 4: Missing value below the range.
    RunTest(numbers, 1);
    // Test 5: Missing value inside the range.
    RunTest(numbers, 8);

    return 0;
}