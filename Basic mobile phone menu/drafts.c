void drafts()
{
    printf("\n\n Opening..... \n\n\n\n");
    int d,s;
    do
    {
       printf("\n\n DRAFTS\n\n");
       printf("1. VIEW\n");
       printf("2. SEND\n");
       printf("3. EDIT\n");
       printf("4. DELETE ALL DRAFTS\n");
       printf("5. SORT BY\n");
       printf("6. BACK TO MESSAGES\n");
       printf("\nENTER OPTION:");
       scanf("%d",&d);
       switch(d)
       {
        case 1:
            printf("\nVIEW THE DRAFTS\n");
            break;
        case 2:
            printf("\nSEND THE DRAFTS\n");
            break;
            case 3:
                printf("\nEDIT THE DRAFTS\n");
                break;
            case 4:
                printf("\n\nDeleting..........\n\n\n");
                printf("DELETED ALL DRAFTS\n");
                break;
            case 5:
                printf("\nSORT BY:\n");
                printf("1. DATE\n");
                printf("2. SIZE\n");
                printf("3. SUBJECT\n");
                printf("Enter choice: ");
                scanf("%d",&s);
                switch(s)
                {
                    case 1:
                        printf("\nDRAFTS SORTED BY DATE!\n");
                        break;
                    case 2:
                        printf("\nDRAFS SORTED BY SIZE\n");
                        break;
                    case 3:
                        printf("\nDRAFTS SORTED BY SUBJECT\n");
                        break;
                    default:
                        printf("INVALID INPUT!");
                }
                break;
            case 6:
                printf("\n\nGOING BACK.........\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT!!!\n\n");

       }
    }while(d!=6);
}
