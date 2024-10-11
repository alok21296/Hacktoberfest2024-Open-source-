#include <iostream>
#include <vector>
using namespace std;

// Function to build KMP table (partial match table)
vector<int> buildKMPTable(const string &s) {
    int n = s.size();
    vector<int> table(n, 0);
    int j = 0;  // Length of the previous longest prefix suffix
    
    for (int i = 1; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = table[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        table[i] = j;
    }
    
    return table;
}

// Function to find the shortest palindrome
string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    
    // Combine the original string with its reverse, separated by a special character
    string combined = s + "#" + rev_s;
    
    // Build the KMP table for the combined string
    vector<int> kmpTable = buildKMPTable(combined);
    
    // Length of the longest prefix of the original string which is a palindrome
    int longestPrefixPalindrome = kmpTable.back();
    
    // Add the necessary characters to make the entire string a palindrome
    string addOn = rev_s.substr(0, s.size() - longestPrefixPalindrome);
    
    return addOn + s;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    string result = shortestPalindrome(s);
    cout << "The shortest palindrome is: " << result << endl;

    return 0;
}
