	.file	"test_restrict.c"
	.text
	.p2align 4
	.globl	copyArray
	.type	copyArray, @function
copyArray:
.LFB12:
	.cfi_startproc
	endbr64
	movslq	%edi, %rax
	movq	%rsi, %rdi
	movq	%rdx, %rsi
	testl	%eax, %eax
	jle	.L1
	leaq	0(,%rax,4), %rdx
	jmp	memcpy@PLT
	.p2align 4,,10
	.p2align 3
.L1:
	ret
	.cfi_endproc
.LFE12:
	.size	copyArray, .-copyArray
	.p2align 4
	.globl	FuncCopyArray
	.type	FuncCopyArray, @function
FuncCopyArray:
.LFB13:
	.cfi_startproc
	endbr64
	movq	%rsi, %rcx
	leal	-1(%rdi), %r8d
	testl	%edi, %edi
	jle	.L4
	leaq	4(%rdx), %rsi
	movq	%rcx, %rax
	subq	%rsi, %rax
	cmpq	$8, %rax
	jbe	.L6
	cmpl	$2, %r8d
	jbe	.L6
	movl	%edi, %esi
	xorl	%eax, %eax
	shrl	$2, %esi
	salq	$4, %rsi
	.p2align 4,,10
	.p2align 3
.L7:
	movdqu	(%rdx,%rax), %xmm0
	movups	%xmm0, (%rcx,%rax)
	addq	$16, %rax
	cmpq	%rax, %rsi
	jne	.L7
	movl	%edi, %esi
	andl	$-4, %esi
	movl	%esi, %eax
	subl	%esi, %r8d
	salq	$2, %rax
	addq	%rax, %rcx
	addq	%rdx, %rax
	cmpl	%esi, %edi
	je	.L4
	movl	(%rax), %edx
	movl	%edx, (%rcx)
	testl	%r8d, %r8d
	jle	.L4
	movl	4(%rax), %edx
	movl	%edx, 4(%rcx)
	cmpl	$1, %r8d
	jle	.L4
	movl	8(%rax), %eax
	movl	%eax, 8(%rcx)
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	movslq	%edi, %rdi
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L9:
	movl	(%rdx,%rax,4), %esi
	movl	%esi, (%rcx,%rax,4)
	addq	$1, %rax
	cmpq	%rax, %rdi
	jne	.L9
.L4:
	ret
	.cfi_endproc
.LFE13:
	.size	FuncCopyArray, .-FuncCopyArray
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB14:
	.cfi_startproc
	endbr64
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE14:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
