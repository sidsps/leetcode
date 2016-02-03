#include <stdio.h>
int maxArea(int* height, int heightSize);
int main(void)
{
    int height[] = {4, 14, 13, 12, 15, 60, 2, 5, 43, 34};
    int heightSize = 10;
    int max = maxArea(height, heightSize);
    printf("%d\n", max);
}
int maxArea(int* height, int heightSize) {

    int area, greatest_area = 0;

    for(int i = 0;i < heightSize - 1;i++)

    {

        for(int j = i + 1;j < heightSize;j++)

        {

            area = (j - i)*((height[i] < height[j])?height[i]:height[j]);

            if(area > greatest_area)

            {

                greatest_area = area;
                printf("%d ", greatest_area);
                printf("%d %d\n", i, j);

            }

        }

    }

    return greatest_area;

}
