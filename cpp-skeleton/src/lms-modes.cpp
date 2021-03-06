#include <stdio.h>
#include <stdlib.h>

int main ( void )
{
	enum LMSModes { CONFIG_FREQ_ANGRES, CONFIG_ANGSTART_ANGSTOP, OPEN, CLOSE, NumOfModes };
    char lmsMODE[NumOfModes][50] = {
		// CONFIG_FREQ_ANGRES, scan config
		{ 0x02, 0x73, 0x52, 0x4E, 0x20, 0x4C, 0x4D, 0x50, 0x73, 0x63, 0x61, 0x6E, 0x63, 0x66, 0x67, 0x03 },
		// CONFIG_ANGSTART_ANGSTOP, output range
		{ 0x02, 0x73, 0x52, 0x4E, 0x20, 0x4C, 0x4D, 0x50, 0x6F, 0x75, 0x74, 0x70, 0x75, 0x74, 0x52, 0x61, 0x6E, 0x67, 0x65, 0x03 },
		// OPEN, scan data 1 (turn ON)
		{ 0x02, 0x73, 0x45, 0x4E, 0x20, 0x4C, 0x4D, 0x44, 0x73, 0x63, 0x61, 0x6E, 0x64, 0x61, 0x74, 0x61, 0x20, 0x31, 0x03 },
		// CLOSE, scan data 0 (turn OFF)
		{ 0x02, 0x73, 0x45, 0x4E, 0x20, 0x4C, 0x4D, 0x44, 0x73, 0x63, 0x61, 0x6E, 0x64, 0x61, 0x74, 0x61, 0x20, 0x30, 0x03 } 
	};

    for (int i = 0; i < 4; ++i) {
	    fprintf(stdout, "Mode%1d: %s\n", i, lmsMODE[i]);
	}
	/*
		Mode0: sRN LMPscancfg
		Mode1: sRN LMPoutputRange
		Mode2: sEN LMDscandata 1
		Mode3: sEN LMDscandata 0
	*/
	getchar();
    return EXIT_SUCCESS;
}