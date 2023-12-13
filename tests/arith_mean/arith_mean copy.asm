.data 
n:
.word 3
.word -1
.word 3
.word -3
.word 9 
.word 6
.word 0
.word 0
.word 10
y:
.word -1 # random initial value

.text
lui     t0,%hi(n)
addi    t0, t0,%lo(n)
lw t1, 0(t0)
add t3, x0, x0
bltz t1, EXIT
add t4, t1, x0
addi t2, x0, 1
sll t2, t2, t1 
add t1, t2, x0
NEXT:
addi t0, t0, 4
lw t2, 0(t0)
add t3, t3, t2
addi t1, t1, -1
blt t1, NEXT
sra t3, t3, t4
addi t0, t0, 4
sw t3, 0(t0)
EXIT :


