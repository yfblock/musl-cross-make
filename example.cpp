#include <stdio.h>
#include <unistd.h>

int main() {
  int pid = getpid();
  printf("get pid: %d\n", pid);
  printf("Hello World!\n");
  return 0;
}

extern "C" long _vsyscall(long n, long a, long b, long c, long d, long e, long f) {
  register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0") = a;
	register long x1 __asm__("x1") = b;
	register long x2 __asm__("x2") = c;
	register long x3 __asm__("x3") = d;
	register long x4 __asm__("x4") = e;
	register long x5 __asm__("x5") = f;
  __asm__ __volatile__("svc 0": "=r"(x0): "r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5):"memory", "cc");
  
  if(x8 != 64 && x8 != 66) {
    // setbuf(stdout, NULL);
    printf("Hello syscall: %d\n", x8);
    // fflush(stdout);
  }
  // if(x8 != 172) {
  //   _vsyscall(172, 0, 0, 0, 0, 0, 0);
  // }
  return x0;
}

