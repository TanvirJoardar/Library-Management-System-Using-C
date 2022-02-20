#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct lib
{
    char category[20],name[20],author[20],issue[20];
    int page,id,quantity,b_quantity;
    float price;
};

int main (void)
{

    struct lib book[1000];
    char bname[20],del[10];
    int choice,i,j,n,count=0,flag=0;
    while(1)
    {
        system("cls");
        printf("\n\n\t\t\t\t===========================================================");
        printf("\n\t\t\t\t=============== Library Management System =================");
        printf("\n\t\t\t\t===========================================================\n\n\n");
        printf("\t\t\t\t\t[1]  ::: Add Books\n\n");
        printf("\t\t\t\t\t[2]  ::: Delete Books\n\n");
        printf("\t\t\t\t\t[3]  ::: Search Books\n\n");
        printf("\t\t\t\t\t[4]  ::: Issue Books\n\n");
        printf("\t\t\t\t\t[5]  ::: Return Books\n\n");
        printf("\t\t\t\t\t[6]  ::: View Book List\n\n");
        printf("\t\t\t\t\t[7]  ::: Update Books\n\n");
        printf("\t\t\t\t\t[8]  ::: Quite\n\n");
        printf("\n\t\t\t\t :::: Enter your Choice: ");
        scanf("%d",&choice);

        if(choice==8)
        {
            system("cls");
            printf("\n\n\n\t\t\t\t--------------------------------------------\n");
            printf("\n\t\t\t\t::::::::::: You Quit the Program :::::::::::\n");
            printf("\n\t\t\t\t--------------------------------------------\n\n");
            break;
        }

        if(choice==1)// Add Book Start
        {
            system("cls");
            printf("\n\t\t\t\t     ******** You Pressed: 1 ********\n");
            printf("\n\t\t\t============ How many Book you want to Add ??? ============\n");
            printf("\n\t\t\t\tQuantity : ");
            scanf("%d",&n);
            printf("\n\n\t\t\t\t******** You want to Add %d Books ********\n",n);
            n=n+count;

            for(i=count; i<n; i++)
            {
                printf("\n\n\t\t\t============================================================\n");
                printf("\t\t\t============== Enter Information For Book: %d ===============\n",i+1);
                printf("\t\t\t============================================================\n");
                printf("\n\t\t\t\t[::] Enter Category (Above 7 letters): ");
                fflush(stdin);
                gets(book[i].category);
                printf("\n\t\t\t\t[::] Enter Name (Above 7 letters): ");
                fflush(stdin);
                gets(book[i].name);
                printf("\n\t\t\t\t[::] Enter ID (4-7 numbers): ");
                scanf("%d",&book[i].id);
                printf("\n\t\t\t\t[::] Enter Author (Above 7 letters): ");
                fflush(stdin);
                gets(book[i].author);
                printf("\n\t\t\t\t[::] Enter Page (Above 3 numbers): ");
                scanf("%d",&book[i].page);
                printf("\n\t\t\t\t[::] Enter Price (Above 3 numbers): ");
                scanf("%f",&book[i].price);

                printf("\n\t\t\t\t[::] Book Quantity: ");// new copy
                scanf("%d",&book[i].quantity);
                book[i].b_quantity=book[i].quantity;

                printf("\n\t\t\t\t[::] Issue status (Yes/No): ");
                fflush(stdin);
                gets(book[i].issue);

                printf("\n\n\t\t\t\t\t****** Done Successfully ******\n");
                count++;
            }
            printf("\n\n\n\t\t\t Press any key for go to Main menu........");
            getch();

        }//Add Book End

        if(choice==2)// Delete Book Start
        {
            system("cls");
            printf("\n\n\t\t\t\t    *********** You Pressed: 2 ***********\n");

            printf("\n\n:::::::: Total books: %d ::::::::\n",count);// was n....
            printf("\n=============================================== Information For Book =================================================================");
            printf("\n======================================================================================================================================");
            printf("\nCategory\t\tName\t\tID\t\tAuthor\t\tPage\t\tPrice  \t\tQuantity  \tIssue status");
            printf("\n======================================================================================================================================");

            for(i=0; i<count; i++)
            {
                printf("\n%s",book[i].category);
                printf("\t\t%s",book[i].name);
                printf("\t%d",book[i].id);
                printf("\t\t%s",book[i].author);
                printf("\t%d",book[i].page);
                printf("\t\t%.2f",book[i].price);
                printf("  \t%d",book[i].quantity);// new copy
                printf(" of %d",book[i].b_quantity);
                printf("\t\t%s",book[i].issue);
            }

            while(1)
            {
                printf("\n\n\n\n\n\t\t\t\t============ Enter the Book Name for Delete: ============\n");
                printf("\n\t\t\t\tDelete Book Name : ");
                fflush(stdin);
                gets(bname);

                flag=0;
                for(i=0; i<count; i++)
                {
                    if(!strcmp(book[i].name,bname))
                    {
                        printf("\n\n\t\t\t\t    ===============================================");
                        printf("\n\t\t\t\t    ============= Delete Book Details =============");
                        printf("\n\t\t\t\t    ===============================================");
                        printf("\n\n\t\t\t\t\t  Book Category : %s",book[i].category);
                        printf("\n\n\t\t\t\t\t  Book Name : %s",book[i].name);
                        printf("\n\n\t\t\t\t\t  Book ID : %d",book[i].id);
                        printf("\n\n\t\t\t\t\t  Book Author : %s",book[i].author);
                        printf("\n\n\t\t\t\t\t  Book Pages : %d",book[i].page);
                        printf("\n\n\t\t\t\t\t  Book Price : %.2f",book[i].price);
                        printf("\n\n\t\t\t\t\t  Book quantity : %d",book[i].quantity);// new copy
                        printf(" of %d",book[i].b_quantity);
                        printf("\n\n\t\t\t\t\t  Issue status : %s",book[i].issue);

                        printf("\n\n\n\t\t\t\t    Are You Sure to Delete It ??? Type 'yes'/'no'\n");
                        printf("\n\t\t\t\t    Your Opinion : ");
                        gets(del);
                        if(!strcmp(del,"yes"))
                        {
                            for(j=i; j<n-1; j++)
                            {
                                book[j]=book[j+1];
                            }
                            count--;
                            printf("\n\n\t\t\t\t    ******** Successfully Deleted ********");
                            flag++;
                        }
                        else
                        {
                            flag++;
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("\n\n\t\t\t  ********** There is no book with this name...Please try again **********");
                }
                else
                    break;
            }
            printf("\n\n\n\t\t\t\t  Press any key for go to Main menu........");
            getch();
        }


        if(choice==3)// Search Book Start
        {
            system("cls");
            printf("\n\n\t\t\t\t\t     ******** You Pressed: 3 ********\n");
            while(1)
            {
                printf("\n\n\t\t\t\t============= Enter the Book Name for Search: =============\n");
                printf("\n\t\t\t\tBook Name : ");
                fflush(stdin);
                gets(bname);

                flag=0;
                for(i=0; i<count; i++)
                {
                    if(!strcmp(book[i].name,bname))
                    {
                        printf("\n\n\t\t\t\t    ===============================================");
                        printf("\n\t\t\t\t    ============ Searched Book Details ============");
                        printf("\n\t\t\t\t    ===============================================\n");
                        printf("\n\n\t\t\t\t\tBook Category : %s",book[i].category);
                        printf("\n\n\t\t\t\t\tBook Name : %s",book[i].name);
                        printf("\n\n\t\t\t\t\tBook ID : %d",book[i].id);
                        printf("\n\n\t\t\t\t\tBook Author : %s",book[i].author);
                        printf("\n\n\t\t\t\t\tBook Pages : %d",book[i].page);
                        printf("\n\n\t\t\t\t\tBook Price : %.2f",book[i].price);
                        printf("\n\n\t\t\t\t\tBook quantity : %d",book[i].quantity);// new copy
                        printf(" of %d",book[i].b_quantity);
                        printf("\n\n\t\t\t\t\tIssue status : %s",book[i].issue);

                        printf("\n\n\n\t\t\t\t\t******** Successfully Searched ********");
                        flag++;
                    }
                }
                if(flag==0)
                {
                    printf("\n\n\t\t\t  ********** There is no book with this name...Please try again **********\n");
                }
                else
                    break;
            }
            printf("\n\n\n\t\t\t\tPress any key for go to Main menu........");
            getch();

        }

        if(choice==4)// Issue Book Start
        {
            system("cls");
            printf("\n\n\t\t\t\t\t     ******** You Pressed: 4 ********\n");
            while(1)
            {
                printf("\n\n\t\t\t\t============= Enter the Book Name for Issue: =============\n");
                printf("\n\t\t\t\tBook Name : ");
                fflush(stdin);
                gets(bname);

                flag=0;
                for(i=0; i<count; i++)
                {
                    if(!strcmp(book[i].name,bname))
                    {
                        printf("\n\n\t\t\t\t    ===============================================");
                        printf("\n\t\t\t\t    ============== Issue Book Details =============");
                        printf("\n\t\t\t\t    ===============================================\n");
                        printf("\n\n\t\t\t\t\tBook Category : %s",book[i].category);
                        printf("\n\n\t\t\t\t\tBook Name : %s",book[i].name);
                        printf("\n\n\t\t\t\t\tBook ID : %d",book[i].id);
                        printf("\n\n\t\t\t\t\tBook Author : %s",book[i].author);
                        printf("\n\n\t\t\t\t\tBook Pages : %d",book[i].page);
                        printf("\n\n\t\t\t\t\tBook Price : %.2f",book[i].price);
                        printf("\n\n\t\t\t\t\tBook quantity : %d",book[i].quantity);// new copy
                        printf(" of %d",book[i].b_quantity);
                        printf("\n\n\t\t\t\t\tIssue status : %s",book[i].issue);
                        if(book[i].b_quantity==book[i].quantity)
                        {
                            printf("\n\n\n\t\t\t\t::::: Change issue status (Type 'Yes'): ");
                            fflush(stdin);
                            gets(book[i].issue);
                        }
                        printf("\n\n\n\t\t\t\t\t******** Successfully Issued ********");
                        book[i].quantity--;
                        flag++;
                    }
                }
                if(flag==0)
                {
                    printf("\n\n\t\t\t  ********** There is no book with this name...Please try again **********\n");
                }
                else
                    break;
            }
            printf("\n\n\n\t\t\t\tPress any key for go to Main menu........");
            getch();
        }

        if(choice==5)// Return Book Start
        {
            system("cls");
            printf("\n\n\t\t\t\t\t     ******** You Pressed: 5 ********\n");
            while(1)
            {
                printf("\n\n\t\t\t\t============= Enter the Book Name for Return: =============\n");
                printf("\n\t\t\t\tBook Name : ");
                fflush(stdin);
                gets(bname);

                flag=0;
                for(i=0; i<count; i++)
                {
                    if(!strcmp(book[i].name,bname))
                    {
                        printf("\n\n\t\t\t\t    ===============================================");
                        printf("\n\t\t\t\t    ============= Return Book Details =============");
                        printf("\n\t\t\t\t    ===============================================\n");
                        printf("\n\n\t\t\t\t\tBook Category : %s",book[i].category);
                        printf("\n\n\t\t\t\t\tBook Name : %s",book[i].name);
                        printf("\n\n\t\t\t\t\tBook ID : %d",book[i].id);
                        printf("\n\n\t\t\t\t\tBook Author : %s",book[i].author);
                        printf("\n\n\t\t\t\t\tBook Pages : %d",book[i].page);
                        printf("\n\n\t\t\t\t\tBook Price : %.2f",book[i].price);
                        printf("\n\n\t\t\t\t\tBook quantity : %d",book[i].quantity);// new copy
                        printf(" of %d",book[i].b_quantity);
                        printf("\n\n\t\t\t\t\tIssue status : %s",book[i].issue);
                        if(book[i].b_quantity-1==book[i].quantity)
                        {
                           printf("\n\n\n\t\t\t\t::::: Change issue status (Type 'No'): ");
                            fflush(stdin);
                            gets(book[i].issue);
                        }
                        printf("\n\n\n\t\t\t\t\t******** Successfully Returned ********");
                        book[i].quantity++;

                        flag++;
                    }
                }
                if(flag==0)
                {
                    printf("\n\n\t\t\t  ********** There is no book with this name...Please try again **********\n");
                }
                else
                    break;
            }
            printf("\n\n\n\t\t\t\tPress any key for go to Main menu........");
            getch();
        }



        if(choice==6)// View Book Start
        {
            system("cls");
            printf("\n\n\t\t\t\t*********** You Pressed: 6 ***********\n");
            printf("\n\n:::::::: Total books: %d ::::::::\n",count);// was n....
            printf("\n=============================================== Information For Book =================================================================");
            printf("\n======================================================================================================================================");
            printf("\nCategory\t\tName\t\tID\t\tAuthor\t\tPage\t\tPrice  \t\tQuantity  \tIssue status");
            printf("\n======================================================================================================================================");

            for(i=0; i<count; i++)
            {
                printf("\n%s",book[i].category);
                printf("\t\t%s",book[i].name);
                printf("\t%d",book[i].id);
                printf("\t\t%s",book[i].author);
                printf("\t%d",book[i].page);
                printf("\t\t%.2f",book[i].price);
                printf("  \t%d",book[i].quantity);// new copy
                printf(" of %d",book[i].b_quantity);// new copy
                printf("\t\t%s",book[i].issue);
            }
            printf("\n\n\nPress any key for go to Main menu........");
            getch();
        }
        printf("\n\n");

        if(choice==7)// Update Book Start
        {
            system("cls");
            printf("\n\n\t\t\t\t\t     ******** You Pressed: 7 ********\n");
            while(1)
            {
                printf("\n\n\t\t\t\t============= Enter the Book Name for Update: =============\n");
                printf("\n\t\t\t\tBook Name : ");
                fflush(stdin);
                gets(bname);

                flag=0;
                for(i=0; i<count; i++)
                {
                    if(!strcmp(book[i].name,bname))
                    {
                        printf("\n\n\t\t\t\t    ===============================================");
                        printf("\n\t\t\t\t    ============= Update Book Details =============");
                        printf("\n\t\t\t\t    ===============================================\n");
                        printf("\n\n\t\t\t\t\tBook Category : %s",book[i].category);
                        printf("\n\n\t\t\t\t\tBook Name : %s",book[i].name);
                        printf("\n\n\t\t\t\t\tBook ID : %d",book[i].id);
                        printf("\n\n\t\t\t\t\tBook Author : %s",book[i].author);
                        printf("\n\n\t\t\t\t\tBook Pages : %d",book[i].page);
                        printf("\n\n\t\t\t\t\tBook Price : %.2f",book[i].price);
                        printf("\n\n\t\t\t\t\tBook quantity : %d",book[i].quantity);// new copy
                        printf(" of %d",book[i].b_quantity);
                        printf("\n\n\t\t\t\t\tIssue status : %s",book[i].issue);

                        printf("\n\n\t\t\t\t============================================================");
                        printf("\n\t\t\t\t========== Update Information For Book: %s ==========",book[i].name);
                        printf("\n\t\t\t\t============================================================\n\n\n");
                        printf("\n\t\t\t\t\t[::] Enter Category (Above 7 letters): ");
                        fflush(stdin);
                        gets(book[i].category);
                        printf("\n\t\t\t\t\t[::] Enter Name (Above 7 letters): ");
                        fflush(stdin);
                        gets(book[i].name);
                        printf("\n\t\t\t\t\t[::] Enter ID (4-7 numbers): ");
                        scanf("%d",&book[i].id);
                        printf("\n\t\t\t\t\t[::] Enter Author (Above 7 letters): ");
                        fflush(stdin);
                        gets(book[i].author);
                        printf("\n\t\t\t\t\t[::] Enter Page (Above 3 numbers): ");
                        scanf("%d",&book[i].page);
                        printf("\n\t\t\t\t\t[::] Enter Price (Above 3 numbers): ");
                        scanf("%f",&book[i].price);

                        printf("\n\t\t\t\t\t[::] Book Quantity: ");// new copy
                        scanf("%d",&book[i].quantity);
                        book[i].b_quantity=book[i].quantity;

                        printf("\n\t\t\t\t\t[::] Issue status (yes/no): ");
                        fflush(stdin);
                        gets(book[i].issue);

                        printf("\n\n\t\t\t\t\t******** Successfully Updated ********");
                        flag++;
                    }
                }
                if(flag==0)
                {
                    printf("\n\n\t\t\t  ********** There is no book with this name...Please try again **********\n");
                }
                else
                    break;
            }
            printf("\n\n\n\t\t\t\tPress any key for go to Main menu........");
            getch();
        }
        printf("\n\n");
    }
    return 0;
}



