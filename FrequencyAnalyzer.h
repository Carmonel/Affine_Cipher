#ifndef AFFIN_CIPHER_NEW_FREQUENCYANALYZER_H
#define AFFIN_CIPHER_NEW_FREQUENCYANALYZER_H

#include <string>
#include <iostream>

class FrequencyAnalyzer {
private:
    int inputFileTable[256] = {0};
    int outputFileTable[256] = {0};
    std::string debugPath;
    int sumFromInputTable;
    std::ofstream debugFile;
public:
    FrequencyAnalyzer(const std::string& inputPath, const std::string& outputPath);
    void printTables();
    void analyzeFromEngTable();
    ~FrequencyAnalyzer();
};


#endif //AFFIN_CIPHER_NEW_FREQUENCYANALYZER_H
