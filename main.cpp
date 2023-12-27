#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string genPassword() {
    // Character sets
    const string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numbers = "0123456789";
    string allChars = lowerCase + upperCase + numbers;

    // Character type booleans
    bool hasLower = false, hasUpper = false, hasDigit = false, isValid = false;
    string password;
    srand(time(0));

    // Generating a password until it is valid
    while (!isValid) {
        hasLower = hasUpper = hasDigit = false;
        password.clear();

        int length = rand() % 7 + 10; // Password length between 10 and 16
        char lastChar = '\0';

        // Generating a password of the specified length
        for (int i = 0; i < length; ++i) {
            char nextChar = allChars[rand() % allChars.size()];

            // Check for consecutive identical characters
            if (nextChar == lastChar) {
                --i; // Decrement i to retry this character
                continue;
            }

            // Update character type flags
            hasLower |= islower(nextChar);
            hasUpper |= isupper(nextChar);
            hasDigit |= isdigit(nextChar);

            lastChar = nextChar;
            password += nextChar;
        }

        // Validate the password
        isValid = hasLower && hasUpper && hasDigit;
    }

    return password;
}

int main() {
    cout << "Generated Password: " << genPassword() << endl;
    return 0;
}
