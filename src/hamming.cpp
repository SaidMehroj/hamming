#include "../header/hamming.h"
#include <vector>
#include <cstdint>
#include <iostream>
Hamming::Hamming() {}

void Hamming::showBits(const std::vector<uint8_t> &bytes, const std::vector<uint8_t> &encoded) {
    for (int byte : bytes) {
        std::cout<<byte<<' ';
    }

    std::cout<<" --> ";

    for (int byte : encoded) {
        std::cout<<byte<<' ';
    }

    std::cout<<std::endl;
}

void Hamming::showBitsByNum(const std::vector<uint8_t> &bytes) {
    std::cout<<"Entered number in bits\n";
    int count=0;
    for (int byte : bytes) {
        count++;
        std::cout<<byte<<' ';
        if (count == 4) {
            std::cout<<' ';
            count=0;
        }
    }
    std::cout<<"\n";
}

std::vector<uint8_t> Hamming::encode(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> code(8);

    code[2] = data[0]; // d1
    code[4] = data[1]; // d2
    code[5] = data[2]; // d3
    code[6] = data[3]; // d4

    code[0] = code[2] ^ code[4] ^ code[6];      // p1
    code[1] = code[2] ^ code[5] ^ code[6];      // p2
    code[3] = code[4] ^ code[5] ^ code[6];      // p3
    code[7] = code[0] ^ code[1] ^ code[3] ^ code[2] ^ code[4] ^ code[5] ^ code[6]; // p4

    return code;
}

std::vector<uint8_t> Hamming::decode(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> decoded = data;

    uint8_t p1 = decoded[0]; uint8_t p2 = decoded[1]; uint8_t p3 = decoded[3]; uint8_t p4 = decoded[7];
    uint8_t d1 = decoded[2]; uint8_t d2 = decoded[4]; uint8_t d3 = decoded[5]; uint8_t d4 = decoded[6];

    uint8_t S1 = p1 ^ d1 ^ d2 ^ d4;
    uint8_t S2 = p2 ^ d1 ^ d3 ^ d4;
    uint8_t S3 = p3 ^ d2 ^ d3 ^ d4;
    uint8_t S4 = p4 ^ d1 ^ d2 ^ d3;

    uint8_t sum = S1 + (S2 << 1) + (S3 << 2) + (S4 << 3);

    if (sum != 0 && sum <= 8) 
    {
        decoded[sum - 1] ^= 1; 
    } 
    else if (sum != 0 && sum > 8)
    {
        decoded[sum - 9] ^= 1;
    }
    

    return {decoded[2], decoded[4], decoded[5], decoded[6]};
}

std::vector<uint8_t> Hamming::hammingEncode(const std::vector<uint8_t>& bytes) {
    if (bytes.empty()) {
        throw std::invalid_argument("Input vector is empty.");
    }

    std::vector<uint8_t> temp;
    std::vector<uint8_t> res;
   
    int count=0;
    std::cout<<"\nENCODED DATA\n";
    for (uint8_t byte : bytes) {
        count++;
        temp.push_back(byte);
        
        if (count == 4) {
            std::vector<uint8_t> ans = encode(temp);
            showBits(temp,ans);
            res.insert(res.end(), ans.begin(), ans.end());
            temp.clear();
            count=0;
        }
    }
    
    return res;
}

std::vector<uint8_t> Hamming::hammingDecode(const std::vector<uint8_t>& bytes) {
    if (bytes.empty()) {
        throw std::invalid_argument("Input vector is empty.");
    }
    int count=0;
    std::vector<uint8_t> temp;
    std::vector<uint8_t> res;
    std::cout<<"\nDECODED DATA\n";
    for (uint8_t byte : bytes) {
        count++;
        temp.push_back(byte);
        if (count == 8) {
            std::vector<uint8_t> ans = decode(temp);
            showBits(temp,ans);
            res.insert(res.end(), ans.begin(), ans.end());
            temp.clear();
            count=0;
        }
    }
    return res;
}

std::vector<uint8_t> Hamming::numberToBits(uint64_t number) {
    std::vector<uint8_t> bits;

    while (number > 0) {
        bits.insert(bits.begin(), number & 1); 
        number >>= 1; 
    }

    while (bits.size() % 4 != 0) {
        bits.insert(bits.begin(), 0); 
    }

    return bits;
}

std::pair<std::vector<uint8_t>, size_t> Hamming::invertRandomBit(const std::vector<uint8_t>& input) {
    if (input.empty()) {
        throw std::invalid_argument("Input vector is empty.");
    }

    std::vector<uint8_t> output = input;

    std::srand(std::time(nullptr));

    size_t position = std::rand() % output.size();

    output[position] ^= 1;

    return {output, position};
}

uint64_t Hamming::bitsToNumber(const std::vector<uint8_t>& bits) {
    uint64_t number = 0;

    for (size_t i = 0; i < bits.size(); ++i) {
        number = (number << 1) | bits[i]; // Сдвигаем число влево и добавляем текущий бит
    }

    return number;
}