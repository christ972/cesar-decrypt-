#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Pour tolower et toupper

void decrypt(char message[], int shift) {
    char decrypted_message[100]; // Déclaration d'un tableau pour stocker le message décrypté

    for(int k = 0; message[k] != '\0'; k++) {
        if (islower(message[k])) { // Si c'est une lettre minuscule
            decrypted_message[k] = 'a' + (message[k] - 'a' - shift + 26) % 26;
        } else if (isupper(message[k])) { // Si c'est une lettre majuscule
            decrypted_message[k] = 'A' + (message[k] - 'A' - shift + 26) % 26;
        } else { // Si ce n'est pas une lettre, copie tel quel
            decrypted_message[k] = message[k];
        }
    }

    printf("Clé %d : %s\n", shift, decrypted_message);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    char *message = argv[1];

    for (int shift = 0; shift < 26; shift++) {
        decrypt(message, shift);
    }

    return 0;
}
