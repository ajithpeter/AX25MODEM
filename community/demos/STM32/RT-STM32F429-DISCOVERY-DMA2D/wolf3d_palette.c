#include <ch.h>
#include <hal.h>
#include <stm32_ltdc.h>

const ltdc_color_t wolf3d_palette[256] __attribute__((aligned(4))) = {
  0xFF000000,   /* 0x00 */
  0xFF0000A8,   /* 0x01 */
  0xFF00A800,   /* 0x02 */
  0xFF00A8A8,   /* 0x03 */
  0xFFA80000,   /* 0x04 */
  0xFFA800A8,   /* 0x05 */
  0xFFA85400,   /* 0x06 */
  0xFFA8A8A8,   /* 0x07 */
  0xFF545454,   /* 0x08 */
  0xFF5454FC,   /* 0x09 */
  0xFF54FC54,   /* 0x0A */
  0xFF54FCFC,   /* 0x0B */
  0xFFFC5454,   /* 0x0C */
  0xFFFC54FC,   /* 0x0D */
  0xFFFCFC54,   /* 0x0E */
  0xFFFCFCFC,   /* 0x0F */
  0xFFECECEC,   /* 0x10 */

  0xFFDCDCDC,   /* 0x11 */
  0xFFD0D0D0,   /* 0x12 */
  0xFFC0C0C0,   /* 0x13 */
  0xFFB4B4B4,   /* 0x14 */
  0xFFA8A8A8,   /* 0x15 */
  0xFF989898,   /* 0x16 */
  0xFF8C8C8C,   /* 0x17 */
  0xFF7C7C7C,   /* 0x18 */
  0xFF707070,   /* 0x19 */
  0xFF646464,   /* 0x1A */
  0xFF545454,   /* 0x1B */
  0xFF484848,   /* 0x1C */
  0xFF383838,   /* 0x1D */
  0xFF2C2C2C,   /* 0x1E */
  0xFF202020,   /* 0x1F */
  0xFFFC0000,   /* 0x20 */

  0xFFEC0000,   /* 0x21 */
  0xFFE00000,   /* 0x22 */
  0xFFD40000,   /* 0x23 */
  0xFFC80000,   /* 0x24 */
  0xFFBC0000,   /* 0x25 */
  0xFFB00000,   /* 0x26 */
  0xFFA40000,   /* 0x27 */
  0xFF980000,   /* 0x28 */
  0xFF880000,   /* 0x29 */
  0xFF7C0000,   /* 0x2A */
  0xFF700000,   /* 0x2B */
  0xFF640000,   /* 0x2C */
  0xFF580000,   /* 0x2D */
  0xFF4C0000,   /* 0x2E */
  0xFF400000,   /* 0x2F */
  0xFFFCD8D8,   /* 0x30 */

  0xFFFCB8B8,   /* 0x31 */
  0xFFFC9C9C,   /* 0x32 */
  0xFFFC7C7C,   /* 0x33 */
  0xFFFC5C5C,   /* 0x34 */
  0xFFFC4040,   /* 0x35 */
  0xFFFC2020,   /* 0x36 */
  0xFFFC0000,   /* 0x37 */
  0xFFFCA85C,   /* 0x38 */
  0xFFFC9840,   /* 0x39 */
  0xFFFC8820,   /* 0x3A */
  0xFFFC7800,   /* 0x3B */
  0xFFE46C00,   /* 0x3C */
  0xFFCC6000,   /* 0x3D */
  0xFFB45400,   /* 0x3E */
  0xFF9C4C00,   /* 0x3F */
  0xFFFCFCD8,   /* 0x40 */

  0xFFFCFCB8,   /* 0x41 */
  0xFFFCFC9C,   /* 0x42 */
  0xFFFCFC7C,   /* 0x43 */
  0xFFFCF85C,   /* 0x44 */
  0xFFFCF440,   /* 0x45 */
  0xFFFCF420,   /* 0x46 */
  0xFFFCF400,   /* 0x47 */
  0xFFE4D800,   /* 0x48 */
  0xFFCCC400,   /* 0x49 */
  0xFFB4AC00,   /* 0x4A */
  0xFF9C9C00,   /* 0x4B */
  0xFF848400,   /* 0x4C */
  0xFF706C00,   /* 0x4D */
  0xFF585400,   /* 0x4E */
  0xFF404000,   /* 0x4F */
  0xFFD0FC5C,   /* 0x50 */

  0xFFC4FC40,   /* 0x51 */
  0xFFB4FC20,   /* 0x52 */
  0xFFA0FC00,   /* 0x53 */
  0xFF90E400,   /* 0x54 */
  0xFF80CC00,   /* 0x55 */
  0xFF74B400,   /* 0x56 */
  0xFF609C00,   /* 0x57 */
  0xFFD8FCD8,   /* 0x58 */
  0xFFBCFCB8,   /* 0x59 */
  0xFF9CFC9C,   /* 0x5A */
  0xFF80FC7C,   /* 0x5B */
  0xFF60FC5C,   /* 0x5C */
  0xFF40FC40,   /* 0x5D */
  0xFF20FC20,   /* 0x5E */
  0xFF00FC00,   /* 0x5F */
  0xFF00FC00,   /* 0x60 */

  0xFF00EC00,   /* 0x61 */
  0xFF00E000,   /* 0x62 */
  0xFF00D400,   /* 0x63 */
  0xFF04C800,   /* 0x64 */
  0xFF04BC00,   /* 0x65 */
  0xFF04B000,   /* 0x66 */
  0xFF04A400,   /* 0x67 */
  0xFF049800,   /* 0x68 */
  0xFF048800,   /* 0x69 */
  0xFF047C00,   /* 0x6A */
  0xFF047000,   /* 0x6B */
  0xFF046400,   /* 0x6C */
  0xFF045800,   /* 0x6D */
  0xFF044C00,   /* 0x6E */
  0xFF044000,   /* 0x6F */
  0xFFD8FCFC,   /* 0x70 */

  0xFFB8FCFC,   /* 0x71 */
  0xFF9CFCFC,   /* 0x72 */
  0xFF7CFCF8,   /* 0x73 */
  0xFF5CFCFC,   /* 0x74 */
  0xFF40FCFC,   /* 0x75 */
  0xFF20FCFC,   /* 0x76 */
  0xFF00FCFC,   /* 0x77 */
  0xFF00E4E4,   /* 0x78 */
  0xFF00CCCC,   /* 0x79 */
  0xFF00B4B4,   /* 0x7A */
  0xFF009C9C,   /* 0x7B */
  0xFF008484,   /* 0x7C */
  0xFF007070,   /* 0x7D */
  0xFF005858,   /* 0x7E */
  0xFF004040,   /* 0x7F */
  0xFF5CBCFC,   /* 0x80 */

  0xFF40B0FC,   /* 0x81 */
  0xFF20A8FC,   /* 0x82 */
  0xFF009CFC,   /* 0x83 */
  0xFF008CE4,   /* 0x84 */
  0xFF007CCC,   /* 0x85 */
  0xFF006CB4,   /* 0x86 */
  0xFF005C9C,   /* 0x87 */
  0xFFD8D8FC,   /* 0x88 */
  0xFFB8BCFC,   /* 0x89 */
  0xFF9C9CFC,   /* 0x8A */
  0xFF7C80FC,   /* 0x8B */
  0xFF5C60FC,   /* 0x8C */
  0xFF4040FC,   /* 0x8D */
  0xFF2024FC,   /* 0x8E */
  0xFF0004FC,   /* 0x8F */
  0xFF0000FC,   /* 0x90 */

  0xFF0000EC,   /* 0x91 */
  0xFF0000E0,   /* 0x92 */
  0xFF0000D4,   /* 0x93 */
  0xFF0000C8,   /* 0x94 */
  0xFF0000BC,   /* 0x95 */
  0xFF0000B0,   /* 0x96 */
  0xFF0000A4,   /* 0x97 */
  0xFF000098,   /* 0x98 */
  0xFF000088,   /* 0x99 */
  0xFF00007C,   /* 0x9A */
  0xFF000070,   /* 0x9B */
  0xFF000064,   /* 0x9C */
  0xFF000058,   /* 0x9D */
  0xFF00004C,   /* 0x9E */
  0xFF000040,   /* 0x9F */
  0xFF282828,   /* 0xA0 */

  0xFFFCE034,   /* 0xA1 */
  0xFFFCD424,   /* 0xA2 */
  0xFFFCCC18,   /* 0xA3 */
  0xFFFCC008,   /* 0xA4 */
  0xFFFCB400,   /* 0xA5 */
  0xFFB420FC,   /* 0xA6 */
  0xFFA800FC,   /* 0xA7 */
  0xFF9800E4,   /* 0xA8 */
  0xFF8000CC,   /* 0xA9 */
  0xFF7400B4,   /* 0xAA */
  0xFF60009C,   /* 0xAB */
  0xFF500084,   /* 0xAC */
  0xFF440070,   /* 0xAD */
  0xFF340058,   /* 0xAE */
  0xFF280040,   /* 0xAF */
  0xFFFCD8FC,   /* 0xB0 */

  0xFFFCB8FC,   /* 0xB1 */
  0xFFFC9CFC,   /* 0xB2 */
  0xFFFC7CFC,   /* 0xB3 */
  0xFFFC5CFC,   /* 0xB4 */
  0xFFFC40FC,   /* 0xB5 */
  0xFFFC20FC,   /* 0xB6 */
  0xFFFC00FC,   /* 0xB7 */
  0xFFE000E4,   /* 0xB8 */
  0xFFC800CC,   /* 0xB9 */
  0xFFB400B4,   /* 0xBA */
  0xFF9C009C,   /* 0xBB */
  0xFF840084,   /* 0xBC */
  0xFF6C0070,   /* 0xBD */
  0xFF580058,   /* 0xBE */
  0xFF400040,   /* 0xBF */
  0xFFFCE8DC,   /* 0xC0 */

  0xFFFCE0D0,   /* 0xC1 */
  0xFFFCD8C4,   /* 0xC2 */
  0xFFFCD4BC,   /* 0xC3 */
  0xFFFCCCB0,   /* 0xC4 */
  0xFFFCC4A4,   /* 0xC5 */
  0xFFFCBC9C,   /* 0xC6 */
  0xFFFCB890,   /* 0xC7 */
  0xFFFCB080,   /* 0xC8 */
  0xFFFCA470,   /* 0xC9 */
  0xFFFC9C60,   /* 0xCA */
  0xFFF0945C,   /* 0xCB */
  0xFFE88C58,   /* 0xCC */
  0xFFDC8854,   /* 0xCD */
  0xFFD08050,   /* 0xCE */
  0xFFC87C4C,   /* 0xCF */
  0xFFBC7848,   /* 0xD0 */

  0xFFB47044,   /* 0xD1 */
  0xFFA86840,   /* 0xD2 */
  0xFFA0643C,   /* 0xD3 */
  0xFF9C6038,   /* 0xD4 */
  0xFF905C34,   /* 0xD5 */
  0xFF885830,   /* 0xD6 */
  0xFF80502C,   /* 0xD7 */
  0xFF744C28,   /* 0xD8 */
  0xFF6C4824,   /* 0xD9 */
  0xFF5C4020,   /* 0xDA */
  0xFF543C1C,   /* 0xDB */
  0xFF483818,   /* 0xDC */
  0xFF403018,   /* 0xDD */
  0xFF382C14,   /* 0xDE */
  0xFF28200C,   /* 0xDF */
  0xFF600064,   /* 0xE0 */

  0xFF006464,   /* 0xE1 */
  0xFF006060,   /* 0xE2 */
  0xFF00001C,   /* 0xE3 */
  0xFF00002C,   /* 0xE4 */
  0xFF302410,   /* 0xE5 */
  0xFF480048,   /* 0xE6 */
  0xFF500050,   /* 0xE7 */
  0xFF000034,   /* 0xE8 */
  0xFF1C1C1C,   /* 0xE9 */
  0xFF4C4C4C,   /* 0xEA */
  0xFF5C5C5C,   /* 0xEB */
  0xFF404040,   /* 0xEC */
  0xFF303030,   /* 0xED */
  0xFF343434,   /* 0xEE */
  0xFFD8F4F4,   /* 0xEF */
  0xFFB8E8E8,   /* 0xF0 */

  0xFF9CDCDC,   /* 0xF1 */
  0xFF74C8C8,   /* 0xF2 */
  0xFF48C0C0,   /* 0xF3 */
  0xFF20B4B4,   /* 0xF4 */
  0xFF20B0B0,   /* 0xF5 */
  0xFF00A4A4,   /* 0xF6 */
  0xFF009898,   /* 0xF7 */
  0xFF008C8C,   /* 0xF8 */
  0xFF008484,   /* 0xF9 */
  0xFF007C7C,   /* 0xFA */
  0xFF007878,   /* 0xFB */
  0xFF007474,   /* 0xFC */
  0xFF007070,   /* 0xFD */
  0xFF006C6C,   /* 0xFE */
  0xFF980088,   /* 0xFF */
};
