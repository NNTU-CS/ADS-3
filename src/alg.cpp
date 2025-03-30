#include <cstdint>
#include "alg.h"
#include <unordered_map>

using namespace std;

unordered_map<uint64_t, unsigned int> collatz_cache;

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_value = num;
    while (num != 1) {
        num = (num % 2 == 0) ? num / 2 : 3 * num + 1;
        if (num > max_value) max_value = num;
    }
    return max_value;
}

unsigned int collatzLen(uint64_t num) {
    if (num == 1) return 1;
    if (collatz_cache.count(num)) return collatz_cache[num];
    
    unsigned int length = 1 + collatzLen(num % 2 == 0 ? num / 2 : 3 * num + 1);
    collatz_cache[num] = length;
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int longest_num = 0;
    *maxlen = 0;
    
    for (uint64_t num = lbound; num <= rbound; ++num) {
        unsigned int length = collatzLen(num);
        if (length > *maxlen) {
            *maxlen = length;
            longest_num = num;
        }
    }
    return longest_num;
}
