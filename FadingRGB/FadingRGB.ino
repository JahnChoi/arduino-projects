const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

void setup() 
{
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop()
{
  delay(1000);
  primaryColors(1,0,0); // Red
  delay(2000);
  primaryColors(0,1,0); // Green
  delay(2000);
  primaryColors(0,0,1); // Blue
  delay(2000);
  primaryColors(1,1,0); // Yellow
  delay(2000);
  primaryColors(1,0,1); // Magenta
  delay(2000);
  primaryColors(0,1,1); // Cyan
  delay(2000);
  primaryColors(1,1,1); // White
  delay(2000);
  
  RGBFading();
}
void primaryColors(int redValue, int greenValue, int blueValue)
{
  digitalWrite(redPin, redValue);
  digitalWrite(greenPin, greenValue);
  digitalWrite(bluePin, blueValue);
}

void RGBFading()
{
  int x;  
  int redBrightness;
  int greenBrightness;
  int blueBrightness;
  
  for (x = 0; x < 768; x++)
  {
    if (x <= 255)
    {
      redBrightness = 255 - x;
      greenBrightness = x;
      blueBrightness = 0;
    }
    else if (x <= 511)
    {
      redBrightness = 0;
      greenBrightness = 255 - (x - 256);
      blueBrightness = (x - 256);
    }
    else
    {
      redBrightness = (x - 512);
      greenBrightness = 0;
      blueBrightness = 255 - (x - 512);
    }
    
  analogWrite(redPin, redBrightness);
  analogWrite(bluePin, blueBrightness);
  analogWrite(greenPin, greenBrightness);
  
  delay(10);
  }
}
