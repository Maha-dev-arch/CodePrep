// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int>& v) {

    bool isBitonic = false;
    int currSlope = 0, risingSlopeCount = 0, fallingSlopeCount = 0, constSeq = 0; //1->rising 2->falling
    int prev = 0;

    // Write your code here
    for (int i : v) {
        if (prev != 0) {
            if (i > prev && currSlope != 1) {
                risingSlopeCount++;
                currSlope = 1;
            }
            else if (i < prev && currSlope != 2) {
                fallingSlopeCount++;
                currSlope = 2;
            }
            else if (i == prev) {
                constSeq++;
            }
        }
        prev = i;

    }
    if (risingSlopeCount == 1 && fallingSlopeCount == 1)
        return true;
    else if ((risingSlopeCount == 1 && !fallingSlopeCount) || (fallingSlopeCount == 1 && !risingSlopeCount))
        return true;
    else if (constSeq == v.size() - 1)
        return true;
    else if (risingSlopeCount + fallingSlopeCount == 3) {
        if (risingSlopeCount == 2 && v[v.size() - 1] <= v[0])
            return true;
        else if (fallingSlopeCount == 2 && v[v.size() - 1] >= v[0])
            return true;
    }
    return false;
}

// Main function
//int main() {
//    // Uncomment one of these lines and make sure you get the result at the right. 
//
//    std::vector<int> myvec = { 1, 2, 5, 4, 3 };  // Yes
//     std::vector<int> myvec1 = {1, 1, 1, 1, 1};  // Yes
//     std::vector<int> myvec2 = {3, 4, 5, 2, 2};  // Yes
//     std::vector<int> myvec3 = {3, 4, 5, 2, 4};  // No
//     std::vector<int> myvec4 = {1, 2, 3, 4, 5};  // Yes
//     std::vector<int> myvec5 = {1, 2, 3, 1, 2};  // No
//     std::vector<int> myvec6 = {5, 4, 6, 2, 6};  // No
//     std::vector<int> myvec7 = {5, 4, 3, 2, 1};  // Yes
//     std::vector<int> myvec8 = {5, 4, 3, 2, 6};  // Yes
//     std::vector<int> myvec9 = {5, 4, 6, 5, 4};  // No
//     std::vector<int> myvec10 = {5, 4, 6, 5, 5};  // Yes
//
//    /*std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec1) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec2) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec3) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec4) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec5) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec6) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec7) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec8) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//    std::cout << (is_bitonic(myvec9) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;*/
//    std::cout << (is_bitonic(myvec10) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
//    std::cout << std::endl << std::flush;
//
//
//    return 0;
//}