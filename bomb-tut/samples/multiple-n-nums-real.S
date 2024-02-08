	.file	"multiple-n-nums.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
.LC1:
	.string	"Failure: Bomb was blown\n"
.LC2:
	.string	"Success: Bomb defused\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB11:
	pushq	%r13
	pushq	%r12
	leaq	.LC0(%rip), %r12
	pushq	%rbp
	movq	%r12, %rdi
	pushq	%rbx
	subq	$24, %rsp
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rsi
	call	__isoc99_scanf@PLT
	movl	(%rsp), %eax
	testl	%eax, %eax
	jle	.L2
	xorl	%ebx, %ebx
	movl	$1, %ebp
	leaq	4(%rsp), %r13
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%r13, %rsi
	movq	%r12, %rdi
	xorl	%eax, %eax
	addl	$1, %ebx
	call	__isoc99_scanf@PLT
	imull	4(%rsp), %ebp
	cmpl	%ebx, (%rsp)
	jg	.L3
	cmpl	$58008, %ebp
	je	.L11
.L2:
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
.L5:
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L12
	addq	$24, %rsp
	xorl	%eax, %eax
	popq	%rbx
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
.L11:
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	jmp	.L5
.L12:
	call	__stack_chk_fail@PLT
.LFE11:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.1 20230111"
	.section	.note.GNU-stack,"",@progbits
