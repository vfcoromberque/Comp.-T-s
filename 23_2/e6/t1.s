##TAC START?
printIntStr:
	.string	"%d\n"

##TAC_FOOSTART
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

##TAC_PRINT
	movl	$5, %esi
	leaq	printIntStr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_FOOEND
	popq	%rbp
	ret

