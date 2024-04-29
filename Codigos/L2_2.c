#include <stdio.h>
int main() {
int x,y,z;
scanf("%d %d", &x, &y);

     if (x > y) {
     for (z = y-1; z < x; z++) {
     if (z % 3 == 0 || z % 4 == 0 || z % 7 == 0 ) {
     printf ("%d ", z);
    }
  }
}
     if (y > x) {
     for (z = x+1; z < y; z++) {
     if (z % 3 == 0 || z % 4 == 0 || z % 7 == 0 ) {
     printf ("%d ", z);
  }    
 }   
}
return 0;
} 
