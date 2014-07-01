extern void scrollup(unsigned int);
extern void print(char *);

extern ky;
extern kattr;

void _start(void)
{
  kY = 18;
  kattr = 0x5E;
  print("nigntmare 0.0.1\n");

  init_gdt();
  
}
