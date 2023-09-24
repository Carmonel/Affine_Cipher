#include <fstream>
#include <sstream>
#include "FrequencyAnalyzer.h"

struct Pair{
    char letter;
    double freq;
    Pair(char a, double b){
        letter = a;
        freq = b;
    }
};

FrequencyAnalyzer::FrequencyAnalyzer(const std::string &inputPath, const std::string &outputPath) {
    std::ifstream inputFile;
    std::ifstream outputFile;
    try{
        inputFile.open(inputPath, std::ios::binary | std::ios::in);
    }
    catch(std::exception& e){
        std::cout << "FrequencyAnalyzer::FrequencyAnalyzer() /***/ FrequencyAnalyzer.cpp::8... inputFile.open() error: " << e.what() << std::endl;
        std::cout << std::endl << "inputPath: " << inputPath;
        exit(-1);
    }
    try{
        outputFile.open(outputPath, std::ios::binary | std::ios::in);
    }
    catch(std::exception& e){
        std::cout << "FrequencyAnalyzer::FrequencyAnalyzer() /***/ FrequencyAnalyzer.cpp::16... outputFile.open() error: " << e.what() << std::endl;
        std::cout << "outputPath: " << outputPath;
        exit(-1);
    }
    if (!inputFile.is_open()){
        std::cout << "FrequencyAnalyzer::FrequencyAnalyzer() /***/ FrequencyAnalyzer.cpp::23... inputFile.is_open() returned false." << std::endl;
        std::cout << std::endl << "inputPath: " << inputPath;
        exit(-1);
    }
    if (!outputFile.is_open()){
        std::cout << "FrequencyAnalyzer::FrequencyAnalyzer() /***/ FrequencyAnalyzer.cpp::29... outputFile.is_open() returned false." << std::endl;
        std::cout << "outputPath: " << outputPath;
        exit(-1);
    }

    unsigned char byte;
    inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte)); // Skip 'a'
    inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte)); // Skip 'b'
    while (inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
        inputFileTable[byte]++;
    }
    while (outputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
        outputFileTable[byte]++;
    }

    debugPath = inputPath + "_freq.txt";
    printTables();
}

void FrequencyAnalyzer::printTables() {
    ///
    /// Debug file export
    ///
    try{
        debugFile.open(debugPath);
    }
    catch(std::exception& e){
        std::cout << "FrequencyAnalyzer::FrequencyAnalyzer() /***/ FrequencyAnalyzer.cpp::55... debugFile.open() error: " << e.what() << std::endl;
        std::cout << std::endl << "inputPath: " << debugPath;
        exit(-1);
    }
    if (!debugFile.is_open()){
        std::cout << "FrequencyAnalyzer::FrequencyAnalyzer() /***/ FrequencyAnalyzer.cpp::62... debugFile.is_open() returned false." << std::endl;
        std::cout << "debugPath: " << debugPath;
        exit(-1);
    }

    ///
    /// Check for sum
    ///
    int sum = 0;
    for (int i = 0; i < 256; i++) sum = sum + inputFileTable[i];
    int sum2 = 0;
    for (int i = 0; i < 256; i++) sum2 = sum2 + outputFileTable[i];
    if (sum != sum2){
        std::cout << "/******/ WARNING: inputFileTable count (" << sum << ") != outputFileTable count (" << sum2 << ")" << std::endl;
    }

    ///
    /// Printing tables
    ///
    std::cout << "Input File Table:" << std::endl;
    debugFile << "Input File Table:" << std::endl;
    for (int i = 0; i < 256; i++){
        if (inputFileTable[i] != 0){
            std::ostringstream ss;
            ss << std::hex << std::uppercase << i << " = " << std::dec << inputFileTable[i]
                                        << "(usages)  " << (double)((double)inputFileTable[i]/sum) << "(freq)" << std::endl;
            debugFile << ss.str();
            std::cout << ss.str();
        }

    }
    debugFile << std::endl;
    std::cout << std::endl;
    std::cout << "Output File Table:" << std::endl;
    debugFile << "Output File Table:" << std::endl;
    for (int i = 0; i < 256; i++){
        if (outputFileTable[i] != 0) {
            std::ostringstream ss;
            ss << std::hex << std::uppercase << i << " = " << std::dec << outputFileTable[i]
                                        << "(usages)  " << (double) ((double) outputFileTable[i] / sum) << "(freq)" << std::endl;
            debugFile << ss.str();
            std::cout << ss.str();
        }
    }
    sumFromInputTable = sum;
}

void FrequencyAnalyzer::analyzeFromEngTable() {
    Pair* alphabet[26];
    ///
    /// Alphabet
    ///
    alphabet[0] = new Pair('A', 0.0817);
    alphabet[1] = new Pair('B', 0.0149);
    alphabet[2] = new Pair('C', 0.0278);
    alphabet[3] = new Pair('D', 0.0425);
    alphabet[4] = new Pair('E', 0.127);
    alphabet[5] = new Pair('F', 0.0223);
    alphabet[6] = new Pair('G', 0.0202);
    alphabet[7] = new Pair('H', 0.0609);
    alphabet[8] = new Pair('I', 0.0697);
    alphabet[9] = new Pair('J', 0.0015);
    alphabet[10] = new Pair('K', 0.0077);
    alphabet[11] = new Pair('L', 0.0403);
    alphabet[12] = new Pair('M', 0.0241);
    alphabet[13] = new Pair('N', 0.0675);
    alphabet[14] = new Pair('O', 0.0751);
    alphabet[15] = new Pair('P', 0.0193);
    alphabet[16] = new Pair('Q', 0.001);
    alphabet[17] = new Pair('R', 0.0599);
    alphabet[18] = new Pair('S', 0.0633);
    alphabet[19] = new Pair('T', 0.0906);
    alphabet[20] = new Pair('U', 0.0276);
    alphabet[21] = new Pair('V', 0.0098);
    alphabet[22] = new Pair('W', 0.0236);
    alphabet[23] = new Pair('X', 0.0015);
    alphabet[24] = new Pair('Y', 0.0197);
    alphabet[25] = new Pair('Z', 0.0007);
    bool letterFound[256] = {false};

    std::cout << std::endl << std::endl << "Frequency analyzing from english alphabet:" << std::endl;
    debugFile << std::endl << std::endl << "Frequency analyzing from english alphabet:" << std::endl;

    for (int i = 0; i < 26; i++){
        double minDiff = 10000;
        int pos = 0;

        // Find minimum difference
        for (int j = 0; j < 256; j++) {
            if (letterFound[j]) continue;
            double diff = std::abs(alphabet[i]->freq - (double)((double)inputFileTable[j] / sumFromInputTable));
            if (diff < minDiff) {
                minDiff = diff;
                pos = j;
            }
        }


        std::ostringstream ss;
        ss << "'" << alphabet[i]->letter << "' = " << std::hex << std::uppercase << pos << " -> " << alphabet[i]->freq << "(alphabet) = "
                                                        << std::dec << (double)((double)inputFileTable[pos] / sumFromInputTable) << "(input file)" << std::endl;
        std::cout << ss.str();
        debugFile << ss.str();
        letterFound[pos] = true;
    }
    for (int i = 0; i < 26; i++) delete alphabet[i];
}

FrequencyAnalyzer::~FrequencyAnalyzer(){
    debugFile.close();
}
