#ifndef AFFIN_CIPHER_NEW_AFFINECIPHER_H
#define AFFIN_CIPHER_NEW_AFFINECIPHER_H

#include <iostream>
#include <fstream>

class AffineCipher {
private:
    int a;
    int b;
    std::string path;
    std::ifstream inputFile;
    std::ofstream outputFile;
public:
    AffineCipher(const std::string& inputPath, int a, int b);
    void changeValues(int a, int b);
    void changePath(const std::string& path);
    void encode();
    void decode();
    void randomValues();
    ~AffineCipher();
};

#endif
