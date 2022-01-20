#include <fstream>
#include <iostream>
#include <thread>
#include "functions.h"

typedef void(_stdcall* GaussianBlur)(BYTE*, int, int, int, int);

bool validateInput(System::String^ fileName) {
	int length = fileName->Length;
	char* charFileName = new char[length];
	sprintf(charFileName, "%s", fileName);

	std::ifstream inputFile(charFileName, std::ios::in | std::ios::binary | std::ios::ate);
	if (!inputFile) {
		return false;
	}
	return true;
}

int blur(System::String^ fileName, System::String^ threadsCount, bool isCPPSelected) {
	int length = fileName->Length;
	char* charFileName = new char[length];
	sprintf(charFileName, "%s", fileName);
	char* charThreadsCount = new char[2];
	sprintf(charThreadsCount, "%s", threadsCount);
	int intThreadsCount = atoi(charThreadsCount);

	Image* image = new Image;
	readBMP(image, charFileName);
	saveBMP(image, ".\\before.bmp");

	HINSTANCE library;
	if (isCPPSelected)
		library = LoadLibraryA("CPP.dll");
	else
		library = LoadLibraryA("ASM.dll");
	GaussianBlur gaussianBlur = (GaussianBlur)GetProcAddress(library, "gaussianBlur");

	int imageParts = image->info_header->biHeight / intThreadsCount;
	std::thread* threads = new std::thread[intThreadsCount];
	for (int i = 0; i < intThreadsCount - 1; i++)
		threads[i] = std::thread(gaussianBlur, image->pixels, image->size, image->info_header->biWidth, i * imageParts, (i + 1) * imageParts);
	threads[intThreadsCount - 1] = std::thread(gaussianBlur, image->pixels, image->size, image->info_header->biWidth, (intThreadsCount - 1) * imageParts, image->info_header->biHeight - 1);

	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < intThreadsCount; i++)
		threads[i].join();
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	int time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

	saveBMP(image, ".\\after.bmp");
	return time;
}

void readBMP(Image* image, char* fileName)
{
	std::ifstream inputFile(fileName, std::ios::in | std::ios::binary | std::ios::ate);
	std::ifstream::pos_type eof = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);
	image->size = eof;
	image->data = new char[image->size];
	inputFile.read(image->data, image->size);
	image->file_header = PBITMAPFILEHEADER(image->data);
	image->info_header = PBITMAPINFOHEADER(image->data + sizeof(BITMAPFILEHEADER));
	image->pixels = reinterpret_cast<BYTE*>(image->data + image->file_header->bfOffBits);
	inputFile.close();
}

void saveBMP(Image* image, char* fileName)
{
	std::ofstream outputFile(fileName, std::ios::out | std::ios::binary);
	outputFile.write(image->data, image->size);
	outputFile.close();
}