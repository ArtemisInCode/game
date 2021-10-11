#include <stdint.h>
#include "maps.h"



Maps_t maps_init(void)
{
	uint16_t map1Array[20] = {0xffff, 0x8421, 0x8001, 0x8421, 0xfeff, 0x8281, 0x8291, 0x8291, 0xbe11, 0x809f, 0xba81, 0x9281, 0x9281, 0x92df, 0x9281, 0x9e81, 0x8281, 0x8281, 0x8281, 0xffff};
	uint16_t map2Array[20] = {0xffff, 0x8801, 0x8851, 0x8fd1, 0x8811, 0x8051, 0x8ffb, 0x8001, 0x8ffb, 0x8011, 0x8be1, 0x8a11, 0x8a11, 0x8bd1, 0x8851, 0x8fd1, 0x8811, 0x8011, 0x8811, 0xffff};
	uint16_t map3Array[20] = {0xffff, 0x8889, 0x8009, 0x8881, 0x8dff, 0x8481, 0x823d, 0x8185, 0xddf5, 0x9025, 0x9025, 0x9fe5, 0x8205, 0xfbff, 0x9001, 0x9001, 0x9001, 0x9001, 0x9001, 0xffff};
	static Maps_t maps;
	
	for(uint8_t i = 0; i<20; i++) {
		(maps.map1)[i] = map1Array[i];
		(maps.map2)[i] = map2Array[i];
		(maps.map3)[i] = map3Array[i]; 
	}
	return maps;
}

Map_collectables_t collectables_init(void)
{
	Map_collectables_t collectables;
	
	(collectables.map1).x1 = 2;
	(collectables.map1).y1 = 2;
	
	(collectables.map1).x2 = 7;
	(collectables.map1).y2 = 2;
	
	(collectables.map1).x3 = 11;
	(collectables.map1).y3 = 2;
	
	(collectables.map1).x4 = 6;
	(collectables.map1).y4 = 11;
	
	(collectables.map1).x5 = 17;
	(collectables.map1).y5 = 11;
	
	
	(collectables.map2).x1 = 2;
	(collectables.map2).y1 = 2;
	
	(collectables.map2).x2 = 1;
	(collectables.map2).y2 = 10;
	
	(collectables.map2).x3 = 10;
	(collectables.map2).y3 = 8;
	
	(collectables.map2).x4 = 14;
	(collectables.map2).y4 = 7;
	
	(collectables.map2).x5 = 17;
	(collectables.map2).y5 = 13;
	
	
	(collectables.map3).x1 = 1;
	(collectables.map3).y1 = 1;
	
	(collectables.map3).x2 = 12;
	(collectables.map3).y2 = 1;
	
	(collectables.map3).x3 = 10;
	(collectables.map3).y3 = 11;
	
	(collectables.map3).x4 = 12;
	(collectables.map3).y4 = 8;
	
	(collectables.map3).x5 = 18;
	(collectables.map3).y5 = 18;
	
	return collectables;
	
	

}

//{0xffff, 0x1248, 0x1008, 0x1248, 0xffef, 0x1828, 0x1928, 0x1928, 0x11eb, 0xf908, 0x18ab, 0x1829, 0x1829, 0xfd29, 0x1829, 0x18e9, 0x1828, 0x1828, 0x1828, 0xffff};
//{0xffff, 0x1088, 0x1588, 0x1df8, 0x1188, 0x1508, 0xbff8, 0x1008, 0xbff8, 0x1108, 0x1eb8, 0x11a8, 0x11a8, 0x1db8, 0x1588, 0x1df8, 0x1188, 0x1108, 0x1188, 0xffff};
//{0xffff, 0x9888, 0x9008, 0x1888, 0xff8d, 0x1848, 0xd328, 0x5818, 0x5fdd, 0x5209, 0x5209, 0x5ef9, 0x5028, 0xffbf, 0x1009, 0x1009, 0x1009, 0x1009, 0x1009, 0xffff}
