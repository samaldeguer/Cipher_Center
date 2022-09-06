#include "Executive.h"

Executive::Executive()
{

}

void Executive::run()
{
    int option;
    char exit;
    Operations operations;
    std::cout << std::endl;
    do {
        do {
            std::cout << "CIPHER CENTER" << std::endl;
            std::cout << "-------------" << std::endl;
            std::cout << "1. Affine Cipher" << std::endl;
            std::cout << "2. Atbash Cipher" << std::endl;
            std::cout << "3. Caesar Cipher" << std::endl;
            std::cout << "Choose an option (1-3): ";
            std::cin >> option;
            if (option < 1 || option > 3)
            {
                std::cout << "Must choose a valid option" << std::endl << std::endl;
            }
        } while(option < 1 || option > 3);
        std::cout << std::endl;
        if (option == 1)
        {
            operations.affineCipher();
        }
        else if (option == 2)
        {
            operations.atbashCipher();
        }
        else if (option == 3)
        {
            operations.caesarCipher();
        }
        std::cout << std::endl << "Would you like to continue? (y/n): ";
        std::cin >> exit;
    }while (exit != 'n' && exit != 'N');

}
