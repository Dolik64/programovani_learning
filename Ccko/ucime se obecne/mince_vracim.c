//mince_vracim

#include <stdio.h>

int main() { 
    int amount = 37;
    int r = scanf("%d", &amount);
    if (r == 1)
    
        for (int coins = 50; coins >= 1;) {
            if (amount / coins)
                printf("Number of %d CZK:\t %d\n", coins, amount / 50);
            amount = amount % coins;
            coins = coins == 50 ? 20 : coins / 2;
        }
}