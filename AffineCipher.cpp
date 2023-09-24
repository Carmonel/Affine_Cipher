#include "AffineCipher.h"

int FindInverse(int a, int N) {
    int m0 = N, t, q;
    int x0 = 0, x1 = 1;

    while (a > 1) {
        q = a / N;
        t = N;

        N = a % N;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

unsigned char Encrypt(unsigned char P, int a, int b, int N) {
    int x = static_cast<int>(P);
    int E_x = (a * x + b) % N;
    return (unsigned char)(E_x);
}

unsigned char Decrypt(unsigned char C, int a, int b, int N) {
    int y = static_cast<int>(C);
    int a_inverse = FindInverse(a, N);
    int D_y = (a_inverse * (y - b + N)) % N;
    return (unsigned char)(D_y);
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

AffineCipher::AffineCipher(const std::string& inputPath, int a, int b){
    changeValues(a, b);
    path = inputPath;
}

void AffineCipher::changeValues(int a, int b){
    if (!((a >= 0) && (a < 256))){
        std::cout << "AffineCipher::changeValues() /***/ AffineCipher.cpp::45... a != [0, 255] ";
        exit(-1);
    }
    if (!((b >= 0) && (b < 256))){
        std::cout << "AffineCipher::changeValues() /***/ AffineCipher.cpp::49... a != [0, 255] ";
        exit(-1);
    }
    if (gcd(a, 256) != 1){
        std::cout << "AffineCipher::changeValues() /***/ AffineCipher.cpp::58... gcd[a, N] != 1";
        exit(-1);
    }
    this->a = a;
    this->b = b;
}

void AffineCipher::encode(){
    try{
        inputFile.open(path, std::ios::binary | std::ios::in);
    }
    catch(std::exception& e){
        std::cout << "AffineCipher::encode() /***/ AffineCipher.cpp::68... inputFile.open() error: " << e.what() << std::endl;
        std::cout << std::endl << "inputPath: " << path;
        exit(-1);
    }
    try{
        outputFile.open(path + ".ENCODE", std::ios::binary | std::ios::out);
    }
    catch(std::exception& e){
        std::cout << "AffineCipher::encode() /***/ AffineCipher.cpp::76... outputFile.open() error: " << e.what() << std::endl;
        std::cout << "outputPath: " << path + ".ENCODE";
        exit(-1);
    }
    if (!inputFile.is_open()){
        std::cout << "AffineCipher::encode() /***/ AffineCipher.cpp::83... inputFile.is_open() returned false." << std::endl;
        std::cout << std::endl << "inputPath: " << path;
        exit(-1);
    }
    if (!outputFile.is_open()){
        std::cout << "AffineCipher::encode() /***/ AffineCipher.cpp::88... outputFile.is_open() returned false." << std::endl;
        std::cout << "outputPath: " << path + ".ENCODE";
        exit(-1);
    }

    outputFile.put(a);
    outputFile.put(b);
    unsigned char byte;
    while (inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
        unsigned char result = Encrypt(byte, a, b, 256);
        outputFile.write(reinterpret_cast<char*>(&result), sizeof(result));
    }

    path = path + ".ENCODE";

    inputFile.close();
    outputFile.close();

    std::cout << "AffineCipher::encode(): Created new file: " << path << std::endl;
}

void AffineCipher::decode(){
    std::string check = path.substr(path.length()-7, 7);
    std::string outputPath = path.substr(0, path.length()-7);
    if (check != ".ENCODE"){
        std::cout << "AffineCipher::decode() /***/ AffineCipher.cpp::113... Not supported file for decoding." << std::endl << "check (string): " << check << std::endl;
        std::cout << "outputPath: " << outputPath;
        exit(-1);
    }
    int i = outputPath.length();
    while (outputPath[i] != '\\') i--;
    i++;
    outputPath.insert(i, "DECODED");


    try{
        inputFile.open(path, std::ios::binary | std::ios::in);
    }
    catch(std::exception& e){
        std::cout << "AffineCipher::decode() /***/ AffineCipher.cpp::125... inputFile.open() error: " << e.what() << std::endl;
        std::cout << "inputPath: " << path;
        exit(-1);
    }
    try{
        outputFile.open(outputPath, std::ios::binary | std::ios::out);
    }
    catch(std::exception& e){
        std::cout << "AffineCipher::decode() /***/ AffineCipher.cpp::133... outputFile.open() error: " << e.what() << std::endl;
        std::cout << "outputPath: " << outputPath;
        exit(-1);
    }
    if (!inputFile.is_open()){
        std::cout << "AffineCipher::decode() /***/ AffineCipher.cpp::140... inputFile.is_open() returned false." << std::endl;
        std::cout << "inputPath: " << path;
        exit(-1);
    }
    if (!outputFile.is_open()){
        std::cout << "AffineCipher::decode() /***/ AffineCipher.cpp::145... outputFile.is_open() returned false." << std::endl;
        std::cout << "outputPath: " << outputPath;
        exit(-1);
    }

    unsigned char byte;
    inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte));
    a = byte;
    inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte));
    b = byte;
    while (inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
        unsigned char result = Decrypt(byte, a, b, 256);
        outputFile.write(reinterpret_cast<char*>(&result), sizeof(result));
    }

    inputFile.close();
    outputFile.close();

    std::cout << "AffineCipher::decode(): Created new file: " << outputPath << std::endl;
}

void AffineCipher::changePath(const std::string &path) {
    this->path = path;
}

void AffineCipher::randomValues() {
    srand(time(nullptr));
    b = (int)(rand() % 256);

    while (true){
        a = (int)(rand() % 256);
        if (gcd(a, 256) == 1) break;
    }
}

AffineCipher::~AffineCipher() = default;
