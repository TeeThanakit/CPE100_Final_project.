 #include <stdio.h>
#include <string.h>
#include "owner.h"
#include <time.h>
#include <ctype.h>
int i;
int Cuscount;
int temp; // total menu
char addAnother = 41;
int code;
int qty;
float price;
float amt;
float tamt;
int array[30] = {0};
float cash;
float change;
int checktrue;
char interested = 41;
char getch();
int  bill();
void start();
int	customer();
void	save();
void    srand();
typedef struct Item
{
    char name[50];
    int id;
    int type; // 1 Drink, 2 Appetizer, 3 Main course ,4 Desert
    float cost;
    float price;
    int stock;
} item;

typedef struct temporary
{
    char name[50];
    float price;
    int volum;
} temporary;

typedef struct Receipt
{
    char phone[10];
    int id[30];
    char time[30];
    float cash;
    float change;
    char card[16];
    char coupon[10];
} Receipt;

Receipt receipt[100];
item Product[30];
temporary cart[100];
int firstcart=0;
int secondfirst=0;
int nextcart=0;
int	 AddProduct()
{
    printf("Enter Product Name : ");
    scanf("%s", Product[temp].name);
    printf("Enter Product Type \n1.Drink \n2.Appetizer \n3.Main course \n4.Desert\nPlease Type : ");
    scanf("%d", &Product[temp].type);

    printf("Enter Product Cost : ");
    scanf("%f", &Product[temp].cost);
    if(Product[temp].cost<0)
    {
        printf("Product cost cannot less than 0\n");
        printf("Please enter product cost again:");
        scanf("%f", &Product[temp].cost);
    }

    printf("Enter Product Price : ");
    scanf("%f", &Product[temp].price);
    if(Product[temp].price<0)
    {
        printf("Product price cannot less than 0\n");
        printf("Please enter product price again:");
        scanf("%f", &Product[temp].price);
    }
    printf("Enter Product Quantity : ");
    scanf("%d", &Product[temp].stock);
    if(Product[temp].stock<0)
    {
        printf("Product quantity cannot less than 0\n");
        printf("Please enter product quantity again:");
        scanf("%d", &Product[temp].stock);
    }
    Product[temp].id = temp;
    printf("New Product has been Added!\n Press 9 to add more else press other number");
    temp++;
    scanf("%d", &i);
    if (i == 9)
        AddProduct();
    else
        owner();

	return 0;
}
void Stock()
{
    for (int x = 0; x <= temp-1; x++)
    {
        if(strlen(Product[x].name)<=7)
        {
            printf("%s", Product[x].name);
            printf("\t\t%d Left\n", Product[x].stock);
        }
        else
        {
            printf("%s", Product[x].name);
            printf("\t%d Left\n", Product[x].stock);
        }
    }
    for (int x = 0; x <= temp-1; x++)
    {
        if(Product[x].stock<=5)
        {
            printf("##########%s has only %d pieces##########\n",Product[x].name,Product[x].stock);
        }
    }
    printf("Exit Please Type 0\n");
    printf("Edit Stock Please Type 9\n");
    int z;
    scanf("%d", &z);
    if (z == 0)
        owner();
    else if (z == 9)
        EditProduct();
    else
    {
        printf("Type again");
	Stock();
	}
}
void Finance(){
    int max1 = 0; int a;
    float max2 = 0; float total = 0;
    int max11 = 0;
    int max22 = 0;
    int list[30]={0};
    float profit[30]={0};
    for (int i = 0; i < Cuscount;i++ )
    {
        for (int x = 0 ; x<temp; x++)
        {
            list[x] = list[x] + receipt[i].id[x];
        }
    }
        printf("########################################\n");
        printf("Product\t\tSell amount\tProfit\n");
        for (int x = 0 ; x<temp; x++)
        {
            profit[x] = list[x]*Product[x].price - list[x]*Product[x].cost;
            total = total + profit[x];
            if(list[x]> max1) max1 = list[x],max11 = x;
            if(profit[x]> max2)max2 = profit[x],max22 = x;
            //int lengthstring=strlen(Product[x].name);
            printf("%s",Product[x].name);
            for(int lengthstring=strlen(Product[x].name);lengthstring<=14;lengthstring++)
                printf(" ");
            //printf("Sell amount: %d Profit: %.2f$\n",list[x], profit[x]);
            printf("\t\t  %d\t%.2f$\n",list[x], profit[x]);
        }
    printf("Total Profits = %.2f$\n",total);
    printf("Best Seller = %s\n",Product[max11].name);
    printf("Best Profits = %s\n",Product[max22].name);
        printf("########################################\n");
    printf("Return Press 9\n"); scanf("%d",&a);

    while (a!=9) scanf("%d",&a);
    owner();
}
int FindCustomer(){
    int a;
    char Cusno[10];
    printf("Customer Number : ");
    scanf("%s",Cusno);
for (int i=0;i<Cuscount;i++){
    //printf("R");
    int value = strcmp(Cusno,receipt[i].phone);
    //printf("%d",value);
    if(value == 0){
    printf("Bill Number %d\n",i+1);
    printf("Phone Number : %s\n",receipt[i].phone);
for (int x=0;x<temp;x++){
if (receipt[i].id[x] > 0){ a = receipt[i].id[x],
printf("%s\t",Product[a].name),
printf("%d*%.2f$ = ", receipt[i].id[x],Product[x].price),
printf("%.2f$\n", a*Product[x].price);
}}
printf("Total = %.2f$\t",receipt[i].cash);
if (receipt[i].change == -1) printf("Card Payment: %s\n",receipt[i].card);
if (receipt[i].change == -2) printf("Mobile Payment\n");
if (receipt[i].change >= 0)printf("Change = %.2f\n",receipt[i].change);
printf("%s\n\n",receipt[i].time);
}}
owner();
return 1;
}

int EditProduct()
{
    for (int x = 0; x <= temp; x++)
    {
        printf("ID %d:%s\n", x, Product[x].name);
    }
    printf("Exit Please type -1\n");
    printf("Select Product ID : ");
    int z;
    scanf("%d", &z);
    if (z == -1) owner();
    else EditProduct2(z);
    return 1;
}
int EditProduct2(int i)
{
    int a;
    printf("1.Name:%s\n", Product[i].name);
    printf("2.Type:%d\n", Product[i].type);
    printf("3.Cost:%.2f\n", Product[i].cost);
    printf("4.Price:%.2f\n", Product[i].price);
    printf("5.Quantity:%d\n", Product[i].stock);
    printf("6.Save\n");
    printf("Select Topic to Edit : ");
    scanf("%d", &a);
    if (a == 1)
        printf("Enter Product Name : "), scanf("%s", Product[i].name), EditProduct2(i);
    else if (a == 2)
        printf("Enter Product Type \n1.Drink \n2.Appetizer \n3.Main course \n4.Desert\nPlease Type : "), scanf("%d", &Product[i].type), EditProduct2(i);
    else if (a == 3)
        printf("Enter Product Cost : "), scanf("%f", &Product[i].cost), EditProduct2(i);
    else if (a == 4)
        printf("Enter Product Price : "), scanf("%f", &Product[i].price), EditProduct2(i);
    else if (a == 5)
        printf("Enter Product Quantity : "), scanf("%d", &Product[i].stock), EditProduct2(i);
    else if (a == 6)
        EditProduct();
    else
        printf("Error Back to EditProduct\n"), EditProduct();

	return 1;
}

void owner()
{
    printf("Menu\n1.Add Product\n2.Stock\n3.Finance\n4.Edit Product\n5.Receipt\n6.Find Customer\n9.Return\nPlease Select : ");
    scanf("%d", &i);
    if (i == 1)
        AddProduct();
    else if (i == 2)
        Stock();
    else if (i == 3)
        Finance();
    else if (i == 4)
        EditProduct();
    else if (i == 5)
        bill();
    else if (i == 6)
        FindCustomer();
    else if (i == 9)
        start();
    else
    {
    	("Please Input again\n");
	owner();
	}
}
//Discount coupon
const char* DiscountCoupon[] = {
  "first10",
  "off10",
  "patty10",
  "dis10",
  "chirstmas10",
  "welcome10"};

const int num_DiscountCoupon = sizeof(DiscountCoupon) / sizeof(DiscountCoupon[0]);

void inventory()
{
//const char *save_record = "Item name: %s | ID : %d | Type : %d | Cost : %.2f | Price : %.2f | Stock : %d\n";
//const char *import_record = "Item name: %s | ID : %d | Type : %d | Cost : %.2f | Price : %.2f | Stock : %d\n";
//const char *bill_record = "%s | %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d | Time = %s | Cash = %f | Change = %f | Card = %s | Coupon = %s |";
FILE *file_inventory, *file_pos;
file_inventory = fopen("C:/Users/Teeboy/Desktop/New folder (3)/CPE100/Inventory.txt", "r+");
file_pos = fopen("C:/Users/Teeboy/Desktop/New folder (3)/CPE100/Sell.txt", "r+");
for (int i = 0; i < 30; i++)
    {
fscanf(file_inventory, "Item name: %s | ID : %d | Type : %d | Cost : %f | Price : %f | Stock : %d\n", Product[i].name, &Product[i].id, &Product[i].type, &Product[i].cost, &Product[i].price, &Product[i].stock);

        if ((int)Product[i].price == 0)
        {
            temp = i;
            break;
        }
    }
for (int i = 0; i < 100; i++){
fscanf(file_pos, "%s | %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d | Time = %s | Cash = %f | Change = %f | Card = %s | Coupon = %s |\n",&receipt[i].phone, &receipt[i].id[0],&receipt[i].id[1],&receipt[i].id[2],&receipt[i].id[3],&receipt[i].id[4],&receipt[i].id[5],&receipt[i].id[6],&receipt[i].id[7],&receipt[i].id[8],&receipt[i].id[9],&receipt[i].id[10],&receipt[i].id[11],&receipt[i].id[12],&receipt[i].id[13],&receipt[i].id[14],&receipt[i].id[15],&receipt[i].id[16],&receipt[i].id[17],&receipt[i].id[18],&receipt[i].id[19],&receipt[i].id[20],&receipt[i].id[21],&receipt[i].id[22],&receipt[i].id[23],&receipt[i].id[24],&receipt[i].id[25],&receipt[i].id[26],&receipt[i].id[27],&receipt[i].id[28],&receipt[i].id[29],&receipt[i].time,&receipt[i].cash,&receipt[i].change,&receipt[i].card,&receipt[i].coupon);

if ((int)receipt[i].cash == 0)
        {
            Cuscount = i;
            break;
        }
}

}

int bill(){
int a;
for (int i=0;i<Cuscount;i++){
    printf("Bill Number %d\n",i+1);
    printf("Phone Number : %s\n",receipt[i].phone);
for (int x=0;x<temp;x++){
if (receipt[i].id[x] >= 1){a = receipt[i].id[x],
printf("%d",receipt[i].id[x]);
printf("%s\t",Product[x].name),
printf("%d *%.2f$ = ", a,Product[x].price),
printf("%.2f$\n", receipt[i].id[x]*Product[x].price);
}}
printf("Total = %.2f$\t",receipt[i].cash);
if (receipt[i].change == -1) printf("Card Payment\n"), printf("Card Number : %s\n",receipt[i].card);
if (receipt[i].change == -2) printf("Bank Payment\n");
if (receipt[i].change >= 0)printf("Change = %.2f\n",receipt[i].change);
//if (strcmp(receipt[i].coupon,"n")==0) printf("Coupon : %s\n",receipt[i].coupon);
printf("%s\n\n",receipt[i].time);
}
owner();
return 1;
}

int	ft_isdigit(char *x,int lenght)
{
    int CountIsAllNumOrNot=0;
    for(int i=0;i<lenght;i++)
    {
        if(x[i] >= '0' && x[i] <= '9')
            CountIsAllNumOrNot++;
        else
            CountIsAllNumOrNot--;
    }
    if(CountIsAllNumOrNot==lenght)
        return 1;
    else
        return 0;
}
/*
int ft_strcmp(char *s1,char *s2,int lenght)
{
    unsigned int x=0;
    while(s1[x]==s2[x] && (s1[x]!='\0' || s2[x]!='\0'))
      x++;
    if(x==lenght)
      return 1;
    else
      return 0;
}

int checkcoupon(char *x)
{
        char temp[10];
        strcpy(temp,x);
        int checkcouponexistornot=0;
        int CHECKCOUPONEXISTORNOT=0;
        checkcouponexistornot=ft_strcmp(temp,"first10",7);
        //printf("%d\n",checkcouponexistornot);
        CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
        checkcouponexistornot=ft_strcmp(temp,"patty10",7);
        CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
        checkcouponexistornot=ft_strcmp(temp,"dis10",5);
        CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
        checkcouponexistornot=ft_strcmp(temp,"chirstmas10",11);
        CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
        checkcouponexistornot=ft_strcmp(temp,"welcome10",9);
        CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
        if(CHECKCOUPONEXISTORNOT==1)
            return 1;
        else
            return 0;
}*/
void PrintItemCus(int i)
{
    char coupon[10];
    srand(time(NULL));
    int index = rand() % num_DiscountCoupon;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
    do
    {
        if (addAnother == 89 || addAnother == 121)
        {
            printf("Menu\n1.Drink\n2.Appetizer\n3.Main Course\n4.Desert\n5.Return\nPlease Select : ");
            scanf("%d", &i);
        }
        int count = 0;
        for (int x = 0; x <= temp; x++)
        {
            if (Product[x].type == i)
            {
                printf("[%d]%s", x, Product[x].name),
                printf("\t%.2f$", Product[x].price),
                printf("\t%d Left\n", Product[x].stock);
                count++;
            }
        }
        printf("Enter Code:\t");
        scanf("%d", &code);
        if (code < 0 || code > 29) PrintItemCus(i);
        printf("Enter Quantity:\t");
        scanf("%d", &qty);
        strcpy(cart[firstcart].name,Product[code].name);
        cart[firstcart].price=Product[code].price;
        cart[firstcart].volum=qty;
        firstcart++;
        //l ถ้าของที่ลูกค้าต้องการมีค่าน้อยกว่าใสstockก็ให้ทำซ้ำไปเรื่อยจนกว่าสินค้าที่ลูกค้าต้องการพอดีกับstock
        do
        {
            if (qty > Product[code].stock)
            {
                do
                {
                    printf("Product is not available it has only: %d pieces \n", Product[code].stock);
                    printf("Please Enter Quantity again:\t");
                    scanf("%d", &qty);
                } while (qty > Product[code].stock);
            }
            else if(qty<=0)
            {
                do
                {
                    printf("Product quantity cannot less than 1\n");
                    printf("Please Enter Quantity again:\t");
                    scanf("%d", &qty);
                } while (qty <= 0);
            }
        }while(qty > Product[code].stock||qty <= 0);
        array[code] = array[code] + qty;
        Product[code].stock = Product[code].stock - qty;
        price = Product[code].price;
        amt = price * qty;
        printf("Amount: %.2f\n", amt);
        receipt[Cuscount].id[code] = qty;
        tamt = tamt + amt;
        printf("Total amount: %.2f$\n", tamt);
        printf("Add another order(y/n)?\n");
        //l addAnotherเท่ากับ89หรือ121(มันเป็นเลขasciiของตัวYเเละy)ก็จะซื้อสินค้าเพิ่มได้
        addAnother = getch();
    } while (addAnother == 89 || addAnother == 121);

        printf("Press (n) if no coupon\n");
        printf("Coupon : ");
        scanf("%s",coupon);
        /*if(coupon!='n')
        {
            int checkcouponexistornot=0;
            int CHECKCOUPONEXISTORNOT=0;
            checkcouponexistornot=ft_strcmp(coupon,"first10",7);
            CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
            checkcouponexistornot=ft_strcmp(coupon,"patty10",7);
            CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
            checkcouponexistornot=ft_strcmp(coupon,"dis10",6);
            CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
            checkcouponexistornot=ft_strcmp(coupon,"chirstmas10",11);
            CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
            checkcouponexistornot=ft_strcmp(coupon,"welcome10",9);
            CHECKCOUPONEXISTORNOT=CHECKCOUPONEXISTORNOT+checkcouponexistornot;
            if(CHECKCOUPONEXISTORNOT==1&&tamt>=50)
                tamt=tamt-10;
            else
                printf("This coupon does not exist\n");
        }*/
    if (strcmp(coupon,"first10")==0) {if(tamt >= 50) printf("Discounted 10$ Total = %.2f$\n",tamt -10),tamt = tamt-10;}
    else if (strcmp(coupon,"off10")==0) {if (tamt >= 50) printf("Discounted 10$ Total = %.2f$\n",tamt -10),tamt = tamt-10;}
    else if (strcmp(coupon,"patty10")==0) {if (tamt >= 50) printf("Discounted 10$ Total = %.2f$\n",tamt -10),tamt = tamt-10;}
    else if (strcmp(coupon,"dis10")==0) {if (tamt >= 50 ) printf("Discounted 10$ Total = %.2f$\n",tamt -10),tamt = tamt-10;}
    else if (strcmp(coupon,"chirstmas10")==0) {if (tamt >= 50) printf("Discounted 10$ Total = %.2f$\n",tamt -10),tamt = tamt-10;}
    else if (strcmp(coupon,"welcome10")==0) {if (tamt >= 50) printf("Discounted 10$ Total = %.2f$\n",tamt -10),tamt = tamt-10;}
    else if (strcmp(coupon,"n")==0) printf("No coupon added\n"); // make loop here please
    else printf("This coupon does not exist\n");
    //strcpy(receipt[Cuscount].coupon, ("%s",coupon));
    int paymentmethod;
    char card16digits[20];
    /*#################### Payment method ##########*/
    do
    {
        int counterror=0;
        printf("Payment Method\n");
        printf("[1] Cash payment\n");
        printf("[2] Credit/Debit Card\n");
        printf("[3] Mobile Banking\n");
        scanf("%d",&paymentmethod);
        if(paymentmethod==1)
        {
            do
            {
                printf("Product\t\tQuantity\tPrice\n");
                while(secondfirst<firstcart)
                {
                    printf("%s",cart[secondfirst].name);
                    //int lenghtstring=strlen(cart[secondfirst].name);
                    for(int lenghtstring=strlen(cart[secondfirst].name);lenghtstring<=14;lenghtstring++)
		    	printf(" ");
                    printf("%d\t",cart[secondfirst].volum);
                    printf("\t%.2f\n",cart[secondfirst].price);
		    secondfirst++;
                }
                secondfirst=firstcart;
                printf("Total amount: %.2f$\n", tamt);
                counterror++;
                printf("Cash Terdered\t:");
                scanf("%f", &cash);
            } while (cash < tamt);
            change = cash - tamt;
            receipt[Cuscount].cash = cash;
            printf("Change: %.2f$\n", change);
            printf("10$ off for 50$ purchase Coupons:(%s)\nThank you\n", DiscountCoupon[index]);
            strcpy(receipt[Cuscount].card, "Cash");
        }
        else if(paymentmethod==2)
        {
            do
            {
                if(counterror>0)
                {
                    printf("The number is incorrect.Please try again\n");
                }
                printf("Product\t\tQuantity\tPrice\n");
                while(secondfirst<firstcart)
                {
                    printf("%s",cart[secondfirst].name);
                    int lenghtstring=strlen(cart[secondfirst].name);
                    for(int lenghtstring=strlen(cart[secondfirst].name);lenghtstring<=14;lenghtstring++)
                        printf(" ");
                    printf("%d\t",cart[secondfirst].volum);
                    printf("\t%.2f\n",cart[secondfirst].price);
		    secondfirst++;
                }
                secondfirst=firstcart;
                printf("Total amount: %.2f$\n", tamt);
                printf("Enter 16 digit credit/debit card number: ");
                scanf("%s",card16digits);

                checktrue=ft_isdigit(card16digits,16);
                if(checktrue==1)
                {
                    while(1)
                    {
                        printf("Progress.");
                        sleep(1);
                        printf(".");
                        sleep(1);
                        printf(".");
                        sleep(1);
                        printf(".");
                        sleep(1);
                        printf(".");
                        float r = -1;
                        receipt[Cuscount].cash= tamt;
                        change = -1;
                        strcpy(receipt[Cuscount].card, ("%s",card16digits));
                        printf("\nPayment Payment successful\n");
                        /*printf("Add line @pattysuay to get 100 THB E-coupon\n");
                        do
                        {
                            printf("Are you interested discount coupon(y\n)?");
                            printf("\n");
                            interested=getch();
                            if(interested==89||interested==121)
                                printf("Here is discount coupon: %s\nThank you\n", DiscountCoupon[index]);
                            else
                                printf("Thank you");
                        }while(interested!=89&&interested!=121);*/
                        printf("10$ off for 50$ purchase Coupons:(%s)\nThank you\n", DiscountCoupon[index]);
                        sleep(1);
                        break;

                    }
                }
            }while(checktrue!=1);
        }
        else if(paymentmethod==3)
        {
                printf("Product\t\tQuantity\tPrice\n");
                while(secondfirst<firstcart)
                {
                    printf("%s",cart[secondfirst].name);
                    //int lenghtstring=strlen(cart[secondfirst].name);
                    for(int lenghtstring=strlen(cart[secondfirst].name);lenghtstring<=14;lenghtstring++)
		    	printf(" ");
                    printf("%d\t",cart[secondfirst].volum);
                    printf("\t%.2f\n",cart[secondfirst].price);
		    secondfirst++;
                }
                secondfirst=firstcart;
                printf("Total amount: %.2f$\n", tamt);
                printf("Please transfer to Bank:Scb 4041492367\n");
                printf("10$ off for 50$ purchase Coupons:(%s)\nThank you\n", DiscountCoupon[index]);
                change = -2;
                receipt[Cuscount].cash= tamt;
                strcpy(receipt[Cuscount].card, "Bank");
        }
    }while(paymentmethod!=1&&paymentmethod!=2&&paymentmethod!=3);
/*#################### Payment method ##########*/
char times[30];
sprintf(times,"%d-%02d-%02d_%02d:%02d:%02d",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
strcpy(receipt[Cuscount].time,(&times));
    receipt[Cuscount].change = change;
    Cuscount++;
    sleep(1);
    tamt = 0;
    start();
}
void start()
{
    int ii;
    printf("Menu\n1.Owner\n2.Customer\n9.Save&Exit\nPlease Select : ");
    scanf("%d", &ii);
    if (ii == 1)
        owner();
    else if (ii == 2)
        customer();
    else if (ii == 9)
        save();
    else
        printf("Please Input again\n"), start();
}
int customer()
{
    printf("Please type your phone number : ");
    int checkeisphonenumberornot;
    scanf("%s", receipt[Cuscount].phone);
    checkeisphonenumberornot=ft_isdigit(receipt[Cuscount].phone,10);
    if(checkeisphonenumberornot==1)
    {
        printf("Menu\n1.Drink\n2.Appetizer\n3.Main Course\n4.Desert\n5.Return\nPlease Select : ");
        scanf("%d", &i);
        if (i == 1)
            PrintItemCus(1);
        else if (i == 2)
            PrintItemCus(2);
        else if (i == 3)
            PrintItemCus(3);
        else if (i == 4)
            PrintItemCus(4);
        else if (i == 5)
            start();
        else
            printf("Please Input again\n"), customer();
    }
    else
    {
        printf("Phone number is incorrect\n");
        customer();
    }
    return 1;
}
void save(){
    FILE *file_inventory,*file_pos;
    const char *save_record = "Item name: %s | ID : %d | Type : %d | Cost : %.2f | Price : %.2f | Stock : %d\n";
    const char *bill_record = "%s | %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d | Time = %s | Cash = %.2f | Change = %.2f | Card = %s | Coupon = %s |\n";
    file_inventory = fopen("C:/Users/Teeboy/Desktop/New folder (3)/CPE100/Inventory.txt", "w");
    file_pos = fopen("C:/Users/Teeboy/Desktop/New folder (3)/CPE100/Sell.txt", "w");
    for (int i = 0;i<temp;i++)
fprintf(file_inventory, save_record, Product[i].name, Product[i].id, Product[i].type, Product[i].cost, Product[i].price, Product[i].stock);
    for (int i = 0;i<Cuscount;i++)
fprintf(file_pos, bill_record, receipt[i].phone,receipt[i].id[0],receipt[i].id[1],receipt[i].id[2],receipt[i].id[3],receipt[i].id[4],receipt[i].id[5],receipt[i].id[6],receipt[i].id[7],receipt[i].id[8],receipt[i].id[9],receipt[i].id[10],receipt[i].id[11],receipt[i].id[12],receipt[i].id[13],receipt[i].id[14],receipt[i].id[15],receipt[i].id[16],receipt[i].id[17],receipt[i].id[18],receipt[i].id[19],receipt[i].id[20],receipt[i].id[21],receipt[i].id[22],receipt[i].id[23],receipt[i].id[24],receipt[i].id[25],receipt[i].id[26],receipt[i].id[27],receipt[i].id[28],receipt[i].id[29],receipt[i].time,receipt[i].cash,receipt[i].change, receipt[i].card, receipt[i].coupon);
}
int main()
{
    srand(time(NULL));
    inventory();
    start();
    return 0;
}

