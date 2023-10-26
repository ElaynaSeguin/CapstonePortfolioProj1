#include <iostream>  
#include <cstdint>
#include <stdint.h>
using namespace std;
#ifndef CPU_H
#define CPU_H


const uint8_t R = 0x00110011; // r-type opcode    e.g. add rd, r1, r2
const uint8_t S = 0x00100011; // s-type opcode    e.g. sw   rs1, rs2, imm
const uint8_t L = 0x00000011; // i-type load data,           exp. lw   rd,  rs1, imm
const uint8_t I = 0x00010011; // imm data processing, exp. addi rd, rs1, imm
const uint8_t SB = 0x01100011; // sb-type opcode                 exp. bne  rs1, rs2, imm
const uint8_t UJ = 0x01101111; // uj-type jal opcode         exp. jal  rd, imm
const uint8_t JALR = 0x01100111; // i- type jalr            
const uint8_t LUI = 0x00110111; // u-type lui opcode
const uint8_t AUIPC = 0x00010111; // u type auipc opcode


class cpu{
public:
  cpu();
  void run();
private:
  void fetch();

    uint8_t getfunct7(uint32_t instr);

    uint8_t getOpcode(uint32_t instr);

    uint8_t getrd(uint32_t instr);

    uint8_t getfunc3(uint32_t instr);

    uint8_t getrs1(uint32_t instr);

    uint8_t getrs2(uint32_t instr);

    uint32_t getimm12(uint32_t instr);

    uint32_t get_branch_imm(uint32_t instr);

    uint32_t get_jal_offset(uint32_t instr);

  void execute();
};

#endif
