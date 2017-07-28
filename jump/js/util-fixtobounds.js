function fixToBounds(sprite, x, y, width, height) {
  // Constrain on Y axis
  if (sprite.y > y + height - sprite.height) {
  	sprite.y = y + height - sprite.height;
  } else if (sprite.y < y) {
  	sprite.y = y;
  }
  // Constrain on X axis
  if (sprite.x > x + width - sprite.width) {
  	sprite.x = x + width - sprite.width;
  } else if (sprite.x < x) {
  	sprite.x = x;
  }
}