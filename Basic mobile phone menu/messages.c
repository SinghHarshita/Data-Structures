void messages()
{
    printf("\n\n Opening..... \n\n\n\n");
    int m;
    do
    {
        printf("\n\n MESSAGES\n");
        printf("1. COMPOSE\n");
        printf("2. INBOX\n");
        printf("3. DRAFTS\n");
        printf("4. OUTBOX\n");
        printf("5. SENT BOX\n");
        printf("0. RETURN TO MENU\n");
        printf("\n\nENTER OPTION:");
        scanf("%d",&m);
        switch(m)
        {
            case 1:
                printf("\n\nCOMPOSE YOUR MESSAGE\n\n\n");
                break;
            case 2:
                inbox();
                break;
            case 3:
                drafts();
                break;
            case 4:
                printf("\n\nOPENING......\n\n\n");
                printf(" SWITCHED TO OUTBOX \n");
                break;
            case 5:
                printf("\n\nOPENING.......\n\n\n");
                printf("  SWITCHED TO SENT BOX \n");
                break;
            case 0:
                printf("\n\nRETURNING.......\n\n\n\n");
                break;
            default:
                printf("INVALID INPUT!");
        }
    }while(m!=0);
}
