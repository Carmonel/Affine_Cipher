#include "AffineCipher.h"
#include <string>
#include "FrequencyAnalyzer.h"

int main() {
    int a = 3;
    int b = 5;

    auto* op = new AffineCipher("C:\\Users\\Ярослав\\Documents\\TEXT", a, b);

    op->encode();
    op->decode();

    auto* frequencyAnalyzer = new FrequencyAnalyzer("C:\\Users\\Ярослав\\Documents\\TEXT.ENCODE", "C:\\Users\\Ярослав\\Documents\\DECODEDTEXT");
    frequencyAnalyzer->analyzeFromEngTable();

    delete op;
    delete frequencyAnalyzer;
}
