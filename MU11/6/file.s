	.file	"file.c"
	.text
	.globl	countersManager
	.bss
	.align 32
countersManager:
	.space 32
	.text
	.globl	getSaveCount
	.def	getSaveCount;	.scl	2;	.type	32;	.endef
	.seh_proc	getSaveCount
getSaveCount:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L2
	movq	countersManager(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L3
.L6:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, 16(%rbp)
	jne	.L4
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	jmp	.L5
.L4:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
.L3:
	cmpq	$0, -8(%rbp)
	jne	.L6
	movl	$0, %eax
	jmp	.L5
.L2:
	movl	8+countersManager(%rip), %eax
.L5:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	getLoadCount
	.def	getLoadCount;	.scl	2;	.type	32;	.endef
	.seh_proc	getLoadCount
getLoadCount:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L8
	movq	16+countersManager(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L9
.L12:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, 16(%rbp)
	jne	.L10
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	jmp	.L11
.L10:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
.L9:
	cmpq	$0, -8(%rbp)
	jne	.L12
	movl	$0, %eax
	jmp	.L11
.L8:
	movl	24+countersManager(%rip), %eax
.L11:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "file.c\0"
.LC1:
	.ascii "file\0"
	.align 8
.LC2:
	.ascii "Error! Cant locate memory for save file counter.\0"
	.text
	.globl	addSaveCount
	.def	addSaveCount;	.scl	2;	.type	32;	.endef
	.seh_proc	addSaveCount
addSaveCount:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	cmpq	$0, 16(%rbp)
	jne	.L14
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rax
	movl	$54, %r8d
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L14:
	movq	countersManager(%rip), %rax
	movq	%rax, -8(%rbp)
	nop
	cmpq	$0, -8(%rbp)
	je	.L20
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, 16(%rbp)
	jne	.L21
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 8(%rax)
	jmp	.L21
.L20:
	movl	$24, %ecx
	call	malloc
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L19
	movq	-16(%rbp), %rax
	movl	$1, 8(%rax)
	movq	-16(%rbp), %rax
	movq	16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	countersManager(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, countersManager(%rip)
	movl	8+countersManager(%rip), %eax
	addl	$1, %eax
	movl	%eax, 8+countersManager(%rip)
	jmp	.L13
.L19:
	movl	$2, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rdx, %r9
	movl	$48, %r8d
	movl	$1, %edx
	movq	%rax, %rcx
	call	fwrite
	jmp	.L13
.L21:
	nop
.L13:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	addLoadCount
	.def	addLoadCount;	.scl	2;	.type	32;	.endef
	.seh_proc	addLoadCount
addLoadCount:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	cmpq	$0, 16(%rbp)
	jne	.L23
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rax
	movl	$76, %r8d
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L23:
	movq	16+countersManager(%rip), %rax
	movq	%rax, -8(%rbp)
	nop
	cmpq	$0, -8(%rbp)
	je	.L29
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, 16(%rbp)
	jne	.L30
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 8(%rax)
	jmp	.L30
.L29:
	movl	$24, %ecx
	call	malloc
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L28
	movq	-16(%rbp), %rax
	movl	$1, 8(%rax)
	movq	-16(%rbp), %rax
	movq	16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	16+countersManager(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, 16+countersManager(%rip)
	movl	24+countersManager(%rip), %eax
	addl	$1, %eax
	movl	%eax, 24+countersManager(%rip)
	jmp	.L22
.L28:
	movl	$2, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rdx, %r9
	movl	$48, %r8d
	movl	$1, %edx
	movq	%rax, %rcx
	call	fwrite
	jmp	.L22
.L30:
	nop
.L22:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
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
	je	.L32
	cmpq	$0, 24(%rbp)
	je	.L32
	movq	32(%rbp), %rax
	testq	%rax, %rax
	je	.L32
	movq	16(%rbp), %rdx
	leaq	32(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$8, %edx
	movq	%rax, %rcx
	call	fwrite
	testq	%rax, %rax
	je	.L32
	movq	32(%rbp), %rdx
	movq	16(%rbp), %rcx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	testq	%rax, %rax
	je	.L32
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	addSaveCount
	movl	$1, %eax
	jmp	.L33
.L32:
	movl	$0, %eax
.L33:
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
	je	.L35
	cmpq	$0, 24(%rbp)
	je	.L35
	movq	16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$8, %edx
	movq	%rax, %rcx
	call	fread
	testq	%rax, %rax
	je	.L35
	movq	-8(%rbp), %rdx
	movq	16(%rbp), %rcx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	testq	%rax, %rax
	je	.L35
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	addLoadCount
	movl	$1, %eax
	jmp	.L37
.L35:
	movl	$0, %eax
.L37:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
