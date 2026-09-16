#include <iostream>
using namespace std;

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long number;

    cout << "Enter a credit card number as a long integer: ";
    cin >> number;

    if (isValid(number))
        cout << number << " is valid" << endl;
    else
        cout << number << " is invalid" << endl;

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);

    // Check length is between 13 and 16 digits
    if (size < 13 || size > 16)
        return false;

    // Check prefix is 4, 5, 37, or 6
    if (!(prefixMatched(number, 4) || prefixMatched(number, 5) ||
          prefixMatched(number, 37) || prefixMatched(number, 6)))
        return false;

    // Apply the Luhn check (Mod 10 check)
    if ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0)
        return true;
    else
        return false;
}

// Get the result from Step 2: sum of doubled digits at even places (from right)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;

    // Strip off the last digit first, since even places (from right)
    // are the 2nd, 4th, 6th, ... digits from the right
    number = number / 10;

    while (number != 0) {
        int digit = (int)(number % 10);
        sum += getDigit(digit * 2);
        number = number / 100; // move two digits over to reach the next even place
    }

    return sum;
}

// Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int number) {
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}

// Return sum of odd place digits in number
int sumOfOddPlace(long long number) {
    int sum = 0;

    while (number != 0) {
        int digit = (int)(number % 10);
        sum += digit;
        number = number / 100; // move two digits over to reach the next odd place
    }

    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int digitSize = getSize(d);
    long long prefix = getPrefix(number, digitSize);
    return prefix == d;
}

// Return the number of digits in d
int getSize(long long d) {
    int numOfDigits = 0;

    if (d == 0)
        return 1;

    while (d != 0) {
        d = d / 10;
        numOfDigits++;
    }

    return numOfDigits;
}

// Return the first k number of digits from number.
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);

    if (size < k)
        return number;

    long long divisor = 1;
    for (int i = 0; i < size - k; i++)
        divisor *= 10;

    return number / divisor;
}