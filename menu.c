/*
Description: menu and bill for restaurant
*/
#include <stdio.h>
#define ITEM_COUNT      4
#define TAX_RATE        0.18f

int main(){
    int option;
    float tax=0.0,total=0.0;
    int item_count[ITEM_COUNT]={0};
    int item_price[ITEM_COUNT] = {100,25,30,30};
    char item_name[ITEM_COUNT][10] = {"Coffee","Puffs","Cake","Samosa"};

    printf("%s\n","<---Welcome to GCC cafe--->");

    while(1){
        printf("%15s\n","Menu");
        for(int i=0;i<ITEM_COUNT;i++){
            printf("%d.%-15s%s%d\n",i+1,item_name[i],"Rs.",item_price[i]);
        }
        printf("5.Exit menu\n");
        printf("Enter your choice: ");
        scanf("%d",&option);

        if(option == 5){
            break;
        }
        else if((option>0)&&(option<ITEM_COUNT)){
            item_count[option] +=1;
        }
        else{
            printf("Invalid choice!");
        }
    }

    printf("\n%s\n","<-----Bill----->");
    printf("%-10s%-10s%-5s%-5s\n","Item","Price","Qty","Total");
    for(int i=0;i<ITEM_COUNT;i++){
        if(item_count[i]){
           total += item_count[i]*item_price[i];
           printf("%-10s%-10d%-5d%-5d\n",item_name[i],item_price[i],item_count[i],item_price[i]*item_count[i]);
        }   
    }
    printf("\n%s\n","----------");
    tax = TAX_RATE*total;
    printf("%-25s%-5.2f\n","Tax",tax);
    printf("\n%s\n","----------");
    total += tax;
    printf("%-25s%-5.2f\n","Total",total);
}