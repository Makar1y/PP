	.file	"file.c"
	.text
	.globl	saveCount
	.bss
	.align 4
saveCount:
	.space 4
	.globl	loadCount
	.align 4
loadCount:
	.space 4
	.text
	.globl	saveToFile
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.seh_proc	saveToFile
saveToFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L2
	cmpq	$0, 24(%rbp)
	je	.L2
	movq	32(%rbp), %rax
	testq	%rax, %rax
	je	.L2
	movq	16(%rbp), %rdx
	leaq	32(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$8, %edx
	movq	%rax, %rcx
	call	fwrite
	testq	%rax, %rax
	je	.L2
	movq	32(%rbp), %rdx
	movq	16(%rbp), %rcx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	testq	%rax, %rax
	je	.L2
	movl	saveCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, saveCount(%rip)
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	$0, %eax
.L3:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	loadFromFile
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.seh_proc	loadFromFile
loadFromFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L5
	cmpq	$0, 24(%rbp)
	je	.L5
	movq	16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$8, %edx
	movq	%rax, %rcx
	call	fread
	testq	%rax, %rax
	je	.L5
	movq	-8(%rbp), %rdx
	movq	16(%rbp), %rcx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	testq	%rax, %rax
	je	.L5
	movl	loadCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, loadCount(%rip)
	movl	$1, %eax
	jmp	.L7
.L5:
	movl	$0, %eax
.L7:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
