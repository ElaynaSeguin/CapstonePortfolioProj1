#include <iostream>
#include <bitset>
using namespace std;

#ifndef CPU_H
#define CPU_H

class cpu
{
public:
    cpu();
    uint32_t getPC();
    uint32_t getReg(uint8_t idx);
    uint32_t getMem(uint32_t addr);

    // Convert machine -> assembly code
    // Write to .asm file for debugging
    void debug(){
                string instr = "";
        const uint8_t R_type = 0b0110011;
        const uint8_t I_type = 0b0000011;
        //test-values
        uint8_t opcode = 0b0110011; 
        uint8_t rs1 = 0b00000; //x0
        uint8_t rs2 = 0b00001; //x1
        uint8_t rd = 0b00010;  //x2
        uint8_t funct3 = 0b000;
        uint8_t funct7 = 0b0000000; //add
         
        //R-type
        if(opcode==R_type){
            if(funct3==0b000){
                if(funct7==0b0100000) instr += "sub ";
                else instr += "add ";
            }
            else if(funct3==0b001) instr += "sll ";
            else if(funct3==0b100) instr += "xor ";
            else if(funct3==0b101){
                if(funct7==0b0100000) instr += "sra ";
                else instr += "srl ";
            } 
            else if(funct3==0b110) instr += "or ";
            else if(funct3==0b111) instr += "and ";
        }
        //I-type
        else if(opcode==I_type){
            if(funct3==0b000) instr += "lb ";
            else if(funct3==0b000) instr += "addi ";
            else if(funct3==0b001) instr += "slli ";
            else if(funct3==0b100) instr += "xori ";
            else if(funct3==0b101){
                if(funct7==0b0100000) instr += "srai ";
                else instr += "srli ";
            } 
            else if(funct3==0b110) instr += "ori ";
            else if(funct3==0b111) instr += "andi ";
        }

        //need to check rs1,rs2,rsd, etc...

        cout << "\n"<<instr; //debug
    }
};
#endif