#pragma once
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <utility>
class Hamming
{
private:
    
public:
    Hamming();
    void showBits(const std::vector<uint8_t> &bytes, const std::vector<uint8_t> &encoded);
    void showBitsByNum(const std::vector<uint8_t> &bytes);
    std::vector<uint8_t> encode(const std::vector<uint8_t>& data);
    std::vector<uint8_t> decode(const std::vector<uint8_t>& data);
    std::vector<uint8_t> hammingEncode(const std::vector<uint8_t>& bytes);
    std::vector<uint8_t> hammingDecode(const std::vector<uint8_t>& bytes);
    std::vector<uint8_t> numberToBits(uint64_t number);
    std::pair<std::vector<uint8_t>, size_t> invertRandomBit(const std::vector<uint8_t>& input);
    uint64_t bitsToNumber(const std::vector<uint8_t>& bits);
};