#include <string>
#include <windows.h>

/*
* Rozmycie obrazu zgodnie z algorytmem rozmycia gaussa.
* pixels - dane bitmapy
* size - rozmiar bitmapy
* imageWidth - szerokość bitmapy
* heightStart - wysokość od której funkcja zaczyna działać
* heightEnd - wysokość przy której funkcja kończy działanie
*/
extern "C" void __declspec(dllimport) gaussianBlur(BYTE * pixels, int size, int imageWidth, int heightStart, int heightEnd);