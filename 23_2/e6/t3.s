

printIntStr:
	.string	"%f\n"
	
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	
	movl	$13, a(%rip)

	movl	f(%rip), %esi
	leaq	printIntStr(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax


	popq	%rbp
	ret

	.data
a:
	.long	10
b:
	.long 	15
_123:
	.long 	123
f:
	.long	2,5
