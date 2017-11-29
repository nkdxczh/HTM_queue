
main:     file format elf64-x86-64


Disassembly of section .init:

0000000000400978 <_init>:
  400978:	48 83 ec 08          	sub    $0x8,%rsp
  40097c:	48 8b 05 75 16 20 00 	mov    0x201675(%rip),%rax        # 601ff8 <_DYNAMIC+0x200>
  400983:	48 85 c0             	test   %rax,%rax
  400986:	74 05                	je     40098d <_init+0x15>
  400988:	e8 13 01 00 00       	callq  400aa0 <_ZNSt8ios_base4InitD1Ev@plt+0x10>
  40098d:	48 83 c4 08          	add    $0x8,%rsp
  400991:	c3                   	retq   

Disassembly of section .plt:

00000000004009a0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@plt-0x10>:
  4009a0:	ff 35 62 16 20 00    	pushq  0x201662(%rip)        # 602008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4009a6:	ff 25 64 16 20 00    	jmpq   *0x201664(%rip)        # 602010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4009ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004009b0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@plt>:
  4009b0:	ff 25 62 16 20 00    	jmpq   *0x201662(%rip)        # 602018 <_GLOBAL_OFFSET_TABLE_+0x18>
  4009b6:	68 00 00 00 00       	pushq  $0x0
  4009bb:	e9 e0 ff ff ff       	jmpq   4009a0 <_init+0x28>

00000000004009c0 <pthread_mutex_unlock@plt>:
  4009c0:	ff 25 5a 16 20 00    	jmpq   *0x20165a(%rip)        # 602020 <_GLOBAL_OFFSET_TABLE_+0x20>
  4009c6:	68 01 00 00 00       	pushq  $0x1
  4009cb:	e9 d0 ff ff ff       	jmpq   4009a0 <_init+0x28>

00000000004009d0 <__cxa_atexit@plt>:
  4009d0:	ff 25 52 16 20 00    	jmpq   *0x201652(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  4009d6:	68 02 00 00 00       	pushq  $0x2
  4009db:	e9 c0 ff ff ff       	jmpq   4009a0 <_init+0x28>

00000000004009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
  4009e0:	ff 25 4a 16 20 00    	jmpq   *0x20164a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4009e6:	68 03 00 00 00       	pushq  $0x3
  4009eb:	e9 b0 ff ff ff       	jmpq   4009a0 <_init+0x28>

00000000004009f0 <_ZNSolsEPFRSoS_E@plt>:
  4009f0:	ff 25 42 16 20 00    	jmpq   *0x201642(%rip)        # 602038 <_GLOBAL_OFFSET_TABLE_+0x38>
  4009f6:	68 04 00 00 00       	pushq  $0x4
  4009fb:	e9 a0 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a00 <__stack_chk_fail@plt>:
  400a00:	ff 25 3a 16 20 00    	jmpq   *0x20163a(%rip)        # 602040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400a06:	68 05 00 00 00       	pushq  $0x5
  400a0b:	e9 90 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a10 <pthread_mutex_lock@plt>:
  400a10:	ff 25 32 16 20 00    	jmpq   *0x201632(%rip)        # 602048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400a16:	68 06 00 00 00       	pushq  $0x6
  400a1b:	e9 80 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a20 <GOMP_parallel@plt>:
  400a20:	ff 25 2a 16 20 00    	jmpq   *0x20162a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400a26:	68 07 00 00 00       	pushq  $0x7
  400a2b:	e9 70 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a30 <_ZNSt8ios_base4InitC1Ev@plt>:
  400a30:	ff 25 22 16 20 00    	jmpq   *0x201622(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400a36:	68 08 00 00 00       	pushq  $0x8
  400a3b:	e9 60 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a40 <omp_get_thread_num@plt>:
  400a40:	ff 25 1a 16 20 00    	jmpq   *0x20161a(%rip)        # 602060 <_GLOBAL_OFFSET_TABLE_+0x60>
  400a46:	68 09 00 00 00       	pushq  $0x9
  400a4b:	e9 50 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a50 <__gxx_personality_v0@plt>:
  400a50:	ff 25 12 16 20 00    	jmpq   *0x201612(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400a56:	68 0a 00 00 00       	pushq  $0xa
  400a5b:	e9 40 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a60 <_ZNSolsEi@plt>:
  400a60:	ff 25 0a 16 20 00    	jmpq   *0x20160a(%rip)        # 602070 <_GLOBAL_OFFSET_TABLE_+0x70>
  400a66:	68 0b 00 00 00       	pushq  $0xb
  400a6b:	e9 30 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a70 <__libc_start_main@plt>:
  400a70:	ff 25 02 16 20 00    	jmpq   *0x201602(%rip)        # 602078 <_GLOBAL_OFFSET_TABLE_+0x78>
  400a76:	68 0c 00 00 00       	pushq  $0xc
  400a7b:	e9 20 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a80 <omp_get_num_threads@plt>:
  400a80:	ff 25 fa 15 20 00    	jmpq   *0x2015fa(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400a86:	68 0d 00 00 00       	pushq  $0xd
  400a8b:	e9 10 ff ff ff       	jmpq   4009a0 <_init+0x28>

0000000000400a90 <_ZNSt8ios_base4InitD1Ev@plt>:
  400a90:	ff 25 f2 15 20 00    	jmpq   *0x2015f2(%rip)        # 602088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400a96:	68 0e 00 00 00       	pushq  $0xe
  400a9b:	e9 00 ff ff ff       	jmpq   4009a0 <_init+0x28>

Disassembly of section .plt.got:

0000000000400aa0 <.plt.got>:
  400aa0:	ff 25 52 15 20 00    	jmpq   *0x201552(%rip)        # 601ff8 <_DYNAMIC+0x200>
  400aa6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000400ab0 <_start>:
  400ab0:	31 ed                	xor    %ebp,%ebp
  400ab2:	49 89 d1             	mov    %rdx,%r9
  400ab5:	5e                   	pop    %rsi
  400ab6:	48 89 e2             	mov    %rsp,%rdx
  400ab9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400abd:	50                   	push   %rax
  400abe:	54                   	push   %rsp
  400abf:	49 c7 c0 00 10 40 00 	mov    $0x401000,%r8
  400ac6:	48 c7 c1 90 0f 40 00 	mov    $0x400f90,%rcx
  400acd:	48 c7 c7 38 0c 40 00 	mov    $0x400c38,%rdi
  400ad4:	e8 97 ff ff ff       	callq  400a70 <__libc_start_main@plt>
  400ad9:	f4                   	hlt    
  400ada:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400ae0 <deregister_tm_clones>:
  400ae0:	b8 a7 20 60 00       	mov    $0x6020a7,%eax
  400ae5:	55                   	push   %rbp
  400ae6:	48 2d a0 20 60 00    	sub    $0x6020a0,%rax
  400aec:	48 83 f8 0e          	cmp    $0xe,%rax
  400af0:	48 89 e5             	mov    %rsp,%rbp
  400af3:	76 1b                	jbe    400b10 <deregister_tm_clones+0x30>
  400af5:	b8 00 00 00 00       	mov    $0x0,%eax
  400afa:	48 85 c0             	test   %rax,%rax
  400afd:	74 11                	je     400b10 <deregister_tm_clones+0x30>
  400aff:	5d                   	pop    %rbp
  400b00:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400b05:	ff e0                	jmpq   *%rax
  400b07:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  400b0e:	00 00 
  400b10:	5d                   	pop    %rbp
  400b11:	c3                   	retq   
  400b12:	0f 1f 40 00          	nopl   0x0(%rax)
  400b16:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400b1d:	00 00 00 

0000000000400b20 <register_tm_clones>:
  400b20:	be a0 20 60 00       	mov    $0x6020a0,%esi
  400b25:	55                   	push   %rbp
  400b26:	48 81 ee a0 20 60 00 	sub    $0x6020a0,%rsi
  400b2d:	48 c1 fe 03          	sar    $0x3,%rsi
  400b31:	48 89 e5             	mov    %rsp,%rbp
  400b34:	48 89 f0             	mov    %rsi,%rax
  400b37:	48 c1 e8 3f          	shr    $0x3f,%rax
  400b3b:	48 01 c6             	add    %rax,%rsi
  400b3e:	48 d1 fe             	sar    %rsi
  400b41:	74 15                	je     400b58 <register_tm_clones+0x38>
  400b43:	b8 00 00 00 00       	mov    $0x0,%eax
  400b48:	48 85 c0             	test   %rax,%rax
  400b4b:	74 0b                	je     400b58 <register_tm_clones+0x38>
  400b4d:	5d                   	pop    %rbp
  400b4e:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400b53:	ff e0                	jmpq   *%rax
  400b55:	0f 1f 00             	nopl   (%rax)
  400b58:	5d                   	pop    %rbp
  400b59:	c3                   	retq   
  400b5a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400b60 <__do_global_dtors_aux>:
  400b60:	80 3d 49 16 20 00 00 	cmpb   $0x0,0x201649(%rip)        # 6021b0 <completed.7585>
  400b67:	75 11                	jne    400b7a <__do_global_dtors_aux+0x1a>
  400b69:	55                   	push   %rbp
  400b6a:	48 89 e5             	mov    %rsp,%rbp
  400b6d:	e8 6e ff ff ff       	callq  400ae0 <deregister_tm_clones>
  400b72:	5d                   	pop    %rbp
  400b73:	c6 05 36 16 20 00 01 	movb   $0x1,0x201636(%rip)        # 6021b0 <completed.7585>
  400b7a:	f3 c3                	repz retq 
  400b7c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400b80 <frame_dummy>:
  400b80:	bf f0 1d 60 00       	mov    $0x601df0,%edi
  400b85:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400b89:	75 05                	jne    400b90 <frame_dummy+0x10>
  400b8b:	eb 93                	jmp    400b20 <register_tm_clones>
  400b8d:	0f 1f 00             	nopl   (%rax)
  400b90:	b8 00 00 00 00       	mov    $0x0,%eax
  400b95:	48 85 c0             	test   %rax,%rax
  400b98:	74 f1                	je     400b8b <frame_dummy+0xb>
  400b9a:	55                   	push   %rbp
  400b9b:	48 89 e5             	mov    %rsp,%rbp
  400b9e:	ff d0                	callq  *%rax
  400ba0:	5d                   	pop    %rbp
  400ba1:	e9 7a ff ff ff       	jmpq   400b20 <register_tm_clones>

0000000000400ba6 <_ZL15__get_cpuid_maxjPj>:
  400ba6:	55                   	push   %rbp
  400ba7:	48 89 e5             	mov    %rsp,%rbp
  400baa:	53                   	push   %rbx
  400bab:	89 7d e4             	mov    %edi,-0x1c(%rbp)
  400bae:	48 89 75 d8          	mov    %rsi,-0x28(%rbp)
  400bb2:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  400bb5:	0f a2                	cpuid  
  400bb7:	89 de                	mov    %ebx,%esi
  400bb9:	89 45 e8             	mov    %eax,-0x18(%rbp)
  400bbc:	89 75 ec             	mov    %esi,-0x14(%rbp)
  400bbf:	89 4d f0             	mov    %ecx,-0x10(%rbp)
  400bc2:	89 55 f4             	mov    %edx,-0xc(%rbp)
  400bc5:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
  400bca:	74 09                	je     400bd5 <_ZL15__get_cpuid_maxjPj+0x2f>
  400bcc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400bd0:	8b 55 ec             	mov    -0x14(%rbp),%edx
  400bd3:	89 10                	mov    %edx,(%rax)
  400bd5:	8b 45 e8             	mov    -0x18(%rbp),%eax
  400bd8:	5b                   	pop    %rbx
  400bd9:	5d                   	pop    %rbp
  400bda:	c3                   	retq   

0000000000400bdb <_Z17check_rtm_supportv>:
  400bdb:	55                   	push   %rbp
  400bdc:	48 89 e5             	mov    %rsp,%rbp
  400bdf:	53                   	push   %rbx
  400be0:	48 83 ec 10          	sub    $0x10,%rsp
  400be4:	be 00 00 00 00       	mov    $0x0,%esi
  400be9:	bf 00 00 00 00       	mov    $0x0,%edi
  400bee:	e8 b3 ff ff ff       	callq  400ba6 <_ZL15__get_cpuid_maxjPj>
  400bf3:	83 f8 06             	cmp    $0x6,%eax
  400bf6:	0f 97 c0             	seta   %al
  400bf9:	84 c0                	test   %al,%al
  400bfb:	74 2f                	je     400c2c <_Z17check_rtm_supportv+0x51>
  400bfd:	b8 07 00 00 00       	mov    $0x7,%eax
  400c02:	ba 00 00 00 00       	mov    $0x0,%edx
  400c07:	89 d1                	mov    %edx,%ecx
  400c09:	0f a2                	cpuid  
  400c0b:	89 de                	mov    %ebx,%esi
  400c0d:	89 45 e8             	mov    %eax,-0x18(%rbp)
  400c10:	89 75 ec             	mov    %esi,-0x14(%rbp)
  400c13:	89 4d f0             	mov    %ecx,-0x10(%rbp)
  400c16:	89 55 f4             	mov    %edx,-0xc(%rbp)
  400c19:	8b 45 ec             	mov    -0x14(%rbp),%eax
  400c1c:	25 00 08 00 00       	and    $0x800,%eax
  400c21:	85 c0                	test   %eax,%eax
  400c23:	74 07                	je     400c2c <_Z17check_rtm_supportv+0x51>
  400c25:	b8 01 00 00 00       	mov    $0x1,%eax
  400c2a:	eb 05                	jmp    400c31 <_Z17check_rtm_supportv+0x56>
  400c2c:	b8 00 00 00 00       	mov    $0x0,%eax
  400c31:	48 83 c4 10          	add    $0x10,%rsp
  400c35:	5b                   	pop    %rbx
  400c36:	5d                   	pop    %rbp
  400c37:	c3                   	retq   

0000000000400c38 <main>:
  400c38:	55                   	push   %rbp
  400c39:	48 89 e5             	mov    %rsp,%rbp
  400c3c:	53                   	push   %rbx
  400c3d:	48 83 ec 18          	sub    $0x18,%rsp
  400c41:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  400c48:	00 00 
  400c4a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  400c4e:	31 c0                	xor    %eax,%eax
  400c50:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
  400c57:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  400c5a:	89 45 e0             	mov    %eax,-0x20(%rbp)
  400c5d:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  400c61:	b9 00 00 00 00       	mov    $0x0,%ecx
  400c66:	ba 02 00 00 00       	mov    $0x2,%edx
  400c6b:	48 89 c6             	mov    %rax,%rsi
  400c6e:	bf 25 0e 40 00       	mov    $0x400e25,%edi
  400c73:	e8 a8 fd ff ff       	callq  400a20 <GOMP_parallel@plt>
  400c78:	8b 45 e0             	mov    -0x20(%rbp),%eax
  400c7b:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  400c7e:	be 14 10 40 00       	mov    $0x401014,%esi
  400c83:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400c88:	e8 53 fd ff ff       	callq  4009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400c8d:	48 89 c2             	mov    %rax,%rdx
  400c90:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  400c93:	89 c6                	mov    %eax,%esi
  400c95:	48 89 d7             	mov    %rdx,%rdi
  400c98:	e8 c3 fd ff ff       	callq  400a60 <_ZNSolsEi@plt>
  400c9d:	be b0 09 40 00       	mov    $0x4009b0,%esi
  400ca2:	48 89 c7             	mov    %rax,%rdi
  400ca5:	e8 46 fd ff ff       	callq  4009f0 <_ZNSolsEPFRSoS_E@plt>
  400caa:	8b 1d 24 15 20 00    	mov    0x201524(%rip),%ebx        # 6021d4 <htm_count>
  400cb0:	be 1b 10 40 00       	mov    $0x40101b,%esi
  400cb5:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400cba:	e8 21 fd ff ff       	callq  4009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400cbf:	89 de                	mov    %ebx,%esi
  400cc1:	48 89 c7             	mov    %rax,%rdi
  400cc4:	e8 97 fd ff ff       	callq  400a60 <_ZNSolsEi@plt>
  400cc9:	be b0 09 40 00       	mov    $0x4009b0,%esi
  400cce:	48 89 c7             	mov    %rax,%rdi
  400cd1:	e8 1a fd ff ff       	callq  4009f0 <_ZNSolsEPFRSoS_E@plt>
  400cd6:	8b 1d f4 14 20 00    	mov    0x2014f4(%rip),%ebx        # 6021d0 <gl_count>
  400cdc:	be 26 10 40 00       	mov    $0x401026,%esi
  400ce1:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400ce6:	e8 f5 fc ff ff       	callq  4009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400ceb:	89 de                	mov    %ebx,%esi
  400ced:	48 89 c7             	mov    %rax,%rdi
  400cf0:	e8 6b fd ff ff       	callq  400a60 <_ZNSolsEi@plt>
  400cf5:	be b0 09 40 00       	mov    $0x4009b0,%esi
  400cfa:	48 89 c7             	mov    %rax,%rdi
  400cfd:	e8 ee fc ff ff       	callq  4009f0 <_ZNSolsEPFRSoS_E@plt>
  400d02:	8b 1d b8 14 20 00    	mov    0x2014b8(%rip),%ebx        # 6021c0 <capacity_abort>
  400d08:	be 32 10 40 00       	mov    $0x401032,%esi
  400d0d:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400d12:	e8 c9 fc ff ff       	callq  4009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400d17:	89 de                	mov    %ebx,%esi
  400d19:	48 89 c7             	mov    %rax,%rdi
  400d1c:	e8 3f fd ff ff       	callq  400a60 <_ZNSolsEi@plt>
  400d21:	be b0 09 40 00       	mov    $0x4009b0,%esi
  400d26:	48 89 c7             	mov    %rax,%rdi
  400d29:	e8 c2 fc ff ff       	callq  4009f0 <_ZNSolsEPFRSoS_E@plt>
  400d2e:	8b 1d 90 14 20 00    	mov    0x201490(%rip),%ebx        # 6021c4 <conflict_abort>
  400d34:	be 43 10 40 00       	mov    $0x401043,%esi
  400d39:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400d3e:	e8 9d fc ff ff       	callq  4009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400d43:	89 de                	mov    %ebx,%esi
  400d45:	48 89 c7             	mov    %rax,%rdi
  400d48:	e8 13 fd ff ff       	callq  400a60 <_ZNSolsEi@plt>
  400d4d:	be b0 09 40 00       	mov    $0x4009b0,%esi
  400d52:	48 89 c7             	mov    %rax,%rdi
  400d55:	e8 96 fc ff ff       	callq  4009f0 <_ZNSolsEPFRSoS_E@plt>
  400d5a:	8b 1d 68 14 20 00    	mov    0x201468(%rip),%ebx        # 6021c8 <other_abort>
  400d60:	be 54 10 40 00       	mov    $0x401054,%esi
  400d65:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400d6a:	e8 71 fc ff ff       	callq  4009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400d6f:	89 de                	mov    %ebx,%esi
  400d71:	48 89 c7             	mov    %rax,%rdi
  400d74:	e8 e7 fc ff ff       	callq  400a60 <_ZNSolsEi@plt>
  400d79:	be b0 09 40 00       	mov    $0x4009b0,%esi
  400d7e:	48 89 c7             	mov    %rax,%rdi
  400d81:	e8 6a fc ff ff       	callq  4009f0 <_ZNSolsEPFRSoS_E@plt>
  400d86:	8b 1d 40 14 20 00    	mov    0x201440(%rip),%ebx        # 6021cc <gl_abort>
  400d8c:	be 62 10 40 00       	mov    $0x401062,%esi
  400d91:	bf a0 20 60 00       	mov    $0x6020a0,%edi
  400d96:	e8 45 fc ff ff       	callq  4009e0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400d9b:	89 de                	mov    %ebx,%esi
  400d9d:	48 89 c7             	mov    %rax,%rdi
  400da0:	e8 bb fc ff ff       	callq  400a60 <_ZNSolsEi@plt>
  400da5:	be b0 09 40 00       	mov    $0x4009b0,%esi
  400daa:	48 89 c7             	mov    %rax,%rdi
  400dad:	e8 3e fc ff ff       	callq  4009f0 <_ZNSolsEPFRSoS_E@plt>
  400db2:	b8 00 00 00 00       	mov    $0x0,%eax
  400db7:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  400dbb:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  400dc2:	00 00 
  400dc4:	74 05                	je     400dcb <main+0x193>
  400dc6:	e8 35 fc ff ff       	callq  400a00 <__stack_chk_fail@plt>
  400dcb:	48 83 c4 18          	add    $0x18,%rsp
  400dcf:	5b                   	pop    %rbx
  400dd0:	5d                   	pop    %rbp
  400dd1:	c3                   	retq   

0000000000400dd2 <_Z41__static_initialization_and_destruction_0ii>:
  400dd2:	55                   	push   %rbp
  400dd3:	48 89 e5             	mov    %rsp,%rbp
  400dd6:	48 83 ec 10          	sub    $0x10,%rsp
  400dda:	89 7d fc             	mov    %edi,-0x4(%rbp)
  400ddd:	89 75 f8             	mov    %esi,-0x8(%rbp)
  400de0:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
  400de4:	75 27                	jne    400e0d <_Z41__static_initialization_and_destruction_0ii+0x3b>
  400de6:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
  400ded:	75 1e                	jne    400e0d <_Z41__static_initialization_and_destruction_0ii+0x3b>
  400def:	bf 08 22 60 00       	mov    $0x602208,%edi
  400df4:	e8 37 fc ff ff       	callq  400a30 <_ZNSt8ios_base4InitC1Ev@plt>
  400df9:	ba 98 20 60 00       	mov    $0x602098,%edx
  400dfe:	be 08 22 60 00       	mov    $0x602208,%esi
  400e03:	bf 90 0a 40 00       	mov    $0x400a90,%edi
  400e08:	e8 c3 fb ff ff       	callq  4009d0 <__cxa_atexit@plt>
  400e0d:	90                   	nop
  400e0e:	c9                   	leaveq 
  400e0f:	c3                   	retq   

0000000000400e10 <_GLOBAL__sub_I_capacity_abort>:
  400e10:	55                   	push   %rbp
  400e11:	48 89 e5             	mov    %rsp,%rbp
  400e14:	be ff ff 00 00       	mov    $0xffff,%esi
  400e19:	bf 01 00 00 00       	mov    $0x1,%edi
  400e1e:	e8 af ff ff ff       	callq  400dd2 <_Z41__static_initialization_and_destruction_0ii>
  400e23:	5d                   	pop    %rbp
  400e24:	c3                   	retq   

0000000000400e25 <main._omp_fn.0>:
  400e25:	55                   	push   %rbp
  400e26:	48 89 e5             	mov    %rsp,%rbp
  400e29:	53                   	push   %rbx
  400e2a:	48 83 ec 28          	sub    $0x28,%rsp
  400e2e:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  400e32:	e8 49 fc ff ff       	callq  400a80 <omp_get_num_threads@plt>
  400e37:	89 c3                	mov    %eax,%ebx
  400e39:	e8 02 fc ff ff       	callq  400a40 <omp_get_thread_num@plt>
  400e3e:	89 c6                	mov    %eax,%esi
  400e40:	b8 14 00 00 00       	mov    $0x14,%eax
  400e45:	99                   	cltd   
  400e46:	f7 fb                	idiv   %ebx
  400e48:	89 c1                	mov    %eax,%ecx
  400e4a:	b8 14 00 00 00       	mov    $0x14,%eax
  400e4f:	99                   	cltd   
  400e50:	f7 fb                	idiv   %ebx
  400e52:	89 d0                	mov    %edx,%eax
  400e54:	39 c6                	cmp    %eax,%esi
  400e56:	0f 8c 1b 01 00 00    	jl     400f77 <main._omp_fn.0+0x152>
  400e5c:	0f af f1             	imul   %ecx,%esi
  400e5f:	89 f2                	mov    %esi,%edx
  400e61:	01 d0                	add    %edx,%eax
  400e63:	8d 1c 08             	lea    (%rax,%rcx,1),%ebx
  400e66:	39 d8                	cmp    %ebx,%eax
  400e68:	0f 8d 16 01 00 00    	jge    400f84 <main._omp_fn.0+0x15f>
  400e6e:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  400e71:	c7 45 e8 05 00 00 00 	movl   $0x5,-0x18(%rbp)
  400e78:	b8 e0 21 60 00       	mov    $0x6021e0,%eax
  400e7d:	8b 00                	mov    (%rax),%eax
  400e7f:	85 c0                	test   %eax,%eax
  400e81:	0f 95 c0             	setne  %al
  400e84:	84 c0                	test   %al,%al
  400e86:	0f 85 e4 00 00 00    	jne    400f70 <main._omp_fn.0+0x14b>
  400e8c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  400e91:	c7 f8 00 00 00 00    	xbeginq 400e97 <main._omp_fn.0+0x72>
  400e97:	89 45 ec             	mov    %eax,-0x14(%rbp)
  400e9a:	83 7d ec ff          	cmpl   $0xffffffff,-0x14(%rbp)
  400e9e:	0f 84 b7 00 00 00    	je     400f5b <main._omp_fn.0+0x136>
  400ea4:	8b 45 ec             	mov    -0x14(%rbp),%eax
  400ea7:	83 e0 08             	and    $0x8,%eax
  400eaa:	85 c0                	test   %eax,%eax
  400eac:	75 46                	jne    400ef4 <main._omp_fn.0+0xcf>
  400eae:	eb 18                	jmp    400ec8 <main._omp_fn.0+0xa3>
  400eb0:	83 6d e8 01          	subl   $0x1,-0x18(%rbp)
  400eb4:	83 7d e8 00          	cmpl   $0x0,-0x18(%rbp)
  400eb8:	7e 02                	jle    400ebc <main._omp_fn.0+0x97>
  400eba:	eb bc                	jmp    400e78 <main._omp_fn.0+0x53>
  400ebc:	bf e0 21 60 00       	mov    $0x6021e0,%edi
  400ec1:	e8 4a fb ff ff       	callq  400a10 <pthread_mutex_lock@plt>
  400ec6:	eb 3e                	jmp    400f06 <main._omp_fn.0+0xe1>
  400ec8:	8b 45 ec             	mov    -0x14(%rbp),%eax
  400ecb:	83 e0 04             	and    $0x4,%eax
  400ece:	85 c0                	test   %eax,%eax
  400ed0:	75 11                	jne    400ee3 <main._omp_fn.0+0xbe>
  400ed2:	8b 05 f0 12 20 00    	mov    0x2012f0(%rip),%eax        # 6021c8 <other_abort>
  400ed8:	83 c0 01             	add    $0x1,%eax
  400edb:	89 05 e7 12 20 00    	mov    %eax,0x2012e7(%rip)        # 6021c8 <other_abort>
  400ee1:	eb cd                	jmp    400eb0 <main._omp_fn.0+0x8b>
  400ee3:	8b 05 db 12 20 00    	mov    0x2012db(%rip),%eax        # 6021c4 <conflict_abort>
  400ee9:	83 c0 01             	add    $0x1,%eax
  400eec:	89 05 d2 12 20 00    	mov    %eax,0x2012d2(%rip)        # 6021c4 <conflict_abort>
  400ef2:	eb bc                	jmp    400eb0 <main._omp_fn.0+0x8b>
  400ef4:	8b 05 c6 12 20 00    	mov    0x2012c6(%rip),%eax        # 6021c0 <capacity_abort>
  400efa:	83 c0 01             	add    $0x1,%eax
  400efd:	89 05 bd 12 20 00    	mov    %eax,0x2012bd(%rip)        # 6021c0 <capacity_abort>
  400f03:	eb ab                	jmp    400eb0 <main._omp_fn.0+0x8b>
  400f05:	90                   	nop
  400f06:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400f0a:	8b 00                	mov    (%rax),%eax
  400f0c:	8d 50 01             	lea    0x1(%rax),%edx
  400f0f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400f13:	89 10                	mov    %edx,(%rax)
  400f15:	83 7d e8 00          	cmpl   $0x0,-0x18(%rbp)
  400f19:	7f 2c                	jg     400f47 <main._omp_fn.0+0x122>
  400f1b:	eb 0f                	jmp    400f2c <main._omp_fn.0+0x107>
  400f1d:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
  400f21:	39 5d e4             	cmp    %ebx,-0x1c(%rbp)
  400f24:	0f 8c 47 ff ff ff    	jl     400e71 <main._omp_fn.0+0x4c>
  400f2a:	eb 58                	jmp    400f84 <main._omp_fn.0+0x15f>
  400f2c:	bf e0 21 60 00       	mov    $0x6021e0,%edi
  400f31:	e8 8a fa ff ff       	callq  4009c0 <pthread_mutex_unlock@plt>
  400f36:	8b 05 94 12 20 00    	mov    0x201294(%rip),%eax        # 6021d0 <gl_count>
  400f3c:	83 c0 01             	add    $0x1,%eax
  400f3f:	89 05 8b 12 20 00    	mov    %eax,0x20128b(%rip)        # 6021d0 <gl_count>
  400f45:	eb d6                	jmp    400f1d <main._omp_fn.0+0xf8>
  400f47:	0f 01 d5             	xend   
  400f4a:	8b 05 84 12 20 00    	mov    0x201284(%rip),%eax        # 6021d4 <htm_count>
  400f50:	83 c0 01             	add    $0x1,%eax
  400f53:	89 05 7b 12 20 00    	mov    %eax,0x20127b(%rip)        # 6021d4 <htm_count>
  400f59:	eb c2                	jmp    400f1d <main._omp_fn.0+0xf8>
  400f5b:	b8 e0 21 60 00       	mov    $0x6021e0,%eax
  400f60:	8b 00                	mov    (%rax),%eax
  400f62:	85 c0                	test   %eax,%eax
  400f64:	0f 95 c0             	setne  %al
  400f67:	84 c0                	test   %al,%al
  400f69:	74 9a                	je     400f05 <main._omp_fn.0+0xe0>
  400f6b:	c6 f8 1e             	xabort $0x1e
  400f6e:	eb 95                	jmp    400f05 <main._omp_fn.0+0xe0>
  400f70:	f3 90                	pause  
  400f72:	e9 01 ff ff ff       	jmpq   400e78 <main._omp_fn.0+0x53>
  400f77:	b8 00 00 00 00       	mov    $0x0,%eax
  400f7c:	83 c1 01             	add    $0x1,%ecx
  400f7f:	e9 d8 fe ff ff       	jmpq   400e5c <main._omp_fn.0+0x37>
  400f84:	48 83 c4 28          	add    $0x28,%rsp
  400f88:	5b                   	pop    %rbx
  400f89:	5d                   	pop    %rbp
  400f8a:	c3                   	retq   
  400f8b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000400f90 <__libc_csu_init>:
  400f90:	41 57                	push   %r15
  400f92:	41 56                	push   %r14
  400f94:	41 89 ff             	mov    %edi,%r15d
  400f97:	41 55                	push   %r13
  400f99:	41 54                	push   %r12
  400f9b:	4c 8d 25 36 0e 20 00 	lea    0x200e36(%rip),%r12        # 601dd8 <__frame_dummy_init_array_entry>
  400fa2:	55                   	push   %rbp
  400fa3:	48 8d 2d 3e 0e 20 00 	lea    0x200e3e(%rip),%rbp        # 601de8 <__init_array_end>
  400faa:	53                   	push   %rbx
  400fab:	49 89 f6             	mov    %rsi,%r14
  400fae:	49 89 d5             	mov    %rdx,%r13
  400fb1:	4c 29 e5             	sub    %r12,%rbp
  400fb4:	48 83 ec 08          	sub    $0x8,%rsp
  400fb8:	48 c1 fd 03          	sar    $0x3,%rbp
  400fbc:	e8 b7 f9 ff ff       	callq  400978 <_init>
  400fc1:	48 85 ed             	test   %rbp,%rbp
  400fc4:	74 20                	je     400fe6 <__libc_csu_init+0x56>
  400fc6:	31 db                	xor    %ebx,%ebx
  400fc8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  400fcf:	00 
  400fd0:	4c 89 ea             	mov    %r13,%rdx
  400fd3:	4c 89 f6             	mov    %r14,%rsi
  400fd6:	44 89 ff             	mov    %r15d,%edi
  400fd9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  400fdd:	48 83 c3 01          	add    $0x1,%rbx
  400fe1:	48 39 eb             	cmp    %rbp,%rbx
  400fe4:	75 ea                	jne    400fd0 <__libc_csu_init+0x40>
  400fe6:	48 83 c4 08          	add    $0x8,%rsp
  400fea:	5b                   	pop    %rbx
  400feb:	5d                   	pop    %rbp
  400fec:	41 5c                	pop    %r12
  400fee:	41 5d                	pop    %r13
  400ff0:	41 5e                	pop    %r14
  400ff2:	41 5f                	pop    %r15
  400ff4:	c3                   	retq   
  400ff5:	90                   	nop
  400ff6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400ffd:	00 00 00 

0000000000401000 <__libc_csu_fini>:
  401000:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000401004 <_fini>:
  401004:	48 83 ec 08          	sub    $0x8,%rsp
  401008:	48 83 c4 08          	add    $0x8,%rsp
  40100c:	c3                   	retq   
