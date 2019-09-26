void call_logs()
{
    printf("\n\n Opening..... \n\n\n\n");
    int call, dail;
    char mess[100];
    do
    {
        printf("\n\n CALL LOGS\n\n");
        printf("1.DAILED CALLS\n");
        printf("2.MISSED CALLS\n");
        printf("3.RECEIVED CALLS\n");
        printf("4.ALL CALLS\n");
        printf("5.DELETE CALL LOGS\n");
        printf("0.RERTURN TO MENU\n");
        printf("\nENTER OPTION:");
        scanf("%d",&call);
        switch(call)
        {
            case 1:
                printf("\n\n DAILED CALLS\n");
                printf("1. VIEW\n");
                printf("2. CALL\n");
                printf("3. SEND A MESSAGE\n");
                printf("4. DELETE\n");
                printf("\nENTER OPTION: ");
                scanf("%d",&dail);
                switch(dail)
                {
                    case 1:
                        printf("\nYOU CAN VIEW DAILED CALLS");
                        break;
                    case 2:
                        printf("\nDailing.........\n\n");
                        printf("CALL UNSUCCESSFUL\n");
                        break;
                    case 3:
                        printf("\nTYPE MESSAGE: ");
                        scanf("%s",&mess);
                        printf("\n Sending..........\n\n MESSAGE SENT");
                        break;
                    case 4:
                            printf("\nDELETED\n\n");
                            break;
                    default:
                        printf("\n INVALID INPUT \n\n");
                }
                break;
            case 2:
                printf("\n\n MISSED CALLS\n");
                printf("1. VIEW\n");
                printf("2. CALL\n");
                printf("3. SEND A MESSAGE\n");
                printf("4. DELETE\n");
                printf("\nENTER OPTION: ");
                scanf("%d",&dail);
                switch(dail)
                {
                    case 1:
                        printf("\nYOU CAN VIEW DAILED CALLS");
                        break;
                    case 2:
                        printf("\nDailing.........\n\n");
                        printf("CALL UNSUCCESSFUL\n");
                        break;
                    case 3:
                        printf("\nTYPE MESSAGE: ");
                        scanf("%s",&mess);
                        printf("\n Sending..........\n\n MESSAGE SENT");
                        break;
                    case 4:
                            printf("\nDELETED\n\n");
                            break;
                    default:
                        printf("\n INVALID INPUT \n\n");
                }
                break;
            case 3:
                printf("\n\n RECEIVED CALLS\n");
                printf("1. VIEW\n");
                printf("2. CALL\n");
                printf("3. SEND A MESSAGE\n");
                printf("4. DELETE\n");
                printf("0. RETURN TO MENU");
                printf("\nENTER OPTION: ");
                scanf("%d",&dail);
                switch(dail)
                {
                    case 1:
                        printf("\nYOU CAN VIEW DAILED CALLS");
                        break;
                    case 2:
                        printf("\nDailing.........\n\n");
                        printf("CALL UNSUCCESSFUL\n");
                        break;
                    case 3:
                        printf("\nTYPE MESSAGE: ");
                        scanf("%s",&mess);
                        printf("\n Sending..........\n\n MESSAGE SENT");
                        break;
                    case 4:
                            printf("\nDELETED\n\n");
                            break;
                    default:
                        printf("\n INVALID INPUT \n\n");
                }
                break;
            case 4:
                printf("\n\n ALL CALLS\n");
                printf("1. VIEW\n");
                printf("2. SEND A MESSAGE\n");
                printf("3. DELETE\n");
                printf("\nENTER OPTION: ");
                scanf("%d",&dail);
                switch(dail)
                {
                    case 1:
                        printf("\nYOU CAN VIEW DAILED CALLS");
                        break;
                    case 2:
                        printf("\nTYPE MESSAGE: ");
                        scanf("%s",&mess);
                        printf("\n Sending..........\n\n MESSAGE SENT");
                        break;
                    case 3:
                            printf("\nDELETED\n\n");
                            break;
                    default:
                        printf("\n INVALID INPUT \n\n");
                }
                break;
            case 0:
                printf("\n\nRETURNING...............\n\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT\n\n");
        }
    }while(call!=0);
}

