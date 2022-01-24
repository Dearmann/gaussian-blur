#include "functions.h"

void gaussianBlur(BYTE* pixels, int size, int imageWidth, int heightStart, int heightEnd) {
	int matrix[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	int rgbWidth = imageWidth * 3;
	for (int i = rgbWidth * heightStart; i < rgbWidth * heightEnd; i += 3) {
		if ((i - rgbWidth - 3) >= 0 && (i - rgbWidth + 3) >= 0 && (i - rgbWidth + 3) < size && (i + rgbWidth - 3) >= 0 && (i + rgbWidth - 3) < size) {
			int newPixelR = pixels[i - rgbWidth - 3] * matrix[0] + pixels[i - rgbWidth] * matrix[1] + pixels[i - rgbWidth + 3] * matrix[2] + pixels[i - 3] * matrix[3]
				+ pixels[i] * matrix[4] + pixels[i + 3] * matrix[5] + pixels[i + rgbWidth - 3] * matrix[6]
				+ pixels[i + rgbWidth] * matrix[7] + pixels[i + rgbWidth + 3] * matrix[8];
			int newPixelG = pixels[i + 1 - rgbWidth - 3] * matrix[0] + pixels[i + 1 - rgbWidth] * matrix[1] + pixels[i + 1 - rgbWidth + 3] * matrix[2] + pixels[i + 1 - 3] * matrix[3]
				+ pixels[i + 1] * matrix[4] + pixels[i + 1 + 3] * matrix[5] + pixels[i + 1 + rgbWidth - 3] * matrix[6]
				+ pixels[i + 1 + rgbWidth] * matrix[7] + pixels[i + 1 + rgbWidth + 3] * matrix[8];
			int newPixelB = pixels[i + 2 - rgbWidth - 3] * matrix[0] + pixels[i + 2 - rgbWidth] * matrix[1] + pixels[i + 2 - rgbWidth + 3] * matrix[2] + pixels[i + 2 - 3] * matrix[3]
				+ pixels[i + 2] * matrix[4] + pixels[i + 2 + 3] * matrix[5] + pixels[i + 2 + rgbWidth - 3] * matrix[6]
				+ pixels[i + 2 + rgbWidth] * matrix[7] + pixels[i + 2 + rgbWidth + 3] * matrix[8];
			pixels[i] = newPixelR / 16;
			pixels[i + 1] = newPixelG / 16;
			pixels[i + 2] = newPixelB / 16;
		}
	}
}