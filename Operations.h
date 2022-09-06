#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
#include <iostream>

class Operations
{
    public:
        Operations();
        void caesarCipher();
        void atbashCipher();
        void affineCipher();
    private:
        int euclideanAlgorithm(int a, int b);

};
#endif
