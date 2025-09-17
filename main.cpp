#include "Header.h"

Deck playdeck;
Player player;

int main()
{
#ifdef BOO
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
#endif

	playdeck.shuffle();

	Card card1 = playdeck.dealCard();
	Card card2 = playdeck.dealCard();

	player.getCard(card1, card2);
	player.printHand();

    return 0;
}
