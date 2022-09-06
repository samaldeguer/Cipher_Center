#include "Operations.h"

Operations::Operations()
{

}

void Operations::caesarCipher()
{
    char mode;
    std::string input;
    int shift;
    std::cout << "CAESAR CIPHER" << std::endl << "-------------" << std::endl << "The Caesar Cipher is named after the Roman general Julian Caesar, who is the first known user of this substitution cipher." << std::endl << "This cipher takes in a message and encrypts it by shifting every letter an inputted amount down the alphabet." << std::endl << std::endl;
    do {
        std::cout << "Encrypt (e) or decrypt (d)?: ";
        std::cin >> mode;
        if (mode != 'e' && mode != 'd' && mode != 'E' && mode != 'D')
        {
            std::cout << "Must enter valid input" << std::endl << std::endl;
        }
    } while(mode != 'e' && mode != 'd' && mode != 'E' && mode != 'D');
    if (mode == 'e' || mode == 'E')
    {
        std::string encrypted = "";
        char tempLetter;
        int newAscii;
        std::cout << "Enter a message to encrypt (contains only lowercase letters, no spaces): ";
        std::cin >> input;
        std::cout << "Enter a shift: ";
        std::cin >> shift;
        std::cout << std:: endl;
        for (int i = 0; i < input.length(); i++)
        {
            tempLetter = input.at(i);
            if ((int)tempLetter + shift > 122)
            {
                newAscii = ((int)tempLetter + shift) - 26;
            }
            else
            {
                newAscii = (int)tempLetter + shift;
            }
            encrypted = encrypted + "" + (char)newAscii;
        }
        std::cout << "Encrypted message: " << encrypted << std::endl;

    }
    else if (mode == 'd' || mode == 'D')
    {
        std::string decrypted = "";
        char tempLetter;
        int newAscii;
        std::cout << "Enter a message to decrypt (contains only lowercase letters, no spaces): ";
        std::cin >> input;
        std::cout << "Enter a shift: ";
        std::cin >> shift;
        std::cout << std:: endl;
        for (int i = 0; i < input.length(); i++)
        {
            tempLetter = input.at(i);
            if ((int)tempLetter - shift < 97)
            {
                newAscii = ((int)tempLetter - shift) + 26;
            }
            else
            {
                newAscii = (int)tempLetter - shift;
            }
            decrypted = decrypted + "" + (char)newAscii;
        }
        std::cout << "Decrypted message: " << decrypted << std::endl;
    }
}

void Operations::atbashCipher()
{
    char mode, tempLetter;
    std::string input;
    std::string encrypted = "";
    int newAscii;
    std::cout << "ATBASH CIPHER" << std::endl << "-------------" << std::endl << "The Atbash Cipher is the Caesar Cipher that has a shift of 26. This cipher takes in a message and encrypts" << std::endl << "it by replacing each letter with the letter that's in the same spot when the alphabet is reversed. With" << std::endl << "that being said, there is no decryption option for this cipher because the encryption does the exact" << std::endl << "same thing since it's using the reverse alphabet, which is a symmetrical shift." << std::endl << std::endl;
    std::cout << "Enter a message to encrypt (contains only lowercase letters, no spaces): ";
    std::cin >> input;
    std::cout << std:: endl;
    for (int i = 0; i < input.length(); i++)
    {
        tempLetter = input.at(i);
        newAscii = (122 - (int)tempLetter) + 97;
        encrypted = encrypted + "" + (char)newAscii;
    }
    std::cout << "Encrypted message: " << encrypted << std::endl;
}

void Operations::affineCipher()
{
    char mode;
    char c;
    std::string input;
    std::string encrypted = "";
    std::string decrypted = "";
    bool validInput;
    int newAscii, tempAscii, a, b, a_inv;
    std::cout << "AFFINE CIPHER" << std::endl << "-------------" << std::endl << "The Affine Cipher is a type of substitution cipher that uses two keys (a and b) mathematical equations to encrypt" << std::endl << "and decrypt messages. To encrypt a message, each letter is converted to its numeric equivalent (p) and put into c = ap + b (mod 26)." << std::endl << "c, once converted to its letter equivalent, replaces the original letter. To decrypt a message, each letter of the encrypted message (c)" << std::endl << "is converted to its number equivalent and put into p = ((a^-1)(c-b)) mod 26, where a^-1 is the multiplicative inverse of a." << std::endl << "p, once converted to its letter equivalent, replaces the encrypted letter." << std::endl << std::endl;
    do {
        std::cout << "Encrypt (e) or decrypt (d)?: ";
        std::cin >> mode;
        if (mode != 'e' && mode != 'd' && mode != 'E' && mode != 'D')
        {
            std::cout << "Must enter valid input" << std::endl << std::endl;
        }
    } while(mode != 'e' && mode != 'd' && mode != 'E' && mode != 'D');
    if (mode == 'e' || mode == 'E')
    {
        std::cout << "Enter a message to encrypt (contains only lowercase letters, no spaces): ";
    }
    else if (mode == 'd' || mode == 'D')
    {
        std::cout << "Enter a message to decrypt (contains only lowercase letters, no spaces): ";
    }
    std::cin >> input;
    do {
        validInput = true;
        std::cout << "Enter key 'a' (must be relatively prime to 26 and between 1 and 26 inclusively): ";
        std::cin >> a;
        if (euclideanAlgorithm(26, a) != 1)
        {
            std::cout << "'a' must be relatively prime to 26" << std::endl << std::endl;
            validInput = false;
        }
        else if(a > 26 || a < 1)
        {
            std::cout << "'a' must be between 1 and 26 inclusively" << std::endl << std::endl;
            validInput = false;
        }
    } while(validInput == false);
    do
    {
        validInput = true;
        std::cout << "Enter key 'b' (must be between 1 and 26 inclusively): ";
        std::cin >> b;
        if (b < 1 || b > 26)
        {
            std::cout << "'b' must be between 1 and 26 inclusively" << std::endl << std::endl;
            validInput = false;
        }
    }while(validInput == false);
    if (mode == 'e' || mode == 'E')
    {
        for (int i = 0; i < input.length(); i++)
        {
            tempAscii = (int)input.at(i) - 97;
            newAscii = (((a * tempAscii) + b) % 26) + 97;
            c = (char)newAscii;
            encrypted = encrypted + "" + c;
        }
        std::cout << "Encrypted message: " << encrypted << std::endl;
    }
    else if (mode == 'd' || mode == 'D')
    {
        for (int i = 0; i < 26; i++)
        {
            if (((a * i) % 26) == 1)
            {
                a_inv = i;
            }
        }
        for (int i = 0; i < input.length(); i++)
        {
            tempAscii = (int)input.at(i)-97;
            newAscii = ((a_inv*(tempAscii-b))%26)+97;
            c = (char)newAscii;
            decrypted = decrypted + "" + c;

        }
        std::cout << "Decrypted message: " << decrypted << std::endl;
    }
}

int Operations::euclideanAlgorithm(int a, int b)
{
    int num1, num2, mod;
    if (a >= b)
    {
        num1 = a;
        num2 = b;
    }
    else
    {
        num1 = b;
        num2 = a;
    }
    do {
        mod = num1 % num2;
        if (mod == 0)
        {
            return num2;
        }
        num1 = num2;
        num2 = mod;
    } while(1);
}
