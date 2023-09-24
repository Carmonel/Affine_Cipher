#include "Affine_Cipher.h"
#include "string"

int main() {
    int a = 3;
    int b = 5;

    auto* op = new Affine_Cipher("C:\\Users\\Ярослав\\Documents\\in", a, b);

    op->encode();
    op->decode();
}
