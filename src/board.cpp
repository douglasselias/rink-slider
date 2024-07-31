u8 PLAYER   = 1;
u8 PLATFORM = 2;

u8 board[7][7] = {};

#define number_of_players 4
Vector2 player_positions[number_of_players] = {
  // Top left
  {0,0},
  // Top right
  {6,0},
  // Bottom left
  {0,6},
  // Bottom right
  {6,6},
};

void clear_board_positions() {
  for(u8 row = 0; row < 7; row++)
    for(u8 column = 0; column < 7; column++)
      board[row][column] = 0;
}

void update_board_positions(Vector2 platform_positions[12]) {
  for(u8 i = 0; i < 12; i++) {
    Vector2 p = platform_positions[i];
    board[cast_u8(p.y)][cast_u8(p.x)] |= PLATFORM;
  }
}

void update_board_players(Vector2 positions[number_of_players]) {
  for(u8 row = 0; row < 7; row++)
    for(u8 column = 0; column < 7; column++)
      board[row][column] &= ~PLAYER;

  for(u8 i = 0; i < number_of_players; i++) {
    Vector2 p = positions[i];
    board[cast_u8(p.y)][cast_u8(p.x)] |= PLAYER;
  }
}

Vector2 convert_board_position_to_screen_position(Vector2 offset, Vector2 position, u8 move_distance) {
  return offset + position * move_distance;
}