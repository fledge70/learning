// Helpful Aliases
var loader = PIXI.loader,
  resources = PIXI.loader.resources,
  Sprite = PIXI.Sprite;

// Create the PIXI app (helper class that includes
// necessary elements like stage and renderer)
var app = new PIXI.Application(360, 640);
document.body.appendChild(app.view);

// Define global variables
var player,
  gameState,
  jumping,
  fpsText,
  fpsDisplayCounter = 0;

// Load assets
loader
  .add("img/diamond.png")
  .load(setup);

function onClick() {
  if (!jumping) {
    jumping = true;
    player.vy = -6;
  }
}

function setup() {
	// Create sprites
  player = new Sprite(resources["img/diamond.png"].texture);

  // Create text for FPS counter display
  fpsText = new PIXI.Text('FPS:', {fill: '#00ff99'});
  fpsText.x = 16;
  fpsText.y = 16;
  app.stage.addChild(fpsText);
	
  // Set initial game state
  gameState = play;

  // Set initial position
  player.x = app.renderer.width / 2 - player.width / 2;
  player.y = app.renderer.height - player.height;
  // Set initial velocity and jumping state
  player.vx = 0;
  player.vy = 0;
  jumping = false;


  app.stage.addChild(player);

  // Make the stage interactive to capture pointer events
  app.stage.interactive = true;
  app.stage.hitArea = new PIXI.Rectangle(0, 0, 360, 640);
  app.stage.on('pointerdown', onClick);

  // Start the listener to update on every ticker from App
  app.ticker.add(gameState);
}

function play() {
  // Apply velocity values
  player.x += player.vx;
  player.y += player.vy;

  // Decay jumping velocity
  player.vy += .1;
  if (player.vy >= 6) {
    player.vy = 6;
    jumping = false;
  }

  // Constrain player to bounds of game screen
  fixToBounds(player, 0, 0, app.renderer.width, app.renderer.height);

  // Update FPS Counter text once every
  // 30 ticks (approx twice per second)
  fpsDisplayCounter++
  if (fpsDisplayCounter >= 30) {
    fpsText.text = "FPS: " + Math.round(app.ticker.FPS);
    fpsDisplayCounter = 0;
  }
}