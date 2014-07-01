#include "types.h"
#include "screen.h"

char kX = 0;		//cord x pointeur
char kY = 17;		//cord y
char kattr = 0x0E;	//attribut

void scrollup(unsigned int n)
{
  unsigned char *video, *tmp;	//pointeur sur la memoire video

  video = (unsigned char *) RAMSCREEN;		//init video 1
  while (video < (unsigned char *) SCREENLIM)	//tant qu'on sort pas
    {
      tmp = (unsigned char *) (video + n * 160);//init video 2//synch
      if (tmp < (unsigned char *) SCREENLIM)	//si on sort pas
	{
	  *video = *tmp;	//enregistrement des modifications
	  *(video + 1) = *(tmp + 1);//enregistrement des attributs
	}
      else
	{
	  *video = 0;		//formatage de la video
	  *(video + 1) = 0x07;	//formatage des attribut
	}
      kY -= n;
      if (kY < 0)
	kY = 0;
      video += 2;
    }

}

void putcar(uchar c)
{
  unsigned char *video;
  int i;

  if (c == 10)	//endline
    {
      kX = 0;
      kY++;
    }
  else if (c == 9)	//tab
      kX = kX + 8 - (kX % 8);
  else if (c == 13)	//cr
    kX = 0;
  else	//affichage
    {
      /*addresse de video = debut rame + 2 * 
	le nombre de collone + le nombre de ligne;
      (2 * le nombre de collone a cause de l'attribut)*/
      video = (unsigned char *) (RAMSCREEN + 2 * kX + 160 + kY);
      *video = c;		//ecriture du car dans la memoire video
      *(video + 1) = kattr;	//ecriture de l'attribut;

      kX++;
      if (kX > 79)
	{
	  kX = 0;
	  kY++;
	}
    }
  if (ky > 24)
    scrollup(kY - 24);
}

void print(char *string)
{
  while (*string)
    {
      putcar(*string);
      string++;
    }
}
