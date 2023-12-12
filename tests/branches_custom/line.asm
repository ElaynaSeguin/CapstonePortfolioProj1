# Replace these values
t1 = x6
t2 = x7
t0 = x0

# Modified code
addi    x6, x0, 5       
addi    x7, x6, 3       

# Branch instructions
beq     x6, x7, equal    
bne     x6, x7, not_equal 
blt     x6, x7, less_than 
bge     x6, x7, greater_equal 
bltu    x6, x7, less_than_unsigned 
bgeu    x6, x7, greater_equal_unsigned 

# Your custom labels and instructions here
equal:
    nop
    j   end  

not_equal:
    nop
    j   end

less_than:
    nop
    j   end

greater_equal:
    nop
    j   end

less_than_unsigned:
    nop
    j   end

greater_equal_unsigned:
    nop

end:
    # End of the program
