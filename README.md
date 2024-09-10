### Virtual Cricket Game

#### CRIC-IN: Virtual Cricket Game Application

**CRIC-IN** is a C++ virtual cricket game The application simulates a simple yet engaging cricket match between two teams with customizable players and game dynamics.

#### Features:

- **Two Teams (Team A & Team B)**:
  - Each team consists of 4 players, selected by the user from a pool of 11.
  - Players are selected in a sequence that defines their batting and bowling order.
  
- **Toss & Game Flow**:
  - A toss determines which team bats or bowls first.
  - The game consists of two innings, each with 6 deliveries.

- **Innings & Gameplay**:
  - Each innings has one bowler delivering 6 balls, and one batsman playing until they are out.
  - Runs can range from 0 to 6 per ball, with a batsman being declared out if they score 0.
  - The sequence of players batting and bowling is predefined based on the selection order.

- **Victory Conditions**:
  - Team with the higher score at the end of both innings wins.
  - If scores are tied, the match results in a draw.

- **User Interface**:
  - Display of player pool, team selections, scorecards after every delivery, and a detailed match summary at the end.

#### Classes:

- **Player**: Manages player details (name, runs, wickets, etc.).
- **Team**: Tracks team performance (total runs, wickets, etc.).
- **Game**: Coordinates the match, controls teams, and manages the overall game flow.

#### How to Play:

1. Select 4 players for each team.
2. Perform a toss and decide to bat or bowl first.
3. Play two innings with 6 deliveries each.
4. Check the real-time score updates and enjoy the match outcome.

#### Requirements:
- C++ compiler to run the program.
  
#### How to Run:
- Clone the repository and compile the program using a C++ compiler.

- ![m5-project-output_pptx-1](https://github.com/user-attachments/assets/1d5c975e-4613-4b50-9e5c-164fb56e0716)

- ![m5-project-output_pptx-3](https://github.com/user-attachments/assets/8a1cd68b-668a-4134-b5dc-f8132e7f3095)

- ![m5-project-output_pptx-6](https://github.com/user-attachments/assets/e1e0d4dd-86e8-4cef-a99a-730d1ebdf1e7)



