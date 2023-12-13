
lui x5, 65552

addi x5, x5, 0

lw x6, 0(x5)

lui x5, 65552

addi x5, x5, 4

lw x7, 0(x5)

lui x5, 65552

addi x5, x5, 8

lw x28, 0(x5)

add x29, x0, x0

bge x6, x0, label_12

sub x30, x0, x6

jal x0, label_8

bge x7, x0, label_12

sub x31, x0, x7

jal x0, label_8

beq x30, x0, label_16

add x29, x29, x31

addi x30, x30, 65535

jal x0, label_65524

beq x30, x0, label_16

add x29, x29, x31

addi x30, x30, 65535

jal x0, label_65524

beq x30, x0, label_16

add x29, x29, x31

addi x30, x30, 65535

jal x0, label_65524

beq x30, x0, label_16

xor x5, x6, x7

bge x5, x0, label_8

add x29, x29, x28

lui x5, 65552

addi x5, x5, 12

sw x29, 0(x5)
