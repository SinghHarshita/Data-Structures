void main()
{
    int n;
    do
    {
        printf("    MENU\n\n");
        printf("1. CONTACTS\n");
        printf("2. MESSAGES\n");
        printf("3. SETTINGS\n");
        printf("4. CALL LOGS\n");
        printf("5. TOOLS\n");
        printf("6. GAMES\n");
        printf("7. MULTIMEDIA\n");
        printf("0. EXIT\n\n");
        printf("ENETR OPTION:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                contacts();
                break;
            case 2:
                messages();
                break;
            case 3:
                settings();
                break;
            case 4:
                call_logs();
                break;
            case 5:
                tools();
                break;
            case 6:
                games();
                break;
            case 7:
                multimedia();
                break;
            case 0:
                printf("\n\nEXITING.........\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT!!!\n\n\n");
        }
    }while(n!=0);
}

