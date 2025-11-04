	.file	"11-3.c"
	.text
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	%r9d, 40(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L5
	movl	$0, -4(%rbp)
	jmp	.L3
.L4:
	call	rand
	movl	40(%rbp), %edx
	subl	32(%rbp), %edx
	leal	1(%rdx), %ecx
	cltd
	idivl	%ecx
	movl	%edx, %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	32(%rbp), %edx
	addl	%ecx, %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cltq
	cmpq	24(%rbp), %rax
	jb	.L4
.L5:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d \0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
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
	je	.L10
	movq	$0, -8(%rbp)
	jmp	.L8
.L9:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	leaq	.LC0(%rip), %rcx
	movl	%eax, %edx
	call	printf
	addq	$1, -8(%rbp)
.L8:
	movq	-8(%rbp), %rax
	cmpq	24(%rbp), %rax
	jb	.L9
	movl	$10, %ecx
	call	putchar
.L10:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "wb\0"
.LC2:
	.ascii "test1.bin\0"
.LC3:
	.ascii "test2.bin\0"
.LC4:
	.ascii "11-3.c\0"
	.align 8
.LC5:
	.ascii "file1 && file2 && m1 && m2 && m3\0"
.LC6:
	.ascii "rb\0"
.LC7:
	.ascii "All good.\0"
.LC8:
	.ascii "Something's wrong.\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$192, %rsp
	.seh_stackalloc	192
	.seh_endprologue
	call	__main
	movl	$0, %ecx
	call	_time64
	movl	%eax, %ecx
	call	srand
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L12
	cmpq	$0, -16(%rbp)
	jne	.L13
.L12:
	leaq	.LC4(%rip), %rdx
	leaq	.LC5(%rip), %rax
	movl	$40, %r8d
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L13:
	leaq	-64(%rbp), %rax
	movl	$10, %r9d
	movl	$0, %r8d
	movl	$10, %edx
	movq	%rax, %rcx
	call	fillArray
	leaq	-112(%rbp), %rax
	movl	$10, %r9d
	movl	$0, %r8d
	movl	$10, %edx
	movq	%rax, %rcx
	call	fillArray
	leaq	-160(%rbp), %rax
	movl	$10, %r9d
	movl	$0, %r8d
	movl	$10, %edx
	movq	%rax, %rcx
	call	fillArray
	leaq	-64(%rbp), %rdx
	movq	-8(%rbp), %rax
	movl	$10, %r8d
	movq	%rax, %rcx
	call	saveToFile
	leaq	-160(%rbp), %rdx
	movq	-8(%rbp), %rax
	movl	$10, %r8d
	movq	%rax, %rcx
	call	saveToFile
	movq	-8(%rbp), %rcx
	leaq	.LC6(%rip), %rdx
	leaq	.LC2(%rip), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	freopen
	movq	%rax, -8(%rbp)
	leaq	-64(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	leaq	-112(%rbp), %rdx
	movq	-16(%rbp), %rax
	movl	$10, %r8d
	movq	%rax, %rcx
	call	saveToFile
	movq	-16(%rbp), %rcx
	leaq	.LC6(%rip), %rdx
	leaq	.LC3(%rip), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	freopen
	movq	%rax, -16(%rbp)
	leaq	-160(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	leaq	-112(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	.refptr.loadCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L14
	movq	.refptr.saveCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L14
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L15
.L14:
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L15:
	movl	$0, %eax
	addq	$192, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.saveCount, "dr"
	.p2align	3, 0
	.globl	.refptr.saveCount
	.linkonce	discard
.refptr.saveCount:
	.quad	saveCount
	.section	.rdata$.refptr.loadCount, "dr"
	.p2align	3, 0
	.globl	.refptr.loadCount
	.linkonce	discard
.refptr.loadCount:
	.quad	loadCount
