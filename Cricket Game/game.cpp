#include "game.h"
using namespace std;

Game::Game(){

	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;

	players[0]="Virat";
	players[1]="Rohit";
	players[2]="Dhawan";
	players[3]="Rishab";
	players[4]="Karthik";
	players[5]="KLRahul";
	players[6]="Jadeja";
	players[7]="Hardik";
	players[8]="Bumrah";
	players[9]="BKumar";
	players[10]="Ishant";

	isFirstInnings=false;
	teamA.name="Team-A";
	teamB.name="Team-B";
}

void Game::welcomeUser(){

	cout<<"+-------------------------------------+"<<endl;
	cout<<"|=============Cricket-Game============|"<<endl;
	cout<<"|                                     |"<<endl;
	cout<<"|   Welcome to Virtual Cricket Game   |"<<endl;
	cout<<"+-------------------------------------+"<<endl;

	cout<<endl<<endl;
	cout<<"+----------------------------------------------------+"<<endl;
	cout<<"|=================+++Instructions+++=================|"<<endl;
	cout<<"+----------------------------------------------------+"<<endl;
	cout<<"|                                                    |"<<endl;
	cout<<"|1. Create 2 teams (Team-A and Team-B with 4 players |"<<endl<<
		  "|   each) from a given pool of 11 players.           |"<<endl<<
		  "|2. Lead the toss and decide the choice of play.     |"<<endl<<
		  "|3. Each innings will be of 6 balls.                 |"<<endl;
	cout<<"+----------------------------------------------------+"<<endl<<endl;
}

void Game::showAllPlayers(){

	cout<<"+-------------------------------------+"<<endl;
	cout<<"|===========Pool of Players===========|"<<endl;
	cout<<"+-------------------------------------+"<<endl<<endl;

	for(int i=0; i<totalPlayers; i++){
		cout<<"\t\t["<<i<<"]"<<players[i]<<endl;
	}
	cout<<endl;
}

int Game::takeIntegerInput(){

	int n;

	while(!(cin>>n)){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Invalid Input! Please try again with valid input: ";
	}

	return n;
}

bool Game::validateSelectedPlayer(int index){

	int n;
	vector<Player> players;

	players=teamA.players;
	n=players.size();
	for(int i=0; i<n; i++){
		if(players[i].id==index){
			return false;
		}
	}

	players=teamB.players;
	n=players.size();
	for(int i=0; i<n; i++){
		if(players[i].id==index){
			return false;
		}
	}

	return true;
}

void Game::selectPlayer(){

	cout<<endl;
	cout<<"+-------------------------------------+"<<endl;
	cout<<"|======Create Team-A and Team-B=======|"<<endl;
	cout<<"+-------------------------------------+"<<endl;

	for(int i=0; i<playersPerTeam; i++){

		//Add player to team A
		teamASelection:
		cout<<endl<<"Select Player "<<i+1<<" of Team A-";

		int playerIndexTeamA=takeIntegerInput();

		if(playerIndexTeamA<0 || playerIndexTeamA>10){
			cout<<endl<<"Please select from the given players"<<endl;
			goto teamASelection;
		}
		else if(!validateSelectedPlayer(playerIndexTeamA)){
			cout<<endl<<"Player has been already selected please select another player"<<endl;
			goto teamASelection;
		}
		else{
			Player teamAPlayer;
			teamAPlayer.id=playerIndexTeamA;
			teamAPlayer.name=players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
		}

		//Add player to team B
		teamBSelection:
		cout<<endl<<"Select Player "<<i+1<<" of Team B-";

		int playerIndexTeamB=takeIntegerInput();

		if(playerIndexTeamB<0 || playerIndexTeamB>10){
			cout<<endl<<"Please select from the given players"<<endl;
			goto teamBSelection;
		}
		else if(!validateSelectedPlayer(playerIndexTeamB)){
			cout<<endl<<"Player has been already selected please select another player"<<endl;
			goto teamBSelection;
		}
		else{
			Player teamBPlayer;
			teamBPlayer.id=playerIndexTeamB;
			teamBPlayer.name=players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);
		}
	}
}

void Game::showTeamPlayers(){

	vector<Player> teamAPlayers=teamA.players;
	vector<Player> teamBPlayers=teamB.players;

	cout<<endl<<endl;
	cout<<"+------------------------+\t\t+------------------------+"<<endl;
	cout<<"|======== Team-A ========|\t\t|======== Team-B ========|"<<endl;
	cout<<"+------------------------+\t\t+------------------------+"<<endl;
	for(int i=0; i<playersPerTeam; i++){
		cout<<"|\t"<<"["<<i<<"]"<<teamAPlayers[i].name<<"\t |"
			<<"\t\t"
			<<"|\t"<<"["<<i<<"]"<<teamBPlayers[i].name<<"\t |"<<endl;
	}
	cout<<"+------------------------+\t\t+------------------------+"<<endl;
}

void Game::toss(){

	cout<<endl;
	cout<<"+-------------------------------------+"<<endl;
	cout<<"|==============Let's Toss=============|"<<endl;
	cout<<"+-------------------------------------+"<<endl;
	cout<<endl;
	cout<<"Tossing the coin....."<<endl<<endl;

	sleep(2);

	srand(time(NULL));
	int randomValue = rand() % 2;  // 0 & 1

	switch(randomValue){
		case 0:
			cout<<"Team-A won the toss"<<endl;
			tossChoice(teamA);
			break;
		case 1:
			cout<<"Team-B won the toss"<<endl;
			tossChoice(teamB);
			break;
	}
}

void Game::tossChoice(Team tossWinnerTeam){

	cout<<endl<<"Enter 1 to bat or 2 to bowl first. "<<endl;
	cout<<"1. Bat"<<endl;
	cout<<"2. Bowl"<<endl;

	int tossInput=takeIntegerInput();

	switch(tossInput){
		case 1:
			cout<<endl<<tossWinnerTeam.name<<" won the toss and elected to bat first"<<endl<<endl;
			if(tossWinnerTeam.name.compare("Team-A")==0){
				battingTeam=&teamA;
				bowlingTeam=&teamB;
			}
			else{
				battingTeam=&teamB;
				bowlingTeam=&teamA;
			}
			break;
		case 2:
			cout<<endl<<tossWinnerTeam.name<<" won the toss and elected to bowl first"<<endl<<endl;
			if(tossWinnerTeam.name.compare("Team-A")==0){
				battingTeam=&teamB;
				bowlingTeam=&teamA;
			}
			else{
				battingTeam=&teamA;
				bowlingTeam=&teamB;
			}
			break;
		default:
			cout<<endl<<"Invalid input. Please try again: "<<endl<<endl;
			tossChoice(tossWinnerTeam);
			break;
	}
}

void Game::startFirstInning(){

	cout<<"\t\t\t ||| FIRST INNING STARTS ||| "<<endl<<endl;

	isFirstInnings=true;

	initializePlayers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	playInning();
}

void Game::initializePlayers(){

	//Choose Batsman and bowler and Initialize *batsman and *bowler
	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];

	cout<<battingTeam->name<<" - "<<batsman->name<<" is batting"<<endl;
	cout<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling"<<endl<<endl;
}

void Game::playInning(){

	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for(int i=0; i<maxBalls; i++){
		cout<<"Press Enter to bowl...";
		cin.ignore();
		cout<<"Bowling..."<<endl<<endl;
		sleep(1);
		bat();

		if(!validateInningScore()){
			break;
		}
	}
}

void Game::bat(){

	srand(time(NULL));
	int runsScored=rand() % 7;

	//Update batting team and batsman score
	batsman->runsScored += runsScored;
	battingTeam->totalRunsScored += runsScored;
	batsman->ballsPlayed += 1;

	//Update bowling team and bowler score
	bowler->ballsBowled += 1;
	bowlingTeam->totalBallsBowled += 1;
	bowler->runsGiven += runsScored;

	if(runsScored != 0){      //if run is 1 2 3 4 5 6 then if will run
		cout<<batsman->name<<" scored: "<<runsScored<<" runs!"<<" on "
				<<bowler->ballsBowled<<" ball of "<<bowler->name<<endl<<endl;

		scoreCard();
	}
	else{    //else runsScored=0 and the batsman is 'OUT'
		cout<<batsman->name<<" is OUT! by "<<bowler->name<<" on "
				<<bowler->ballsBowled<<" ball"<<endl<<endl;

		battingTeam->wicketsLost += 1;
		bowler->wicketsTaken += 1;

		int nextPlayerIndex=battingTeam->wicketsLost;
		batsman=&battingTeam->players[nextPlayerIndex];

		scoreCard();
	}
}

bool Game::validateInningScore(){

	if(isFirstInnings){      //if it is 1st inning
		if(battingTeam->wicketsLost==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){     // conditions for which first innings can be ended
			cout<<"\t\t\t ||| FIRST INNINGS ENDS |||"<<endl<<endl;

			cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
					<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") "
					<<endl;

			cout<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored + 1
					<<" runs to win the match"
					<<endl<<endl;
			return false;
		}
	}
	else{	//if it is 2nd inning
		if(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored){   //batting team hit more runs than bowling team
			cout<<battingTeam->name<<" WON THE MATCH"<<endl<<endl;

			cout<<"\t\t\t ||| MATCH ENDS |||"<<endl<<endl;
			return false;
		}
		else if(battingTeam->wicketsLost==playersPerTeam){  //all the players are out
			if(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored){  //batting team hit more runs than bowling team
				cout<<battingTeam->name<<" WON THE MATCH"<<endl<<endl;

				cout<<"\t\t\t ||| MATCH ENDS |||"<<endl<<endl;
				return false;
			}
			else if(battingTeam->totalRunsScored<bowlingTeam->totalRunsScored){ //batting team hit less runs than bowling team
				cout<<bowlingTeam->name<<" WON THE MATCH"<<endl<<endl;

				cout<<"\t\t\t ||| MATCH ENDS |||"<<endl<<endl;
				return false;
			}
			else{												//both have scored the same
				cout<<"ITS A DRAW BETWEEN BOTH THE TEAMS"<<endl<<endl;

				cout<<"\t\t\t ||| MATCH ENDS |||"<<endl<<endl;
				return false;
			}
		}
		else if(bowlingTeam->totalBallsBowled==maxBalls){ //player have played all the balls
			if(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored){ //batting team hit more runs than bowling team
				cout<<battingTeam->name<<" WON THE MATCH"<<endl<<endl;

				cout<<"\t\t\t ||| MATCH ENDS |||"<<endl<<endl;
				return false;
			}
			else if(battingTeam->totalRunsScored<bowlingTeam->totalRunsScored){ //batting team hit less runs than bowling team
				cout<<bowlingTeam->name<<" WON THE MATCH"<<endl<<endl;

				cout<<"\t\t\t ||| MATCH ENDS |||"<<endl<<endl;
				return false;
			}
			else{    								//both have scored the same
				cout<<"ITS A DRAW BETWEEN BOTH THE TEAMS"<<endl<<endl;

				cout<<"\t\t\t ||| MATCH ENDS |||"<<endl<<endl;
				return false;
			}
		}
	}

	return true;
}

void Game::scoreCard(){

	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
			<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") | "
			<<batsman->name<<" "<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<") \t\t"
			<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "
			<<bowler->wicketsTaken<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl<<endl;
}

void Game::startSecondInning(){

	swapTeam(battingTeam, bowlingTeam);

	cout<<"\t\t\t ||| SECOND INNING STARTS ||| "<<endl<<endl;

	isFirstInnings=false;

	initializePlayers();

	playInning();

}

void Game::swapTeam(Team *bat, Team *bowl){
	Team temp=*bat;
	*bat=*bowl;
	*bowl=temp;
}

void Game::displayScoreBoard(){
	swapTeam(battingTeam, bowlingTeam);

	cout<<teamA.name<<" "<<teamA.totalRunsScored<<"-"<<teamA.wicketsLost
			<<" ("<<teamB.totalBallsBowled<<") "<<endl;
	cout<<"+=======================================================+"<<endl;
	cout<<"|\t Players\tBatting\t\tBowling \t|"<<endl;
	for(int i=0; i<playersPerTeam; i++){
		cout<<"|-------------------------------------------------------|"<<endl;
		cout<<"| \t["<<i<<"] "<<teamA.players[i].name<<"\t"<<teamA.players[i].runsScored<<
		"("<<teamA.players[i].ballsPlayed<<")"<<"\t\t"<<teamA.players[i].ballsBowled
				<<"-"<<teamA.players[i].runsGiven<<"-"<<teamA.players[i].wicketsTaken
				<<"\t\t|"<<endl;
	}
	cout<<"+=======================================================+"<<endl<<endl;
}

void Game::displayScoreBoard2(){

	cout<<teamB.name<<" "<<teamB.totalRunsScored<<"-"<<teamB.wicketsLost
			<<" ("<<teamA.totalBallsBowled<<") "<<endl;
	cout<<"+=======================================================+"<<endl;
	cout<<"|\t Players\tBatting\t\tBowling \t|"<<endl;
	for(int i=0; i<playersPerTeam; i++){
		cout<<"|-------------------------------------------------------|"<<endl;
		cout<<"| \t["<<i<<"] "<<teamB.players[i].name<<"\t"<<teamB.players[i].runsScored<<
		"("<<teamB.players[i].ballsPlayed<<")"<<"\t\t"<<teamB.players[i].ballsBowled
				<<"-"<<teamB.players[i].runsGiven<<"-"<<teamB.players[i].wicketsTaken
				<<"\t\t|"<<endl;
	}
	cout<<"+=======================================================+"<<endl<<endl;
}


