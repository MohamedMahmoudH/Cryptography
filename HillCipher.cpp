#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

char flow{};
string plainText{} , key{} , cipherText{};
string Encrypt()
{
    do {
    cout << "Enter Plain Text : "; cin >> plainText;
    cout << "Enter The key    : "; cin >> key;
    } while (key.size() != plainText.size() * plainText.size());
    short sz = plainText.size();
    for(char &c: plainText) {c = toupper(c);}
    for(char &c: key      ) {c = toupper(c);}

    vector<short> PT_mtrx(sz, 0); // PT :: Plain Text
    for(short i = 0; i < sz; ++i)
        PT_mtrx[i] = plainText[i] - 'A';

    vector<short> CT_mtrx(sz, 0); // CT :: Cipher Text
    for(short i = 0; i < sz; ++i)
        for(short j = 0; j < sz; ++j)
            CT_mtrx[i] += ((key[i*sz + j] - 'A') * PT_mtrx[j]) % 26;
    
    for(short i = 0; i < sz; ++i)
        cipherText.push_back((CT_mtrx[i] % 26) + 'A');
    return cipherText;
}

string Decrypt()
{
    cout << "Sorry, this feature hasn't been added yet\nYou can only perform encryption";
    cout << "\n\nif you want to encrypt press \'E\' : ";
    cin >> flow; flow = toupper(flow);
    return (flow == 'E' ? Encrypt() : "Thank you for your time");
    // do {
    // cout << "Enter cipher Text : "; cin >> cipherText;
    // cout << "Enter The key     : "; cin >> key;
    // } while (key.size() != cipherText.size() * cipherText.size());
}

int main()
{
    bool warning = false;
    cout << "******************************** \"WELCOME TO HILL (CIPHER)\" ********************************\n";
    cout << "Encrypt \'E\' OR Decrypt \'D\' : ";
    do {
        if(warning) cout << "please enter \'E\' or \'D\' : ";
        cin >> flow; flow = toupper(flow);
        warning = true; 
    } while (flow != 'E' && flow != 'D');

    cout << (flow == 'E' ? Encrypt() : Decrypt());
}