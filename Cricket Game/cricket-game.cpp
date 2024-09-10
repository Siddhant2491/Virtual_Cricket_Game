#include "game.h"
using namespace std;

int main(){
	Game game;
	game.welcomeUser();

	cout<<"\nPress enter to continue";
	cin.ignore();

	game.showAllPlayers();

	cout<<"\nPress enter to continue";
	cin.ignore();

	game.selectPlayer();
	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout<<"\nPress enter to toss";
	cin.ignore();

	game.toss();

	game.startFirstInning();

	game.startSecondInning();

	game.displayScoreBoard();

	game.displayScoreBoard2();

	return 0;
}
