//================================= check whethere the given string is palindrome or not ====================================================
#include <iostream>
#include <cstring>
char toLowerCase(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch - 'A' + 'a';
    }
    return ch;
}

bool checkPalindrome(const char* ch, int n)
{
    int s = 0;
    int e = n - 1;

    while(s <= e){
        if(toLowerCase(ch[s]) != toLowerCase(ch[e])){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main() {
    char s[100]; // Assuming maximum string length is 100
    std::cin >> s;
    bool ans = checkPalindrome(s, strlen(s));
    if(ans){
        std::cout << "Yes, it is a palindrome." << std::endl;
    }
    else{
        std::cout << "No, it is not a palindrome." << std::endl;
    }
    return 0;
}

// Time Complexity: O(n)