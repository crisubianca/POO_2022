#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
	// a = (char**)malloc(width * sizeof(char*));
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			// a[i] = (char*)malloc(height * sizeof(char));
			this->a[i][j] = ' ';
		}
	}
	this->width = width;
	this->height = height;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = x - ray; i <= x + ray; i++)
	{
		for (int j = y - ray; j <= y + ray; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				a[i][j] = ch;
			}
		}

	}
	int r = ray - 1;
	for (int i = x - r; i <= x + r; i++)
	{
		for (int j = y - r; j <= y + r; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
			{
				a[i][j] = ' ';
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	ray = ray - 1;
	for (int i = x - ray; i <= x + ray; i++)
	{
		for (int j = y - ray; j <= y + ray; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				a[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int j = left; j <= right; j++)
		a[top][j] = ch;
	for (int j = left; j <= right; j++)
		a[bottom][j] = ch;
	for (int i = top; i <= bottom; i++)
		a[i][right] = ch;
	for (int i = top; i <= bottom; i++)
		a[i][left] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top + 1;i <= bottom - 1;i++)
		for (int j = left + 1; j <= right - 1; j++)
			a[i][j] = ch;

}

void Canvas::SetPoint(int x, int y, char ch)
{
	a[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int deltax = x2 - x1;
	int deltay = y2 - y1;
	int deltaerr = abs(deltay / deltax);
	int error = 0.0; // No error at start
	int y = y1;
	for (int x = x1; x < x2; x++)
	{
		a[x][y] = ch;
		error = error + deltaerr;
		if (error >= 0.5)
		{
			y = y + 1;
			error = error - 1.0;
		}
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			a[i][j] = ' ';
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
