
quicksort.o：     文件格式 elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 72 2f 00 00    	push   0x2f72(%rip)        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 73 2f 00 00 	bnd jmp *0x2f73(%rip)        # 3fa0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	push   $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    107f:	90                   	nop

Disassembly of section .plt.got:

0000000000001080 <__cxa_finalize@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 45 2f 00 00 	bnd jmp *0x2f45(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001090 <__cxa_atexit@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 0d 2f 00 00 	bnd jmp *0x2f0d(%rip)        # 3fa8 <__cxa_atexit@GLIBC_2.2.5>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <__stack_chk_fail@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 05 2f 00 00 	bnd jmp *0x2f05(%rip)        # 3fb0 <__stack_chk_fail@GLIBC_2.4>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 fd 2e 00 00 	bnd jmp *0x2efd(%rip)        # 3fb8 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@GLIBCXX_3.4>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010c0 <_ZNSt8ios_base4InitC1Ev@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 f5 2e 00 00 	bnd jmp *0x2ef5(%rip)        # 3fc0 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010d0 <_ZNSolsEi@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 ed 2e 00 00 	bnd jmp *0x2eed(%rip)        # 3fc8 <_ZNSolsEi@GLIBCXX_3.4>
    10db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010e0 <_start>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	31 ed                	xor    %ebp,%ebp
    10e6:	49 89 d1             	mov    %rdx,%r9
    10e9:	5e                   	pop    %rsi
    10ea:	48 89 e2             	mov    %rsp,%rdx
    10ed:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10f1:	50                   	push   %rax
    10f2:	54                   	push   %rsp
    10f3:	45 31 c0             	xor    %r8d,%r8d
    10f6:	31 c9                	xor    %ecx,%ecx
    10f8:	48 8d 3d 5f 02 00 00 	lea    0x25f(%rip),%rdi        # 135e <main>
    10ff:	ff 15 d3 2e 00 00    	call   *0x2ed3(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1105:	f4                   	hlt    
    1106:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    110d:	00 00 00 

0000000000001110 <deregister_tm_clones>:
    1110:	48 8d 3d f9 2e 00 00 	lea    0x2ef9(%rip),%rdi        # 4010 <__TMC_END__>
    1117:	48 8d 05 f2 2e 00 00 	lea    0x2ef2(%rip),%rax        # 4010 <__TMC_END__>
    111e:	48 39 f8             	cmp    %rdi,%rax
    1121:	74 15                	je     1138 <deregister_tm_clones+0x28>
    1123:	48 8b 05 b6 2e 00 00 	mov    0x2eb6(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    112a:	48 85 c0             	test   %rax,%rax
    112d:	74 09                	je     1138 <deregister_tm_clones+0x28>
    112f:	ff e0                	jmp    *%rax
    1131:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1138:	c3                   	ret    
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <register_tm_clones>:
    1140:	48 8d 3d c9 2e 00 00 	lea    0x2ec9(%rip),%rdi        # 4010 <__TMC_END__>
    1147:	48 8d 35 c2 2e 00 00 	lea    0x2ec2(%rip),%rsi        # 4010 <__TMC_END__>
    114e:	48 29 fe             	sub    %rdi,%rsi
    1151:	48 89 f0             	mov    %rsi,%rax
    1154:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1158:	48 c1 f8 03          	sar    $0x3,%rax
    115c:	48 01 c6             	add    %rax,%rsi
    115f:	48 d1 fe             	sar    %rsi
    1162:	74 14                	je     1178 <register_tm_clones+0x38>
    1164:	48 8b 05 85 2e 00 00 	mov    0x2e85(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    116b:	48 85 c0             	test   %rax,%rax
    116e:	74 08                	je     1178 <register_tm_clones+0x38>
    1170:	ff e0                	jmp    *%rax
    1172:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1178:	c3                   	ret    
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <__do_global_dtors_aux>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	80 3d c5 2f 00 00 00 	cmpb   $0x0,0x2fc5(%rip)        # 4150 <completed.0>
    118b:	75 2b                	jne    11b8 <__do_global_dtors_aux+0x38>
    118d:	55                   	push   %rbp
    118e:	48 83 3d 3a 2e 00 00 	cmpq   $0x0,0x2e3a(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    1195:	00 
    1196:	48 89 e5             	mov    %rsp,%rbp
    1199:	74 0c                	je     11a7 <__do_global_dtors_aux+0x27>
    119b:	48 8b 3d 66 2e 00 00 	mov    0x2e66(%rip),%rdi        # 4008 <__dso_handle>
    11a2:	e8 d9 fe ff ff       	call   1080 <__cxa_finalize@plt>
    11a7:	e8 64 ff ff ff       	call   1110 <deregister_tm_clones>
    11ac:	c6 05 9d 2f 00 00 01 	movb   $0x1,0x2f9d(%rip)        # 4150 <completed.0>
    11b3:	5d                   	pop    %rbp
    11b4:	c3                   	ret    
    11b5:	0f 1f 00             	nopl   (%rax)
    11b8:	c3                   	ret    
    11b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011c0 <frame_dummy>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	e9 77 ff ff ff       	jmp    1140 <register_tm_clones>

00000000000011c9 <_Z4swapRiS_>:
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    11c9:	f3 0f 1e fa          	endbr64 
    11cd:	55                   	push   %rbp
    11ce:	48 89 e5             	mov    %rsp,%rbp
    11d1:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    11d5:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  int t = a;
    11d9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11dd:	8b 00                	mov    (%rax),%eax
    11df:	89 45 fc             	mov    %eax,-0x4(%rbp)
  a = b;
    11e2:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    11e6:	8b 10                	mov    (%rax),%edx
    11e8:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11ec:	89 10                	mov    %edx,(%rax)
  b = t;
    11ee:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    11f2:	8b 55 fc             	mov    -0x4(%rbp),%edx
    11f5:	89 10                	mov    %edx,(%rax)
}
    11f7:	90                   	nop
    11f8:	5d                   	pop    %rbp
    11f9:	c3                   	ret    

00000000000011fa <_Z5qsortPiii>:

void qsort(int q[], int low, int high) {
    11fa:	f3 0f 1e fa          	endbr64 
    11fe:	55                   	push   %rbp
    11ff:	48 89 e5             	mov    %rsp,%rbp
    1202:	48 83 ec 20          	sub    $0x20,%rsp
    1206:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    120a:	89 75 e4             	mov    %esi,-0x1c(%rbp)
    120d:	89 55 e0             	mov    %edx,-0x20(%rbp)
  if (low < high) {
    1210:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1213:	3b 45 e0             	cmp    -0x20(%rbp),%eax
    1216:	0f 8d 3f 01 00 00    	jge    135b <_Z5qsortPiii+0x161>
    int i = low, j = high, pivot = q[low];
    121c:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    121f:	89 45 f4             	mov    %eax,-0xc(%rbp)
    1222:	8b 45 e0             	mov    -0x20(%rbp),%eax
    1225:	89 45 f8             	mov    %eax,-0x8(%rbp)
    1228:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    122b:	48 98                	cltq   
    122d:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1234:	00 
    1235:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1239:	48 01 d0             	add    %rdx,%rax
    123c:	8b 00                	mov    (%rax),%eax
    123e:	89 45 fc             	mov    %eax,-0x4(%rbp)
    while (i < j) {
    1241:	e9 09 01 00 00       	jmp    134f <_Z5qsortPiii+0x155>
      while (i < j && q[j] >= pivot)
        j--;
    1246:	83 6d f8 01          	subl   $0x1,-0x8(%rbp)
      while (i < j && q[j] >= pivot)
    124a:	8b 45 f4             	mov    -0xc(%rbp),%eax
    124d:	3b 45 f8             	cmp    -0x8(%rbp),%eax
    1250:	7d 1b                	jge    126d <_Z5qsortPiii+0x73>
    1252:	8b 45 f8             	mov    -0x8(%rbp),%eax
    1255:	48 98                	cltq   
    1257:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    125e:	00 
    125f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1263:	48 01 d0             	add    %rdx,%rax
    1266:	8b 00                	mov    (%rax),%eax
    1268:	39 45 fc             	cmp    %eax,-0x4(%rbp)
    126b:	7e d9                	jle    1246 <_Z5qsortPiii+0x4c>
      if (i < j) {
    126d:	8b 45 f4             	mov    -0xc(%rbp),%eax
    1270:	3b 45 f8             	cmp    -0x8(%rbp),%eax
    1273:	7d 37                	jge    12ac <_Z5qsortPiii+0xb2>
        q[i] = q[j];
    1275:	8b 45 f8             	mov    -0x8(%rbp),%eax
    1278:	48 98                	cltq   
    127a:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1281:	00 
    1282:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1286:	48 01 d0             	add    %rdx,%rax
    1289:	8b 55 f4             	mov    -0xc(%rbp),%edx
    128c:	48 63 d2             	movslq %edx,%rdx
    128f:	48 8d 0c 95 00 00 00 	lea    0x0(,%rdx,4),%rcx
    1296:	00 
    1297:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    129b:	48 01 ca             	add    %rcx,%rdx
    129e:	8b 00                	mov    (%rax),%eax
    12a0:	89 02                	mov    %eax,(%rdx)
        i++;
    12a2:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
      }
      while (i < j && q[i] < pivot)
    12a6:	eb 04                	jmp    12ac <_Z5qsortPiii+0xb2>
        i++;
    12a8:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
      while (i < j && q[i] < pivot)
    12ac:	8b 45 f4             	mov    -0xc(%rbp),%eax
    12af:	3b 45 f8             	cmp    -0x8(%rbp),%eax
    12b2:	7d 1b                	jge    12cf <_Z5qsortPiii+0xd5>
    12b4:	8b 45 f4             	mov    -0xc(%rbp),%eax
    12b7:	48 98                	cltq   
    12b9:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    12c0:	00 
    12c1:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    12c5:	48 01 d0             	add    %rdx,%rax
    12c8:	8b 00                	mov    (%rax),%eax
    12ca:	39 45 fc             	cmp    %eax,-0x4(%rbp)
    12cd:	7f d9                	jg     12a8 <_Z5qsortPiii+0xae>
      if (i < j) {
    12cf:	8b 45 f4             	mov    -0xc(%rbp),%eax
    12d2:	3b 45 f8             	cmp    -0x8(%rbp),%eax
    12d5:	7d 31                	jge    1308 <_Z5qsortPiii+0x10e>
        q[j] = q[i];
    12d7:	8b 45 f4             	mov    -0xc(%rbp),%eax
    12da:	48 98                	cltq   
    12dc:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    12e3:	00 
    12e4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    12e8:	48 01 d0             	add    %rdx,%rax
    12eb:	8b 55 f8             	mov    -0x8(%rbp),%edx
    12ee:	48 63 d2             	movslq %edx,%rdx
    12f1:	48 8d 0c 95 00 00 00 	lea    0x0(,%rdx,4),%rcx
    12f8:	00 
    12f9:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    12fd:	48 01 ca             	add    %rcx,%rdx
    1300:	8b 00                	mov    (%rax),%eax
    1302:	89 02                	mov    %eax,(%rdx)
        j--;
    1304:	83 6d f8 01          	subl   $0x1,-0x8(%rbp)
      }
      q[i] = pivot;
    1308:	8b 45 f4             	mov    -0xc(%rbp),%eax
    130b:	48 98                	cltq   
    130d:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1314:	00 
    1315:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1319:	48 01 c2             	add    %rax,%rdx
    131c:	8b 45 fc             	mov    -0x4(%rbp),%eax
    131f:	89 02                	mov    %eax,(%rdx)
      qsort(q, low, i - 1);
    1321:	8b 45 f4             	mov    -0xc(%rbp),%eax
    1324:	8d 50 ff             	lea    -0x1(%rax),%edx
    1327:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    132a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    132e:	89 ce                	mov    %ecx,%esi
    1330:	48 89 c7             	mov    %rax,%rdi
    1333:	e8 c2 fe ff ff       	call   11fa <_Z5qsortPiii>
      qsort(q, j + 1, high);
    1338:	8b 45 f8             	mov    -0x8(%rbp),%eax
    133b:	8d 48 01             	lea    0x1(%rax),%ecx
    133e:	8b 55 e0             	mov    -0x20(%rbp),%edx
    1341:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1345:	89 ce                	mov    %ecx,%esi
    1347:	48 89 c7             	mov    %rax,%rdi
    134a:	e8 ab fe ff ff       	call   11fa <_Z5qsortPiii>
    while (i < j) {
    134f:	8b 45 f4             	mov    -0xc(%rbp),%eax
    1352:	3b 45 f8             	cmp    -0x8(%rbp),%eax
    1355:	0f 8c ef fe ff ff    	jl     124a <_Z5qsortPiii+0x50>
    }
  }
}
    135b:	90                   	nop
    135c:	c9                   	leave  
    135d:	c3                   	ret    

000000000000135e <main>:

int main() {
    135e:	f3 0f 1e fa          	endbr64 
    1362:	55                   	push   %rbp
    1363:	48 89 e5             	mov    %rsp,%rbp
    1366:	48 83 ec 40          	sub    $0x40,%rsp
    136a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1371:	00 00 
    1373:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1377:	31 c0                	xor    %eax,%eax
  int m[] = {23, 45, 12, 87, 67, -3, -99, 0, 23, 34};
    1379:	c7 45 d0 17 00 00 00 	movl   $0x17,-0x30(%rbp)
    1380:	c7 45 d4 2d 00 00 00 	movl   $0x2d,-0x2c(%rbp)
    1387:	c7 45 d8 0c 00 00 00 	movl   $0xc,-0x28(%rbp)
    138e:	c7 45 dc 57 00 00 00 	movl   $0x57,-0x24(%rbp)
    1395:	c7 45 e0 43 00 00 00 	movl   $0x43,-0x20(%rbp)
    139c:	c7 45 e4 fd ff ff ff 	movl   $0xfffffffd,-0x1c(%rbp)
    13a3:	c7 45 e8 9d ff ff ff 	movl   $0xffffff9d,-0x18(%rbp)
    13aa:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
    13b1:	c7 45 f0 17 00 00 00 	movl   $0x17,-0x10(%rbp)
    13b8:	c7 45 f4 22 00 00 00 	movl   $0x22,-0xc(%rbp)
  qsort(m, 0, 9);
    13bf:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
    13c3:	ba 09 00 00 00       	mov    $0x9,%edx
    13c8:	be 00 00 00 00       	mov    $0x0,%esi
    13cd:	48 89 c7             	mov    %rax,%rdi
    13d0:	e8 25 fe ff ff       	call   11fa <_Z5qsortPiii>
  for (int i = 0; i < 10; i++)
    13d5:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%rbp)
    13dc:	eb 2b                	jmp    1409 <main+0xab>
    cout << m[i] << ' ';
    13de:	8b 45 cc             	mov    -0x34(%rbp),%eax
    13e1:	48 98                	cltq   
    13e3:	8b 44 85 d0          	mov    -0x30(%rbp,%rax,4),%eax
    13e7:	89 c6                	mov    %eax,%esi
    13e9:	48 8d 05 50 2c 00 00 	lea    0x2c50(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    13f0:	48 89 c7             	mov    %rax,%rdi
    13f3:	e8 d8 fc ff ff       	call   10d0 <_ZNSolsEi@plt>
    13f8:	be 20 00 00 00       	mov    $0x20,%esi
    13fd:	48 89 c7             	mov    %rax,%rdi
    1400:	e8 ab fc ff ff       	call   10b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@plt>
  for (int i = 0; i < 10; i++)
    1405:	83 45 cc 01          	addl   $0x1,-0x34(%rbp)
    1409:	83 7d cc 09          	cmpl   $0x9,-0x34(%rbp)
    140d:	7e cf                	jle    13de <main+0x80>
  return 0;
    140f:	b8 00 00 00 00       	mov    $0x0,%eax
}
    1414:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    1418:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    141f:	00 00 
    1421:	74 05                	je     1428 <main+0xca>
    1423:	e8 78 fc ff ff       	call   10a0 <__stack_chk_fail@plt>
    1428:	c9                   	leave  
    1429:	c3                   	ret    

000000000000142a <_Z41__static_initialization_and_destruction_0ii>:
    142a:	f3 0f 1e fa          	endbr64 
    142e:	55                   	push   %rbp
    142f:	48 89 e5             	mov    %rsp,%rbp
    1432:	48 83 ec 10          	sub    $0x10,%rsp
    1436:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1439:	89 75 f8             	mov    %esi,-0x8(%rbp)
    143c:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    1440:	75 3b                	jne    147d <_Z41__static_initialization_and_destruction_0ii+0x53>
    1442:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    1449:	75 32                	jne    147d <_Z41__static_initialization_and_destruction_0ii+0x53>
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  ///@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
    144b:	48 8d 05 ff 2c 00 00 	lea    0x2cff(%rip),%rax        # 4151 <_ZStL8__ioinit>
    1452:	48 89 c7             	mov    %rax,%rdi
    1455:	e8 66 fc ff ff       	call   10c0 <_ZNSt8ios_base4InitC1Ev@plt>
    145a:	48 8d 05 a7 2b 00 00 	lea    0x2ba7(%rip),%rax        # 4008 <__dso_handle>
    1461:	48 89 c2             	mov    %rax,%rdx
    1464:	48 8d 05 e6 2c 00 00 	lea    0x2ce6(%rip),%rax        # 4151 <_ZStL8__ioinit>
    146b:	48 89 c6             	mov    %rax,%rsi
    146e:	48 8b 05 83 2b 00 00 	mov    0x2b83(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    1475:	48 89 c7             	mov    %rax,%rdi
    1478:	e8 13 fc ff ff       	call   1090 <__cxa_atexit@plt>
    147d:	90                   	nop
    147e:	c9                   	leave  
    147f:	c3                   	ret    

0000000000001480 <_GLOBAL__sub_I__Z4swapRiS_>:
    1480:	f3 0f 1e fa          	endbr64 
    1484:	55                   	push   %rbp
    1485:	48 89 e5             	mov    %rsp,%rbp
    1488:	be ff ff 00 00       	mov    $0xffff,%esi
    148d:	bf 01 00 00 00       	mov    $0x1,%edi
    1492:	e8 93 ff ff ff       	call   142a <_Z41__static_initialization_and_destruction_0ii>
    1497:	5d                   	pop    %rbp
    1498:	c3                   	ret    

Disassembly of section .fini:

000000000000149c <_fini>:
    149c:	f3 0f 1e fa          	endbr64 
    14a0:	48 83 ec 08          	sub    $0x8,%rsp
    14a4:	48 83 c4 08          	add    $0x8,%rsp
    14a8:	c3                   	ret    
