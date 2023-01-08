#include<stdio.h>
#include<stdlib.h>

struct stock_buy_INFO
{
    int buyer_ID;
    int share_buy_units;
    struct stock_buy_INFO *next_buyer_INFO;
    struct stock_buy_INFO *buyer_transistion_ID;
};

struct stock_buy_INFO *front = NULL;
struct stock_buy_INFO *rare = NULL;
static int total_buy_units = 0;

struct stock_sell_INFO
{
    int seller_ID;
    int share_sell_units;
    struct stock_sell_INFO *next_seller_INFO;
    struct stock_sell_INFO *seller_transistion_ID;
};

struct stock_sell_INFO *sell_front = NULL;
struct stock_sell_INFO *sell_rare = NULL;
static int total_sell_units = 0;

void buy_stock(int buy_units)
{
    struct stock_buy_INFO *new_buyer_INFO = (struct stock_buy_INFO *)malloc(sizeof(struct stock_buy_INFO));
    if (front==NULL && rare==NULL)
    {
        new_buyer_INFO->buyer_transistion_ID=new_buyer_INFO;
        new_buyer_INFO->share_buy_units=buy_units;
        new_buyer_INFO->next_buyer_INFO=NULL;
        rare=new_buyer_INFO;
        front=rare; 
        total_buy_units+=buy_units; 
    }

    else
    {
        new_buyer_INFO->buyer_transistion_ID=new_buyer_INFO;
        new_buyer_INFO->share_buy_units=buy_units;
        new_buyer_INFO->next_buyer_INFO=NULL;
        rare->next_buyer_INFO=new_buyer_INFO;
        rare=new_buyer_INFO;
        total_buy_units+=buy_units; 
    }
    
}

void sell_stock(int sell_units)
{
    struct stock_sell_INFO *new_seller_INFO = (struct stock_sell_INFO *)malloc(sizeof(struct stock_sell_INFO));
    if (sell_front==NULL && sell_rare==NULL)
    {
        new_seller_INFO->seller_transistion_ID=new_seller_INFO;
        new_seller_INFO->share_sell_units=sell_units;
        new_seller_INFO->next_seller_INFO=NULL;
        sell_rare=new_seller_INFO;
        sell_front=sell_rare;
        total_sell_units+=sell_units;  
    }

    else
    {
        new_seller_INFO->seller_transistion_ID=new_seller_INFO;
        new_seller_INFO->share_sell_units=sell_units;
        new_seller_INFO->next_seller_INFO=NULL;
        sell_rare->next_seller_INFO=new_seller_INFO;
        sell_rare=new_seller_INFO;
        total_sell_units+=sell_units; 
    }
    
}

void check_buy_status()
{
    struct stock_buy_INFO *buyer_INFO = (struct stock_buy_INFO *)malloc(sizeof(struct stock_buy_INFO));
    
    if (front==NULL && rare==NULL)
    {
        printf("\nNo Demand Available\n");
    }

    else
    {
        printf("\t   Demands Status\nTransistion ID\t\tDemand Units\n");
        while (front!=rare->next_buyer_INFO)  
        {
            printf("%p\t\t%d\n",front->buyer_transistion_ID,front->share_buy_units);
            front=front->next_buyer_INFO;
            
        }
        printf("Total Demand %d units\n",total_buy_units);
        
    } 
}

void check_sell_status()
{
    struct stock_sell_INFO *seller_INFO = (struct stock_sell_INFO *)malloc(sizeof(struct stock_sell_INFO));
    
    if (sell_front==NULL && sell_rare==NULL)
    {
        printf("\nNo Supply Available\n");
    }

    else
    {
        printf("\n\n\n\n\t   Supply Status\nTransistion ID\t\tSupply Units\n");
        while (sell_front!=sell_rare->next_seller_INFO)  
        {
            printf("%p\t\t%d\n",sell_front->seller_transistion_ID,sell_front->share_sell_units);
            sell_front=sell_front->next_seller_INFO;
            
        }
        printf("Total Supply %d units\n",total_sell_units);
        
    } 
}

void demand_vs_supply()
{
    float total_transistion_units = total_buy_units + total_sell_units;
    printf("\n\n\nMarket Summary\n");

            if (total_buy_units>total_sell_units)
            {
                printf("\nDemand high with %d units\n",total_buy_units-total_sell_units);
            }
            else if(total_sell_units>total_buy_units)
            {
                printf("\nSupply is high with %d units\n",total_sell_units-total_buy_units);
            }
            else
            {
                printf("\nDemand and Supply Equal\n");
            }


        printf("%.2f%% sellers \t %.2f%% buyers active\n",total_sell_units*100/total_transistion_units,total_buy_units*100/total_transistion_units);

    
}



int main()
{
    system("clear");
    buy_stock(200);
    buy_stock(300);
    buy_stock(30);
    sell_stock(530);
    check_buy_status();
    check_sell_status();
    demand_vs_supply();
    return 0;
}