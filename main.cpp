#include "header/hamming.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::unique_ptr<Hamming> hamming = std::make_unique<Hamming>();
    std::vector<uint8_t> data, encoded, decoded;

    uint64_t number;
    int choice = 1, k=0;
    size_t changedPosition;
    std::vector<uint8_t> modifiedBits;
    std::pair<std::vector<uint8_t>, size_t> result;
    while (true)
    {
        std::cout << "\nCHOOSE OPTION:\n1. ENTER A DECIMAL NUMBER\n2. ENCODE\n3. DECODE\n4. INVERT RANDOM BIT\n5. EXIT\n";
        std::cout << "OPTION: "; std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "ENTER A DECIMAL NUMBER LESS THAN 2^64-1: ";
            std::cin >> number;
            data = hamming->numberToBits(number);
            hamming->showBitsByNum(data);
            break;
        case 2:  
            encoded = hamming->hammingEncode(data);
            break; 

        case 3:  
            decoded = hamming->hammingDecode(encoded);
            std::cout<<"Decoded number: "<<hamming->bitsToNumber(decoded)<<"\n";
            break; 

        case 4:  
            result = hamming->invertRandomBit(encoded);
            modifiedBits = result.first;
            changedPosition = result.second;
            std::cout << "\nModified bits: \n";
            
            for (uint8_t bit : modifiedBits) {
                std::cout << static_cast<int>(bit) << " ";
                k++;
                if (k == 8) {
                    std::cout<<"\n";
                    k=0;
                }
            }
            std::cout << "\n";

            std::cout << "Changed position: " << changedPosition << "\n";
            decoded = hamming->hammingDecode(modifiedBits);
            std::cout<<"Decoded number: "<<hamming->bitsToNumber(decoded)<<"\n";
            break;

        case 5:
            std::cout << "PROGRAM EXITED\n";
            return 0;    
        
        default:
            std::cout << "INVALID OPTION, TRY AGAIN!\n";
            break;
        }    
    }    

    return 0;
}
