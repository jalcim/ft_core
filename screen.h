#ifndef __screen__
#define __screen__

# define RAMSCREEN	0xB8000 //memoire video
# define SIXESCREEN	0xFA0	//taille oct page
# define SCREENLIM	0xB8FA0	//fin de la memoire video

void	scrollup(unsigned int n);
void	putcar(uchar c);
void	print(char *string);

#endif
