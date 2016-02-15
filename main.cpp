#include <iostream>
#include <png++/png.hpp>
#include <random>

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		return 1;
	}
	int const X = 1024;
	int const Y = 1024;
	std::mt19937 engine(std::random_device{}());
	std::uniform_int_distribution<int> rand(-1, 1);

	png::image<png::rgba_pixel> dst(X, Y);

	for (int y = 0; y < dst.get_height(); ++y)
	{
		for (int x = 0; x < dst.get_width(); ++x)
		{
			dst[y][x] = png::basic_rgba_pixel<unsigned char>(255, 255, 255, 255);
		}
	}
	int x = 512;
	int y = 512;
	while (true)
	{
		dst[y][x] = png::basic_rgba_pixel<unsigned char>(255, 0, 0, 255);
		x += rand(engine);
		y += rand(engine);
		if (0 > x || x >= X || 0 > y || y >= Y)
		{
			break;
		}
	}
	dst.write(argv[1]);
}

