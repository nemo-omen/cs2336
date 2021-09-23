#include <bits.h>

int countOneBits(int num){
    if (num != 0) {
        uint unum = static_cast<uint>(num);
        return getBit(num, 0) + countOneBits(unum >> 1);
    } else {
        return 0;
    }
}