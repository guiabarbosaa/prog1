#include <stdio.h>
int main() {
int x,y,z;
scanf("%d %d", &x, &y);
printf ("RESP:");
     if (x > y) {
     for (z = y-1; z < x; z++) {
     if (z % 2 == 0) {
     printf ("%d ", z);
    }
  }
}
     if (y > x) {
     for (z = x+1; z < y; z++) {
     if (z % 2 == 0) {
     printf ("%d ", z);
  }    
 }   
}
return 0;
} 
