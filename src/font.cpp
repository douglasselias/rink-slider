Font font;
s32 font_size = 70;
f32 font_spacing = 0;

Font font_title;
s32 font_title_size = 90;

void init_font() {
  s32 codepoint_count = 0;
  s32 *codepoints = LoadCodepoints("1234567890!(),qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", &codepoint_count);
  font = LoadFontEx("fonts/RussoOne-Regular.ttf", font_size, codepoints, codepoint_count);
  /// @todo: not really necessary
  UnloadCodepoints(codepoints);
}

void init_font_title() {
  s32 codepoint_count = 0;
  s32 *codepoints = LoadCodepoints("RinkSlider", &codepoint_count);
  font_title = LoadFontEx("fonts/Rowdies-Regular.ttf", font_title_size, codepoints, codepoint_count);
  /// @todo: not really necessary
  UnloadCodepoints(codepoints);
}

/// @todo: maybe add a string struct? or maybe find a way to not need the const keyword
Vector2 measure_text(const char* text) {
  return MeasureTextEx(font, text, (f32)font_size, font_spacing);
}

void draw_text(const char* text, Vector2 position, Color color) {
  DrawTextEx(font, text, position, (f32)font_size, font_spacing, color);
}

Vector2 measure_text_title(const char* text) {
  return MeasureTextEx(font_title, text, (f32)font_title_size, font_spacing);
}

void draw_text_title(const char* text, Vector2 position, Color color) {
  DrawTextEx(font_title, text, position, (f32)font_title_size, font_spacing, color);
}

/// @todo: not really necessary
void unload_font() {
  UnloadFont(font);
}