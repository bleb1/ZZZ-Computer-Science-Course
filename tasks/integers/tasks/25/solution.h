#include <stdint.h>
#include <stdio.h>

const int64_t INPUT_NUMBER = -922337203685477580;
const int32_t TEN = 10;
const int64_t MINUS_ONE = -1;

int64_t Abs(int64_t num) {
    if (num < 0) {
        return num *= MINUS_ONE;
    } else {
        return num;
    }
}

int64_t Sign(int64_t num) {
    if (num > 0) {
        return 1;
    } else if (num < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main()
{   
    int64_t input_number = INPUT_NUMBER;
    int8_t is_negative = Sign(input_number);
    input_number = Abs(input_number);
    int64_t new_number = 0;
    int64_t power_10 = 1;
    
    while (input_number >= power_10) {
        int64_t digit = (input_number / power_10) % 10;
        if (digit) {
            digit -= (int64_t)(digit % 2 == 0);
        }
        new_number += digit * power_10;
        power_10 *= 10l;
    }
    new_number *= (int64_t)is_negative;
    printf("%ld\n", new_number);
    return 0;
}
