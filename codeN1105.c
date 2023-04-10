#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 9

struct User {
    char username[50];
    char password[MAX_PASSWORD_LEN];
    int uid;
};

struct User usersDb[3] = {
        {.username = "admin", .password = "jrAz+"},
        {.username = "userA", .password = "ocAr6"},
        {.username = "userB", .password = "idMf("},
};


const char secret[8] = {11, 22, 44, 19, 69, 30, 90, 14};

char *encrypt(char *toEncrypt, int size) {
    int i;
    for (i = 0; i < size; i++)
        toEncrypt[i] ^= secret[i];

    return toEncrypt;
}

char *decrypt(char *toDecrypt, int size) {
    int i;
    for (i = 0; i < size; i++)
        toDecrypt[i] ^= secret[i];
    return toDecrypt;

}

int checkValidUserName(char *username) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(username, usersDb[i].username) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkValidPassword(char *username, char *password) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(username, usersDb[i].username) == 0 &&
            strcmp(password, decrypt(usersDb[i].password, strlen(usersDb[i].password))) == 0) {
            return 1;
        }
    }
    return 0;
}


int checkCredentials(char *username, char *password) {
    if (checkValidUserName(username)) {
        if (checkValidPassword(username, password)) {
            printf("Welcome %s", username);
            return 1;
        } else {
            printf("%s", "Password is invalid");
            return 0;
        }
    } else {
        printf("%s", "Username is invalid");
    }
    return 1;
}

int main(int argc, char **argv) {
    char username[20];
    char password[20];
    printf("Enter username:");
    scanf("%19s", username);
    printf("Enter password");
    scanf("%19s", password);
    checkCredentials(username, password);
}