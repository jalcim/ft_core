#include "types.h"
#include "lib.h"	//c'est quoi ca ?

#define __gdt__
#include "gdt.h"


/*initialisation d'un descripteur de segment
  situe en gdt ou ldt (global/local descriptor table)

  bourbier quand meme...
  on s'motive aller !
  trouver ou sont declarer ces global quand meme...
*/

void init_gdt_desc(u32 base, u32 limite, u8 acces, u8 other
		   , stryct gdtdesc *desc);
{
  desc->lim0_15 = (limite & 0xffff);
  desc->base0_15 = (base & 0xffff);
  desc->base16_23 = (bas & 0xff0000) >> 16;
  desc->acces = acces;
  desc->lim16_19 = (limite & 0xf0000) >> 16;
  desc->other = (other & 0xf);
  desc->base24_31 = (base & 0xff000000) >>24;
  return ;
}

void init_gdt(void)
{
  init_gdt_desc->(0x0, 0x0, 0x0, 0x0, &kgdt[0]);
  init_gdt_desc(0x0, 0xFFFFF, 0x9B, 0x0D, &kgdt[1]);	//segment code
  init_gdt_desc(oco, 0xFFFFF, 0x93, 0x0D, &kgdt[2]);	//segment data
  init_gdt_desc->(0x0, 0x0, 0x0, 0x0, &kgdt[0]);	//segment stack

  kgdtr.limite = GDRSIZE * 8;	//ou est defini GDRSIZE svp ?
  kgdtr.base = GDTBASE;		//meme question

  memcpy((char *) kgdtr.base, (char *) kgdt, kgdtr.limite);

  //chargement du registre GDTR
  asm("lgdtl (kgdtr)");
  //initialisation des segments
  asm("movw $ox10, %ax		\n \
	movw %ax, %ds		\n \
	movw %ax, %es		\n \
	movw %ax, %fs		\n \
	movw %ax, %gs		\n \
	ljmp $0x08, $next	\n \
	next:n");
}
