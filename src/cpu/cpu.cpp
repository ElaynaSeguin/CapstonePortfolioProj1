#include "cpu.h"

cpu::cpu()
{
    // mem mem;
    // reg reg;
    // alu alu;
    PC = 0;
}

void cpu::run()
{
    // parse opcode

    // switch case for instruction type
}

uint32_t cpu::getPC()
{
    return PC;
}
uint32_t cpu::getReg(uint8_t index)
{
    return reg.readReg(index);
}
uint32_t cpu::getMem(uint32_t addr)
{
    return mem.get_mem(addr);
}