#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 100

// �ж��Ƿ�Ϊ����
int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

// �Ҳ����� tableSize ���������
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

    // ��ǰ��������ҹؼ���
    int searchKey;
    scanf("%d", &searchKey);

    // ����׶�
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
    // �����ϣ��
    for (int i = 0; i < tableSize; i++) {
        printf("%d", hashTable[i]);
        if (i < tableSize - 1) printf(" ");
    }
    printf("\n");

    // ��� ASL
    if (numInserted > 0)
        printf("ASL=%.3f\n", (float)totalProbes / numInserted);
    else
        printf("ASL=0.000\n");

    // ���ҹؼ���
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

