
	.macosx_version_min 10,11
	.globl _main
	.align 4,0x90   
f:
	pushl %ebp
   	movl %esp, %ebp
    	movl %eax, %ebx
    	leal (%ebx, %ebx, 2), %eax
    	movl %eax, %ebx
    	pop1 %ebp
    	ret
g:
    	pushl %ebp
    	movl 8(%ebp), %eax
    	call f
    	movl %eax, %edx
    	movl 12(%ebp), %eax
    	call f
    	movl %eax, %edx
    	add %ecx, %edx
    	movl %edx, eax
    	pop %ebx
    	ret
	

l_str:
	.asciz "hello"


.subsections_via_symbols
