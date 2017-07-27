// Helpful Aliases
var loader = PIXI.loader,
  resources = PIXI.loader.resources,
  Sprite = PIXI.Sprite;

// Create the PIXI app (helper class that includes
// necessary elements like stage and renderer)
var app = new PIXI.Application(352, 640);
document.body.appendChild(app.view);

// Define global variables
var player,
  treeLeft,
  treeRight,
  diamondPool = [],
  gameState,
  fpsText,
  fpsDisplayCounter = 0,
  slipSpeed = 1.5,
  termVelocity = 6;

// Load assets
loader
  .add('img/diamond.png')
  .add('img/cat.png')
  .add('img/tree.png')
  .load(setup);

function onClick() {
  // TODO: update conditions to check if player is touching tree
  if (player.x === treeLeft.width) {
    // jumping = true;
    player.vx = 4;
    player.vy = -4;
  } else if (player.x === app.renderer.width - treeRight.width
    - player.width) {
    player.vx = -4;
    player.vy = -4;
  }
}

function setup() {
	// Create sprites
  player = new Sprite(resources["img/cat.png"].texture);
  treeLeft = new Sprite(resources['img/tree.png'].texture);
  treeRight = new Sprite(resources['img/tree.png'].texture);

  // Set initial position of sprites
  player.x = treeLeft.width;
  player.y = player.height * 4;
  treeLeft.x = 0;
  treeLeft.y = 0;
  treeRight.x = app.renderer.width - treeRight.width;
  treeRight.y = 0;

  // Set initial velocity and jumping state for player
  player.vx = 0;
  player.vy = slipSpeed;
  // jumping = false;

  // Create and initialize diamonds
  var numberDiamonds = Math.floor(Math.random() * 5 + 3);
  for (var i = 0; i < numberDiamonds; i++) {
    var theDiamond = new Sprite(resources['img/diamond.png'].texture);
    theDiamond.x = Math.floor( (Math.random() * (app.renderer.width - 128 - theDiamond.width)) + 96);
    theDiamond.y = Math.floor( (Math.random() * (app.renderer.height - 192 - theDiamond.height)) + 96);
    diamondPool.push(theDiamond);
  }

  // Add all sprites to the stage
  app.stage.addChild(player);
  app.stage.addChild(treeLeft);
  app.stage.addChild(treeRight);
  for (var i = 0; i < diamondPool.length; i++) {
    app.stage.addChild(diamondPool[i]);
  }

  // Create text for FPS counter display
  fpsText = new PIXI.Text('FPS:', {fill: '#00ff99'});
  fpsText.x = 16;
  fpsText.y = 16;
  app.stage.addChild(fpsText);

  // Make the stage interactive to capture pointer events
  app.stage.interactive = true;
  app.stage.hitArea = new PIXI.Rectangle(0, 0, 352, 640);
  app.stage.on('pointerdown', onClick);

  // Set initial game state
  gameState = play;

  // diagnostic/troubleshooting
  console.log("app.renderer.width: " + app.renderer.width);
  console.log("treeRight.width: " + treeRight.width);

  // Start the listener to update on every ticker from App
  app.ticker.add(gameState);
}

function play() {
  // Apply velocity values
  player.x += player.vx;
  player.y += player.vy;

  // Constrain player to bounds of game screen and trees
  fixToBounds(player, treeLeft.width, 0,
    app.renderer.width - treeLeft.width - treeRight.width,
    app.renderer.height);
    
  // Check if player is touching a tree
  if (player.x <= treeLeft.width || player.x >= app.renderer.width
    - treeRight.width - player.width) {
    // player is hanging on tree, slowly slip
    player.vy = slipSpeed;
    player.vx = 0;
  } else {
    // player is falling or jumping, apply gravity
    player.vy += 0.1;
    if (player.vy >= termVelocity) {
      player.vy = termVelocity;
      // jumping = false;
    }
  }

  // Update FPS Counter text once every
  // 30 ticks (approx twice per second)
  fpsDisplayCounter++
  if (fpsDisplayCounter >= 30) {
    fpsText.text = "FPS: " + Math.round(app.ticker.FPS);
    fpsDisplayCounter = 0;
  }
}