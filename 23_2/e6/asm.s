##TAC_VARDEC
	movl	_15(%rip), %eax
	movl	%eax, _a(%rip)

##TAC_VARDEC
	movl	_charx(%rip), %eax
	movl	%eax, _x(%rip)

##TAC_VARDEC
	movl	_charx(%rip), %eax
	movl	%eax, _c(%rip)

##TAC_VARDEC
	movl	_100(%rip), %eax
	movl	%eax, _d(%rip)

##TAC_VARDEC
	movl	_charA(%rip), %eax
	movl	%eax, _1a(%rip)

##TAC_VARDEC
	movl	_1(%rip), %eax
	movl	%eax, _i(%rip)

##Assembly code 
##Assembly code 
##TAC_VARDEC
	movl	_2(%rip), %eax
	movl	%eax, _f(%rip)

##Assembly code 

##Assembly code 

##TAC_FOOSTART
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp 

##TAC_DIV 
	movl	_1(%rip), %edx
	movl	_1(%rip), %edx
	cltd
	idivl	%ecx
	movl	%eax, __temp1(%rip)

##TAC_MOVE
	movl	__temp1(%rip), %eax
	movl	%eax, _1a(%rip)

##TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1a(%rip)

##TAC_SUB
	movl	_d(%rip), %eax
	subl	_i(%rip), %eax
	movl	%eax, __temp2(%rip)

##TAC_MOVE
	movl	__temp2(%rip), %eax
	movl	%eax, _d(%rip)

##TAC_MOVE
	movl	_5(%rip), %eax
	movl	%eax, _d(%rip)

##TAC_ADD
	movl	_5(%rip), %eax
	addl	_2(%rip), %eax
	movl	%eax, __temp3(%rip)

##TAC_MUL 
	movl	_1(%rip), %edx
	movl	__temp3(%rip), %edx
	imull	%edx, %eax
	movl	%eax, __temp4(%rip)

##TAC_MOVE
	movl	__temp4(%rip), %eax
	movl	%eax, _c(%rip)

##Assembly code 

##Assembly code 
##Assembly code 

##TAC_PRINT
	movl	_v(%rip), %esi
	leaq	printIntStr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_PRINT
	movl	_d(%rip), %esi
	leaq	printCharStr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_MOVE
	movl	_2(%rip), %eax
	movl	%eax, _i(%rip)

##TAC_PRINT
	leaq	_s0(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##Assembly code 

##TAC_MOVE
	movl	__temp5(%rip), %eax
	movl	%eax, _d(%rip)

##TAC_PRINT
	leaq	_s1(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_LABEL
__label0:

##TAC_LSS
	movl	_i(%rip), %edx
	movl	_10(%rip), %eax
	cmpl	%eax, %edx 

##TAC_IF 
	jge	__label1

##Assembly code 

##Assembly code 

##TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1a(%rip)

##Assembly code 

##Assembly code 

##TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _i(%rip)

##Assembly code 

##Assembly code 

##TAC_MOVE
	movl	_d(%rip), %eax
	movl	%eax, _d(%rip)

##TAC_JUMP 
	jmp  __label0

##TAC_LABEL
__label1:

##TAC_PRINT
	leaq	_s2(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_PRINT
	movl	_d(%rip), %esi
	leaq	printCharStr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_PRINT
	leaq	_s3(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_EQ
	movl	_a(%rip), %edx
	movl	_15(%rip), %eax
	cmpl	%eax, %edx 

##TAC_IF 
	jne	__label2

##TAC_ADD
	movl	_a(%rip), %eax
	addl	_1(%rip), %eax
	movl	%eax, __temp11(%rip)

##TAC_MOVE
	movl	__temp11(%rip), %eax
	movl	%eax, _a(%rip)

##TAC_PRINT
	leaq	_s4(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_LABEL
__label2:

##TAC_EQ
	movl	_i(%rip), %edx
	movl	_100(%rip), %eax
	cmpl	%eax, %edx 

##TAC_IF 
	jne	__label3

##TAC_PRINT
	leaq	_s5(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_JUMP 
	jmp  __label4

##TAC_LABEL
__label3:

##TAC_PRINT
	leaq	_s6(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

##TAC_LABEL
__label4:

##TAC_FOOEND
	popq	%rbp
	ret

##TAC_FOOSTART
	.globl	incn
incn:
	pushq	%rbp
	movq	%rsp, %rbp 

##TAC_RETURN 
	movl	_x(%rip), %eax 

##TAC_FOOEND
	popq	%rbp
	ret

printIntStr:
	.string	"%d"

printFloatStr:
	.string	"%f"

printCharStr:
	.string	"%c"

_s4: 
	.string	"A era=15\n"

_s1: 
	.string	"Digite mais um numero: \n"

_s6: 
	.string	"OK!\n"

_s0: 
	.string	"Digite um numero: \n"

_s5: 
	.string	"Nao tem como isso...\n"

_s3: 
	.string	"\n"

_s2: 
	.string	"Incrementado algumas vezes a fica "

	.data 
_0: 
	.long	0
_1: 
	.long	1
_2: 
	.long	2
_5: 
	.long	5
_chare: 
	.long	53
_a: 
	.long	0
_c: 
	.long	0
_d: 
	.long	0
_f: 
	.long	0
__temp4: 
	.long	0
_i: 
	.long	0
_v: 
	.long	0
__temp10: 
	.long	0
_x: 
	.long	0
_matrix: 
	.long	0
__temp2: 
	.long	0
__temp9: 
	.long	0
__temp0: 
	.long	0
_charb: 
	.long	50
_10: 
	.long	10
__temp7: 
	.long	0
__temp5: 
	.long	0
_100: 
	.long	100
_15: 
	.long	15
__temp3: 
	.long	0
__temp12: 
	.long	0
_charA: 
	.long	17
__temp1: 
	.long	0
_charx: 
	.long	72
_chara: 
	.long	49
_1a: 
	.long	0
_55: 
	.long	55
__temp8: 
	.long	0
__temp11: 
	.long	0
__temp6: 
	.long	0
