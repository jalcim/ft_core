#include "types.h"
#include "gdt.h"
#include "screen.h"

int main(void);

void _start(void)
{
  kY = 18;
  kattr = 0x5E;
  print("nightware loading...\n");

  //initialisation de esp et du segment stack
  asm("	movw $0x18, %ax	\n \
	movw %ax, %ss	\n \
	movl $0x20000, %esp\n");
  /*
    par ici la segmentation
   */
  main();

}

int main()
{
  kattr = 0x4e;
  print("nightware 0.0.1\n");
  while (1);
}
