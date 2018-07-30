/*
  the_horse -- display an animated horse on Arduboy
*/
#include <Arduboy2.h>

Arduboy2 arduboy;
Sprites sprites;

/* Images adapted from the public domain image set "The Horse in Motion" by Eadweard Maybridge */

const unsigned char PROGMEM the_horse[] =
{
/* width, height */
100, 64,

/* frame 01 */
0xea, 0xfc, 0xfe, 0xf6, 0xee, 0xfc, 0xfc, 0xfe, 0xfe, 0xf8, 0xfc, 0xfa, 0xfc, 0xfe, 0xfe, 0xf8, 0xfe, 0xdc, 0xf4, 0xfa, 0xfc, 0xfc, 0xfc, 0xfa, 0xbc, 0xfc, 0xfe, 0x78, 0xfe, 0xfc, 0xf8, 0xfc, 0xf6, 0xec, 0xfa, 0xfc, 0xf8, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfa, 0xfc, 0xfc, 0xfc, 0xfe, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xe8, 0xfe, 0xfa, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfe, 0xf8, 0xfe, 0xfc, 0xfc, 0xfe, 0xfa, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xc0, 0x00, 
0x6b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x15, 0x01, 0x00, 0xe0, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x56, 0x00, 
0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x03, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x9e, 0xbf, 0x3f, 0x7f, 0x3f, 0x1f, 0x0f, 0x0f, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d, 0x00, 
0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1f, 0x0d, 0x0f, 0x0f, 0x8f, 0x4f, 0x07, 0x06, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xeb, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0x7f, 0xff, 0xfe, 0x70, 0xf0, 0xe0, 0xe1, 0xf0, 0xe0, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0x1c, 0x1e, 0x3f, 0x3f, 0x19, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x75, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xbf, 0xff, 0x7f, 0xef, 0xff, 0xff, 0x7f, 0x7f, 0x01, 0x00, 0x7c, 0xfc, 0xf8, 0xf0, 0xe0, 0xcc, 0x1c, 0x3c, 0x3e, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7e, 0xfe, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0x3c, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d, 0x00, 
0x00, 0xd7, 0x5f, 0xff, 0xd7, 0x7f, 0xd7, 0x7f, 0x5f, 0xf7, 0xdf, 0x57, 0xdf, 0x77, 0xff, 0x57, 0x7f, 0xdf, 0x55, 0xf7, 0xe7, 0x7f, 0xf4, 0x5c, 0xfc, 0x56, 0xdf, 0x77, 0xd7, 0x7f, 0xf7, 0xcf, 0x5f, 0xf7, 0x78, 0xd0, 0xd5, 0x7f, 0xff, 0xdf, 0x77, 0xdf, 0x77, 0xff, 0xfe, 0xd6, 0xfe, 0xdc, 0x7c, 0xf9, 0xfd, 0x79, 0xfb, 0x11, 0x00, 0x60, 0x7e, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xf7, 0xff, 0x7f, 0xff, 0xdf, 0x7f, 0xff, 0xdf, 0xff, 0x7f, 0xff, 0xf7, 0x5f, 0xff, 0xdf, 0xdf, 0x7f, 0xff, 0x7f, 0x7f, 0xff, 0x7f, 0xf7, 0xff, 0x7f, 0xd7, 0xff, 0xff, 0x7f, 0xf7, 0x5f, 0x7f, 0xff, 0x05, 0x00, 
0x00, 0xeb, 0x79, 0xff, 0xfd, 0xef, 0x7d, 0xdb, 0x7d, 0xef, 0xff, 0xb5, 0xfd, 0x7b, 0xef, 0xf9, 0xe3, 0xe7, 0xbe, 0xf3, 0xe8, 0xfb, 0xfb, 0xf3, 0xf9, 0xfb, 0xb9, 0xf9, 0xf9, 0xb3, 0xf1, 0xfb, 0x7b, 0xf1, 0xf9, 0xe3, 0x7b, 0xf1, 0xf3, 0xb9, 0xb1, 0xfb, 0xf3, 0xf9, 0xf3, 0xf1, 0xf9, 0xf9, 0xf9, 0xf3, 0xf9, 0xf9, 0xf3, 0xf8, 0xf8, 0xf8, 0xf0, 0xf9, 0xf3, 0xf9, 0xf9, 0xfb, 0xf3, 0xfb, 0xf9, 0xf9, 0xf9, 0xf9, 0xf1, 0xf9, 0xf9, 0xf9, 0xf9, 0xfb, 0xf9, 0xf3, 0xf9, 0xfb, 0xfb, 0xf9, 0xfb, 0xf9, 0x7b, 0xf9, 0xfb, 0xf9, 0xfb, 0xfb, 0xff, 0xfb, 0x7b, 0xf9, 0xfd, 0xfb, 0xff, 0x7d, 0xff, 0xff, 0x10, 0x00, 

/* frame 02 */
0x00, 0x00, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfc, 0xe6, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfa, 0xfc, 0xfe, 0xfe, 0xf4, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfa, 0xf8, 0xfe, 0xfe, 0xfc, 0xfa, 0xfe, 0xf8, 0xfe, 0xfe, 0xfc, 0xfe, 0xfa, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfc, 0x7e, 0x7e, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xf8, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xde, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xe6, 0xf4, 0xfe, 0xfe, 0xfc, 0xfc, 0xda, 0xfc, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xec, 0xf6, 0xfa, 0x48, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x1d, 0x00, 0x00, 0x00, 0xf0, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf7, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 
0x00, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x03, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc8, 0x9d, 0x3f, 0x3f, 0x3f, 0x2f, 0x0d, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5b, 
0x00, 0x04, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x9f, 0x9f, 0x9f, 0x8f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xff, 0xfd, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xff, 0xff, 0xff, 0xfb, 0xef, 0xff, 0xff, 0xff, 0x24, 
0x00, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0xc1, 0xc1, 0xc1, 0xc1, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xf0, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x82, 
0x00, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf1, 0xf0, 0xe0, 0xcc, 0xce, 0xde, 0x14, 0x00, 0x00, 0x9c, 0xbf, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xfe, 0x7e, 0x0c, 0x00, 0x00, 0x70, 0xf8, 0x78, 0xf8, 0x70, 0x70, 0x23, 0x0f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xdf, 0xff, 0xff, 0xfb, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x40, 
0x00, 0x00, 0x7f, 0xff, 0xdf, 0xff, 0x7f, 0xf7, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0xf7, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xff, 0xff, 0x7f, 0xf3, 0xf3, 0xf2, 0xf0, 0x70, 0xd1, 0xf3, 0xf3, 0xf9, 0xf9, 0xf8, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0xdf, 0xff, 0x7f, 0xdf, 0x5f, 0xff, 0xf7, 0x7f, 0xdf, 0x7f, 0xd7, 0xff, 0xdf, 0x77, 0xf7, 0x5f, 0xdf, 0x77, 0xf6, 0x5f, 0xfd, 0xd7, 0x57, 0xff, 0x77, 0xff, 0xff, 0x00, 
0x00, 0x00, 0xfd, 0xff, 0xfd, 0xff, 0xfd, 0xf9, 0xf9, 0xdd, 0xf9, 0xff, 0xfd, 0xff, 0xff, 0xfd, 0xfd, 0xfb, 0xe3, 0xff, 0xff, 0xfd, 0xfb, 0xfd, 0xfb, 0xfd, 0xff, 0xfd, 0xfd, 0xfb, 0xfd, 0xfb, 0xfb, 0xf9, 0xfb, 0xfd, 0xff, 0xf9, 0xf9, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xfb, 0xfd, 0xfb, 0xfd, 0xfd, 0xfd, 0xff, 0xf9, 0xfd, 0xfb, 0xfd, 0xfb, 0xfd, 0xfb, 0xfd, 0xfd, 0xff, 0xfd, 0xff, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xf9, 0xfd, 0xfd, 0xfd, 0xf9, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xdd, 0xfd, 0xdd, 0xfd, 0xfd, 0xb9, 0xfc, 0xdd, 0xfd, 0x7d, 0xe5, 0xfd, 0xfd, 0xbd, 0xfd, 0xfd, 0xdf, 0xfd, 0xff, 0xff, 0x00, 

/* frame 03 */
0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfc, 0xee, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfe, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xfa, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xf6, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfc, 0x66, 0x78, 0xfe, 0xfe, 0xfc, 0xfe, 0xf6, 0xfe, 0xfc, 0xfe, 0xfc, 0xfa, 0xfe, 0xf6, 0xee, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0xfa, 0xfc, 0xfe, 0xfe, 0xfe, 0xf6, 0xfe, 0xfc, 0xf6, 0xfe, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfe, 
0x00, 0x00, 0xa9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x0f, 0x00, 0x00, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0xda, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x8c, 0x9e, 0x3f, 0x3f, 0x3f, 0x3f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xbf, 0xf7, 0xff, 0xfb, 0xdf, 0xfb, 0xff, 0xdf, 
0x00, 0x00, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x9f, 0x9f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x01, 0x03, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xff, 0xfd, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xfb, 0x7d, 0xff, 0xdf, 0xfb, 0x7f, 0xf7, 0xfe, 0xff, 0xff, 
0x00, 0x00, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xe1, 0xc3, 0xe3, 0xe1, 0xe1, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfe, 0xff, 0xff, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xeb, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x66, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xe3, 0xe0, 0xe8, 0xcc, 0xce, 0xc8, 0xc0, 0x00, 0x0f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0x90, 0x00, 0xc0, 0xf8, 0xfc, 0xfc, 0x3c, 0x7c, 0x7c, 0x7c, 0x38, 0xd8, 0xc1, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 
0x00, 0x00, 0x11, 0xdf, 0x57, 0xef, 0x5b, 0x7f, 0xdf, 0x79, 0xdf, 0x7f, 0xdf, 0x77, 0xfb, 0x5f, 0xdf, 0x77, 0xff, 0xdf, 0x7f, 0xdf, 0xf7, 0x7f, 0xff, 0x5f, 0xff, 0xff, 0x7f, 0xdf, 0xf7, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xfe, 0xfe, 0xfe, 0xf8, 0xf8, 0xfd, 0xf8, 0xf8, 0xfc, 0xff, 0xff, 0x7f, 0xff, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0x7f, 0xff, 0x7f, 0xff, 0xff, 0xd7, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x7b, 0x77, 0xff, 0xf7, 0x7f, 0xdb, 0xff, 0x7f, 0xdf, 0x57, 0xfb, 0x7f, 0xf7, 0x77, 0xdf, 0x7f, 0xff, 
0x00, 0x00, 0x28, 0x55, 0x5c, 0xfd, 0x6e, 0x75, 0xbd, 0xfe, 0xed, 0xfd, 0xbd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xf7, 0xf1, 0xfd, 0xff, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xf9, 0xfd, 0xfd, 0xff, 0xfd, 0xfd, 0xff, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xff, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xf9, 0xfd, 0xfd, 0xfd, 0xf9, 0xf9, 0xfd, 0xfd, 0xf9, 0xf9, 0xf9, 0xf9, 0xfb, 0xf9, 0xfd, 0xf9, 0xf9, 0xf9, 0xfd, 0xfd, 0xfd, 0xfd, 0xf9, 0xfd, 0xf8, 0xfd, 0xfd, 0xfd, 0xf9, 0xfd, 0xf9, 0xf8, 0xfd, 0xfd, 0xf9, 0xfd, 0xf9, 0xf9, 0xfd, 0xf9, 0xfd, 0xfd, 0xf9, 0xf9, 0xfd, 0xfd, 0xf8, 0xfd, 0xf8, 0xfd, 0xfd, 

/* frame 04 */
0x00, 0x00, 0x00, 0x20, 0xee, 0xfe, 0xfc, 0xfe, 0xfc, 0xfe, 0xfe, 0xfe, 0xfc, 0xfe, 0xfc, 0xfe, 0xfe, 0xfe, 0xf6, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfc, 0xbe, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfe, 0xfe, 0xf4, 0xfc, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xfe, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xec, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xdc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xec, 0xfc, 0xe4, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xb4, 0xf8, 0xfc, 0xfc, 0xfc, 
0x00, 0x00, 0x00, 0x09, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x01, 0x00, 0xc0, 0xe0, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0x01, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x3c, 0x3f, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
0x00, 0x00, 0x00, 0x20, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x9f, 0x3f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0x7f, 0xff, 0xfe, 0xff, 0xfe, 0x7f, 0xff, 
0x00, 0x00, 0x00, 0x4a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x1f, 0x1f, 0x87, 0x83, 0xc1, 0xe0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x3d, 0x7f, 0x3f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xdf, 0xff, 0xff, 0xbf, 0xff, 0xff, 
0x00, 0x00, 0x00, 0xa4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xf8, 0xd0, 0x00, 0x00, 0x00, 0x80, 0x8e, 0x9e, 0x9e, 0x3c, 0x3c, 0x3c, 0x78, 0x7c, 0x78, 0xfc, 0xf8, 0xf8, 0xf8, 0xb8, 0x38, 0x38, 0x70, 0x70, 0x70, 0x60, 0x04, 0x8c, 0xdc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0x00, 0x3d, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xfd, 0xdf, 0xfe, 0xef, 0xff, 0xff, 0xff, 0xbf, 0xff, 
0x00, 0x00, 0x00, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xf7, 0xff, 0xff, 0xdf, 0xff, 0x77, 0xff, 0xff, 0xb7, 0xdf, 0xf7, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xbf, 0xbf, 0xff, 0xe7, 0xbf, 0xff, 0xf7, 0xef, 0xbf, 0xbf, 0xef, 0xfc, 0xfc, 0xf8, 0xf1, 0xe3, 0x87, 0x87, 0x1f, 0x3f, 0x3f, 0x5e, 0xfe, 0x9e, 0xfc, 0xb8, 0xfc, 0xef, 0xbf, 0xbf, 0xfe, 0xde, 0xfe, 0x7e, 0xff, 0x5f, 0xff, 0xdf, 0xff, 0xff, 0x7f, 0xff, 0xdc, 0xf8, 0xbf, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xff, 0x7f, 0x77, 0xff, 0xe7, 0xff, 0xf7, 0x7d, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x6b, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf3, 0xeb, 0xff, 0xfe, 0xfa, 0xff, 0xfa, 0xff, 0xfb, 0xfa, 0xfb, 0xf6, 0xd8, 0xff, 0xfb, 0xfb, 0xfe, 0xfb, 0xda, 0xfb, 0xfb, 0xfb, 0xfb, 0xfd, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xf3, 0xfb, 0xfb, 0xfb, 0xf8, 0xf8, 0xf0, 0xfa, 0xeb, 0xfb, 0xf9, 0xfb, 0xf9, 0xfb, 0xfb, 0xfd, 0xfb, 0xfa, 0xf9, 0xff, 0xf9, 0xf9, 0xfd, 0xf9, 0xfd, 0xfd, 0xf9, 0xfb, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xfe, 
};


int frame;

void setup() {
      arduboy.begin();
        arduboy.setFrameRate(4);
  frame = 0;
  
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();    
  arduboy.fillRect(0, 0, 14, 64, WHITE);    
  sprites.drawSelfMasked(14, 0, the_horse, frame);
  arduboy.fillRect(114, 0, 14, 64, WHITE);
  
  frame++;
  if (frame > 3)
    frame = 0;

  arduboy.display();
}
