#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool isValidKey(string key) // must be all alphabetic characters
{
    for(char &ch: key)
        if(!isalpha(ch))
            return false;
    return true;
}

int main()
{
    string text{}, key{}, result{};
    bool ENC_DEC{true};
    cout << "Would you like to Encrypt OR Decrypt\nFor Encrypt press '1' For Decrypt press '0' : ";
    cin >> ENC_DEC;
    cin.ignore();

    cout << "Enter the Text : "; getline(cin, text);
    do{
    cout << "Enter the Key  : "; getline(cin , key);
    } while(!isValidKey(key));
    
    int sz1 = text.size() , sz2 = key.size();
    for(char &c: text)
        if(isalpha(c))
            c = toupper(c);
    
    for(char &c: key)
        c = toupper(c);
    
    for(int i = 0, j = 0; i < sz1; ++i)
    {
        if(!isalpha(text[i])){
            result.push_back(text[i]);
            continue;
        }

        if(ENC_DEC)
            result.push_back((((text[i] - 'A') + (key[j % sz2] - 'A')     ) % 26) + 'A');
        else
            result.push_back((((text[i] - 'A') - (key[j % sz2] - 'A') + 26) % 26) + 'A');
        ++j;
    }
    cout << "The Result is  : " << result;
}