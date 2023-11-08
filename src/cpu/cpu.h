#include <iostream>
#include <cstdint>
#include <stdint.h>
// #include "mem/mem.h"
// #include "reg/reg.h"
// #include "alu/alu.h"
#include "/Users/lanido/Documents/GitHub/RISC-V-Simulator/src/mem/mem.h"
#include "/Users/lanido/Documents/GitHub/RISC-V-Simulator/src/reg/reg.h"
#include "/Users/lanido/Documents/GitHub/RISC-V-Simulator/src/alu/alu.h"

#ifndef CPU_H
#define CPU_H

class cpu
{
public: // functions called in Main
  cpu();
  void run();
  void fetch();   // delete?
  void execute(); // delete?
  uint32_t getPC();
  uint32_t getReg(uint8_t index);
  uint32_t getMem(uint32_t addr);

private:
  mem mem;
  reg reg;
  alu alu;
  uint32_t PC;
  uint8_t getOpcode(uint32_t instr);
  uint8_t getrd(uint32_t instr);
  uint8_t getrs1(uint32_t instr);
  uint8_t getrs2(uint32_t instr);
  uint8_t getfunc3(uint32_t instr);
  uint8_t getfunct7(uint32_t instr);
  uint32_t getimm12(uint32_t instr);
  uint32_t get_branch_imm(uint32_t instr);
  uint32_t get_jal_offset(uint32_t instr);

  // funct 3 & 7 for each instruction type
  const static uint8_t S = 0b00100011;
  const static uint8_t R = 0b00110011;
  const static uint8_t L = 0b00000011;
  const static uint8_t I = 0b00010011;
  const static uint8_t SB = 0b01100011;
  const static uint8_t UJ = 0b01101111;
  const static uint8_t JALR = 0b01100111;
  const static uint8_t LUI = 0b00110111;
  const static uint8_t AUIPC = 0b00010111;
};

#endif
