#include <iostream>

extern "C" {
    void squares(int, int, int);
    void print(int, int);
}

int main() {
    int start = 10;
    int end = 10;
    int square = 0;

    squares(start, end, square);
    return 0;
}

void squares(int x, int end, int square) {
    __asm {
        beg: 
            mov eax, x
            mul eax
            mov square, eax
            push square
            push x
            call print
            pop x
            pop square
            inc x
            dec end
            mov ecx, end
            cmp ecx, 0
            jge beg
    }
}

void print(int x, int square) {
    std::cout << x << " -> " << square << std::endl;
}
