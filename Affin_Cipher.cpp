#include "Affin_Cipher.h"

Affin_Cipher::Affin_Cipher(int a, int b){
    changeValues(a, b);
}
void Affin_Cipher::changeValues(int a, int b){
    this->a = a;
    this->b = b;
}
void Affin_Cipher::encode(const std::string& inputPath, const std::string& outputPath){
    std::ifstream inputFile;
    std::ifstream outputFile;
    try{
        inputFile.open(inputPath, std::ios::binary | std::ios::in);
    }
    catch(std::exception& e){
        std::cout << "inputPath.open() error: " << e.what() << std::endl;
        exit(-1);
    }
    try{
        outputFile.open(outputPath, std::ios::binary | std::ios::out);
    }
    catch(std::exception& e){
        std::cout << "inputPath.open() error: " << e.what() << std::endl;
        exit(-1);
    }
    if (!inputFile.is_open()){
        std::cout << "inputFile.is_open() returned false." << std::endl;
        exit(-1);
    }
    if (!outputFile.is_open()){
        std::cout << "outputFile.is_open() returned false." << std::endl;
        exit(-1);
    }

    inputFile.close();
    outputFile.close();
}
void Affin_Cipher::decode(const std::string& inputPath, const std::string& outputPath){
    std::ifstream inputFile;
    std::ifstream outputFile;
    try{
        inputFile.open(inputPath, std::ios::binary | std::ios::in);
    }
    catch(std::exception& e){
        std::cout << "inputPath.open() error: " << e.what() << std::endl;
        exit(-1);
    }
    try{
        outputFile.open(outputPath, std::ios::binary | std::ios::out);
    }
    catch(std::exception& e){
        std::cout << "inputPath.open() error: " << e.what() << std::endl;
        exit(-1);
    }
    if (!inputFile.is_open()){
        std::cout << "inputFile.is_open() returned false." << std::endl;
        exit(-1);
    }
    if (!outputFile.is_open()){
        std::cout << "outputFile.is_open() returned false." << std::endl;
        exit(-1);
    }

    inputFile.close();
    outputFile.close();
}
Affin_Cipher::~Affin_Cipher() = default;
