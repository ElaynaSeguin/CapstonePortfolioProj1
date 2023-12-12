#include <iostream>
#include <cstdint>
#include <stdint.h>
#include <string.h>
#include "../mem/mem.cpp"
#include "../reg/reg.cpp"
#include "../alu/alu.cpp"
// #include "../alu/alu.h"

#ifndef __CPU_H__
#define __CPU_H__

class cpu
{
public: // functions called in Main
    cpu(mem,mem);
    void run();
    uint32_t getPC();
    uint32_t getReg(uint8_t index);
    uint32_t getMem(uint32_t addr);
private:
    mem imem;
    mem dmem;
    reg reg;
    alu alu;
    uint32_t PC;
    // vector<uint32_t> instr;
    // OPCODES
    const static uint8_t R = 0b00110011;    
    const static uint8_t I = 0b00010011;   
    const static uint8_t L = 0b00000011;   
    const static uint8_t S = 0b00100011;   
    const static uint8_t B = 0b01100011;   
    const static uint8_t JAL = 0b01101111;  
    const static uint8_t JALR = 0b01100111;
    const static uint8_t LUI = 0b00110111;
    const static uint8_t AUIPC = 0b00010111;
    // DECODE
    uint8_t getOpcode(uint32_t instr);
    uint8_t getrd(uint32_t instr);
    uint8_t getrs1(uint32_t instr);
    uint8_t getrs2(uint32_t instr);
    uint8_t getfunct3(uint32_t instr);
    uint8_t getfunct7(uint32_t instr);
    int16_t getimm12(uint32_t instr);
    int32_t getimm20(uint32_t instr);
    uint32_t get_branch_imm(uint32_t instr);
    int16_t get_jal_offset(uint32_t instr);
    uint8_t getALU_op(uint32_t instr);
    string stringify(int32_t line);
    // EXECUTE
    void r_type(uint32_t instr);
    void i_type(uint32_t instr);
    void s_type(uint32_t instr);
    void b_type(uint32_t instr);
    void l_type(uint32_t instr);
    void jal(uint32_t instr);
    void jalr(uint32_t instr);
    void lui(uint32_t instr);
    void auipc(uint32_t instr);

    //DELETE, issue with #include alu.h
    const static int8_t ADD = 0b00000000; // alu opcodes
    const static int8_t SUB = 0b00100000;
    const static int8_t OR = 0b00000110; 
    const static int8_t AND = 0b00000111;
    const static int8_t XOR = 0b00000100;
    const static int8_t SRL = 0b00000101;
    const static int8_t SRA = 0b00100101;
    const static int8_t SLL = 0b00000001;
    const static int8_t SLT = 0b00000010;
    const static int8_t SLTU = 0b00000011;
};

#endif