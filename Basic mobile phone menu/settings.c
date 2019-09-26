void settings()
{
    printf("\n\n Opening..... \n\n\n\n");
    int set,j;
    char l;
    do
    {
        printf("\n\n SETTINGS\n\n");
        printf("1. DISPLAY SETTINGS\n");
        printf("2. PROFILES\n");
        printf("3. PHONE SETTINGS\n");
        printf("4. SECURITY SETTINGS\n");
        printf("5. CALL SETTINGS\n");
        printf("6. NETWORK SETTINGS\n");
        printf("7. RESTORE FACTORY\n");
        printf("0. RETURN TO MENU");
        printf("\nENTER OPTION:");
        scanf("%d", &set);
        switch(set)
        {
            case 1:
                printf("\n  DISPLAY SETTINGS \n\n");
                printf("1. SET WALLPAPER\n");
                printf("2. SHOW DATE AND TIME:     on/off\n");
                printf("3. SHOW OPERATOR NAME:      yes/no\n");
                break;
            case 2:
                printf("\n PROFILES\n\n");
                printf("1. General\n");
                printf("2. Silent\n");
                printf("3. Meeting\n");
                printf("4. Outdoor\n");
                break;
            case 3:
                printf("\n PHONE SETTINGS \n\n");
                printf("1. SET DATE\n");
                printf("2. SET TIME\n");
                printf("3. LANGUAGE SETTINGS\n");
                printf("4. PREFERRED INPUT\n");
                printf("\n ENTER OPTION:");
                scanf("%d",&j);
                switch(j)
                {
                    case 1:
                        printf("\nDATE IS SETTED\n\n");
                        break;
                    case 2:
                        printf("\n TIME IS SETTED\n\n");
                        break;
                    case 3:
                        printf("\n LANGUAGE SETTINGS\n");
                        printf("\na. ENGLISH\n");
                        printf("b. HINDI\n");
                        printf("ENTER CHOICE:");
                        scanf(" %c",&l);
                        switch(l)
                        {
                            case 'a':
                            case 'A':
                                printf("\nLANGUAGE IS SET TO ENGLISH\n");
                                break;
                            case 'b':
                            case 'B':
                                printf("\nLANGUAGE IS SET TO HINDI\n");
                                break;
                            default:
                                printf("\nINVALID INPUT\n");
                        }
                        break;
                        case 4:
                                printf("\n PREFERRED OUTPUT\n");
                                printf("1.ABC\n");
                                printf("2.abc\n");
                                printf("3.Abc\n");
                                break;
                        default:
                            printf("\nINVALID INPUT\n");
                }
                break;
            case 4:
                    printf("\n SWITCHED TO SECURITY SETTINGS\n\n");
                    printf("");
                    break;
            case 5:
                printf("\n SWITCHED TO CALL SETTINGS\n\n");
                break;
            case 6:
                printf("\n NETWORK SETTINGS\n");
                printf("1.BLUETOOTH:            ON/OFF\n");
                printf("2.NETWORK MODE:  AUTO-CONNECT/MANUAL\n");
                break;
            case 7:
                printf("\n\nRestoring...........\n\n");
                printf("PHONE RESTORED\n\n");
                break;
            case 0:
                printf("\n\nRETURNING..........\n\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT\n\n");
            }
    }while(set!=0);
}

