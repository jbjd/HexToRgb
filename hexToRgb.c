// gcc hexToRgb.c
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(int argc, char* argv[]){
	if(argc == 1){
		printf("Convert hex string to RGB values and copies it to the clipboard.\nThe hex string should be 6 total characters long and NOT include a #.\n");
		return 0;
	}
	if(argc > 2 || strlen(argv[1]) != 6){
		printf("Only provide a 6 digit input please.\n");
		return 0;
	}
	int r=0,g=0,b=0,i;
	for(i=0; i<6; ++i){
		int toAdd;
		switch (argv[1][i]){
			case '0':
				toAdd = 0;
				break;
			case '1':
				toAdd = 1;
				break;
			case '2':
				toAdd = 2;
				break;
			case '3':
				toAdd = 3;
				break;
			case '4':
				toAdd = 4;
				break;
			case '5':
				toAdd = 5;
				break;
			case '6':
				toAdd = 6;
				break;
			case '7':
				toAdd = 7;
				break;
			case '8':
				toAdd = 8;
				break;
			case '9':
				toAdd = 9;
				break;
			case 'a':
			case 'A':
				toAdd = 10;
				break;
			case 'b':
			case 'B':
				toAdd = 11;
				break;
			case 'c':
			case 'C':
				toAdd = 12;
				break;
			case 'd':
			case 'D':
				toAdd = 13;
				break;
			case 'e':
			case 'E':
				toAdd = 14;
				break;
			case 'f':
			case 'F':
				toAdd = 15;
				break;
			// If we reach here, character was not 0-9 or a-f or A-F
			default:
				printf("Input contained non-hex characters, exiting...\n");
				return 0;
		}

		if(i%2 == 0){
			toAdd *= 16;
		}

		switch (i){
			case 0:
			case 1:
				r += toAdd;
				break;
			case 2:
			case 3:
				g += toAdd;
				break;
			case 4:
			case 5:
				b += toAdd;
				break;
			default:
				break;
		}
	}
	char toCopy[16];
	sprintf(toCopy, "%d %d %d\0", r, g, b);
	printf("RGB: %s", toCopy);

	const unsigned long long len = strlen(toCopy)+1;
	HGLOBAL globalHandle = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(globalHandle), toCopy, len);
	GlobalUnlock(globalHandle);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, globalHandle);
	CloseClipboard();

	return 0;
}