#include "functions.h"

void gaussianBlur(BYTE* pixels, int size, int imageWidth, int heightStart, int heightEnd) {
	int matrix[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	int width = imageWidth * 3;
	for (int i = width * heightStart; i < width * heightEnd; i += 3) {
		if ((i - width - 3) >= 0 && (i - width + 3) >= 0 && (i - width + 3) < size && (i + width - 3) >= 0 && (i + width - 3) < size) {
			int newPixelLeft = pixels[i - width - 3] * matrix[0] + pixels[i - width] * matrix[1] + pixels[i - width + 3] * matrix[2] + pixels[i - 3] * matrix[3]
				+ pixels[i] * matrix[4] + pixels[i + 3] * matrix[5] + pixels[i + width - 3] * matrix[6]
				+ pixels[i + width] * matrix[7] + pixels[i + width + 3] * matrix[8];
			int newPixelMiddle = pixels[i + 1 - width - 3] * matrix[0] + pixels[i + 1 - width] * matrix[1] + pixels[i + 1 - width + 3] * matrix[2] + pixels[i + 1 - 3] * matrix[3]
				+ pixels[i + 1] * matrix[4] + pixels[i + 1 + 3] * matrix[5] + pixels[i + 1 + width - 3] * matrix[6]
				+ pixels[i + 1 + width] * matrix[7] + pixels[i + 1 + width + 3] * matrix[8];
			int newPixelRight = pixels[i + 2 - width - 3] * matrix[0] + pixels[i + 2 - width] * matrix[1] + pixels[i + 2 - width + 3] * matrix[2] + pixels[i + 2 - 3] * matrix[3]
				+ pixels[i + 2] * matrix[4] + pixels[i + 2 + 3] * matrix[5] + pixels[i + 2 + width - 3] * matrix[6]
				+ pixels[i + 2 + width] * matrix[7] + pixels[i + 2 + width + 3] * matrix[8];
			pixels[i] = newPixelLeft / 16;
			pixels[i + 1] = newPixelMiddle / 16;
			pixels[i + 2] = newPixelRight / 16;
		}
	}
}