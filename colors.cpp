#include "colors.h"
#include "extractcolors.h"
#include "pngreader.h"
#include "globals.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define SETCOLOR(col,r,g,b,a) do { \
		colors[col][PBLUE]		= b; \
		colors[col][PGREEN] 		= g; \
		colors[col][PRED] 		= r; \
		colors[col][PALPHA] 		= a; \
		colors[col][BRIGHTNESS]	= (uint8_t)sqrt( \
		                          double(r) *  double(r) * .236 + \
		                          double(g) *  double(g) * .601 + \
		                          double(b) *  double(b) * .163); \
	} while (false)

#define SETCOLORNOISE(col,r,g,b,a,n) do { \
		colors[col][PBLUE]		= b; \
		colors[col][PGREEN] 		= g; \
		colors[col][PRED] 		= r; \
		colors[col][PALPHA] 		= a; \
		colors[col][NOISE]		= n; \
		colors[col][BRIGHTNESS]	= (uint8_t)sqrt( \
		                          double(r) *  double(r) * .236 + \
		                          double(g) *  double(g) * .601 + \
		                          double(b) *  double(b) * .163); \
	} while (false)

// See header for description
uint8_t colors[256][8];


void loadColors()
{
	memset(colors, 0, sizeof colors);
	SETCOLOR(AIR, 255,255,255,0);
	SETCOLORNOISE(STONE, 128,128,128,255, 16);
	SETCOLORNOISE(GRASS, 102,142,62,255, 14);
	SETCOLORNOISE(DIRT, 134,96,67,255, 22);
	SETCOLORNOISE(COBBLESTONE, 115,115,115,255, 24);
	SETCOLORNOISE(WOOD, 157,128,79,255, 11);
	SETCOLOR(6, 120,120,120,0);
	SETCOLOR(7, 84,84,84,255);
	SETCOLOR(WATER, 38,92,225,36);
	SETCOLOR(STAT_WATER, 38,92,225,36);
	SETCOLOR(10, 255,90,0,255);
	SETCOLOR(11, 255,90,0,255);
	SETCOLORNOISE(SAND, 220,212,160,255, 14);
	SETCOLORNOISE(GRAVEL, 136,126,126,255, 24);
	SETCOLOR(14, 143,140,125,255);
	SETCOLOR(15, 136,130,127,255);
	SETCOLOR(16, 115,115,115,255);
	SETCOLOR(LOG, 102,81,51,255);
	SETCOLORNOISE(LEAVES, 54,135,40,180, 12);
	SETCOLOR(20, 255,255,255,40); //glass
	SETCOLORNOISE(21, 102, 112, 134, 255, 10);
	SETCOLORNOISE(22, 29, 71, 165, 255, 5);
	SETCOLOR(23, 107, 107, 107, 255);
	SETCOLORNOISE(SANDSTONE, 218, 210, 158, 255, 7);
	SETCOLORNOISE(25, 100, 67, 50, 255, 10);
	SETCOLOR(BED, 175,116,116, 254); // Not fully opaque to prevent culling on this one
	SETCOLOR(POW_RAILROAD, 160,134,72,250);
	SETCOLOR(DET_RAILROAD, 120,114,92,250);
	SETCOLOR(29, 106,102,95,255);
	SETCOLOR(COBWEB, 220,220,220,190);
	SETCOLORNOISE(TALL_GRASS, 110,166,68,254, 12);
	SETCOLORNOISE(SHRUB, 123,79,25,254, 25);
	SETCOLOR(33, 106,102,95,255);
	SETCOLOR(34, 153,129,89,255);
	SETCOLOR(WOOL, 222,222,222,255); //Color(143,143,143,255);
	//SETCOLOR(36, 222,222,222,255);
	SETCOLOR(FLOWERR, 255,0,0,254); // Not fully opaque to prevent culling on this one
	SETCOLOR(FLOWERY, 255,255,0,254); // Not fully opaque to prevent culling on this one
	SETCOLOR(MUSHROOMB, 128,100,0,254); // Not fully opaque to prevent culling on this one
	SETCOLOR(MUSHROOMR, 140,12,12,254); // Not fully opaque to prevent culling on this one
	SETCOLOR(41, 231,165,45,255);
	SETCOLOR(42, 191,191,191,255);
	SETCOLOR(DOUBLESTEP, 200,200,200,255);
	SETCOLOR(STEP, 200,200,200,254); // Not fully opaque to prevent culling on this one
	SETCOLOR(UP_STEP, 200,200,200,254); // Not fully opaque to prevent culling on this one
	SETCOLOR(45, 170,86,62,255);
	SETCOLOR(BRICKSTEP, 170,86,62,254);
	SETCOLOR(UP_BRICKSTEP, 170,86,62,254);
	SETCOLOR(46, 160,83,65,255);
	SETCOLORNOISE(48, 90,108,90,255, 27);
	SETCOLOR(49, 26,11,43,255);
	SETCOLOR(TORCH, 245,220,50,200);
	SETCOLOR(FIRE, 255,170,30,200);
	SETCOLOR(52, 20,170,200,255);
	SETCOLOR(53, 157,128,79,255);
	SETCOLOR(54, 125,91,38,255);
	SETCOLOR(REDWIRE, 200,10,10,200);
	SETCOLOR(56, 129,140,143,255);
	SETCOLOR(57, 45,166,152,255);
	SETCOLOR(58, 114,88,56,255);
	SETCOLOR(59, 146,192,0,255);
	SETCOLOR(60, 95,58,30,255);
	SETCOLOR(61, 96,96,96,255);
	SETCOLOR(62, 96,96,96,255);
	SETCOLOR(63, 111,91,54,255);
	SETCOLOR(64, 136,109,67,255);
	SETCOLOR(65, 181,140,64,32);
	SETCOLOR(RAILROAD, 140,134,72,250);
	SETCOLOR(67, 115,115,115,255);
	SETCOLOR(71, 191,191,191,255);
	SETCOLOR(73, 131,107,107,255);
	SETCOLOR(74, 131,107,107,255);
	SETCOLOR(REDTORCH_OFF, 181,100,44,254);
	SETCOLOR(REDTORCH_ON, 255,0,0,254);
	SETCOLORNOISE(SNOW, 245,246,245,254, 13); // Not fully opaque to prevent culling on this one
	SETCOLORNOISE(79, 125,173,255,159, 7);
	SETCOLOR(80, 250,250,250,255);
	SETCOLOR(81, 25,120,25,255);
	SETCOLOR(82, 151,157,169,255);
	SETCOLOR(83, 183,234,150,255);
	SETCOLOR(84, 100,67,50,255);
	SETCOLOR(FENCE, 137,112,65,225); // Not fully opaque to prevent culling on this one
	SETCOLOR(86, 197,120,23,255);
	SETCOLORNOISE(87, 110,53,51,255, 16);
	SETCOLORNOISE(88, 84,64,51,255, 7);
	SETCOLORNOISE(89, 137,112,64,255, 11);
	SETCOLOR(90, 0,42,255,127);
	SETCOLOR(91, 185,133,28,255);
	SETCOLORNOISE(CAKE, 228, 205, 206, 255, 7);
	SETCOLORNOISE(93, 151,147,147, 255, 2);
	SETCOLORNOISE(94, 161,147,147, 255, 2);
	SETCOLOR(95, 125,91,38,255);
	SETCOLORNOISE(TRAPDOOR, 126,93,45,240, 5);
	SETCOLORNOISE(97, 128,128,128,255, 16);
	SETCOLORNOISE(98, 122,122,122,255, 7);
	SETCOLORNOISE(STONEBRICKSTEP, 122,122,122,254, 7);
	SETCOLORNOISE(UP_STONEBRICKSTEP, 122,122,122,254, 7);
	SETCOLORNOISE(99, 141,106,83,255, 0);
	SETCOLORNOISE(100, 182,37,36,255, 6);
	SETCOLORNOISE(IRON_BARS, 109,108,106,254, 6);
	SETCOLOR(102, 255,255,255,40);
	SETCOLORNOISE(103, 151,153,36,255, 10);
	SETCOLOR(PUMPKIN_STEM, 115,170,73,254);
	SETCOLOR(MELON_STEM, 115,170,73,254);
	SETCOLORNOISE(VINES, 51,130,36,180, 12);
	SETCOLOR(FENCE_GATE, 137,112,65,225);
	SETCOLOR(108, 170,86,62,255);
	SETCOLORNOISE(109, 122,122,122,255, 7);
	SETCOLORNOISE(MYCELIUM, 140,115,119,255, 14);
	SETCOLOR(LILYPAD, 85,124,60,254); 
	SETCOLORNOISE(NETHER_BRICK, 54,24,30,255, 7);
	SETCOLOR(NETHER_BRICK_FENCE, 54,24,30,225);
	SETCOLOR(NETHER_BRICK_STAIRS, 54,24,30,255);
	SETCOLOR(NETHER_WART, 112,8,28,254);
	SETCOLORNOISE(116, 103,64,59,255, 6);
	SETCOLORNOISE(117, 124,103,81,255, 25);
	SETCOLOR(118, 55,55,55,255);
	SETCOLOR(119, 18,16,27,127);
	SETCOLORNOISE(120, 89,117,96,255, 6);
	SETCOLORNOISE(121, 221,223,165,255, 3);
	SETCOLOR(122, 20,18,29,255);
	SETCOLORNOISE(123, 70,43,26,255, 2);
	SETCOLORNOISE(124, 119,89,55,255, 7);
	SETCOLORNOISE(WOODEN_DOUBLE_STEP, 156,127,78,255, 11);
	SETCOLORNOISE(WOODEN_STEP, 156,127,78,254, 11);
	SETCOLOR(COCOA_PLANT, 145,80,30,200);
	SETCOLORNOISE(128, 218,210,158,255, 15);
	SETCOLORNOISE(129, 109,128,116,255, 18);
	SETCOLORNOISE(130, 18,16,27,255, 5);
	SETCOLORNOISE(131, 138,129,113,255, 28);
	SETCOLORNOISE(132, 129,129,129,107, 25);
	SETCOLOR(133, 81,217,117,255);
	SETCOLORNOISE(134, 103,77,46,255, 1);
	SETCOLORNOISE(135, 195,179,123,255, 3);
	SETCOLORNOISE(136, 154,110,77,255, 2);
	
	SETCOLORNOISE(PINELEAVES, 44,84,44,160, 20); // Pine leaves
	SETCOLORNOISE(BIRCHLEAVES, 85,124,60,170, 11); // Birch leaves
	SETCOLORNOISE(JUNGLELEAVES, 44,135,50,175, 11); // Birch leaves
	SETCOLORNOISE(SANDSTEP, 218, 210, 158, 254, 7); // Not fully opaque to prevent culling on this one
	SETCOLORNOISE(UP_SANDSTEP, 218, 210, 158, 254, 7); // Not fully opaque to prevent culling on this one
	SETCOLORNOISE(WOODSTEP, 157,128,79,254, 11); // Not fully opaque to prevent culling on this one
	SETCOLORNOISE(UP_WOODSTEP, 157,128,79,254, 11); // Not fully opaque to prevent culling on this one
	SETCOLORNOISE(COBBLESTEP, 115,115,115,254, 26); // Not fully opaque to prevent culling on this one
	SETCOLORNOISE(UP_COBBLESTEP, 115,115,115,254, 26); // Not fully opaque to prevent culling on this one

	SETCOLORNOISE(PINESTEP, 103,77,46,254, 1);
	SETCOLORNOISE(BIRCHSTEP, 195,179,123,254, 3);
	SETCOLORNOISE(JUNGLESTEP, 154,110,77,254, 2);
	
	SETCOLORNOISE(UP_WOODSTEP2, 157,128,79,254, 11);
	SETCOLORNOISE(UP_PINESTEP, 103,77,46,255, 1);
	SETCOLORNOISE(UP_BIRCHSTEP, 195,179,123,255, 3);
	SETCOLORNOISE(UP_JUNGLESTEP, 154,110,77,255, 2);
	
	SETCOLORNOISE(226, 103,77,46,255, 1);
	SETCOLORNOISE(227, 195,179,123,255, 3);
	SETCOLORNOISE(228, 154,110,77,255, 2);
	
	SETCOLOR(237, 70,50,32, 255); // Pine trunk
	SETCOLORNOISE(238, 206,206,201, 255, 5); // Birch trunk
	SETCOLOR(239, 122,91,51, 255); // Jungle trunk
	SETCOLOR(240, 244,137,54, 255); // Dyed wool
	SETCOLOR(241, 200,75,210,255);
	SETCOLOR(242, 120,158,241, 255);
	SETCOLOR(243, 204,200,28, 255);
	SETCOLOR(244, 59,210,47, 255);
	SETCOLOR(245, 237,141,164, 255);
	SETCOLOR(246, 76,76,76, 255);
	SETCOLOR(247, 168,172,172, 255);
	SETCOLOR(248, 39,116,149, 255);
	SETCOLOR(249, 133,53,195, 255);
	SETCOLOR(250, 38,51,160, 255);
	SETCOLOR(251, 85,51,27, 255);
	SETCOLOR(252, 55,77,24, 255);
	SETCOLOR(253, 173,44,40, 255);
	SETCOLOR(254, 32,27,27, 255);
	
	//1.3.1+ various
	SETCOLOR(133, 61, 255, 61, 255  ); //emerald
	SETCOLOR(137, 203, 163, 136, 255 ); //command block
	SETCOLOR(138, 21, 255, 255, 255 ); //beacon
	SETCOLORNOISE(139,    128,   128,   128,   255,   16); // cobblestone wall
	SETCOLOR(145, 110, 110, 110, 255 ); //anvil
	SETCOLOR(146, 125,    91,    38,   255   ); //trapped chest
	SETCOLOR(151, 187, 158, 109, 255 ); //daylight sensor
	SETCOLOR(152, 227,  38,  12, 255 ); //redstone block
	SETCOLOR(154, 110, 110, 110, 255 ); //hopper
	SETCOLOR(155, 240, 238, 232, 255 ); //quartz
	SETCOLOR(156, 240, 238, 232, 255 ); //quartz stairs
	SETCOLOR(207, 240, 238, 232, 255 ); //quartz slab
	//SETCOLOR(159, 209, 177, 160, 255 ); //white stained clay !
	SETCOLOR(161, 54, 135, 40, 180 ); //leaves Acacia/Dark Oak
	SETCOLOR(162, 72,  72, 72, 255 ); //log Acacia/Dark Oak
	SETCOLOR(163, 156, 127, 78, 255); // Acacia Wood Stairs
	SETCOLOR(164, 156, 127, 78, 255); // Dark Oak Wood Stairs
	SETCOLOR(170, 172, 145, 18,  255 ); //haystack
	SETCOLOR(171, 224, 224, 224, 255 ); //white carpet
	SETCOLOR(172, 184, 126, 99, 255 ); //hardened clay
	SETCOLOR(173, 21,  21,  21,  255 ); //coal block
	SETCOLOR(174, 159, 189, 239, 255 ); //packed ice
	SETCOLOR(175, 0, 255, 0, 254 ); //Large flower
	SETCOLOR(206, 54, 24, 30, 255 ); //nether bricks slab

	//1.8+
	SETCOLOR(165, 61, 255, 61, 96  ); //slime block
	SETCOLOR(19, 224, 240, 48, 255  ); //sponge
	SETCOLOR(232, 25, 146, 132, 255  ); //prismarine
	SETCOLOR(236, 75, 196, 152, 255  ); //sea lantern
	SETCOLOR(140, 208, 128, 128, 255  ); //granite
	SETCOLOR(144, 228, 228, 228, 255  ); //diorite
	SETCOLOR(157, 160, 160, 160, 255  ); //andesite
	SETCOLOR(208, 176, 181, 0, 255  ); //grass path
	SETCOLOR(209, 155, 63, 176, 255  ); //purpur blocks

	// carpets
	SETCOLOR(36 ,  255, 255, 255,  254   ); //White carpet
	SETCOLOR(68 ,  244, 137,  54,  254   ); //Orange carpet
	SETCOLOR(69 ,  200,  75, 210,  254   ); //Magenta carpet
	SETCOLOR(70 ,  120, 158, 241,  254   ); //Light Blue carpet
	SETCOLOR(72 ,  204, 200,  28,  254   ); //Yellow carpet
	SETCOLOR(77 ,   59, 210,  47,  254   ); //Lime carpet
	SETCOLOR(131,  237, 141, 164,  254   ); //Pink carpet
	SETCOLOR(132,   76,  76,  76,  254   ); //Gray carpet
	SETCOLOR(141,  168, 172, 172,  254   ); //Light Gray
	SETCOLOR(142,   39, 116, 149,  254   ); //Cyan carpet
	SETCOLOR(143,  133,  53, 195,  254   ); //Purple carpet
	SETCOLOR(147,   38,  51, 160,  254   ); //Blue carpet
	SETCOLOR(148,   85,  51,  27,  254   ); //Brown carpet
	SETCOLOR(149,   55,  77,  24,  254   ); //Green carpet
	SETCOLOR(150,  173,  44,  40,  254   ); //Red carpet
	SETCOLOR(158,   32,  27,  27,  254   ); //Black carpet

	// clays
	SETCOLOR(159,  241, 210, 192, 255   ); //White Stained Clay

	SETCOLOR(186,  194, 116,  69, 255   ); //Orange Stained Clay
	SETCOLOR(187,  182, 120, 140, 255   ); //Magenta Stained Clay
	SETCOLOR(188,  141, 137, 167, 255   ); //Light Blue Stained Clay
	SETCOLOR(189,  219, 165,  66, 255   ); //Yellow Stained Clay
	SETCOLOR(190,  137, 149,  84, 255   ); //Lime Stained Clay
	SETCOLOR(191,  194, 110, 110, 255   ); //Pink Stained Clay
	SETCOLOR(192,   97,  82,  75, 255   ); //Gray Stained Clay
	SETCOLOR(193,  168, 138, 128, 255   ); //Light Gray Stained Clay
	SETCOLOR(194,  119, 122, 122, 255   ); //Cyan Stained Clay
	SETCOLOR(195,  152, 102, 117, 255   ); //Purple Stained Clay
	SETCOLOR(196,  103,  88, 120, 255   ); //Blue Stained Clay
	SETCOLOR(197,  109,  82,  66, 255   ); //Brown Stained Clay
	SETCOLOR(198,  105, 112,  70, 255   ); //Green Stained Clay
	SETCOLOR(199,  176,  93,  78, 255   ); //Red Stained Clay
	SETCOLOR(200,   67,  52,  46, 255   ); //Black Stained Clay

	SETCOLOR(153,  225, 140,  73, 255   ); //Red Sand

	// glass
	SETCOLOR(95 , 255, 255,  255,  100  ); //White Stained Glass
	SETCOLOR(160, 255, 255,  255,  100  ); //White Stained Glass pane
	SETCOLOR(234,  244, 137,  54,  40   ); //Orange Stained Glass [pane]
	SETCOLOR(225,  200,  75, 210,  40   ); //Magenta Stained Glass [pane]
	SETCOLOR(255,  120, 158, 241,  40   ); //Light Blue Stained Glass [pane]
	SETCOLOR(166,  204, 200,  28,  40   ); //Yellow Stained Glass [pane]
	SETCOLOR(167,   59, 210,  47,  40   ); //Lime Stained Glass [pane]
	SETCOLOR(168,  237, 141, 164,  40   ); //Pink Stained Glass [pane]
	SETCOLOR(169,   76,  76,  76,  40   ); //Gray Stained Glass [pane]
	SETCOLOR(178,  168, 172, 172,  40   ); //Light Gray Stained Glass [pane]
	SETCOLOR(179,   39, 116, 149,  40   ); //Cyan Stained Glass [pane]
	SETCOLOR(180,  133,  53, 195,  40   ); //Purple Stained Glass [pane]
	SETCOLOR(181,   38,  51, 160,  40   ); //Blue Stained Glass [pane]
	SETCOLOR(182,   85,  51,  27,  40   ); //Brown Stained Glass [pane]
	SETCOLOR(183,   55,  77,  24,  40   ); //Green Stained Glass [pane]
	SETCOLOR(184,  173,  44,  40,  40   ); //Red Stained Glass [pane]
	SETCOLOR(185,   32,  27,  27,  40   ); //Black Stained Glass [pane]

	// flowers
//	SETCOLOR(165, 120, 158, 241, 254   ); //BLUE_ORCHID 165
	SETCOLOR(176, 200,  75, 210, 254 ); //ALLIUM 176
	SETCOLOR(235, 168, 172, 172, 254 ); //AZURE_BLUET 235
	// 38, 173  44  40 254, ); //RED_TULIP 38
	SETCOLOR(217, 244, 137,  54, 254 ); //ORANGE_TULIP 217
	SETCOLOR(218, 255, 255, 255, 254 ); //WHITE_TULIP 218
	SETCOLOR(219, 237, 141, 164, 254 ); //PINK_TULIP 219
	SETCOLOR(220, 168, 172, 172, 254 ); //OXEYE_DAISY 220
	// 37, 255 255  0 254, ); //SUNFLOWER 37
	SETCOLOR(233, 200,  75, 210, 254 ); //LILAC 233
	SETCOLOR(177, 237, 141, 164, 254 ); //PEONY 177

	// nether
	//SETCOLORNOISE(238,  206, 206, 201,  255,   5); // Birch Wood / quartz slab (sic!)

}


bool loadColorsFromFile(const char *file)
{
	FILE *f = fopen(file, "r");
	if (f == NULL) {
		return false;
	}
	while (!feof(f)) {
		char buffer[500];
		if (fgets(buffer, 500, f) == NULL) {
			break;
		}
		char *ptr = buffer;
		while (*ptr == ' ' || *ptr == '\t') {
			++ptr;
		}
		if (*ptr == '\0' || *ptr == '#' || *ptr == '\12') {
			continue;   // This is a comment or empty line, skip
		}
		int blockid = atoi(ptr);
		if (blockid < 1 || blockid > 255) {
			printf("Skipping invalid blockid %d in colors file\n", blockid);
			continue;
		}
		while (*ptr != ' ' && *ptr != '\t' && *ptr != '\0') {
			++ptr;
		}
		uint8_t vals[5];
		bool valid = true;
		for (int i = 0; i < 5; ++i) {
			while (*ptr == ' ' || *ptr == '\t') {
				++ptr;
			}
			if (*ptr == '\0' || *ptr == '#' || *ptr == '\12') {
				printf("Too few arguments for block %d, ignoring line.\n", blockid);
				valid = false;
				break;
			}
			vals[i] = clamp(atoi(ptr));
			while (*ptr != ' ' && *ptr != '\t' && *ptr != '\0') {
				++ptr;
			}
		}
		if (!valid) {
			continue;
		}
		memcpy(colors[blockid], vals, 5);
		colors[blockid][BRIGHTNESS] = GETBRIGHTNESS(colors[blockid]);
	}
	fclose(f);
	return true;
}

bool dumpColorsToFile(const char *file)
{
	FILE *f = fopen(file, "w");
	if (f == NULL) {
		return false;
	}
	fprintf(f, "# For Block IDs see http://minecraftwiki.net/wiki/Data_values\n"
				"# and http://wrim.pl/mcmap (for blocks introduced since Minecraft 1.3.1 and mcmap 2.4)\n"
				"# Note that noise or alpha (or both) do not work for a few blocks like snow, torches, fences, steps, ...\n"
				"# Actually, if you see any block has an alpha value of 254 you should leave it that way to prevent black artifacts.\n"
				"# If you want to set alpha of grass to <255, use -blendall or you won't get what you expect.\n"
				"# Noise is supposed to look normal using -noise 10\n"
				"# Dyed wool ranges from ID 240 to 254, it's orange to black in the order described at http://www.minecraftwiki.net/wiki/Data_values#Wool\n"
				"# half-steps of sand, wood and cobblestone are 232 to 236\n\n");
	for (size_t i = 1; i < 255; ++i) {
		uint8_t *c = colors[i];
		if (i % 15 == 1) {
			fprintf(f, "#ID    R   G   B    A  Noise\n");
		}
		fprintf(f, "%3d  %3d %3d %3d  %3d  %3d\n", int(i), int(c[PRED]), int(c[PGREEN]), int(c[PBLUE]), int(c[PALPHA]), int(c[NOISE]));
	}
	fclose(f);
	return true;
}

/**
 * Extract block colors from given terrain.png file
 */
bool extractColors(const char* file)
{
	PngReader png(file);
	if (!png.isValidImage()) return false;
	if (png.getWidth() != png.getHeight() // Quadratic
			|| (png.getWidth() / 16) * 16 != png.getWidth() // Has to be multiple of 16
			|| png.getBitsPerChannel() != 8 // 8 bits per channel, 32bpp in total
			|| png.getColorType() != PngReader::RGBA) return false;
	uint8_t *imgData = png.getImageData();
	// Load em up
	for (int i = 0; i < 256; i++) {
		if (i == TORCH) {
			continue;   // Keep those yellow for now
		}
		int r, g, b, a, n; // i i s g t u o l v n
		if (getTileRGBA(imgData, png.getWidth() / 16, i, r, g, b, a, n)) {
			const bool flag = (colors[i][PALPHA] == 254);
			if (i == FENCE) {
				r = clamp(r + 10);
				g = clamp(g + 10);
				b = clamp(b + 10);
			}
			SETCOLORNOISE(i, r, g, b, a, n);
			if (flag) {
				colors[i][PALPHA] = 254;   // If you don't like this, dump texture pack to txt file and modify that one
			}
		}
	}
	return true;
}

static PngReader *pngGrass = NULL;
static PngReader *pngLeaf = NULL;
/**
 * This loads grasscolor.png and foliagecolor.png where the
 * biome colors will be read from upon rendering
 */
bool loadBiomeColors(const char* path)
{
	size_t len = strlen(path) + 21;
	char *grass = new char[len], *foliage = new char[len];
	snprintf(grass, len + 20, "%s/grasscolor.png", path);
	snprintf(foliage, len + 20, "%s/foliagecolor.png", path);
	pngGrass = new PngReader(grass);
	pngLeaf = new PngReader(foliage);
	if (!pngGrass->isValidImage() || !pngLeaf->isValidImage()) {
		delete pngGrass;
		delete pngLeaf;
		printf("Could not load %s and %s: no valid PNG files. Biomes disabled.\n", grass, foliage);
		return false;
	}
	if ((pngGrass->getColorType() != PngReader::RGBA && pngGrass->getColorType() != PngReader::RGB) || pngGrass->getBitsPerChannel() != 8
			|| (pngLeaf->getColorType() != PngReader::RGBA && pngLeaf->getColorType() != PngReader::RGB) || pngLeaf->getBitsPerChannel() != 8
			|| pngGrass->getWidth() != 256 || pngGrass->getHeight() != 256 || pngLeaf->getWidth() != 256 || pngLeaf->getHeight() != 256) {
		delete pngGrass;
		delete pngLeaf;
		printf("Could not load %s and %s; Expecting RGB(A), 8 bits per channel.\n", grass, foliage);
		return false;
	}
	g_GrasscolorDepth = pngGrass->getBytesPerPixel();
	g_FoliageDepth = pngLeaf->getBytesPerPixel();
	g_Grasscolor = pngGrass->getImageData();
	g_TallGrasscolor = new uint8_t[pngGrass->getBytesPerPixel() * 256 * 256];
	g_Leafcolor = pngLeaf->getImageData();
	// Adjust brightness to what colors.txt says
	const int maxG = pngGrass->getWidth() * pngGrass->getHeight() * g_GrasscolorDepth;
	for (int i = 0; i < maxG; ++i) {
		g_TallGrasscolor[i] = ((int)g_Grasscolor[i] * (int)colors[TALL_GRASS][BRIGHTNESS]) / 255;
		g_Grasscolor[i] = ((int)g_Grasscolor[i] * (int)colors[GRASS][BRIGHTNESS]) / 255;
	}
	const int maxT = pngLeaf->getWidth() * pngLeaf->getHeight() * g_FoliageDepth;
	for (int i = 0; i < maxT; ++i) {
		g_Leafcolor[i] = ((int)g_Leafcolor[i] * (int)colors[LEAVES][BRIGHTNESS]) / 255;
	}
	// Now re-calc brightness of those two
	colors[GRASS][BRIGHTNESS] = GETBRIGHTNESS(g_Grasscolor) - 5;
	colors[LEAVES][BRIGHTNESS] = colors[PINELEAVES][BRIGHTNESS] = colors[BIRCHLEAVES][BRIGHTNESS] = GETBRIGHTNESS(g_Leafcolor) - 5;
	printf("Loaded biome color maps from %s\n", path);
	return true;
}
