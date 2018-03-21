# BattleTank
An open-world head-to-head tank fight with simple AI, terrain, and advanced control system in Unreal 4.

## Lecture List
* Intro, Notes & Assets
* Game Design Document (GDD)
* Creating and Deleting Landscapes
* Landscape Setup and Scaling
* The Landscaping Process
* Using Landscape Layers
  * Created a new material in the blueprint and painted the landscape
* More Landscaping Tools
* Actors from Multiple Meshes
  * Created the Tank pawn using sockets
* Configuring a Tank
  * Made the Game Mode blueprint and set the Tank as the default pawn
* 3rd Person Camera Control
  * Use the Spring Arm to rotate the camera by mapping input in a blueprint
* Fixing 3rd Person Camera Rotation
  * Setup a gimbal for the camera to avoid compounding rotation
* User Interface (UI) in Unreal
  * Create the reticle for the tank player
* Main Menu Screens
  * Created Main Menu Level and imported a start screen image
* UI Scale Box, Buttons, & Mouse
* Mid Section Quiz Complete
* Unify Player and AI Timing
* Controller Ready Navigation
  * Linked the Start Button to Controller Input
* Trial Packaging Your Game
  * Packaged and tested the game, found and fixed an input bug
* Delegating to Components
  * Created new Tank Pawn, and new TankPlayerController PlayerController classes
* Using Virtual and Override
  * Overrode the BeginPlay Method in the TankPlayerController Class
* Overloading and Polymorphism
  * Polymorphism Review
* Virtual Functions and VTables
* Creating an AI Controller Class
* Get PlayerController with C++
  * Found the Player from the AIController
* Add Tick() to player controller
* Creating an Out Parameter Method
* Finding Screen Pixel Coordinates
  * Created a method to find a FVector2D of where the crosshair is
* Using DeprojectScreenToWorld
* Using LineTraceSingleByChannel
  * Get the vector location in World of what the reticle is over
* Unify Player and AI Aiming
* Mid Section Quiz
* Create Default Sub Objects in C++
* BlueprintCallable()
* SuggestProjectileVelocity()
  * Set up the arguments for SuggestProjectileVelocity()
* Predict Projectile Landing Point
* Using FRotators in Unreal

