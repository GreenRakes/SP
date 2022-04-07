.data

print_format:
    .string "%d\n"

array:
    .long -50, 5, 85, -102, -17, 42, -126, -21, 103
array_end:

.text
.global main
.type main, @function

main:
    movl $array, %ebx  
    movb (%ebx), %al  
jmp bound

positive:
    cmpl $0, (%ebx) 
    jl negative
    btr $0, (%ebx)
    btr $4, (%ebx)
    push (%ebx)
    push $print_format
    call printf
    jne less
       
negative:
    sar $4, (%ebx)
    push (%ebx)
    push $print_format
    call printf
    jne less

less:
   addl $4, %ebx
   movb (%ebx), %al
    
bound:
    cmpl $array_end, %ebx
    jne positive

addl $8, %esp
movl $1, %eax
movl $0, %ebx
int $0x80



