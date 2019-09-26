void multimedia()
{
    printf("\n\n Opening..... \n\n\n\n");
    int media;
    do
    {
        printf("\n\n  MULTIMEDIA\n\n");
        printf("1. SOUND RECORDER\n");
        printf("2. FM RADIO\n");
        printf("0. RETURN TO MENU");
        printf("\nENTER OPTION:");
        scanf("%d",&media);
        switch(media)
        {
            case 1:
                printf("\nSWITCHED TO SOUND RECORDER\n");
                break;
            case 2:
                printf("\nSWITCHED TO FM RADIO\n");
                break;
            case 0:
                printf("\n\nRETURNING..........\n\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT\n\n");
        }
    }while(media!=0);
}

