void games()
{
    int game;
    printf("\n\n Opening..... \n\n\n\n");
    do
    {
        printf("\n\n  GAMES\n\n");
        printf("1. SNAKE\n");
        printf("2. BRICK AND BALL\n");
        printf("3. RUNNER\n");
        printf("0. RETURN TO MENU\n");
        printf("\nENTER OPTION:");
        scanf("%d",&game);
        switch(game)
        {
            case 1:
                printf("\nPLAY SNAKE GAME\n\n");
                break;
            case 2:
                printf("\nPLAY BRICK AND BALL\n");
                break;
            case 3:
                printf("\nPLAY RUNNER \n");
                break;
            case 0:
                printf("\n\nRETURNING..........\n\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT\n\n");
        }
    }while(game!=0);
}

