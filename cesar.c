#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Pour tolower et toupper

char* decrypt(char message[]) {
    char *decrypted_message = (char *)malloc(sizeof(message)); // Alloue la mémoire pour le message décrypté

    for(int shift = 0; shift < 26; shift++) {
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

    free(decrypted_message); // Libère la mémoire allouée pour le message décrypté

    return message; // Renvoie le message original (non modifié)
}

int main() {
    char message[100];
    printf("Entrez le message à décrypter : ");
    fgets(message, sizeof(message), stdin); // Utilise fgets pour lire une ligne entière avec les espaces

    decrypt(message);

    return 0;
}
