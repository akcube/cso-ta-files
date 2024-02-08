.section	.rodata
.INP_STR:
	.string	"%d %d"
.OUT_STR:
	.string	"%d\n"

.section	.text
.globl	main
main:
	subq	$8, %rsp
	leaq	.INP_STR(%rip), %rdi
	movq	%rsp, %rsi
	leaq	4(%rsp), %rdx
	call	__isoc99_scanf@PLT
	movl	4(%rsp), %esi
	addl	(%rsp), %esi
	leaq	.OUT_STR(%rip), %rdi
	call	printf@PLT
	addq	$8, %rsp
	xorl	%eax, %eax
	ret
	