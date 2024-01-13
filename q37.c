int main() {
  int *p;
  init(&p);
  int *a = p; 
  int *b = p; 
  a += 4; 
  b += 31; 
  printf("%d, %d", *a, *b);
  return 0;
}