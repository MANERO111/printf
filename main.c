///* main.c - Comprehensive ft_printf tester */
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

int main()
{
	int len = 0;
	printf("%d\n",ft_printf(NULL));
	printf("%d\n",printf(NULL));


}

//static int g_fail = 0;
//static int g_total = 0;

///*
//** Compare the return values of ft_printf and printf.
//** Both are sent to /dev/null visually by redirecting via
//** fd 1 duplication is overkill — we just print side by side
//** and print return values, letting you eyeball the output.
//*/

//#define TEST(fmt, ...) do {                                             \
//    int r1, r2;                                                         \
//    g_total++;                                                          \
//    printf("\n--- Test %d ---\n", g_total);                             \
//    printf("fmt: \"%s\"\n", fmt);                                       \
//    printf("ft_printf: \"");                                            \
//    fflush(stdout);                                                     \
//    r1 = ft_printf(fmt, ##__VA_ARGS__);                                 \
//    printf("\"\n");                                                     \
//    printf("printf   : \"");                                            \
//    fflush(stdout);                                                     \
//    r2 = printf(fmt, ##__VA_ARGS__);                                    \
//    printf("\"\n");                                                     \
//    if (r1 == r2)                                                       \
//        printf("[OK]   return: %d\n", r1);                              \
//    else {                                                              \
//        printf("[FAIL] ft=%d vs libc=%d\n", r1, r2);                    \
//        g_fail++;                                                       \
//    }                                                                   \
//} while (0)

//int main(void)
//{
//    /* ---- chars ---- */
//    TEST("%c", 'A');
//    TEST("%c", '\0');
//    TEST("%c%c%c", 'x', 'y', 'z');
//    TEST("char is %c and %c", 'a', 'b');

//    /* ---- strings ---- */
//    TEST("%s", "hello world");
//    TEST("%s", "");
//    TEST("%s %s", "foo", "bar");
//    TEST("%s", (char *)NULL);
//    TEST("prefix:%s:suffix", "mid");

//    /* ---- pointers ---- */
//    {
//        int n = 42;
//        void *p = &n;
//        TEST("%p", p);
//        TEST("%p", (void *)NULL);
//        TEST("%p %p", p, (void *)0);
//    }

//    /* ---- decimal / integer ---- */
//    TEST("%d", 0);
//    TEST("%d", 42);
//    TEST("%d", -42);
//    TEST("%d", INT_MAX);
//    TEST("%d", INT_MIN);
//    TEST("%i", INT_MIN);
//    TEST("%i", -1);
//    TEST("%d %d %d", 1, -2, 3);
//    TEST("%d", (int)-2147483648LL);

//    /* ---- unsigned ---- */
//    TEST("%u", 0u);
//    TEST("%u", 42u);
//    TEST("%u", UINT_MAX);
//    TEST("%u", (unsigned int)-1);
//    TEST("%u %u", 0u, UINT_MAX);

//    /* ---- hex lowercase ---- */
//    TEST("%x", 0);
//    TEST("%x", 255);
//    TEST("%x", 0xdeadbeef);
//    TEST("%x", UINT_MAX);
//    TEST("%x %x", 0xabc, 0x123);

//    /* ---- hex uppercase ---- */
//    TEST("%X", 0);
//    TEST("%X", 255);
//    TEST("%X", 0xDEADBEEF);
//    TEST("%X", UINT_MAX);
//    TEST("%X %x", 0xABC, 0xabc);

//    /* ---- percent ---- */
//    TEST("%%");
//    TEST("100%%");
//    TEST("%%d is not a number");

//    /* ---- mixed ---- */
//    TEST("c=%c s=%s d=%d i=%i u=%u x=%x X=%X p=%p %%",
//         'Z', "str", -123, 456, 789u, 0x1a2b, 0x1A2B,
//         (void *)&g_total);

//    TEST("%c%s%d%u%x%X%p%%",
//         'q', "mix", -7, 7u, 0x7, 0x7, (void *)0);

//    /* ---- no conversion ---- */
//    TEST("just text");
//    TEST("");

//    /* ---- summary ---- */
//    printf("\n========== SUMMARY ==========\n");
//    printf("Tests: %d | Failures: %d\n", g_total, g_fail);
//    if (g_fail == 0)
//        printf("ALL TESTS PASSED ✅\n");
//    else
//        printf("SOME TESTS FAILED ❌\n");
//    return (g_fail != 0);
//}