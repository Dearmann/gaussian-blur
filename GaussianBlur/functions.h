#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <windows.h>

struct Image
{
	PBITMAPFILEHEADER  file_header;
	PBITMAPINFOHEADER  info_header;
	BYTE* pixels;
	int size;
	char* data;
};

/* 
* Sprawdza poprawność danych wejściowych - czy wczytywany plik istnieje.
* Zwraca true jeżeli plik został wczytany poprawnie.
*/
bool validateInput(System::String^ fileName);

/*
* Wczytuje obraz i zapisuje go przed zmianą w pliku before.bmp.
* Sprawdza którą bibliotekę wybrał użytkownik i ładuje odpowiednie plik dll.
* Dzieli obraz na części w zależności od ilości wątków.
* Odlicza czas wykonania algorytmu i ostatecznie go zwraca.
* Obraz po zamazaniu zapisuje w pliku after.bmp.
*/
int blur(System::String^ fileName, System::String^ threadsCount, bool isCPPSelected);

/* 
* Wczytuje plik bitmapy ze ścieżki fileName i zapisuje dane w parametrze funkcji image.
*/
void readBMP(Image* image, char* fileName);

/*
* Zapisuje dane obrazu ze wskaźnika image do pliku bitmapy na ścieżce fileName.
*/
void saveBMP(Image* image, char* fileName);

#endif

