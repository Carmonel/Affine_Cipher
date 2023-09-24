#ifndef AFFIN_CIPHER_NEW_AFFINE_CIPHER_H
#define AFFIN_CIPHER_NEW_AFFINE_CIPHER_H

#include <iostream>
#include <fstream>

class Affine_Cipher {
private:
    int a;
    int b;
    std::string path;
    std::ifstream inputFile;
    std::ofstream outputFile;
public:
    Affine_Cipher(const std::string& inputPath, int a, int b);
    void changeValues(int a, int b);
    void changePath(const std::string& path);
    void encode();
    void decode();
    ~Affine_Cipher();
};

#endif
