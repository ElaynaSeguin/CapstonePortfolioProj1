
#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>

class Register {
public:
    Register();  // Constructor

    uint32_t readRegister(int index) const;  // Read a 32-bit register
    void writeRegister(int index, uint32_t value);  // Write a 32-bit register

    void reset();  // Reset all registers to zero

private:
    static const int NUM_REGISTERS = 32;
    uint32_t registers[NUM_REGISTERS];
};

#endif 
