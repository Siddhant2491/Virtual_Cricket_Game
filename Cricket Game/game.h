#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <limits>
#include "team.h"   // "player.h", <string>, <vector>

class Game{
	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		Team teamA, teamB;
		Team *battingTeam;
		Team *bowlingTeam;
		Player *batsman, *bowler;
		bool isFirstInnings;

		void welcomeUser();
		void showAllPlayers();
		int takeIntegerInput();
		void selectPlayer();
		bool validateSelectedPlayer(int);
		void showTeamPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInning();
		void initializePlayers();
		void playInning();
		void bat();
		bool validateInningScore();
		void scoreCard();
		void startSecondInning();
		void swapTeam(Team *, Team *);
		void displayScoreBoard();
		void displayScoreBoard2();
};
