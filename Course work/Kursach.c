#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct hospitalEmployee{
    char FIO[50];
    int year;
    int month;
    int numberofDays;
    int daysMissedDuetoIllness;
    float paymentinOneDay;                                                                                                                                                        
}a[50];

struct users{
    char login[30];
    char password[30];
    int role;
}a1[5];
void array_nulling(char *array, int *size){
    for (int i=0; i<*size; i++){
        *(array+i)=0;
    }
}
// Вход
void pass(int *k, struct users *a1, int *size){
    int n, stop, maxNumofLetters=30;
    char login[maxNumofLetters], password[maxNumofLetters];
    while (*k==0){
        array_nulling(login, &maxNumofLetters);
        array_nulling(password, &maxNumofLetters);
        stop=0;
        printf("Login: ");
        scanf("%s", &login);
        printf("Password: ");
        scanf("%s", &password);
        for (int i=0; i<*size; i++){
            if (memcmp((a1+i)->login, login, maxNumofLetters)==0 && memcmp((a1+i)->password, password, maxNumofLetters)==0){
                if (a1[i].role==1){
                    *k=1;
                    printf("Enter succesful!\n");
                    break;
                }
                else *k=2;
                printf("Enter succesful!\n");
                break;
            }
        }
        if (*k==0) printf("\nWrong login or password\n");
        while ((*k==0) && stop!=1){
            printf("1 - Try logging in again\n2 - Exit\n");
            scanf("%d", &n);
            switch(n){
                case 1:
                    stop=1;
                    break;
                case 2:
                    *k=-1;
                    break;
                default:
                    printf("\nWrong number, please try again\n");
            }
        }
    }
}
int main(){
    int k=0, size;
    struct users a1[]={"admin", "admin", 1, "user", "user", 0};
    size=sizeof(a1)/sizeof(a1[0]);
    pass(&k, a1, &size);
    system("pause");
    return 0;
}