#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height) : width(width), height(height) { //constructorul Canvas
	pixels.resize(height, std::vector<char>(width, ' ')); //initializeaza vectorul de caract cu spatii
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 and x <= width and y >= 0 and y <= height) //verif daca e in interior
		pixels[y][x] = ch; //seteaza caract in poz [y][x]
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) //deseneaza conturul unui cerc 
{
	int dx = 0;
	int dy = ray;
	int d = 3 - 2 * ray;
	while (dx <= dy)
	{   //deseneaza pct simetrice ale cerculuo
		SetPoint(x + dx, y + dy, ch);
		SetPoint(x - dx, y + dy, ch);
		SetPoint(x + dx, y - dy, ch);
		SetPoint(x - dx, y - dy, ch);
		SetPoint(x + dy, y + dx, ch);
		SetPoint(x - dy, y + dx, ch);
		SetPoint(x + dy, y - dx, ch);
		SetPoint(x - dy, y - dx, ch);

		if (d < 0) //actualizeaza decizia pt urm pixel
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

void Canvas::FillCircle(int x, int y, int ray, char ch) //umple un cerc
{
	for (int i = -ray; i <= ray; i++) {
		for (int j = -ray; j <= ray; j++) {
			if (i * i + j * j <= ray * ray) { //daca se afla in interiorul cercului
				SetPoint(x + i, y + j, ch);
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)//deseneaza conturul unui dreptunghi
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

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) //umple un dreptunghi
{
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			SetPoint(j, i, ch);//umple tot interiorul dreptunghiului
		}
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) //deseneaza o linie intre 2 pct 
{ //alg lui bresenham
	int dx = abs(x2 - x1); //dist pe x
	int dy = abs(y2 - y1); //dist pe y
	int sx = (x1 < x2) ? 1 : -1; //directia pe x
	int sy = (y1 < y2) ? 1 : -1; //directia pe y
	int err = dx - dy; //eroarea curenta

	while (true) {
		SetPoint(x1, y1, ch); //deseneaza pct curent
		if (x1 == x2 && y1 == y2) break; //iesim cand aj la final
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx; //mergi in dir x
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy; //mergi in dir y
		}
	}
}

void Canvas::Print() //afiseaza desenul 
{
	for (const auto& row : pixels) {
		for (char pixel : row) {
			std::cout << pixel;
		}
		std::cout << '\n';
	}
}

void Canvas::Clear() //reseteaza pozitiile la spatii goale
{
	for (auto& row : pixels) {
		std::fill(row.begin(), row.end(), ' ');
	}
}
