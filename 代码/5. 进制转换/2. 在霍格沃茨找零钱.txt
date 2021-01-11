#include <stdio.h>

int main()
{
    int gY,sY,kY,gS,sS,kS;
    while(scanf("%d.%d.%d %d.%d.%d",&gY, &sY,&kY, &gS,&sS,&kS )!=EOF)
    {
        int sumY = gY*29*17 + sY*29+ kY;
        int sumS = gS*29*17 + sS*29 +kS;

        int change = sumS - sumY;
        if(change < 0)
        {
            printf("-");
            change = -change;
        }
        int galleon = change/(29*17);
        int sickle = (change%(29*17))/29;
        int kunt = change%29;
        printf("%d.%d.%d\n",galleon,sickle,kunt);

    }


    return 0;
}
