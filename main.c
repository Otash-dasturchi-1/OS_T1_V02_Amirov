#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10000

// 1 va 2-masalalar uchun funksiya: Pointer arifmetikasi yordamida Eratosfen g'alviri
void eratosfen_galviri_pointer(int n) {
    bool is_prime[MAX_N + 1];
    bool *p = is_prime;

    // Massivni true bilan to'ldirish (faqat pointer arifmetikasi *(p + i) ishlatiladi)
    for (int i = 0; i <= n; i++) {
        *(p + i) = true;
    }

    *(p + 0) = false;
    *(p + 1) = false;

    for (int p_num = 2; p_num * p_num <= n; p_num++) {
        if (*(p + p_num) == true) {
            for (int i = p_num * p_num; i <= n; i += p_num) {
                *(p + i) = false;
            }
        }
    }

    int count = 0;
    printf("\n--- %d gacha bo'lgan tub sonlar ---\n", n);
    for (int i = 2; i <= n; i++) {
        if (*(p + i) == true) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nJami tub sonlar soni: %d ta\n", count);

    // Kamida bitta o'zgaruvchining xotira manzilini %p bilan chiqarish
    printf("Pointer ko'rsatayotgan massivning boshlang'ich adresi (%%p): %p\n", (void*)p);
    printf("N o'zgaruvchisining xotiradagi adresi (%%p): %p\n", (void*)&n);
}

int main() {
    int n;
    printf("N qiymatini kiriting (2 <= N <= 10000): ");

    // Kiritilgan ma'lumotni tekshirish (son emasligi yoki diapozondan tashqariligi)
    if (scanf("%d", &n) != 1) {
        printf("Xato: Noto'g me'yoriy son kiritildi!\n");
        return 1;
    }

    if (n < 2 || n > MAX_N) {
        printf("Xato: N qiymati 2 va %d oralig'ida bo'lishi kerak!\n", MAX_N);
        return 1;
    }

    eratosfen_galviri_pointer(n);

    return 0;
}
