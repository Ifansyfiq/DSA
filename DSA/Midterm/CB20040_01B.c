#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct Electric
{
    float crrnt;
    float prev;
    float bill;
    float disc;
};

struct Water
{
    float crrnt;
    float prev;
    float bill;
    float disc;
};

struct HouseReport
{
    char name[30];
    char address[50];
    struct Electric elctr;
    struct Water wtr;
    float totalBill;
} ;


struct HouseReport getInfo();
struct HouseReport calculateBill();
struct HouseReport calculateTotalBillsAfterDiscount();
struct HouseReport display();

int main()
{
    struct HouseReport house[3];
    for (int i=0;i<3;i++)
    {
        house[i]=getInfo();
        house[i]=calculateBill(house[i]);
        house[i].totalBill=calculateTotalBillsAfterDiscount(house[i]);
    }
    display(house);

    return 0;
}

struct HouseReport getInfo()
{
    struct HouseReport house;

    printf("\nEnter House Owner Name:");
    scanf(" %[^\n]s",&house.name);
    printf("\nEnter House Address:");
    scanf(" %[^\n]s",&house.address);
    printf("\nEnter Current Unit For Electric:");
    scanf("%f",&house.elctr.crrnt);
    printf("\nEnter Previous Unit For Electric:");
    scanf("%f",&house.elctr.prev);
    printf("\nEnter Current Unit For Water:");
    scanf("%f",&house.wtr.crrnt);
    printf("\nEnter Previous Unit For Water:");
    scanf("%f",&house.elctr.prev);

    return house;
}

struct HouseReport calculateBill(struct HouseReport housebill)
{

    float unitUsed1 = housebill.elctr.crrnt - housebill.elctr.prev;

    if(unitUsed1<100)
    {
        housebill.elctr.bill=unitUsed1*0.10;
    }
    else if (unitUsed1<200)
    {
         housebill.elctr.bill=unitUsed1*0.20;
    }
    else
    {
         housebill.elctr.bill=unitUsed1*0.40;
    }

    float unitUsed2 = housebill.wtr.crrnt - housebill.wtr.prev;

    if(unitUsed2<20){
        housebill.wtr.bill=unitUsed2*0.50;
    }
    else
    {
         housebill.wtr.bill=unitUsed2*1;
    }

    housebill.totalBill = housebill.wtr.bill + housebill.elctr.bill;

    return housebill;


}


struct HouseReport calculateTotalBillsAfterDiscount(struct HouseReport discount)
{
        if (discount.elctr.bill<100)
        {
            discount.elctr.disc = discount.elctr.bill-(0.2*discount.elctr.bill);
        }
        else
        {
            discount.elctr.disc = discount.elctr.bill-(0.1*discount.elctr.bill);
        }

        if (discount.wtr.bill<100)
        {
            discount.wtr.disc = discount.wtr.bill-(0.2*discount.wtr.bill);
        }
        else
        {
            discount.wtr.disc = discount.wtr.bill-(0.1*discount.wtr.bill);
        }


    return discount;
}





void display(struct HouseReport house)
{

    printf("\n\t\tHOUSE BILL REPORT");
    printf("\n");

     for (int i=0;i<3;i++)
     {
    printf("\nHouse Owner Name: %s",house[i].name);
    printf("\nHouse Address: %s",house[i].address);
    printf("\nElectric Bill: RM.2f",house[i].elctr.bill);
    printf("\nWater Bil: RM.2f",house[i].wtr.bill);
    printf("\nTotal Bill: RM.2f",house[i].wtr.bill+house[i].wtr.bill);
    printf("\nTotal Bill after discount: RM.2f",house[i].totalBill);
     }

}










