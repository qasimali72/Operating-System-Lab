#include <stdio.h>
#include <stdlib.h>
int mut = 1;
int full = 0;
int empty = 10, x = 0;

void tenliter_function()
{
	--mut;
	++full;
	--empty;
	x=x+10;
	printf("\n Add 10 liter water to water filter then total water %d liter ",x);
	++mut;
}

void fiveliter_function()
{
	-mut;
	--full;
	x=x-5;
	printf("\nremove 5 liter water from water filter then %d warter remain",x);
	++mut;
	++empty; 
}

int main(){
int n, i;
printf("\n1. Press 1 for give water 10 litre" 
    "\n2. Press 2 for take 5 litre"
    "\n3. Press 3 for Exit");
    for (i = 1; i > 0; i++){
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n){
        case 1:
            if((mut == 1) && (empty != 0)){
                tenliter_function();
            }
            else
            {
                printf("Water fileter is fulll");
            }
            break;
        case 2:
            if((mut ==1)&& (full !=0))
            {
                fiveliter_function();
            }
            else
            {
                printf("Water fileter is emptyty");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
