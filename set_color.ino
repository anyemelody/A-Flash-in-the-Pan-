void AsetColor(int red, int green, int blue){
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(AredPin, red);
  analogWrite(AgreenPin, green);
  analogWrite(AbluePin, blue);  
}

void BsetColor(int red, int green, int blue){
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(BredPin, red);
  analogWrite(BgreenPin, green);
  analogWrite(BbluePin, blue);  
}

void CsetColor(int red, int green, int blue){
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(CredPin, red);
  analogWrite(CgreenPin, green);
  analogWrite(CbluePin, blue);  
}
