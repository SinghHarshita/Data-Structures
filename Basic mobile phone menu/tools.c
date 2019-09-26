void tools()
{
    printf("\n\n Opening..... \n\n\n\n");
    int tool;
    do
    {
       printf("\n\n TOOLS\n\n");
       printf("1. CLOCK\n");
       printf("2. ALARAM\n");
       printf("3. CALCULATOR\n");
       printf("4. CALENDER\n");
       printf("0. RETURN TO  MENU\n");
       printf("\nENTER OPTION: ");
       scanf("%d",&tool);
       switch(tool)
       {
            case 1:
                printf("\nSWITCHED TO CLOCK\n");
                break;
            case 2:
                printf("\nSET ALARAM/UNSET ALARAM\n");
                break;
            case 3:
                printf("\nSWITCHED TO CALCULATOR\n");
                break;
            case 4:
                printf("\nSWITCHED TO CALENDER\n");
                break;
            case 0:
                printf("\n\nRETURNING..........\n\n\n\n");
                break;
            default:
                printf("\nINVALID INPUT\n\n");
       }
    }while(tool!=0);
}
