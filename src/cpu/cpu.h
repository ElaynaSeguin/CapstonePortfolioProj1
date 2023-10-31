#include <iostream>
#include <cstdint>
#include <stdint.h>

#ifndef CPU_H
#define CPU_H

class cpu
{
public:
  cpu();
  // functions called in Main
  void run();
  uint32_t getPC();
  uint32_t getReg(uint8_t index);
  uint32_t getMem(uint32_t addr);

private:
  void fetch();   // delete?
  void execute(); // delete?
  uint8_t getOpcode(uint32_t instr);
  uint8_t getrd(uint32_t instr);
  uint8_t getrs1(uint32_t instr);
  uint8_t getrs2(uint32_t instr);
  uint8_t getfunc3(uint32_t instr);
  uint8_t getfunct7(uint32_t instr);
  uint32_t getimm12(uint32_t instr);
  uint32_t get_branch_imm(uint32_t instr);
  uint32_t get_jal_offset(uint32_t instr);

  //funct 3 & 7 for each instruction type 
  const uint8_t R = 0x00110011;     
  const uint8_t S = 0x00100011;     
  const uint8_t L = 0x00000011;     
  const uint8_t I = 0x00010011;     
  const uint8_t SB = 0x01100011;    
  const uint8_t UJ = 0x01101111;    
  const uint8_t JALR = 0x01100111;  
  const uint8_t LUI = 0x00110111;  
  const uint8_t AUIPC = 0x00010111;
};

#endif
