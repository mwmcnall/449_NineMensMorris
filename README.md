# 449_NineMensMorris
Group Project for CS449 at UMKC
Nine Mens Morris

**General goals:**
- Re-create Nine Men's Morris
  - Side goal: Create a flexible enough build that other variations would be simple to implemement. 6 Men's, 12 Men's, etc.
- Take 'minute notes' during our meetings
- Have a GitHub for project

**Rules:**
- Board has a grid of twenty-four intersections / points
- Each Player has 9 pieces
  - Players try to form MILLS - three of their own men lined horizonally or vertically
    NOT diagonally
- Game is over when one Player is down to two pieces (can't form Mills)
  - OR by leaving them with no more legal moves
- Game Phases
  - Placing men on vacant points
    - Board starts EMPTY
    - First player is decided
    - Each places their men one per play on empty points
    - When a Mill is formed by one player:
      - Get to remove a piece of their opponents
        - A piece from a Mill can only be removed if there are no other pieces to remove
    - After ALL men have been placed, phase 2 begins
      - While loop until phase 2 starts
  - Moving men to adjacent points
    - Players alternate moves
    - Can move a man to an adjacent point. A piece cannot 'jump' another piece
    - Player can choose to 'break' a mill by moving one of their pieces out of an existing mill, then moving it back to form the same mill a second time (or any # of times), each time removing one of their opponents peices
    - When one player has been reduced to three men, phase 3 begins
  - (optional) Moving men to any vacant point when the player has been reduced to three men
    - A player that is reduced to three pieces they may 'fly' from any point to any vacant point
    - This can be treated as a 'variation'

**Strategy:**
- Start versatile, instead of forming mills immediately
- Don't concentrate all in one area
- Shuffling between two mills is ideal
- Choosing 'corner' spots w/in squares you can work towards trying to build two mills
  - One corner
  - One L away
    - Take a top left corner of a square
      - There are 3 sets of squares w/in Nine Men's Morris 
    - [All below directions are respective from original top left corner of a square move]
    - Down Down Right
      - Or Right Right Down
    - Then either of these two will guarantee a go:
      - Down Down
      - Down Down Right Right (Bottom right of square)
- For planning for phase 2:
  - Try to create situations where you are locking the other player out from interrupting a mill of yours simply by moving

**Game Logic:**
- Build empty Board
- Create both Players
  - Each players gets 9 pieces
- Game
  - Phase 1 loop
    - Ends when all pieces have been placed
  - Phase 2 loop
    - Ends when any one player has been reduced to three men
  - Phase 3 loop (Optional)
    - Ends when 'end game condition' has been met

**C++ Class Organization:**
- Game
  - Variables:
    - playerFirst, bool
      - Which team goes first
  - Methods:
    - Run Game()
      - Iniates game logic
    - Phase1()
      - Runs phase 1 loop
    - Phase2()
      - Runs phase 2 loop
    - Phase3()
      - Runs phase 3 loop
    - NextPlayer()
      - Initiates next Player's turn
- Board
  - Contain a vector of Points which Men can be placed on
    - a1, a2, etc.
    - Center point is NEVER valid, d4 in this case
  - Variables:
  - Methods:
    - Board():
      - Initializes a vector of size k by k (k = 7 in this case ) Points
- Point
  - Variables:
    - occupied, bool
    - coordinate, int
      - a1, a2, etc. could be defined as an enum, might not be practical for scaling game up or down tho
  - Methods:
    - Point()
      - Initializes occupied to false
        - Unless coordinate is the center point (d4 for our case), which will always be considered occupied
      - Sets coordinate
    - Occupy()
      - Sets occupied to true
    - Vacate()
      - Sets occupied to false
- Player
  - Variables:
    - team, bool
    - Pieces, vector(Men)
  - Methods:
    - Player()
      - Initialize vector of n Men to play the game with
- Men
  - Variables:
    - coordinate, int
    - team, bool
      - Either player 0 or 1 (or computer, but that can just be 1)
    - isMill, bool
      - Whether the piece is part of a mill
  - Methods:
    - Place(int coordinate)
      - Place piece on board
    - Move(int coordinate)
      - Checks if new coordinate is valid to move to
      - Moves if it is
    - DetectMill()
      - Checks horizontally and vertically if part of a mill
        - DetectMillHorizontal()
        - DetectMillVertical()
      - If yes, sets isMill to true
