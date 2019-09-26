void inbox()
{
    printf("\n\n Opening..... \n\n\n\n");
    int i,s;
    do
    {
        printf("\n\n INBOX\n\n");
        printf("1. VIEW MESSAGES\n");
        printf("2. FORWARD\n");
        printf("3. SORT BY\n");
        printf("4. DELETE FORWARD MESSAGES\n");
        printf("5. CLEAR INBOX\n");
        printf("6. BACK TO MESSAGES\n");
        printf("\n ENETER THE OPTION: ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                printf("\n\nOPENING MESSAGES TO VIEW............\n\n\n");
                printf("MESSAGES TO VIEW\n");
                break;
            case 2:
                printf("\n\n FORWARD MESSSAGES\n");
                break;
            case 3:
                   printf("\n\nSORT BY:\n\n");
                   printf("1. DATE\n");
                   printf("2. SENDER\n");
                   printf("3. SUBJECT\n");
                   printf("4. UNREAD/READ\n");
                   printf("5. MESSAGE SIZE\n");
                   printf("\nENTER CHOICE:");
                   scanf("%d",&s);
                   switch(s)
                   {
                        case 1:
                            printf("\n\n MESSAGES SORTED BY DATE\n\n\n");
                            break;
                        case 2:
                            printf("\n\n MESSAGES SORTED BY SENDER\n\n\n");
                            break;
                        case 3:
                            printf("\n\n MESSAGES SORTED BY SUBJECT\n\n\n");
                            break;
                        case 4:
                            printf("\n\n MESSAGES SORTED BY UNREAD/READ\n\n\n");
                            break;
                        case 5:
                            printf("\n\n MESSAGES SORTED BY MESSAGE SIZE\n\n\n");
                            break;
                        default:
                            printf("\n\n INVALID INPUT\n\n\n");
                   }
               break;
            case 4:
                printf("\n DELETED ALL FORWARDED MESSAGES\n\n");
                break;
            case 5:
                printf("\n\n INBOX CLEARED \n\n\n");
                break;
            case 6:
                printf("\n\nGoing Back.............\n\n\n");
                break;

            default:
                printf("\nINAVLID INPUT!!!\n\n\n");
        }
    }while(i!=6);

}
