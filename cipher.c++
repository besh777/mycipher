# include <iostream>
using namespace std;

void Cipher() {// the function to cipher the text
    string plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // two arreys to switch index from plain to cipher
    string cipher = "ZYXWVUTSRQPONMLKIJHGFEDCBA";
    string ciphered = "";
    string text;
    cout << "Please write your text that you want to cipher:";
    cin.ignore();// to ignore condition of getline
    getline(cin,text);// to take full text from user

    for(int i = 0; i < text.length(); i++){
            text[i] = toupper(text[i]);// capitalize every letter
    }
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 10) {
            ciphered += "";// to go to other condition
        } else {
            for (int j = 0; j < plain.length(); j++) {
                if (text[i] == plain[j]) {// check if it is in array plain in exact index as it may not equal j
                    ciphered += cipher[j];
                    break;// prevent infinite loop
                }
                else if (isspace(text[i])){// check if it is a space
                    ciphered += text[i];// put space as it is not required to change it
                    break;
                }
            }
        }
    }
    cout <<"the ciphered text is" << ciphered;// show the ciphered text
}


void Decipher() {// the function to decipher the text
    string plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // two arreys to switch index from cipher to plain
    string cipher = "ZYXWVUTSRQPONMLKIJHGFEDCBA";
    // from this line to * same comments as first call function
    string deciphered = "";
    string text;
    cout << "Please write your text that you want to decipher: ";
    cin.ignore();
    getline(cin, text);

    for (int i = 0; i < text.length() ; i++) {
        text[i] = toupper(text[i]);
    }
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 10) {
            deciphered += "";
        } else {
            for (int j = 0; j < text.length(); j++) {
                if (text[i] == cipher[j]) {
                    deciphered += plain[j];
                    break;
                }else if (isspace(text[i])) {
                    deciphered += text[i];
                    break;
                }
            }
        }
    }//*
    cout << "the deciphered text is" << deciphered;// show the deciphered text
}

int main() {
    int choose;
    // the menu of Atbash Cipher
    cout << "Atbash Cipher" << endl;
    cout << "1)" << "Cipher" << endl;
    cout << "2)" << "Decipher" << endl;
    cout << "3)" << "EXIT" << endl;
    cout << "Please enter your choice";
    cin >> choose;
    if (choose == 1) {// execute the statment in this condition
        Cipher();// call function to cipher texts
    }
    else if (choose ==  2 ) {// execute the statment in this condition
        Decipher();// call function to decipher texts
    }
    else if (choose == 3) {// execute the statment in this condition
        exit(0);// to exit the program
    } else {// if the choice is false this statment will be executed
        cout << "Invalid choice" << endl;
        main();// return to the menu as choice is false
    }
    return 0;
}
