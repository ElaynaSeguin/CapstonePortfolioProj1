# RISC-V-Simulator
### Division of Work
Lani: i-type instructions, User Menu 

Elayna: load, store instructions

Martin: r-type, u-type instructions

Phat: b-type instructions

Ngan: alu class

### List of References: 
- https://luplab.gitlab.io/rvcodecjs/ (asm/binary instruction translation)
- https://www.cs.cornell.edu/courses/cs3410/2019sp/riscv/interpreter/ (online riscv simulator)
- https://www.rapidtables.com/convert/number/decimal-to-binary.html? (hex,binary,decimal conversion)
- https://github.com/Ohyoukillkenny/riscv-simulator (student#1 example riscv simulator)
- https://github.com/fmash16/riscv_emulator (student#2 example riscv simulator)

## Progress

n/a = no tests available 

| Symbol  | Format                | Description                        | STATUS      |
| ------- | --------------------- | ---------------------------------- | ----------- |
| LUI     | `LUI rd,imm`          | Load Upper Immediate               | done |
| AUIPC   | `AUIPC rd,offset`     | Add Upper Immediate to PC          | done |
| JAL     | `JAL rd,offset`       | Jump and Link                      | done |
| JALR    | `JALR rd,rs1,offset`  | Jump and Link Register             | n/a |
| BEQ     | `BEQ rs1,rs2,offset`  | Branch Equal                       | done |
| BNE     | `BNE rs1,rs2,offset`  | Branch Not Equal                   | n/a |
| BLT     | `BLT rs1,rs2,offset`  | Branch Less Than                   | n/a |
| BGE     | `BGE rs1,rs2,offset`  | Branch Greater than Equal          | done |
| BLTU    | `BLTU rs1,rs2,offset` | Branch Less Than Unsigned          | n/a |
| BGEU    | `BGEU rs1,rs2,offset` | Branch Greater than Equal Unsigned | n/a |
| LB      | `LB rd,offset(rs1)`   | Load Byte                          |  |
| LH      | `LH rd,offset(rs1)`   | Load Half                          |  |
| LW      | `LW rd,offset(rs1)`   | Load Word                          | done |
| LBU     | `LBU rd,offset(rs1)`  | Load Byte Unsigned                 |  |
| LHU     | `LHU rd,offset(rs1)`  | Load Half Unsigned                 |  |
| SB      | `SB rs2,offset(rs1)`  | Store Byte                         |  |
| SH      | `SH rs2,offset(rs1)`  | Store Half                         |  |
| SW      | `SW rs2,offset(rs1)`  | Store Word                         | done |
| ADDI    | `ADDI rd,rs1,imm`     | Add Immediate                      | done |
| SLTI    | `SLTI rd,rs1,imm`     | Set Less Than Immediate            | done |
| SLTIU   | `SLTIU rd,rs1,imm`    | Set Less Than Immediate Unsigned   | n/a |
| XORI    | `XORI rd,rs1,imm`     | Xor Immediate                      | done |
| ORI     | `ORI rd,rs1,imm`      | Or Immediate                       | done |
| ANDI    | `ANDI rd,rs1,imm`     | And Immediate                      | done |
| SLLI    | `SLLI rd,rs1,imm`     | Shift Left Logical Immediate       | done |
| SRLI    | `SRLI rd,rs1,imm`     | Shift Right Logical Immediate      | done |
| SRAI    | `SRAI rd,rs1,imm`     | Shift Right Arithmetic Immediate   | done |
| ADD     | `ADD rd,rs1,rs2`      | Add                                | done |
| SUB     | `SUB rd,rs1,rs2`      | Subtract                           | done |
| SLL     | `SLL rd,rs1,rs2`      | Shift Left Logical                 | done |
| SLT     | `SLT rd,rs1,rs2`      | Set Less Than                      | done |
| SLTU    | `SLTU rd,rs1,rs2`     | Set Less Than Unsigned             | done |
| XOR     | `XOR rd,rs1,rs2`      | Xor                                | done |
| SRL     | `SRL rd,rs1,rs2`      | Shift Right Logical                | done |
| SRA     | `SRA rd,rs1,rs2`      | Shift Right Arithmetic             | done |
| OR      | `OR rd,rs1,rs2`       | Or                                 | done |
| AND     | `AND rd,rs1,rs2`      | And                                | done |
