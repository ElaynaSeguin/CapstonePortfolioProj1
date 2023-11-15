#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

#ifndef ALU_H
#define ALU_H

class alu
{
public:
    uint32_t alu::calculate(uint32_t in1, uint32_t in2, uint8_t op);
private:
    std::vector<uint32_t > registers; // 32 general-purpose registers
    // Use funct3 & funct7 to identify alu instruction
    const uint8_t ADD = 0b00000000;  
    const uint8_t SLL = 0b00000001;  
    const uint8_t XOR = 0b00000100;  
    const uint8_t OR = 0b00000110;   
    const uint8_t AND = 0b00000111;  
    const uint8_t SRL = 0b00000101;  
    const uint8_t SUB = 0b00001000;  
    const uint8_t SRA = 0b00001101;  
    const uint8_t SLT = 0b00000010;  
    const uint8_t SLTU = 0b00000011; 
};
#endif