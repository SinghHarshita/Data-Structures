void contacts()
{
    printf("\n\n Opening..... \n\n\n\n");
    int c,e;
    do
    {
        printf("\n\n CONTACTS\n\n");
        printf("1. VIEW\n");
        printf("2. CREATE NEW CONTACT\n");
        printf("3. SEARCH\n");
        printf("4. DELETE CONTACTS\n");
        printf("0. RETURN TO MENU\n");
        printf("\nENTER OPTION:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("\nYOU CAN VIEW THE CONTACTS\n");
                break;
            case 2:
                printf("\nCREATE NEW CONTACT\n");
                printf("\n1.ENTER NAME\n");
                printf("2.ENTER SURNAME\n");
                printf("3.ENTER CONTACT NUMBER\n");
                break;
            case 3:
                printf("\nSEARCH CONTACT\n");
                printf("\nENTER CONTACT NAME\n");
                break;
            case 4:
                printf("\n\n DELETE");
                printf("\n1. DELETE ALL\n");
                printf("2. DELETE SELECTED\n");
                printf("\nENTER OPTION:");
                scanf("%d",&e);
                switch(e)
                {
                    case 1:
                        printf("\n\nDeleting..........\n\n\n");
                        printf("\nALL CONTACTS WERE DELETED\n");
                        break;
                    case 2:
                        printf("\n\nDeleting..........\n\n\n");
                        printf("\THE SELECTED CONTACTS WERE DELETED\n");
                        break;
                    default:
                        printf("\nINVALID INPUT\n\n\n\n");
                }
                break;
            case 0:
                printf("\n\nRETURNING..........\n\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT\n\n");
        }
    }while(c!=0);
}

