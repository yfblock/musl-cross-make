#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

/**
 * TODO: This is a simple solution for the current case.
 *       Improvement of this is read reduce context operations.
 */

// #define __asm_syscall(...) do { \
// 	__asm__ __volatile__ ( "svc 0" \
// 	: "=r"(x0) : __VA_ARGS__ : "memory", "cc"); \
// 	return x0; \
// 	} while (0)
// #define __asm_syscall(...) do { \
// 	register void *saved_lr __asm__("x30"); \
// 	__asm__ __volatile__ (\
// 		"bl _vsyscall" \
// 	: "=r"(x0) : __VA_ARGS__ ,"r"(saved_lr) : "memory", "cc"); \
// 	return x0; \
// 	} while (0)

extern long _vsyscall(long n, long a, long b, long c, long d, long e, long f);

#define __asm_syscall(...) do { \
	return _vsyscall(); \
	} while (0)

static inline long __syscall0(long n)
{
	// register long x8 __asm__("x8") = n;
	// register long x0 __asm__("x0");
	// __asm_syscall("r"(x8));
	return _vsyscall(n, 0, 0, 0, 0, 0, 0);
}

static inline long __syscall1(long n, long a)
{
	// register long x8 __asm__("x8") = n;
	// register long x0 __asm__("x0") = a;
	// __asm_syscall("r"(x8), "0"(x0));
	return _vsyscall(n, a, 0, 0, 0, 0, 0);
}

static inline long __syscall2(long n, long a, long b)
{
	// register long x8 __asm__("x8") = n;
	// register long x0 __asm__("x0") = a;
	// register long x1 __asm__("x1") = b;
	// __asm_syscall("r"(x8), "0"(x0), "r"(x1));
	return _vsyscall(n, a, b, 0, 0, 0, 0);
}

static inline long __syscall3(long n, long a, long b, long c)
{
	// register long x8 __asm__("x8") = n;
	// register long x0 __asm__("x0") = a;
	// register long x1 __asm__("x1") = b;
	// register long x2 __asm__("x2") = c;
	// __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2));
	return _vsyscall(n, a, b, c, 0, 0, 0);
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	// register long x8 __asm__("x8") = n;
	// register long x0 __asm__("x0") = a;
	// register long x1 __asm__("x1") = b;
	// register long x2 __asm__("x2") = c;
	// register long x3 __asm__("x3") = d;
	// __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3));
	return _vsyscall(n, a, b, c, d, 0, 0);
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	// register long x8 __asm__("x8") = n;
	// register long x0 __asm__("x0") = a;
	// register long x1 __asm__("x1") = b;
	// register long x2 __asm__("x2") = c;
	// register long x3 __asm__("x3") = d;
	// register long x4 __asm__("x4") = e;
	// __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4));
	return _vsyscall(n, a, b, c, d, e, 0);
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	// register long x8 __asm__("x8") = n;
	// register long x0 __asm__("x0") = a;
	// register long x1 __asm__("x1") = b;
	// register long x2 __asm__("x2") = c;
	// register long x3 __asm__("x3") = d;
	// register long x4 __asm__("x4") = e;
	// register long x5 __asm__("x5") = f;
	return _vsyscall(n, a, b, c, d, e, f);
	// __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5));
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__kernel_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6.39"

#define IPC_64 0
