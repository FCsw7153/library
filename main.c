#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <windows.h>

struct users {
    // name : user's name
    // passwd : user's password
    char name[10];
    char passwd[10];
    struct users *next;
};

struct books {
    // name : book's name
    // booknum : book's number
    // category : book's category
    // is_lent : book is lent or not       1 : lent         0 : not lent
    // year : the years which book is lent
    // month : the months which book is lent
    // day : the days which book is lent
    char name[10];
    int booknum;
    char category[10];
    
    _Bool is_lent;
    int year;
    int month;
    int day;

    struct books *next;
};

void mainmenu() {
    // print the library's main memu
    printf("welcome to library manage system!\n");
    printf("Now select one mode please!\n");
    printf("1.Add book to system\n");
    printf("2.Delete book from system\n");
    printf("3.login with your ID\n");
}

int check_user(struct users *user) {
    // check user input account is in system or not
    char find_name[10];
    FILE *userfile;
    userfile = fopen("userfile.txt", "a");

    if(userfile == NULL) {
        return 0;
    }
    else {
        while(fgets(find_name, 2 * sizeof(find_name), userfile)) {
            if(strstr(find_name, user -> name)) {
                return 1;
            }
        }
        return 0;
    }
}

int create_user(struct users *user) {
    // create a new user into system
    // if user input account is already in system then warning user to input again
    struct users us;
    FILE *userfile;
    userfile = fopen("userfile.txt", "a");

    if(userfile == NULL)
        fopen("userfile.txt", "w");

create_loop:
    system("CLS");

    printf("Create a new user account!\n");
    printf("\n\n");
    printf("[user account] is a number with 11 words, make sure your number never register this system!\n");
    printf("[account passwd] should be less than 8 words!");
    printf("\n\n");

    printf("Please input your account!\n");
    scanf("%s", us.name);
    printf("\n");

    if(check_user(&us) == 0) {
        printf("Please input your password!\n");

        int i = 0;
        while(i > 0 && i < 8 &&(us.passwd[i] = getchar() != '\r')) {
            if(us.passwd[i] == '\b') {
                if(i <= 0)
                    continue;
                else
                    i--;
            }
            else {
                i++;
                if(i > 8) {
                    printf("Warning! Password must be less than 8 words!\n");
                    i--;
                }
            }
        }
        us.passwd[i] = '\0';

        printf("Please input your password again to ensure your password correct!\n");

        char check_passwd[10];
        i = 0;
        while(i > 0 && i < 8 &&(check_passwd[i] = getchar() != '\r')) {
            if(check_passwd[i] == '\b') {
                if(i <= 0)
                    continue;
                else
                    i--;
            }
            else {
                i++;
                if(i > 8) {
                    printf("Warning! Password must be less than 8 words!\n");
                    i--;
                }
            }
        }
        check_passwd[i] = '\0';

        int check = 1;
        if (strcmp(us.passwd, check_passwd) == 0)
            ;
        else {
            printf("Two password is not the same, please register again!\n");
            goto create_loop;
        }

        fprintf(userfile, "%s %s", us.name, us.passwd);
        fprintf(userfile, "\n");
        fclose(userfile);

        printf("Congratuation! Your account is ready to use!\n");
        printf("Please remember your account and password!\n");

        printf("\n\n");
        printf("input any character back to mainmenu!\n");
    userfile = fopen("user.txt", '/w');
        
        char ch;
        ch = getchar();
        system("cls");
        return 1;
   }
    else {
        printf("Your accunt is already used, Please log in directly or use other to register!\n");
        printf("input any character back to mainmenu!\n");
        
        char ch;
        ch = getchar();
        system("cls");
        goto create_loop;
    }
}

int login() {
    // ensure user to log in system
    // if have the user, log in
    // if not have the user, warn user to register a account
    FILE *userfile;
    userfile = fopen("userfile.txt", "a");
    printf("Please input your account and your password to log in!\n");
    struct users login_user;
    scanf("%s %s", login_user.name, login_user.passwd);
    if(check_user(&login_user)) {
        char find_name[10];
        while(fgets(find_name, 2 * sizeof(find_name), userfile)) {
            if(strstr(find_name, login_user.name)) {
                char find_passwd[10];
                fgets(find_passwd, sizeof(find_passwd), userfile);
                if(strstr(find_passwd, login_user.passwd))
                    return 1;
                else {
                    printf("Your password is wrong, Please input again!\n");
                    return 0;
                }
            }
        }
    }
    else {
        printf("System have not your account, Please input again or register one!\n");
        return 0;
    }
}



int main() {
    return 0;
}
