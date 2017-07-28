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
  playScene,
  gameOverScene,
  gameState,
  fpsText,
  fpsDisplayCounter = 0,
  gameOverMessage,
  score = 0,
  jumpCharging = false,
  jumpCharge = 0,
  jumpMeterBar,
  jumpMeterMask,
  messageBox,
  scoreText,
  slipSpeed = 1.5,
  termVelocity = 6;

// Load assets
loader
  .add(['img/diamond.png',
  'img/cat.png',
  'img/tree.png',
  'img/bar.png',
  'img/mask.png',
  'img/messagebox.png'])
  .load(setup);

function onPointerDown() {
  if (player.x === treeLeft.width) {
    jumpCharging = true;
  } else if (player.x === app.renderer.width - treeRight.width
    - player.width) {
    jumpCharging = true;
  }
}

function onPointerUp() {
  if (jumpCharging) {
    jumpCharging = false;
  }
  makeJump();
}

function onPointerOut() {
  if (jumpCharging) {
    jumpCharging = false;
  }
  makeJump();
}

function onPointerTap() {
  console.log("onPointerTap executed!");
  window.location.reload(false);
}

function makeJump() {
  jumpCharging = false;
  if (player.x === treeLeft.width) {
    player.vx = 0.035 * jumpCharge;
    player.vy = -0.035 * jumpCharge;
  } else if (player.x === app.renderer.width - treeRight.width
    - player.width) {
    player.vx = -0.035 * jumpCharge;
    player.vy = -0.035 * jumpCharge;
  }
  jumpCharge = 0;

  // Update Jump Charge Bar
  jumpMeterMask.width = 200 - jumpCharge;
  jumpMeterMask.x = jumpMeterBar.x + 200 -jumpMeterMask.width;
}

function setup() {
	// Create containers for different game scenes
  playScene = new PIXI.DisplayObjectContainer();
  gameOverScene = new PIXI.DisplayObjectContainer();
  playScene.visible = true;
  gameOverScene.visible = false;
  app.stage.addChild(playScene);
  app.stage.addChild(gameOverScene);

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

  // Create the JumpCharge bar display
  jumpMeterBar = new Sprite(resources['img/bar.png'].texture);
  jumpMeterBar.height = 16;
  jumpMeterBar.width = 200;
  jumpMeterBar.x = app.renderer.width / 2 - jumpMeterBar.width / 2;
  jumpMeterBar.y = 16;
  playScene.addChild(jumpMeterBar);
  // Create the JumpCharge Mask
  jumpMeterMask = new Sprite(resources['img/mask.png'].texture);
  jumpMeterMask.height = jumpMeterBar.height;
  jumpMeterMask.width = 200 - jumpCharge;
  jumpMeterMask.x = jumpMeterBar.x + 200 -jumpMeterMask.width;
  jumpMeterMask.y = jumpMeterBar.y;
  playScene.addChild(jumpMeterMask);

  // Add all sprites to the playScene stage
  playScene.addChild(player);
  playScene.addChild(treeLeft);
  playScene.addChild(treeRight);
  for (var i = 0; i < diamondPool.length; i++) {
    playScene.addChild(diamondPool[i]);
  }

  // Create text for FPS counter display
  fpsText = new PIXI.Text('FPS:', {fill: '#00ff99'});
  fpsText.x = app.renderer.width - 104;
  fpsText.y = app.renderer.height - 32;
  playScene.addChild(fpsText);

  // Create score display
  scoreText = new PIXI.Text('Score: ' + score, {fill: '#00ff99'});
  scoreText.x = 16;
  scoreText.y = app.renderer.height - 32;
  playScene.addChild(scoreText);

  // Make the stage interactive to capture pointer events
  app.stage.interactive = true;
  app.stage.hitArea = new PIXI.Rectangle(0, 0, 352, 640);
  app.stage.on('pointerdown', onPointerDown);
  app.stage.on('pointerup', onPointerUp);
  app.stage.on('pointerout', onPointerOut);

  // Set up the gameOver display items
  messageBox = new Sprite(resources['img/messagebox.png'].texture);
  messageBox.x = 64;
  messageBox.y = 64;
  messageBox.width = app.renderer.width - 128;
  messageBox.height = 256;
  gameOverScene.addChild(messageBox);
  // Set up gameOver message
  gameOverMessage = new PIXI.Text('You win!\nClick or tap\nto reload.',
    {fill: '#bbbbbb'});
  gameOverMessage.x = messageBox.x + 8;
  gameOverMessage.y = messageBox.y + 8;
  gameOverScene.addChild(gameOverMessage);

  // Set initial game state
  gameState = play;

  // Start the listener to update on every ticker from App
  app.ticker.add(gameState);
}

function play() {
  // Apply velocity values
  player.x += player.vx;
  player.y += player.vy;

  // Charge the jumping if pointer held down
  if (jumpCharging) {
    jumpCharge += 3;
    if (jumpCharge > 200) jumpCharge = 200;
    jumpMeterMask.width = 200 - jumpCharge;
    jumpMeterMask.x = jumpMeterBar.x + 200 -jumpMeterMask.width;
  }

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

  for (var i = 0; i < diamondPool.length; i++) {
    if (spritesCollide(player, diamondPool[i])) {
      // destroy the diamond touched
      playScene.removeChild(diamondPool[i]);
      diamondPool.splice(i, 1);
      
      // Update score and associated text
      score += 25;
      scoreText.text = 'Score: ' + score;
    }
  }

  // Check for game over condition - that all diamonds
  // have been collected.  If true, switch to game over state
  if (diamondPool.length === 0) {
    gameOverScene.visible = true;
    app.stage.off('pointerdown', onPointerDown);
    app.stage.on('pointertap', onPointerTap);
    app.ticker.remove(gameState);    
    gameState = gameOver;
    app.ticker.add(gameState);
  }

  // Update FPS Counter text once every
  // 30 ticks (approx twice per second)
  fpsDisplayCounter++
  if (fpsDisplayCounter >= 30) {
    fpsText.text = "FPS: " + Math.round(app.ticker.FPS);
    fpsDisplayCounter = 0;
  }
}

function gameOver() {
  // Seems like this doesn't need anything to happen here
}