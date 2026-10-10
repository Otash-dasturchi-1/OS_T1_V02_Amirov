#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10000

// Eratosfen g'alviri - faqat pointer arifmetikasi yordamida
void eratosfen_galviri(int n) {
    bool is_prime[MAX_N + 1];
    bool *p = is_prime;

    // 1. Barcha elementlarni boshida true (tub) deb belgilaymiz
    for (int i = 0; i <= n; i++) {
        *(p + i) = true;
    }

    // 0 va 1 tub son emas
    *(p + 0) = false;
    *(p + 1) = false;

    // 2. Eratosfen g'alviri: karrali sonlarni o'chirib chiqish
    for (int p_num = 2; p_num <= n; p_num++) {
        // Agar p_num hali ham tub deb belgilangan bo'lsa
        if (*(p + p_num) == true) {
            // Uning barcha karralarini false (tub emas) qilamiz
            for (int i = p_num * 2; i <= n; i += p_num) {
                *(p + i) = false;
            }
        }
    }

    // 3. Natijalarni chiqarish
    int count = 0;
    printf("\n--- %d gacha bo'lgan tub sonlar (Eratosfen g'alviri) ---\n", n);
    for (int i = 2; i <= n; i++) {
        if (*(p + i) == true) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nJami tub sonlar soni: %d ta\n", count);
    
    // Talab qilingan xotira manzillari
    printf("Pointer ko'rsatayotgan massiv adresi (%%p): %p\n", (void*)p);
    printf("N o'zgaruvchisining adresi (%%p): %p\n", (void*)&n);
}

int main() {
    int n;
    printf("N qiymatini kiriting (2 <= N <= 10000): ");
    
    if (scanf("%d", &n) != 1) {
        printf("Xato: Noto'g'ri qiymat kiritildi!\n");
        return 1;
    }

    if (n < 2 || n > MAX_N) {
        printf("Xato: N qiymati 2 va %d oralig'ida bo'lishi kerak!\n", MAX_N);
        return 1;
    }

    eratosfen_galviri(n);

    return 0;
}
