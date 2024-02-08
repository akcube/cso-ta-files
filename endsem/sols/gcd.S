gcd:
.BASE_CASE:
	testq	%rsi, %rsi
	jne	.RECURSION
	movq	%rdi, %rax
	ret
.RECURSION:
	movq	%rdi, %rax
	cqto
	idivq	%rsi
	movq	%rsi, %rdi
	movq	%rdx, %rsi
	call	gcd
	ret

.section	.rodata
.LC0:
	.string	"%Ld %Ld"
.LC1:
	.string	"%Ld\n"

.text
.globl	main
main:
.LFB12:
	subq	$40, %rsp
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	16(%rsp), %rdx
	leaq	8(%rsp), %rsi
	leaq	.LC0(%rip), %rdi
	call	__isoc99_scanf@PLT
	movq	16(%rsp), %rsi
	movq	8(%rsp), %rdi
	call	gcd
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	24(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L11
	movl	$0, %eax
	addq	$40, %rsp
	ret
.L11:
	call	__stack_chk_fail@PLT
