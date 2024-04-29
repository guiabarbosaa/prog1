#include <stdio.h>

int Area(int x1, int y1, int x2, int y2) 
{
    int lado1 = x2 - x1;
    int lado2 = y2 - y1;
    
    return lado1 * lado2;
}

int AreaTotal(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2) 
{
    int result1, result2, diferenca1, diferenca2, novaArea;
	
    result1 = Area(r1_x1, r1_y1, r1_x2, r1_y2);
    result2 = Area(r2_x1, r2_y1, r2_x2, r2_y2);

    if (r1_y2 <= r2_y1 || r1_x2 <= r2_x1) {
        return result1 + result2;
    } else {
        diferenca1 = r1_x2 - r2_x1;
        diferenca2 = r1_y2 - r2_y1;
        novaArea = diferenca1 * diferenca2;

        return result1 + result2 - novaArea;
    }
}

int main() 
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int total;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

    total = AreaTotal(x1, y1, x2, y2, x3, y3, x4, y4);

    printf("RESP:%d", total);

    return 0;
}

