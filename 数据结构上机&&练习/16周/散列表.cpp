#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 100

// 判断是否为素数
int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

// 找不超过 tableSize 的最大素数
int find_max_prime(int tableSize) {
    for (int i = tableSize; i >= 2; i--) {
        if (is_prime(i)) return i;
    }
    return 2;
}

int main() {
    int tableSize;
    scanf("%d", &tableSize);

    int hashTable[MAXSIZE];
    for (int i = 0; i < tableSize; i++)
        hashTable[i] = -1;

    int p = find_max_prime(tableSize);

    int key, totalProbes = 0, numInserted = 0;
    int keysToInsert[MAXSIZE], insertCount = 0;

    while (scanf("%d", &key), key != -1) {
        keysToInsert[insertCount++] = key;
    }

    // 提前输入待查找关键字
    int searchKey;
    scanf("%d", &searchKey);

    // 插入阶段
    for (int i = 0; i < insertCount; i++) {
        key = keysToInsert[i];
        int addr = key % p;
        int probes = 1;

        while (hashTable[addr] != -1) {
            addr = (addr + 1) % tableSize;
            probes++;
        }
        hashTable[addr] = key;
        totalProbes += probes;
        numInserted++;
    }
	/*if(numInserted==0) {
		printf("Empty List\n");
		return 0;
	}*/
    // 输出哈希表
    for (int i = 0; i < tableSize; i++) {
        printf("%d", hashTable[i]);
        if (i < tableSize - 1) printf(" ");
    }
    printf("\n");

    // 输出 ASL
    if (numInserted > 0)
        printf("ASL=%.3f\n", (float)totalProbes / numInserted);
    else
        printf("ASL=0.000\n");

    // 查找关键字
    int addr = searchKey % p;
    int start = addr;
    int found = 0;

    while (hashTable[addr] != -1) {
        printf("%d", hashTable[addr]);
        if (hashTable[addr] == searchKey) {
            found = 1;
            printf("\nkey=%d\n", addr);
            break;
        }
        addr = (addr + 1) % tableSize;
        if (addr == start) break;
        printf(" ");
    }

    if (!found)
        printf("\nnot found\n");

    return 0;
}

