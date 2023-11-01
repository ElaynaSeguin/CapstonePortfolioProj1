#include "cpu.h"

cpu::cpu(){
    //initialize alu ,mem, reg, etc.

}


uint8_t cpu::getOpcode(uint32_t instr){
    return (uint8_t)instr & 0x01111111;
}

uint8_t cpu::getrd(uint32_t instr){
    return (uint8_t)(instr >> 7) & 0x00011111;
}

uint8_t cpu::getrs1(uint32_t instr){
    return (uint8_t)(instr >> 15) & 0x00011111;
}

uint8_t cpu::getrs2(uint32_t instr){
    return (uint8_t)(instr >> 20) & 0x00011111;
}

uint8_t cpu::getfunct3(uint32_t instr){
    return (uint8_t)(instr >> 12) & 0x00000111;
}

uint8_t cpu::getfunct7(uint32_t instr){
    return (uint8_t)(instr >> 25) & 0x01111111;
}

