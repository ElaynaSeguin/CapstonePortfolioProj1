#include <iostream>
#include <cstdint>
#include <stdint.h>
#include <string.h>
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
  // void fetch();   // delete?
  // void execute(); // delete?
  uint32_t getPC();
  uint32_t getReg(uint8_t index);
  uint32_t getMem(uint32_t addr);
  string getAsmInstruction();

private:
  mem mem;
  reg reg;
  alu alu;
  uint32_t PC;
  string AsmInstruction; 
  string setAsmInstruction();
  uint8_t getOpcode(uint32_t instr);
  uint8_t getrd(uint32_t instr);
  uint8_t getrs1(uint32_t instr);
  uint8_t getrs2(uint32_t instr);
  uint8_t getfunct3(uint32_t instr);
  uint8_t getfunct7(uint32_t instr);
  uint32_t getimm12(uint32_t instr);
  uint32_t get_branch_imm(uint32_t instr);
  uint32_t get_jal_offset(uint32_t instr);
};

#endif
