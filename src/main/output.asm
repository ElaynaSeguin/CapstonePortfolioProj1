
lui x5, 65552

addi x5, x5, 0

lw x6, 0(x5)

add x28, x0, x0

blt x6, x0, label_52

add x29, x6, x0

addi x7, x0, 1

sll x7, x7, x6

add x6, x7, x0

addi x5, x5, 4

lw x7, 0(x5)

add x28, x28, x7

addi x6, x6, 65535

blt x0, x6, label_4081
