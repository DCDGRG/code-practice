//九键手机键盘上的数字与字母的对应： 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0

#include <cctype>
#include <iostream>
using namespace std;

char handleLetter(const char& letter) {
    char output = letter;
    if(letter >= 'A' && letter <= 'Z') {
        if(letter == 'Z'){
            return 'a';
        }
        output = tolower(letter) + 1;
        return output;
    }

    if (letter <= 'c' && letter >= 'a'){
        return '2';
    }else if (letter <= 'f' && letter >= 'd'){
        return '3';
    }else if (letter <= 'i' && letter >= 'g'){
        return '4';
    }else if (letter <= 'l' && letter >= 'j'){
        return '5';
    }else if (letter <= 'o' && letter >= 'm'){
        return '6';
    }else if (letter <= 's' && letter >= 'p'){
        return '7';
    }else if (letter <= 'v' && letter >= 't'){
        return '8';
    }else if (letter <= 'z' && letter >= 'w'){
        return '9';
    }
    return letter;
}

int main() {
    string password;
    getline(cin, password);

    for(const char& letter : password) {
        cout << handleLetter(letter);
    }

}
