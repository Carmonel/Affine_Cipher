#include "AffineCipher.h"
#include <string>
#include "FrequencyAnalyzer.h"

int main() {
    int a = 3;
    int b = 5;

    auto* op = new AffineCipher("C:\\Users\\Ярослав\\Documents\\in", a, b);

    op->encode();
    op->decode();

    auto* frequencyAnalyzer = new FrequencyAnalyzer("C:\\Users\\Ярослав\\Documents\\in.ENCODE", "C:\\Users\\Ярослав\\Documents\\DECODEDin");
    frequencyAnalyzer->analyzeFromEngTable();

    delete op;
    delete frequencyAnalyzer;
}
