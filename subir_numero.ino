#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int subir = A0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int buttonState;
int lastButtonState = LOW;

int drawCard() {
  randomSeed(analogRead(1));
  int number = random(12);
  return number;
}


int score;

void setup()
{
  lcd.begin(16, 2);
  pinMode(subir, INPUT);

}

void jogo() {
  int card1 = drawCard();
  int card2 = drawCard();
  lcd.setCursor(0, 0);
  lcd.print(card1);
  lcd.print(", ");
  lcd.print(card2);
  lcd.setCursor(0, 1);
  score = card1 + card2;
  lcd.print("Pontuacao: ");
  lcd.print(score);

  while (score < 21) {
    //waitForButtonPress();
    if (digitalRead(subir) == HIGH) {

      lcd.clear();
      int card3 = drawCard();
      lcd.setCursor(0, 0);
      lcd.print(card1);
      lcd.print(", ");
      lcd.print(card2);
      lcd.print(", ");
      lcd.print(card3);
      score += card3;
      lcd.setCursor(0, 1);
      lcd.print("Pontuacao: ");
      lcd.print(score);
      delay(500);

      if (score < 21) {
        if (digitalRead(subir) == HIGH) {
          lcd.clear();
          int card4 = drawCard();
          lcd.setCursor(0, 0);
          lcd.print(card1);
          lcd.print(", ");
          lcd.print(card2);
          lcd.print(", ");
          lcd.print(card3);
          lcd.print(", ");
          lcd.print(card4);
          score += card4;
          lcd.setCursor(0, 1);
          lcd.print("Pontuacao: ");
          lcd.print(score);
          delay(500);
        }
      }
    }

    if (score == 21) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pontuacao: ");
      lcd.print(score);
      lcd.setCursor(0, 1);
      lcd.print("Vitoria!");
      delay(5000);
      lcd.clear();
    }
    else if (score > 21) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pontuacao: ");
      lcd.print(score);
      lcd.setCursor(0, 1);
      lcd.print("Perdeste!");
      delay(5000);
      lcd.clear();
    }
  }
  delay(5000);
}

void loop() {
  jogo();
}
