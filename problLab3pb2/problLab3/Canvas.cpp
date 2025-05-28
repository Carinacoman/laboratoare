#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height) : width(width), height(height) {
	pixels.resize(height, std::vector<char>(width, ' '));
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 and x <= width and y >= 0 and y <= height)
		pixels[y][x] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int dx = 0;
	int dy = ray;
	int d = 3 - 2 * ray;
	while (dx <= dy)
	{
		SetPoint(x + dx, y + dy, ch);
		SetPoint(x - dx, y + dy, ch);
		SetPoint(x + dx, y - dy, ch);
		SetPoint(x - dx, y - dy, ch);
		SetPoint(x + dy, y + dx, ch);
		SetPoint(x - dy, y + dx, ch);
		SetPoint(x + dy, y - dx, ch);
		SetPoint(x - dy, y - dx, ch);

		if (d < 0)
		{
			d += 4 * dx + 6;
		}
		else
		{
			d += 4 * (dx - dy) + 10;
			dy--;
		}
		dx++;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = -ray; i <= ray; i++) {
		for (int j = -ray; j <= ray; j++) {
			if (i * i + j * j <= ray * ray) {
				SetPoint(x + i, y + j, ch);
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++) {
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (int i = top; i <= bottom; i++) {
		SetPoint(left, i, ch);
		SetPoint(right, i, ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			SetPoint(j, i, ch);
		}
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print()
{
	for (const auto& row : pixels) {
		for (char pixel : row) {
			std::cout << pixel;
		}
		std::cout << '\n';
	}
}

void Canvas::Clear()
{
	for (auto& row : pixels) {
		std::fill(row.begin(), row.end(), ' ');
	}
}