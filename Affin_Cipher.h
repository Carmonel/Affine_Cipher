#ifndef AFFIN_CIPHER_NEW_AFFIN_CIPHER_H
#define AFFIN_CIPHER_NEW_AFFIN_CIPHER_H

#include <iostream>
#include <fstream>

class Affin_Cipher {
private:
    int a;
    int b;
public:
    Affin_Cipher(int a, int b);
    void changeValues(int a, int b);
    void encode(const std::string& inputPath, const std::string& outputPath);
    void decode(const std::string& inputPath, const std::string& outputPath);
    ~Affin_Cipher();
};

#endif
