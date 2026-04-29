#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Test", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    SDL_Surface* surface1 = IMG_Load("C:/Users/reach/Documents/1.jpg");
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    /*takes two arguments = name of renderer and name of the surface*/
    SDL_DestroySurface(surface1);

    SDL_Surface* surface2 = IMG_Load("C:/Users/reach/Documents/2.png");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    /*takes two arguments = name of renderer and name of the surface*/
    SDL_DestroySurface(surface2);

    SDL_Surface* surface3 = IMG_Load("C:/Users/reach/Documents/3.jpg");
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
    /*takes two arguments = name of renderer and name of the surface*/
    SDL_DestroySurface(surface3);

    SDL_Surface* surface4 = IMG_Load("C:/Users/reach/Documents/5.png");
    SDL_Texture* texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
    /*takes two arguments = name of renderer and name of the surface*/
    SDL_DestroySurface(surface4);





    SDL_FRect imgrect1 = { 350, 200, 100, 100 };
    SDL_FRect imgrect2 = { 250, 300, 100, 100 };
    SDL_FRect imgrect3 = { 450, 300, 100, 100 };
    SDL_FRect imgrect4 = { 350, 400, 100, 100 };

    SDL_FRect centerImage = { 350, 300, 100, 100 };
    // below center//first two args x and y points,  last two are height and width

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN)
                if (event.key.key == SDLK_ESCAPE) running = false;

            SDL_RenderClear(renderer);
            SDL_RenderTexture(renderer, texture2, NULL, &imgrect2);
            SDL_RenderTexture(renderer, texture1, NULL, &imgrect1);
            SDL_RenderTexture(renderer, texture3, NULL, &imgrect3);
            SDL_RenderTexture(renderer, texture4, NULL, &imgrect4);
            SDL_RenderTexture(renderer, NULL, NULL, &centerImage);//rect in the first. crops the image to where the rectangle is defined . second renders into the rectangle created
            SDL_RenderPresent(renderer);
        }
    }



    return 0;
};