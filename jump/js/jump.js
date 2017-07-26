// Helpful Aliases
var Container = PIXI.Container,
  autoDetectRenderer = PIXI.autoDetectRenderer,
  loader = PIXI.loader,
  resources = PIXI.loader.resources,
  Sprite = PIXI.Sprite;

// Create the PIXI stage and renderer
var stage = new Container(),
  renderer = autoDetectRenderer(640, 360);
document.body.appendChild(renderer.view);

// Define global variables
var player,
  gameState,
  jumping,
  fpsCounter,
  fpsText,
  currentTime,
  lastTime;

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
  stage.addChild(fpsText);
	
  // Set initial game state
  gameState = play;

  // Set initial position
  player.x = renderer.width / 2 - player.width / 2;
  player.y = renderer.height - player.height;
  // Set initial velocity and jumping state
  player.vx = 0;
  player.vy = 0;
  jumping = false;


  stage.addChild(player);

  // Make the stage interactive to capture pointer events
  stage.interactive = true;
  stage.hitArea = new PIXI.Rectangle(0, 0, 640, 360);
  stage.on('pointerdown', onClick);

  // Initilize counter used for FPS
  lastTime = (new Date()).getMilliseconds();

  // Start the game loop
  gameLoop();
}

function gameLoop() {
  
  requestAnimationFrame(gameLoop);
  
  // Update the current game gameState
  gameState();
  
  // Draw

  renderer.render(stage);
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
  fixToBounds(player, 0, 0, renderer.width, renderer.height);

  currentTime = (new Date()).getMilliseconds();
  fpsCounter = 1000 / (currentTime - lastTime);
  fpsText.text = "FPS: " + Math.round(fpsCounter);
  lastTime = (new Date()).getMilliseconds();
}