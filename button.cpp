#include"button.h"

const int buttonTalbe[16]={
  BUTTON_PIN1,
  BUTTON_PIN2,
  BUTTON_PIN3,
  BUTTON_PIN4,
  
};

void ButtonInit()
{
  int i;
  for(i=0;i<MAX_BT_NUM;i++)
    pinMode(buttonTable[i],INPUT);
  
}

int ButtonRead()
{
  int,nButtonstate=0;
  for(int i=0;i<MAX_BT_NUM;i++)
    if(!digitalRead(buttonTable[i]))
        nButtonstate |= (1<<i);
  return nButtonstate;
}

