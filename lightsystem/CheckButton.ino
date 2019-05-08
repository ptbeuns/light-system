bool CheckButton(int button)
{
  if (digitalRead(button) == HIGH)
  {
    delay(20);
    while(digitalRead(button) == HIGH);
      return true;
    }
  return false;
}
