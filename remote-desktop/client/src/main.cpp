#include <SDL2/SDL.h>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sys/_types/_size_t.h>
#include <vector>

void readPixelsFromFile(const std::string &filename,
                        std::vector<uint8_t> &pixels, int &width, int &height) {
  std::ifstream inFile(filename, std::ios::binary);
  if (!inFile) {
    std::cerr << "Cannot open file: " << filename << std::endl;
    return;
  }

  std::cout << "Hello world" << std::endl;
  size_t w, h;
  inFile.read(reinterpret_cast<char *>(&w), sizeof(size_t));
  inFile.read(reinterpret_cast<char *>(&h), sizeof(size_t));

  width = static_cast<int>(w);
  height = static_cast<int>(h);

  size_t pixelDataSize = static_cast<size_t>(width * height * 4);
  pixels.resize(pixelDataSize);

  if (!inFile.read(reinterpret_cast<char *>(pixels.data()), pixelDataSize)) {
    std::cerr << "Error reading pixel data" << std::endl;
  }

  inFile.close();
}

int main() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    return 1;

  std::vector<uint8_t> pixels;
  int originalW, originalH;
  readPixelsFromFile("1.testfile", pixels, originalW, originalH);

  SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, originalW,
                                        originalH, SDL_WINDOW_SHOWN);
  if (!window) {
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  Uint32 rmask = 0x000000FF;
  Uint32 gmask = 0x0000FF00;
  Uint32 bmask = 0x00FF0000;
  Uint32 amask = 0xFF000000;

  SDL_Surface *surface =
      SDL_CreateRGBSurfaceFrom(pixels.data(), originalW, originalH, 32,
                               originalW * 4, rmask, gmask, bmask, amask);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

  int quit = 0;
  SDL_Event e;

  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        quit = 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
