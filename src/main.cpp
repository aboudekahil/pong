#include "ball.hpp"
#include "paddle.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <utility>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

enum class GameState { Playing, Won };

void Draw();
void Update();
void HandleEvents();
void InitBall();
void Restart();

Paddle paddle1{20, SCREEN_HEIGHT / 2.f, 10, 100, RAYWHITE};
Paddle paddle2{SCREEN_WIDTH - 30, SCREEN_HEIGHT / 2.f, 10, 100, RAYWHITE};

Ball ball{SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 10, RAYWHITE};

const double speed = 300.0f;

Vector2 ball_vec;

GameState gameState;
std::string winning_text;

float dt;

int main() {
  SetRandomSeed(std::time(NULL));
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "pong!");

  SetTargetFPS(60);
  Restart();
  while (!WindowShouldClose()) {
    dt = GetFrameTime();
    HandleEvents();
    Update();
    Draw();
  }

  return EXIT_SUCCESS;
}

void Restart(){
    InitBall();

    paddle1 = {20, SCREEN_HEIGHT / 2.f, 10, 100, RAYWHITE};
    paddle2 = {SCREEN_WIDTH - 30, SCREEN_HEIGHT / 2.f, 10, 100, RAYWHITE};
    gameState = GameState::Playing;
}

void Draw() {
  BeginDrawing();
  if (gameState == GameState::Playing) {
    ClearBackground(BLACK);

    DrawRectangle(paddle1.getX(), paddle1.getY(), paddle1.getWidth(),
                  paddle1.getHeight(), paddle1.getColor());

    DrawRectangle(paddle2.getX(), paddle2.getY(), paddle2.getWidth(),
                  paddle2.getHeight(), paddle2.getColor());

    DrawRectangle(ball.getX() - ball.getRadius() / 2.f,
                  ball.getY() - ball.getRadius() / 2.f, ball.getRadius(),
                  ball.getRadius(), ball.getColor());
  } else {
    Vector2 size = MeasureTextEx(GetFontDefault(), winning_text.c_str(), 48, 1);

    DrawText(winning_text.c_str(), SCREEN_WIDTH / 2.f - size.x / 2.f,
             SCREEN_HEIGHT / 2.f - size.y / 2.f, 48, GREEN);
  }
  EndDrawing();
}

void InitBall() {
  ball = Ball(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 10, RAYWHITE);
  ball_vec = {GetRandomValue(-300, 300) / 100.f,
              GetRandomValue(-300, 300) / 100.f};
  ball_vec = Vector2Normalize(ball_vec);

  ball_vec = {(float)(ball_vec.x * speed), (float)(ball_vec.y * speed)};
}

void HandleEvents() {
  if (gameState == GameState::Playing) {
    if (IsKeyDown(KEY_UP)) {
      paddle2.setY(paddle2.getY() - speed * dt);
    }
    if (IsKeyDown(KEY_DOWN)) {
      paddle2.setY(paddle2.getY() + speed * dt);
    }
    if (IsKeyDown(KEY_W)) {
      paddle1.setY(paddle1.getY() - speed * dt);
    }
    if (IsKeyDown(KEY_S)) {
      paddle1.setY(paddle1.getY() + speed * dt);
    }
  } else {

    if (IsKeyDown(KeyboardKey::KEY_SPACE)) {
      Restart();
    }
  }
}

void Update() {
  ball.setX(ball.getX() + ball_vec.x * dt);
  ball.setY(ball.getY() + ball_vec.y * dt);

  if (ball.getY() < 0 || ball.getY() > SCREEN_HEIGHT) {
    ball_vec.y *= -1;
  }

  bool hit_paddle1 = CheckCollisionRecs(paddle1.getBounds(), ball.getBounds());
  bool hit_paddle2 = CheckCollisionRecs(paddle2.getBounds(), ball.getBounds());

  if (hit_paddle1 || hit_paddle2) {
    ball_vec.x *= -1;
    
  }

  if (ball.getX() < 0 || ball.getX() > SCREEN_WIDTH) {
    gameState = GameState::Won;
    if (ball.getX() < 0) {
      winning_text = "player 2 won";
    } else if (ball.getX() > SCREEN_WIDTH) {
      winning_text = "player 1 won";
    }
  }
}
