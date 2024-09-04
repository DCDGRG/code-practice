// #include <iostream>
// using namespace std;

// //加解密大小写都要逆转
// string Encryption( string& str) {
//     string output;
//     for(char& letter : str){
//         if(letter>= 'a' && letter <= 'y'){
//             letter += 1;
//             letter = toupper(letter);
//             output.push_back(letter);
//         }else if(letter == 'z'){
//             letter = toupper(letter);
//             output.push_back('a');
//         }else if(letter>= 'A' && letter <= 'Y'){
//             letter += 1;
//             letter = tolower(letter);
//             output.push_back(letter);
//         }else if(letter == 'Z'){
//             letter = tolower(letter);
//             output.push_back('a');
//         }else if(letter >= '0' && letter <='8'){
//             output.push_back(letter + 1);
//         }else if (letter == '9') {
//             output.push_back('0');
//         }
//     }

//     return output;
// }

// string Decryption( string& str) {
//     string output;
//     for(char& letter : str){
//         if(letter>= 'b' && letter <= 'z'){
//             letter = toupper(letter);
//             output.push_back(letter - 1);
//         }else if(letter == 'a'){
//             letter = toupper(letter);
//             output.push_back('Z');
//         }else if(letter>= 'B' && letter <= 'Z'){
//             letter = tolower(letter);
//             output.push_back(letter - 1);
//         }else if(letter == 'A'){
//             letter = tolower(letter);
//             output.push_back('z');
//         }else if(letter >= '1' && letter <='9'){
//             output.push_back(letter - 1);
//         }else if (letter == '0') {
//             output.push_back('9');
//         }
//     }

//     return output;
// }

// int main() {
//     string toEncrypt;
//     cin >> toEncrypt;
//     string toDecrypt;
//     cin >> toDecrypt;

//     cout << Encryption(toEncrypt) << endl;
//     cout << Decryption(toDecrypt) << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

// 加解密时，大小写逆转，同时对字母和数字进行偏移处理
string Encryption(const string& str) {
    string output;
    for (char letter : str) {
        if (letter >= 'a' && letter <= 'z') {
            output.push_back(toupper(letter == 'z' ? 'a' : letter + 1));
        } else if (letter >= 'A' && letter <= 'Z') {
            output.push_back(tolower(letter == 'Z' ? 'A' : letter + 1));
        } else if (letter >= '0' && letter <= '8') {
            output.push_back(letter + 1);
        } else if (letter == '9') {
            output.push_back('0');
        }
    }
    return output;
}

string Decryption(const string& str) {
    string output;
    for (char letter : str) {
        if (letter >= 'b' && letter <= 'z') {
            output.push_back(toupper(letter - 1));
        } else if (letter == 'a') {
            output.push_back('Z');
        } else if (letter >= 'B' && letter <= 'Z') {
            output.push_back(tolower(letter - 1));
        } else if (letter == 'A') {
            output.push_back('z');
        } else if (letter >= '1' && letter <= '9') {
            output.push_back(letter - 1);
        } else if (letter == '0') {
            output.push_back('9');
        }
    }
    return output;
}

int main() {
    string toEncrypt, toDecrypt;
    cin >> toEncrypt;
    cin >> toDecrypt;

    cout << Encryption(toEncrypt) << endl;
    cout << Decryption(toDecrypt) << endl;

    return 0;
}