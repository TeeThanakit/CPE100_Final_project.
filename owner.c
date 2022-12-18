int AddProduct(int *temp)
{
    temp++;
    printf("Enter Product Name : ");
    scanf("%s", Product[temp].name);
    printf("Enter Product Type \n0.Drink \n1.Appetizer \n2.Main course \n3.Desert\nPlease Type : ");
    scanf("%d", &Product[temp].type);

    printf("Enter Product Cost : ");
    scanf("%f", &Product[temp].cost);
    if(Product[temp].cost<0)
    {
        printf("Product cost cannot less than 0\n");
        printf("Please enter product cost again:");
        scanf("%d", &Product[temp].cost);
    }

    printf("Enter Product Price : ");
    scanf("%f", &Product[temp].price);
    if(Product[temp].price<0)
    {
        printf("Product price cannot less than 0\n");
        printf("Please enter product price again:");
        scanf("%d", &Product[temp].price);
    }
    printf("Enter Product Quantity : ");
    scanf("%d", &Product[temp].stock);
    if(Product[temp].stock<0)
    {
        printf("Product quantity cannot less than 0\n");
        printf("Please enter product quantity again:");
        scanf("%d", &Product[temp].stock);
    }
    printf("New Product has been Added!\n Press 1 to add more else press other number");
    scanf("%d", &i);
    if (i == 1)
        AddProduct();
    else
        owner();
}
int Stock()
{
    for (int x = 0; x <= temp; x++)
    {
        if(strlen(Product[x].name)<=6)
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
    printf("Exit Please Type 0\n");
    printf("Edit Stock Please Type 9\n");
    scanf("%d", &i);
    if (i == 0)
        owner();
    else if (i == 9)
        EditProduct();
    else
        printf("Type again"), Stock();
}

int EditProduct()
{
    for (int x = 0; x <= temp; x++)
    {
        printf("ID %d:%s\n", x, Product[x].name);
    }
    printf("Exit Please type -1\n");
    printf("Select Product ID : ");
    scanf("%d", &i);
    if (i == -1)
        owner();
    EditProduct2(i);
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
        printf("Enter Product Type \n0.Drink \n1.Appetizer \n2.Main course \n3.Desert\nPlease Type : "), scanf("%d", &Product[i].type), EditProduct2(i);
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
}

int owner()
{
    printf("Menu\n1.Add Product\n2.Stock\n3.Finance\n4.Edit Product\n5.Return\nPlease Select : ");
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
        start();
    else
        ("Please Input again\n"), owner();
}
int inventory()
{
    strcpy(Product[0].name, "Steak");
    Product[0].type = 2;
    Product[0].id = 0;
    Product[0].cost = 5;
    Product[0].price = 14;
    Product[0].stock = 10;
    strcpy(Product[1].name, "Onion Ring");
    Product[1].type = 1;
    Product[1].id = 1;
    Product[1].cost = 1.2;
    Product[1].price = 6;
    Product[1].stock = 20;
    strcpy(Product[2].name, "Ice Cream");
    Product[2].type = 3;
    Product[2].id = 2;
    Product[2].cost = 1;
    Product[2].price = 5;
    Product[2].stock = 20;
    strcpy(Product[3].name, "Mineral Water");
    Product[3].type = 0;
    Product[3].id = 3;
    Product[3].cost = 0.8;
    Product[3].price = 2.5;
    Product[3].stock = 30;
    strcpy(Product[4].name, "Tea");
    Product[4].type = 0;
    Product[4].id = 4;
    Product[4].cost = 1;
    Product[4].price = 3;
    Product[4].stock = 30;
    strcpy(Product[5].name, "Spaghetti");
    Product[5].type = 2;
    Product[5].id = 5;
    Product[5].cost = 4;
    Product[5].price = 12;
    Product[5].stock = 10;
    strcpy(Product[6].name, "Jelly");
    Product[6].type = 3;
    Product[6].id = 6;
    Product[6].cost = 1.5;
    Product[6].price = 5;
    Product[6].stock = 20;
    strcpy(Product[7].name, "French Fried");
    Product[7].type = 1;
    Product[7].id = 7;
    Product[7].cost = 0.5;
    Product[7].price = 4;
    Product[7].stock = 20;
    strcpy(Product[8].name, "Coffee");
    Product[8].type = 0;
    Product[8].id = 9;
    Product[8].cost = 1;
    Product[8].price = 3.5;
    Product[8].stock = 20;
    strcpy(Product[9].name, "Pizza");
    Product[9].type = 2;
    Product[9].id = 9;
    Product[9].cost = 5;
    Product[9].price = 18;
    Product[9].stock = 8;
    strcpy(Product[10].name, "Hashbrown");
    Product[10].type = 1;
    Product[10].id = 10;
    Product[10].cost = 0.6;
    Product[10].price = 4.5;
    Product[10].stock = 17;
}
