#include "Header.h"

int main()
{
	const int screen_width = 1280;
	const int screen_height = 800;

	InitWindow(screen_width, screen_height, "My Poker");
	SetTargetFPS(60);

	while (WindowShouldClose() == false)
	{
		//Start drawing
		BeginDrawing();

		//Updating


		//Checking for collisions


		//Refresh
		ClearBackground(BLACK);

		//Actual drawing
		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		DrawText(TextFormat("%i", cpu.score), screen_width / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", player.score), 3 * screen_width / 4 + 20, 20, 80, WHITE);

		//Stop drawing
		EndDrawing();
	}

	CloseWindow();

    return 0;
}