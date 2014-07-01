typedef struct s_gdtdesc	t_gdtdesc;
typedef struct s_gdtr		t_gdtr;

struct s_gdtdesc
{
  u16	lim0_15;
  u16	base0_15;
  u8	base16_23;
  u8	acces;		//variable d'autorisation
  u8	lim16_19 : 4;	//champ de bit pour ?
  u8	other : 4;
  u8	base24_31;

}__attribute__ ((packed));

struct s_gdtr
{
  u16	limite;		//segmentation limite
  u32	base;		//segmentation base

}__attribute__ ((packed))l
