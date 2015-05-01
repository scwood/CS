#include <stdio.h>

int main() {
  int stuff = 1;
  while ((stuff <<= 1) < 100) {
  }
  printf("%d", stuff);
}
