#include <iostream>
#include <cstdint>
using namespace std;

#ifndef CPU_H
#define CPU_H

class cpu
{
public:
  cpu();
  void run();
  //called in Main
  uint32_t getPC();
  uint32_t getReg(uint8_t index);
  uint32_t getMem(uint32_t addr);

private:
  void fetch();
  void decode();
  void execute();

  uint8_t get_rd();
  uint8_t get_r1();
  uint8_t get_r2();
};

#endif
