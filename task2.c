#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256

// 2-topshiriq funksiyasi: natija yangi ajratilgan xotirada qaytariladi
char *birlashtir(const char *a, const char *b) {
    if (a == NULL || b == NULL) return NULL;

    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    // Yangi ajratiladigan xotira o'lchami (+1 '\0' belgisi uchun)
    char *result = (char *)malloc(len_a + len_b + 1);

    // NULL ga tekshirish
    if (result == NULL) {
        printf("Xatolik: Xotira ajratib bo'lmadi!\n");
        return NULL;
    }

    strcpy(result, a);
    strcat(result, b);

    return result;
}

int main() {
    char str1[MAX_STR];
    char str2[MAX_STR];

    printf("Birinchi satrni kiriting: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) return 1;
    str1[strcspn(str1, "\n")] = '\0'; // '\n' belgisini olib tashlash

    printf("Ikkinchi satrni kiriting: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) return 1;
    str2[strcspn(str2, "\n")] = '\0'; // '\n' belgisini olib tashlash

    // Funksiyani chaqirish
    char *birlashgan = birlashtir(str1, str2);

    if (birlashgan != NULL) {
        printf("\nNatija (birlashtirilgan satr): %s\n", birlashgan);
        printf("Dinamik xotira adresi (%%p): %p\n", (void*)birlashgan);

        // Xotirani bo'shatish
        free(birlashgan);
        birlashgan = NULL;
    }

    return 0;
}
