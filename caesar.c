#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	char cipher[4096] = { 0, };
	char cipher_copy[4096] = { 0, };
	char plain[4096] = { 0, };
	int choice, key1, key2;

	while (true)
	{
		printf("1. Caesar cipher\n");
		printf("2. Caesar brute-force attack\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			memset(plain, 0, 4096);

			printf("plain text: ");
			scanf(" %[^\n]", plain);
			printf("key: ");
			scanf("%d", &key1);

			for (int i = 0; plain[i] != '\0'; i++)
			{
				if (isupper(plain[i])) plain[i] = (((plain[i] - 'A') + key1) % 26) + 'A';
				else if (islower(plain[i])) plain[i] = (((plain[i] - 'a') + key1) % 26) + 'a';
				else plain[i] = plain[i];
				printf("%c", plain[i]);
			}
			printf("\n\n");
		}

		else if (choice == 2)
		{
			memset(cipher, 0, 4096);
			memset(cipher_copy, 0, 4096);

			printf("cipher text: ");
			scanf(" %[^\n]", cipher);

			strcpy(cipher_copy, cipher);

			for (key2 = 0; key2 < 26; key2++)
			{
				strcpy(cipher, cipher_copy);

				printf("%d: ", key2);

				for (int i = 0; cipher[i] != '\0'; i++)
				{
					if (isupper(cipher[i])) cipher[i] = (((cipher[i] - 'A') - key2 + 26) % 26) + 'A';
					else if (islower(cipher[i])) cipher[i] = (((cipher[i] - 'a') - key2 + 26) % 26) + 'a';
					else cipher[i] = cipher[i];
					printf("%c", cipher[i]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
}