#include <iostream>
#include <fstream>

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

int main() {
    int a = 3;
    int b = 5;
    int N = 256;

    std::ifstream inputFile("C:\\Users\\Ярослав\\Documents\\in", std::ios::binary);
    std::ofstream outputFile("C:\\Users\\Ярослав\\Documents\\out", std::ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Не удалось открыть файлы." << std::endl;
        return 1;
    }

    unsigned char byte;
    while (inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
        std::cout << std::hex << std::uppercase << (int)byte << " ";
        unsigned char result;

        result = Encrypt(byte, a, b, N);
        std::cout << std::hex << std::uppercase << (int)result << " ";

        result = Decrypt(result, a, b, N);
        std::cout << std::hex << std::uppercase << (int)result << std::endl;

        outputFile.write(reinterpret_cast<char*>(&result), sizeof(result));
    }

    inputFile.close();
    outputFile.close();
}
